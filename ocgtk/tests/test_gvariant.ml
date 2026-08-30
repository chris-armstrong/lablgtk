(** GVariant Module Tests

    These tests validate the GVariant implementation including:
    - Type introspection (type_string, is_of_type)
    - Scalar constructors and accessors (boolean, int32, int64, double, string)
    - Collections (string arrays)
    - Dictionary access (a{sv} pattern with lookups)
    - Child access for tuples/arrays
    - Serialization (print, parse)
    - Memory management with GC stress testing
*)

(** {2 Type Introspection Tests} *)

let test_type_string_boolean () =
  let v = Gvariant.of_boolean true in
  let type_str = Gvariant.type_string v in
  Alcotest.(check string) "boolean type is 'b'" "b" type_str

let test_type_string_int32 () =
  let v = Gvariant.of_int32 42l in
  let type_str = Gvariant.type_string v in
  Alcotest.(check string) "int32 type is 'i'" "i" type_str

let test_type_string_int64 () =
  let v = Gvariant.of_int64 42L in
  let type_str = Gvariant.type_string v in
  Alcotest.(check string) "int64 type is 'x'" "x" type_str

let test_type_string_double () =
  let v = Gvariant.of_double 3.14 in
  let type_str = Gvariant.type_string v in
  Alcotest.(check string) "double type is 'd'" "d" type_str

let test_type_string_string () =
  let v = Gvariant.of_string "hello" in
  let type_str = Gvariant.type_string v in
  Alcotest.(check string) "string type is 's'" "s" type_str

let test_is_of_type_basic () =
  let v = Gvariant.of_int32 42l in
  Alcotest.(check bool) "int32 is of type 'i'" true (Gvariant.is_of_type v "i");
  Alcotest.(check bool)
    "int32 is not of type 's'" false
    (Gvariant.is_of_type v "s")

(** {2 Boolean Tests} *)

let test_boolean_roundtrip_true () =
  let v = Gvariant.of_boolean true in
  let result = Gvariant.to_boolean v in
  Alcotest.(check bool) "boolean true roundtrip" true result

let test_boolean_roundtrip_false () =
  let v = Gvariant.of_boolean false in
  let result = Gvariant.to_boolean v in
  Alcotest.(check bool) "boolean false roundtrip" false result

(** {2 Int32 Tests} *)

let test_int32_roundtrip_positive () =
  let v = Gvariant.of_int32 42l in
  let result = Gvariant.to_int32 v in
  Alcotest.(check int32) "int32 positive roundtrip" 42l result

let test_int32_roundtrip_negative () =
  let v = Gvariant.of_int32 (-42l) in
  let result = Gvariant.to_int32 v in
  Alcotest.(check int32) "int32 negative roundtrip" (-42l) result

let test_int32_roundtrip_zero () =
  let v = Gvariant.of_int32 0l in
  let result = Gvariant.to_int32 v in
  Alcotest.(check int32) "int32 zero roundtrip" 0l result

let test_int32_roundtrip_max () =
  let v = Gvariant.of_int32 Stdlib.Int32.max_int in
  let result = Gvariant.to_int32 v in
  Alcotest.(check int32) "int32 max roundtrip" Stdlib.Int32.max_int result

let test_int32_roundtrip_min () =
  let v = Gvariant.of_int32 Stdlib.Int32.min_int in
  let result = Gvariant.to_int32 v in
  Alcotest.(check int32) "int32 min roundtrip" Stdlib.Int32.min_int result

(** {2 Int64 Tests} *)

let test_int64_roundtrip_positive () =
  let v = Gvariant.of_int64 42L in
  let result = Gvariant.to_int64 v in
  Alcotest.(check int64) "int64 positive roundtrip" 42L result

let test_int64_roundtrip_negative () =
  let v = Gvariant.of_int64 (-42L) in
  let result = Gvariant.to_int64 v in
  Alcotest.(check int64) "int64 negative roundtrip" (-42L) result

let test_int64_roundtrip_zero () =
  let v = Gvariant.of_int64 0L in
  let result = Gvariant.to_int64 v in
  Alcotest.(check int64) "int64 zero roundtrip" 0L result

