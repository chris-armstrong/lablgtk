(* Forward declaration generation helpers - shared across record, class, enum,
   and bitfield modules *)

open Containers
open StdLabels

(** Generate a section of forward declarations. Common pattern across record,
    class, enum, and bitfield modules.

    Parameters:
    - buf: Buffer to append declarations to
    - items: List of items to generate declarations for
    - section_comment: Comment header for this section
    - generate_one: Function to generate declarations for a single item
    - deduplicate: Whether to track seen types with Hashtbl (default: true) *)
let generate_forward_decl_section ~(buf : Buffer.t) ~(items : 'a list)
    ~(section_comment : string) ~(generate_one : 'a -> unit)
    ?(deduplicate : bool = true) () =
  if List.length items > 0 then (
    Buffer.add_string buf section_comment;
    let seen = if deduplicate then Some (Hashtbl.create 97) else None in
    List.iter
      ~f:(fun item ->
        match seen with
        | Some tbl when Hashtbl.mem tbl item -> ()
        | Some tbl ->
            Hashtbl.add tbl item ();
            generate_one item
        | None -> generate_one item)
      items;
    Buffer.add_string buf "\n")
