(** Glib_bytes Module Tests

    These tests validate the Glib_bytes implementation including:
    - Roundtrip (create from string, convert back to string)
    - Empty byte buffers
    - Size reporting
    - Binary data with null bytes
    - Large buffers
    - GC stress testing
    - Unicode data *)

(** {2 Basic Roundtrip Tests} *)

let test_empty_roundtrip () =
  let b = Glib_bytes.create "" in
  let result = Glib_bytes.to_string b in
  Alcotest.(check string) "empty bytes roundtrip" "" result

let test_simple_string_roundtrip () =
  let b = Glib_bytes.create "hello, world" in
  let result = Glib_bytes.to_string b in
  Alcotest.(check string) "simple string roundtrip" "hello, world" result

(** {2 Size Tests} *)

let test_size_empty () =
  let b = Glib_bytes.create "" in
  Alcotest.(check int) "empty bytes size is 0" 0 (Glib_bytes.size b)

let test_size_nonempty () =
  let b = Glib_bytes.create "hello" in
  Alcotest.(check int) "5-char string size is 5" 5 (Glib_bytes.size b)

let test_size_matches_string_length () =
  let s = "the quick brown fox" in
  let b = Glib_bytes.create s in
  Alcotest.(check int)
    "size matches string length" (String.length s) (Glib_bytes.size b)

(** {2 Binary Data Tests} *)

let test_binary_null_bytes () =
  let s = "\x00\x01\x02\x03" in
  let b = Glib_bytes.create s in
  let result = Glib_bytes.to_string b in
  Alcotest.(check string) "binary data with null bytes roundtrip" s result

let test_binary_null_bytes_size () =
  let s = "\x00\x01\x02\x03" in
  let b = Glib_bytes.create s in
  Alcotest.(check int) "binary data size" 4 (Glib_bytes.size b)

let test_binary_all_byte_values () =
  (* Create a string with all byte values 0..255 *)
  let buf = Bytes.create 256 in
  for i = 0 to 255 do
    Bytes.set buf i (Char.chr i)
  done;
  let s = Bytes.to_string buf in
  let b = Glib_bytes.create s in
  let result = Glib_bytes.to_string b in
  Alcotest.(check string) "all byte values roundtrip" s result

(** {2 Large Buffer Test} *)

let test_large_buffer () =
  let size = 1024 * 1024 in
  (* 1 MB *)
  let s = String.make size 'x' in
  let b = Glib_bytes.create s in
  Alcotest.(check int) "large buffer size" size (Glib_bytes.size b);
  let result = Glib_bytes.to_string b in
  Alcotest.(check string) "large buffer roundtrip" s result

(** {2 GC Stress Test} *)

let test_gc_stress () =
  let last = ref (Glib_bytes.create "init") in
  for i = 0 to 9999 do
    last := Glib_bytes.create (string_of_int i)
  done;
  Gc.full_major ();
  let result = Glib_bytes.to_string !last in
  Alcotest.(check string) "gc stress: last value survives" "9999" result

(** {2 Unicode Data Test} *)

let test_unicode_roundtrip () =
  (* UTF-8 encoded string with multi-byte characters *)
  let s = "Hello, \xc3\xa9\xc3\xa0\xc3\xbc\xc3\xb6!" in
  (* é à ü ö *)
  let b = Glib_bytes.create s in
  let result = Glib_bytes.to_string b in
  Alcotest.(check string) "unicode data roundtrip" s result

(** {2 Multiple References Test} *)

let test_multiple_references () =
  let s = "shared data" in
  let b1 = Glib_bytes.create s in
  (* to_string copies data into a new OCaml string each time *)
  let r1 = Glib_bytes.to_string b1 in
  let r2 = Glib_bytes.to_string b1 in
  Alcotest.(check string) "first reference matches" s r1;
  Alcotest.(check string) "second reference matches" s r2;
  Alcotest.(check bool) "results are equal" true (String.equal r1 r2)

(** {2 Size After GC Test} *)

let test_size_after_gc () =
  let b = Glib_bytes.create "stable size" in
  Gc.compact ();
  Alcotest.(check int) "size stable after GC" 11 (Glib_bytes.size b)

(** {2 of_bigstring Tests}

    [of_bigstring] takes a Bigarray directly instead of an OCaml string, to
    avoid the intermediate string copy [create] requires. These tests check
    content equality against the bigarray's source string, and that the
    resulting GBytes is a real copy -- unaffected by mutating the source
    bigarray after construction, or by [Gc.compact]. *)