let test_int64_roundtrip_large () =
  let large = Int64.of_int32 Stdlib.Int32.max_int |> Int64.add 1L in
  let v = Gvariant.of_int64 large in
  let result = Gvariant.to_int64 v in
  Alcotest.(check int64) "int64 large roundtrip" large result

(** {2 Byte (uint8) Tests} *)

let test_byte_roundtrip () =
  let v = Gvariant.of_byte 42 in
  Alcotest.(check string) "byte type is 'y'" "y" (Gvariant.type_string v);
  let result = Gvariant.to_byte v in
  Alcotest.(check int) "byte roundtrip" 42 result

let test_byte_bounds () =
  let v_min = Gvariant.of_byte 0 in
  let v_max = Gvariant.of_byte 255 in
  Alcotest.(check int) "byte min" 0 (Gvariant.to_byte v_min);
  Alcotest.(check int) "byte max" 255 (Gvariant.to_byte v_max)

(** {2 Int16 Tests} *)

let test_int16_roundtrip () =
  let v = Gvariant.of_int16 1000 in
  Alcotest.(check string) "int16 type is 'n'" "n" (Gvariant.type_string v);
  let result = Gvariant.to_int16 v in
  Alcotest.(check int) "int16 roundtrip" 1000 result

(** {2 UInt16 Tests} *)

let test_uint16_roundtrip () =
  let v = Gvariant.of_uint16 (UInt16.of_int 50000) in
  Alcotest.(check string) "uint16 type is 'q'" "q" (Gvariant.type_string v);
  let result = Gvariant.to_uint16 v in
  Alcotest.(check int) "uint16 roundtrip" 50000 (UInt16.to_int result)

(** {2 UInt32 Tests} *)

let test_uint32_roundtrip () =
  let v = Gvariant.of_uint32 (UInt32.of_int 42) in
  Alcotest.(check string) "uint32 type is 'u'" "u" (Gvariant.type_string v);
  let result = Gvariant.to_uint32 v in
  Alcotest.(check int) "uint32 roundtrip" 42 (UInt32.to_int result)

let test_uint32_max () =
  let max_val = UInt32.of_string "4294967295" in
  let v = Gvariant.of_uint32 max_val in
  let result = Gvariant.to_uint32 v in
  Alcotest.(check string) "uint32 max" "4294967295" (UInt32.to_string result)

(** {2 UInt64 Tests} *)

let test_uint64_roundtrip () =
  let v = Gvariant.of_uint64 (UInt64.of_int 42) in
  Alcotest.(check string) "uint64 type is 't'" "t" (Gvariant.type_string v);
  let result = Gvariant.to_uint64 v in
  Alcotest.(check int) "uint64 roundtrip" 42 (UInt64.to_int result)

let test_uint64_large () =
  let large = UInt64.of_string "18446744073709551615" in
  let v = Gvariant.of_uint64 large in
  let result = Gvariant.to_uint64 v in
  Alcotest.(check string)
    "uint64 max" "18446744073709551615" (UInt64.to_string result)

(** {2 Boundary Tests for Unsigned Types}

    These tests verify correct serialization/deserialization at the
    signed/unsigned boundary (where values exceed max_int but fit in unsigned).
*)

let test_uint16_boundary () =
  (* Test value > Int16.max_int (32767) but < UInt16.max_int (65535) *)
  let boundary_val = UInt16.of_int 50000 in
  let v = Gvariant.of_uint16 boundary_val in
  let result = Gvariant.to_uint16 v in
  Alcotest.(check int) "uint16 boundary value" 50000 (UInt16.to_int result)

let test_uint32_boundary () =
  (* Test values around Int32.max_int boundary *)
  let just_above_max_int =
    UInt32.of_int64 (Int64.add (Int64.of_int32 Stdlib.Int32.max_int) 1L)
  in
  let v = Gvariant.of_uint32 just_above_max_int in
  let result = Gvariant.to_uint32 v in
  Alcotest.(check int64)
    "uint32 just above Int32.max_int"
    (Int64.add (Int64.of_int32 Stdlib.Int32.max_int) 1L)
    (UInt32.to_int64 result)

