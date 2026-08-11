(** Forward declaration section generation for generated C code.

    Generates a comment-headed section of forward declarations with optional
    deduplication, shared by the record, class, enum and bitfield generators. *)

val generate_forward_decl_section :
  buf:Buffer.t ->
  items:'a list ->
  section_comment:string ->
  generate_one:('a -> unit) ->
  ?deduplicate:bool ->
  unit ->
  unit
(** [generate_forward_decl_section ~buf ~items ~section_comment ~generate_one
     ?deduplicate ()] appends a section of forward declarations to [buf].

    @param buf buffer to append declarations to
    @param items list of items to generate declarations for
    @param section_comment comment header for this section
    @param generate_one function to generate declarations for a single item
    @param deduplicate track seen types with a [Hashtbl] (default: [true]) *)