let bigstring_of_string s =
  let n = String.length s in
  let ba = Bigarray.Array1.create Bigarray.char Bigarray.c_layout n in
  for i = 0 to n - 1 do
    Bigarray.Array1.set ba i s.[i]
  done;
  ba

let test_of_bigstring_content_equality () =
  let s = "the quick brown fox jumps over the lazy dog" in
  let ba = bigstring_of_string s in
  let b = Glib_bytes.of_bigstring ba in
  Alcotest.(check int) "of_bigstring size matches source" (String.length s)
    (Glib_bytes.size b);
  Alcotest.(check string) "of_bigstring content matches source" s
    (Glib_bytes.to_string b)

let test_of_bigstring_empty () =
  let ba = bigstring_of_string "" in
  let b = Glib_bytes.of_bigstring ba in
  Alcotest.(check int) "of_bigstring empty size is 0" 0 (Glib_bytes.size b);
  Alcotest.(check string) "of_bigstring empty content" ""
    (Glib_bytes.to_string b)

let test_of_bigstring_binary_null_bytes () =
  let s = "\x00\x01\x02\x03" in
  let ba = bigstring_of_string s in
  let b = Glib_bytes.of_bigstring ba in
  Alcotest.(check string) "of_bigstring binary data roundtrip" s
    (Glib_bytes.to_string b)

(* No lifetime/aliasing coupling: build a GBytes from a bigstring, then
   mutate the bigstring's contents in place and force two full compacting
   collections, and check the GBytes content is still the *original* data.
   Bigarray payloads are malloc'd and Gc.compact never relocates them, so a
   Gc.compact-only check can't distinguish a real copy from an aliasing
   implementation (e.g. one built on g_bytes_new_static) -- the [fill]
   after [of_bigstring] is the load-bearing assertion: if of_bigstring ever
   aliased the bigarray's storage instead of copying it, the GBytes content
   would read back as all 0xFF here. *)
let test_of_bigstring_survives_gc_compact () =
  let expected = "owx: single-copy GBytes from Bigstring" in
  let ba = bigstring_of_string expected in
  let b = Glib_bytes.of_bigstring ba in
  Bigarray.Array1.fill ba '\xff';
  Gc.compact ();
  Gc.compact ();
  Alcotest.(check string) "of_bigstring content is a copy, unaffected by \
                           post-construction mutation of the source \
                           bigarray or Gc.compact"
    expected (Glib_bytes.to_string b)

(** {2 Test Suite} *)

let () =
  Alcotest.run "Glib_bytes"
    [
      ( "roundtrip",
        [
          Alcotest.test_case "empty bytes roundtrip" `Quick test_empty_roundtrip;
          Alcotest.test_case "simple string roundtrip" `Quick
            test_simple_string_roundtrip;
          Alcotest.test_case "unicode roundtrip" `Quick test_unicode_roundtrip;
          Alcotest.test_case "multiple references" `Quick
            test_multiple_references;
        ] );
      ( "size",
        [
          Alcotest.test_case "empty size" `Quick test_size_empty;
          Alcotest.test_case "nonempty size" `Quick test_size_nonempty;
          Alcotest.test_case "size matches string length" `Quick
            test_size_matches_string_length;
          Alcotest.test_case "size after GC" `Quick test_size_after_gc;
        ] );
      ( "binary",
        [
          Alcotest.test_case "null bytes roundtrip" `Quick
            test_binary_null_bytes;
          Alcotest.test_case "null bytes size" `Quick
            test_binary_null_bytes_size;
          Alcotest.test_case "all byte values roundtrip" `Quick
            test_binary_all_byte_values;
        ] );
      ("large", [ Alcotest.test_case "1MB buffer" `Slow test_large_buffer ]);
      ( "gc",
        [ Alcotest.test_case "gc stress 10000 objects" `Slow test_gc_stress ] );
      ( "of_bigstring",
        [
          Alcotest.test_case "content equality" `Quick
            test_of_bigstring_content_equality;
          Alcotest.test_case "empty bigstring" `Quick test_of_bigstring_empty;
          Alcotest.test_case "binary null bytes" `Quick
            test_of_bigstring_binary_null_bytes;
          Alcotest.test_case
            "is a copy: survives source mutation + Gc.compact" `Quick
            test_of_bigstring_survives_gc_compact;
        ] );
    ]