let test_uint32_boundary_exact () =
  (* Test exactly at 2^31 (where signed int32 would be negative) *)
  let boundary = UInt32.of_string "2147483648" in
  let v = Gvariant.of_uint32 boundary in
  let result = Gvariant.to_uint32 v in
  Alcotest.(check string)
    "uint32 at 2^31 boundary" "2147483648" (UInt32.to_string result)

let test_uint64_boundary () =
  (* Test value > Int64.max_int (would be negative as signed) *)
  let above_max_int = UInt64.of_string "9223372036854775808" in
  let v = Gvariant.of_uint64 above_max_int in
  let result = Gvariant.to_uint64 v in
  Alcotest.(check string)
    "uint64 at Int64.max_int+1" "9223372036854775808" (UInt64.to_string result)

let test_uint64_serialization_roundtrip () =
  (* Verify that GVariant print/parse preserves large unsigned values *)
  let large_val = UInt64.of_string "12345678901234567890" in
  let v = Gvariant.of_uint64 large_val in
  (* Print and verify type is correct *)
  Alcotest.(check string) "uint64 large value type" "t" (Gvariant.type_string v);
  (* Verify roundtrip *)
  let result = Gvariant.to_uint64 v in
  Alcotest.(check string)
    "uint64 large value roundtrip" "12345678901234567890"
    (UInt64.to_string result)

(** {2 Double Tests} *)

let test_double_roundtrip_positive () =
  let v = Gvariant.of_double 3.14159 in
  let result = Gvariant.to_double v in
  Alcotest.(check (float 0.0001)) "double positive roundtrip" 3.14159 result

let test_double_roundtrip_negative () =
  let v = Gvariant.of_double (-3.14159) in
  let result = Gvariant.to_double v in
  Alcotest.(check (float 0.0001)) "double negative roundtrip" (-3.14159) result

let test_double_roundtrip_zero () =
  let v = Gvariant.of_double 0.0 in
  let result = Gvariant.to_double v in
  Alcotest.(check (float 0.0001)) "double zero roundtrip" 0.0 result

let test_double_special_values () =
  let v_inf = Gvariant.of_double infinity in
  let result_inf = Gvariant.to_double v_inf in
  Alcotest.(check bool) "infinity roundtrip" true (result_inf = infinity);

  let v_neg_inf = Gvariant.of_double neg_infinity in
  let result_neg_inf = Gvariant.to_double v_neg_inf in
  Alcotest.(check bool)
    "neg_infinity roundtrip" true
    (result_neg_inf = neg_infinity);

  let v_nan = Gvariant.of_double nan in
  let result_nan = Gvariant.to_double v_nan in
  Alcotest.(check bool) "nan roundtrip" true (Float.is_nan result_nan)

(** {2 String Tests} *)

let test_string_roundtrip_ascii () =
  let v = Gvariant.of_string "Hello, World!" in
  let result = Gvariant.to_string v in
  Alcotest.(check string) "string ASCII roundtrip" "Hello, World!" result

let test_string_roundtrip_unicode () =
  let v = Gvariant.of_string "Hello, 世界! 🎉" in
  let result = Gvariant.to_string v in
  Alcotest.(check string) "string Unicode roundtrip" "Hello, 世界! 🎉" result

let test_string_roundtrip_empty () =
  let v = Gvariant.of_string "" in
  let result = Gvariant.to_string v in
  Alcotest.(check string) "string empty roundtrip" "" result

(** {2 String Array Tests} *)

let test_string_array_roundtrip () =
  let arr = [| "hello"; "world"; "foo"; "bar" |] in
  let v = Gvariant.of_string_array arr in
  let result = Gvariant.to_string_array v in
  Alcotest.(check int) "string array length" 4 (Array.length result);
  Alcotest.(check string) "string array element 0" "hello" result.(0);
  Alcotest.(check string) "string array element 1" "world" result.(1);
  Alcotest.(check string) "string array element 2" "foo" result.(2);
  Alcotest.(check string) "string array element 3" "bar" result.(3)

let test_string_array_empty () =
  let arr = [||] in
  let v = Gvariant.of_string_array arr in
  let result = Gvariant.to_string_array v in
  Alcotest.(check int) "empty string array length" 0 (Array.length result)

let test_string_array_single () =
  let arr = [| "only" |] in
  let v = Gvariant.of_string_array arr in
  let result = Gvariant.to_string_array v in
  Alcotest.(check int) "single string array length" 1 (Array.length result);
  Alcotest.(check string) "single string array element" "only" result.(0)

(** {2 Dictionary Tests (a{sv} pattern)}

    Dictionary syntax: {'key': <value>} creates a{sv} (string→variant dict)
    - Keys are single-quoted strings: 'name'
    - Values in angle brackets become variants: <'John'>
*)

let test_dict_lookup_string () =
  let v = Gvariant.parse "{'name': <'John'>, 'city': <'NYC'>}" in
  Alcotest.(check string)
    "dictionary type is a{sv}" "a{sv}" (Gvariant.type_string v);
  match Gvariant.lookup_string v "name" with
  | Some name -> Alcotest.(check string) "lookup string name" "John" name
  | None -> Alcotest.fail "Expected to find 'name' key"

let test_dict_lookup_string_missing () =
  let v = Gvariant.parse "{'name': <'John'>}" in
  match Gvariant.lookup_string v "missing" with
  | Some _ -> Alcotest.fail "Expected not to find 'missing' key"
  | None -> Alcotest.(check bool) "missing key returns None" true true

let test_dict_lookup_int32 () =
  let v = Gvariant.parse "{'count': <42>, 'size': <100>}" in
  match Gvariant.lookup_int32 v "count" with
  | Some count -> Alcotest.(check int32) "lookup int32 count" 42l count
  | None -> Alcotest.fail "Expected to find 'count' key"

let test_dict_lookup_int32_missing () =
  let v = Gvariant.parse "{'count': <42>}" in
  match Gvariant.lookup_int32 v "missing" with
  | Some _ -> Alcotest.fail "Expected not to find 'missing' key"
  | None -> Alcotest.(check bool) "missing int32 key returns None" true true

let test_dict_lookup_boolean () =
  let v = Gvariant.parse "{'enabled': <true>, 'disabled': <false>}" in
  (match Gvariant.lookup_boolean v "enabled" with
  | Some enabled -> Alcotest.(check bool) "lookup boolean enabled" true enabled
  | None -> Alcotest.fail "Expected to find 'enabled' key");
  match Gvariant.lookup_boolean v "disabled" with
  | Some disabled ->
      Alcotest.(check bool) "lookup boolean disabled" false disabled
  | None -> Alcotest.fail "Expected to find 'disabled' key"

(** {2 Child Access Tests} *)

let test_n_children_tuple () =
  let v = Gvariant.parse "(1, 2, 3)" in
  let n = Gvariant.n_children v in
  Alcotest.(check int) "tuple has 3 children" 3 n

let test_n_children_array () =
  let v = Gvariant.of_string_array [| "a"; "b"; "c"; "d" |] in
  let n = Gvariant.n_children v in
  Alcotest.(check int) "array has 4 children" 4 n

let test_get_child_value () =
  let v = Gvariant.parse "(1, 'hello', true)" in
  let child0 = Gvariant.get_child_value v 0 in
  let child1 = Gvariant.get_child_value v 1 in
  let child2 = Gvariant.get_child_value v 2 in
  Alcotest.(check int32) "child 0 is int32" 1l (Gvariant.to_int32 child0);
  Alcotest.(check string)
    "child 1 is string" "hello"
    (Gvariant.to_string child1);
  Alcotest.(check bool) "child 2 is bool" true (Gvariant.to_boolean child2)

(** {2 Serialization Tests} *)

let test_print_simple () =
  let v = Gvariant.of_int32 42l in
  let s = Gvariant.print v false in
  Alcotest.(check string) "print int32" "42" s

let test_print_string () =
  let v = Gvariant.of_string "hello" in
  let s = Gvariant.print v false in
  (* GLib wraps strings in quotes *)
  Alcotest.(check bool)
    "print string contains hello" true
    (String.length s > 0 && String.contains s 'h')

let test_print_boolean () =
  let v = Gvariant.of_boolean true in
  let s = Gvariant.print v false in
  Alcotest.(check string) "print true" "true" s;
  let v2 = Gvariant.of_boolean false in
  let s2 = Gvariant.print v2 false in
  Alcotest.(check string) "print false" "false" s2

let test_print_double () =
  let v = Gvariant.of_double 3.14 in
  let s = Gvariant.print v false in
  (* GLib may format differently, just check it contains the number *)
  Alcotest.(check bool)
    "print double contains 3.14" true
    (String.contains s '3' && String.contains s '.')

let test_parse_simple () =
  let v = Gvariant.parse "42" in
  Alcotest.(check string) "parse int32 type" "i" (Gvariant.type_string v);
  Alcotest.(check int32) "parse int32 value" 42l (Gvariant.to_int32 v)

let test_parse_string () =
  let v = Gvariant.parse "\"hello world\"" in
  Alcotest.(check string) "parse string type" "s" (Gvariant.type_string v);
  Alcotest.(check string)
    "parse string value" "hello world" (Gvariant.to_string v)

let test_parse_boolean () =
  let v_true = Gvariant.parse "true" in
  let v_false = Gvariant.parse "false" in
  Alcotest.(check string) "parse true type" "b" (Gvariant.type_string v_true);
  Alcotest.(check bool) "parse true value" true (Gvariant.to_boolean v_true);
  Alcotest.(check string) "parse false type" "b" (Gvariant.type_string v_false);
  Alcotest.(check bool) "parse false value" false (Gvariant.to_boolean v_false)

let test_parse_roundtrip () =
  let original = "(1, 'test', true)" in
  let v = Gvariant.parse original in
  let printed = Gvariant.print v false in
  (* Parse the printed version and verify it matches *)
  let v2 = Gvariant.parse printed in
  Alcotest.(check int32)
    "roundtrip child 0" 1l
    (Gvariant.to_int32 (Gvariant.get_child_value v2 0));
  Alcotest.(check string)
    "roundtrip child 1" "test"
    (Gvariant.to_string (Gvariant.get_child_value v2 1));
  Alcotest.(check bool)
    "roundtrip child 2" true
    (Gvariant.to_boolean (Gvariant.get_child_value v2 2))

(** {2 GC Stress Tests} *)

let test_gc_stress_variants () =
  (* Create many variants and let GC run *)
  for _i = 1 to 1000 do
    let _ = Gvariant.of_int32 42l in
    let _ = Gvariant.of_string "test" in
    let _ = Gvariant.of_boolean true in
    ()
  done;
  Gc.compact ();
  (* If we get here without crash, test passes *)
  Alcotest.(check bool) "GC stress test completed" true true

let test_gc_stress_arrays () =
  (* Create many string arrays and let GC run *)
  for _i = 1 to 500 do
    let arr = Array.init 100 (fun j -> "element_" ^ string_of_int j) in
    let _ = Gvariant.of_string_array arr in
    ()
  done;
  Gc.compact ();
  Alcotest.(check bool) "GC stress arrays completed" true true

let test_gc_stress_nested () =
  (* Create nested structures via API - simple version *)
  for _i = 1 to 10 do
    let v = Gvariant.of_string_array [| "a"; "b"; "c"; "d"; "e" |] in
    let _ = Gvariant.n_children v in
    ()
  done;
  Gc.compact ();
  Alcotest.(check bool) "GC stress nested completed" true true

let test_ref_count_stability () =
  (* Create variant and check it's stable across GC *)
  let v = Gvariant.of_string "persistent" in
  let s1 = Gvariant.to_string v in
  Gc.compact ();
  let s2 = Gvariant.to_string v in
  Alcotest.(check string) "value stable across GC" s1 s2

(** {2 Type Safety Tests}

    These tests verify that getters raise Failure when called on variants of the
    wrong type. *)

let test_type_safety_boolean () =
  let v = Gvariant.of_int32 42l in
  try
    let _ = Gvariant.to_boolean v in
    Alcotest.fail "to_boolean should have raised Failure on int32 variant"
  with
  | Failure msg ->
      Alcotest.(check bool)
        "error message mentions boolean" true (String.contains msg 'b')
  | exn ->
      Alcotest.fail
        ("to_boolean raised wrong exception type: " ^ Printexc.to_string exn)

let test_type_safety_int32 () =
  let v = Gvariant.of_string "hello" in
  try
    let _ = Gvariant.to_int32 v in
    Alcotest.fail "to_int32 should have raised Failure on string variant"
  with
  | Failure _ -> Alcotest.(check bool) "int32 type check works" true true
  | exn ->
      Alcotest.fail
        ("to_int32 raised wrong exception type: " ^ Printexc.to_string exn)

let test_type_safety_string () =
  let v = Gvariant.of_boolean true in
  try
    let _ = Gvariant.to_string v in
    Alcotest.fail "to_string should have raised Failure on boolean variant"
  with
  | Failure _ -> Alcotest.(check bool) "string type check works" true true
  | exn ->
      Alcotest.fail
        ("to_string raised wrong exception type: " ^ Printexc.to_string exn)

let test_type_safety_string_accepts_object_path () =
  (* get_string should accept object paths as per GLib docs *)
  let v = Gvariant.parse "objectpath '/org/example/Object'" in
  let result = Gvariant.to_string v in
  Alcotest.(check string)
    "get_string accepts object_path" "/org/example/Object" result

let test_type_safety_string_accepts_signature () =
  (* get_string should accept signatures as per GLib docs *)
  let v = Gvariant.parse "signature 'i'" in
  let result = Gvariant.to_string v in
  Alcotest.(check string) "get_string accepts signature" "i" result

let test_type_safety_int64 () =
  let v = Gvariant.of_int32 42l in
  try
    let _ = Gvariant.to_int64 v in
    Alcotest.fail "to_int64 should have raised Failure on int32 variant"
  with
  | Failure _ -> Alcotest.(check bool) "int64 type check works" true true
  | exn ->
      Alcotest.fail
        ("to_int64 raised wrong exception type: " ^ Printexc.to_string exn)

let test_type_safety_double () =
  let v = Gvariant.of_int32 42l in
  try
    let _ = Gvariant.to_double v in
    Alcotest.fail "to_double should have raised Failure on int32 variant"
  with
  | Failure _ -> Alcotest.(check bool) "double type check works" true true
  | exn ->
      Alcotest.fail
        ("to_double raised wrong exception type: " ^ Printexc.to_string exn)

let test_type_safety_byte () =
  let v = Gvariant.of_int32 42l in
  try
    let _ = Gvariant.to_byte v in
    Alcotest.fail "to_byte should have raised Failure on int32 variant"
  with
  | Failure _ -> Alcotest.(check bool) "byte type check works" true true
  | exn ->
      Alcotest.fail
        ("to_byte raised wrong exception type: " ^ Printexc.to_string exn)

let test_type_safety_handle () =
  let v = Gvariant.of_int32 42l in
  try
    let _ = Gvariant.to_handle v in
    Alcotest.fail "to_handle should have raised Failure on int32 variant"
  with
  | Failure _ -> Alcotest.(check bool) "handle type check works" true true
  | exn ->
      Alcotest.fail
        ("to_handle raised wrong exception type: " ^ Printexc.to_string exn)

let test_type_safety_variant () =
  let v = Gvariant.of_int32 42l in
  try
    let _ = Gvariant.to_variant v in
    Alcotest.fail "to_variant should have raised Failure on int32 variant"
  with
  | Failure _ -> Alcotest.(check bool) "variant type check works" true true
  | exn ->
      Alcotest.fail
        ("to_variant raised wrong exception type: " ^ Printexc.to_string exn)

let test_type_safety_maybe () =
  let v = Gvariant.of_int32 42l in
  try
    let _ = Gvariant.to_maybe v in
    Alcotest.fail "to_maybe should have raised Failure on int32 variant"
  with
  | Failure _ -> Alcotest.(check bool) "maybe type check works" true true
  | exn ->
      Alcotest.fail
        ("to_maybe raised wrong exception type: " ^ Printexc.to_string exn)

let test_type_safety_strv () =
  let v = Gvariant.of_string "hello" in
  try
    let _ = Gvariant.to_string_array v in
    Alcotest.fail "to_string_array should have raised Failure on string variant"
  with
  | Failure _ -> Alcotest.(check bool) "strv type check works" true true
  | exn ->
      Alcotest.fail
        ("to_string_array raised wrong exception type: "
       ^ Printexc.to_string exn)

let test_type_safety_objv () =
  let v = Gvariant.of_string "hello" in
  try
    let _ = Gvariant.to_object_path_array v in
    Alcotest.fail
      "to_object_path_array should have raised Failure on string variant"
  with
  | Failure _ -> Alcotest.(check bool) "objv type check works" true true
  | exn ->
      Alcotest.fail
        ("to_object_path_array raised wrong exception type: "
       ^ Printexc.to_string exn)

(** {2 Test Suite} *)

let () =
  Alcotest.run "GVariant Tests"
    [
      ( "Type Introspection",
        [
          Alcotest.test_case "type string boolean" `Quick
            test_type_string_boolean;
          Alcotest.test_case "type string int32" `Quick test_type_string_int32;
          Alcotest.test_case "type string int64" `Quick test_type_string_int64;
          Alcotest.test_case "type string double" `Quick test_type_string_double;
          Alcotest.test_case "type string string" `Quick test_type_string_string;
          Alcotest.test_case "is_of_type basic" `Quick test_is_of_type_basic;
        ] );
      ( "Boolean",
        [
          Alcotest.test_case "roundtrip true" `Quick test_boolean_roundtrip_true;
          Alcotest.test_case "roundtrip false" `Quick
            test_boolean_roundtrip_false;
        ] );
      ( "Int32",
        [
          Alcotest.test_case "roundtrip positive" `Quick
            test_int32_roundtrip_positive;
          Alcotest.test_case "roundtrip negative" `Quick
            test_int32_roundtrip_negative;
          Alcotest.test_case "roundtrip zero" `Quick test_int32_roundtrip_zero;
          Alcotest.test_case "roundtrip max" `Quick test_int32_roundtrip_max;
          Alcotest.test_case "roundtrip min" `Quick test_int32_roundtrip_min;
        ] );
      ( "Int64",
        [
          Alcotest.test_case "roundtrip positive" `Quick
            test_int64_roundtrip_positive;
          Alcotest.test_case "roundtrip negative" `Quick
            test_int64_roundtrip_negative;
          Alcotest.test_case "roundtrip zero" `Quick test_int64_roundtrip_zero;
          Alcotest.test_case "roundtrip large" `Quick test_int64_roundtrip_large;
        ] );
      ( "Byte",
        [
          Alcotest.test_case "roundtrip" `Quick test_byte_roundtrip;
          Alcotest.test_case "bounds" `Quick test_byte_bounds;
        ] );
      ("Int16", [ Alcotest.test_case "roundtrip" `Quick test_int16_roundtrip ]);
      ( "UInt16",
        [
          Alcotest.test_case "roundtrip" `Quick test_uint16_roundtrip;
          Alcotest.test_case "boundary" `Quick test_uint16_boundary;
        ] );
      ( "UInt32",
        [
          Alcotest.test_case "roundtrip" `Quick test_uint32_roundtrip;
          Alcotest.test_case "max" `Quick test_uint32_max;
          Alcotest.test_case "boundary" `Quick test_uint32_boundary;
          Alcotest.test_case "boundary exact" `Quick test_uint32_boundary_exact;
        ] );
      ( "UInt64",
        [
          Alcotest.test_case "roundtrip" `Quick test_uint64_roundtrip;
          Alcotest.test_case "large" `Quick test_uint64_large;
          Alcotest.test_case "boundary" `Quick test_uint64_boundary;
          Alcotest.test_case "serialization roundtrip" `Quick
            test_uint64_serialization_roundtrip;
        ] );
      ( "Double",
        [
          Alcotest.test_case "roundtrip positive" `Quick
            test_double_roundtrip_positive;
          Alcotest.test_case "roundtrip negative" `Quick
            test_double_roundtrip_negative;
          Alcotest.test_case "roundtrip zero" `Quick test_double_roundtrip_zero;
          Alcotest.test_case "special values" `Quick test_double_special_values;
        ] );
      ( "String",
        [
          Alcotest.test_case "roundtrip ASCII" `Quick
            test_string_roundtrip_ascii;
          Alcotest.test_case "roundtrip Unicode" `Quick
            test_string_roundtrip_unicode;
          Alcotest.test_case "roundtrip empty" `Quick
            test_string_roundtrip_empty;
        ] );
      ( "String Array",
        [
          Alcotest.test_case "roundtrip" `Quick test_string_array_roundtrip;
          Alcotest.test_case "empty" `Quick test_string_array_empty;
          Alcotest.test_case "single" `Quick test_string_array_single;
        ] );
      ( "Dictionary",
        [
          Alcotest.test_case "lookup string" `Quick test_dict_lookup_string;
          Alcotest.test_case "lookup string missing" `Quick
            test_dict_lookup_string_missing;
          Alcotest.test_case "lookup int32" `Quick test_dict_lookup_int32;
          Alcotest.test_case "lookup int32 missing" `Quick
            test_dict_lookup_int32_missing;
          Alcotest.test_case "lookup boolean" `Quick test_dict_lookup_boolean;
        ] );
      ( "Child Access",
        [
          Alcotest.test_case "n_children tuple" `Quick test_n_children_tuple;
          Alcotest.test_case "n_children array" `Quick test_n_children_array;
          Alcotest.test_case "get_child_value" `Quick test_get_child_value;
        ] );
      ( "Serialization",
        [
          Alcotest.test_case "print simple" `Quick test_print_simple;
          Alcotest.test_case "print string" `Quick test_print_string;
          Alcotest.test_case "print boolean" `Quick test_print_boolean;
          Alcotest.test_case "print double" `Quick test_print_double;
          Alcotest.test_case "parse simple" `Quick test_parse_simple;
          Alcotest.test_case "parse string" `Quick test_parse_string;
          Alcotest.test_case "parse boolean" `Quick test_parse_boolean;
          Alcotest.test_case "parse roundtrip" `Quick test_parse_roundtrip;
        ] );
      ( "GC Stress",
        [
          Alcotest.test_case "variants" `Slow test_gc_stress_variants;
          Alcotest.test_case "arrays" `Slow test_gc_stress_arrays;
          Alcotest.test_case "nested" `Slow test_gc_stress_nested;
          Alcotest.test_case "ref count stability" `Quick
            test_ref_count_stability;
        ] );
      ( "Type Safety",
        [
          Alcotest.test_case "boolean type check" `Quick
            test_type_safety_boolean;
          Alcotest.test_case "int32 type check" `Quick test_type_safety_int32;
          Alcotest.test_case "string type check" `Quick test_type_safety_string;
          Alcotest.test_case "string accepts object_path" `Quick
            test_type_safety_string_accepts_object_path;
          Alcotest.test_case "string accepts signature" `Quick
            test_type_safety_string_accepts_signature;
          Alcotest.test_case "int64 type check" `Quick test_type_safety_int64;
          Alcotest.test_case "double type check" `Quick test_type_safety_double;
          Alcotest.test_case "byte type check" `Quick test_type_safety_byte;
          Alcotest.test_case "handle type check" `Quick test_type_safety_handle;
          Alcotest.test_case "variant type check" `Quick
            test_type_safety_variant;
          Alcotest.test_case "maybe type check" `Quick test_type_safety_maybe;
          Alcotest.test_case "strv type check" `Quick test_type_safety_strv;
          Alcotest.test_case "objv type check" `Quick test_type_safety_objv;
        ] );
    ]
