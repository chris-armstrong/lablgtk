(* Fold-based helper for parsing Xmlm element trees. See [Gir_xml_fold]. *)

type input = Xmlm.input
type attrs = Xmlm.attribute list
type tag = Xmlm.name

type 'acc handler = attrs:attrs -> 'acc -> 'acc
(** A child handler runs after the child's [`El_start] has been consumed by
    [fold_element]. It receives the child's attributes and the current
    accumulator, and must consume the rest of the child — including its matching
    [`El_end] — returning the updated accumulator.

    The handler typically does one of:
    - recurse via [fold_element] (container children), which consumes the
      child's [`El_end] as part of its own contract;
    - use [leaf] (attribute-only children), which [skip_element]s the body and
      [`El_end] automatically;
    - call [skip_element] / a text reader directly for the rare special case.

    [fold_element] owns the sibling-advance loop, so a handler cannot forget to
    move to the next sibling — the bug class that drops the rest of an element's
    children after a branch is eliminated by construction. *)

type 'acc dispatch = tag -> 'acc handler option
(** Dispatch maps a child's tag to its handler, or [None] for unknown tags.
    [fold_element] skips unknown tags via [skip_element] — the only safe
    default, since interpreting an unknown child as anything else would silently
    mis-parse the parent's remaining children. *)

val skip_element : input -> int -> unit

val leaf : input:input -> (attrs:attrs -> 'acc -> 'acc) -> 'acc handler
(** [leaf ~input f] is a handler for a child whose body is irrelevant — only its
    attributes matter. It computes the new accumulator from [attrs] via [f] and
    then [skip_element]s the rest of the child (consuming its [`El_end]). Use
    for self-closing or empty children such as <type>. *)

val required :
  input:input ->
  extract:(attrs -> 'v option) ->
  build:(attrs:attrs -> 'v -> 'acc -> 'acc) ->
  'acc handler
(** [required ~input ~extract ~build] is a handler for a child whose body is
    only meaningful when its attributes satisfy a precondition.
    - [extract attrs] checks the child's attributes; returning [Some v] means
      they are sufficient and [v] carries the extracted values.
    - [build ~attrs v acc] then consumes the rest of the child (body +
      [`El_end], typically by recursing into [fold_element] / [leaf]) and
      returns the updated accumulator.
    - if [extract attrs = None], the child is skipped (consumed without parsing)
      and [acc] is returned unchanged.

    This is the declarative form of the
    [match required_attrs with Some _ -> parse_body | _ -> skip_element input 1;
     acc] idiom that otherwise litters dispatch tables, and it keeps
    [skip_element] out of handler bodies. *)

val fold_element :
  input:input ->
  dispatch:'acc dispatch ->
  ?on_data:(string -> 'acc -> 'acc) ->
  ?stop_on:(tag -> bool) ->
  init:'acc ->
  unit ->
  'acc
(** [fold_element ~input ~dispatch ~init ()] folds the children of the element
    whose [`El_start] has just been consumed, and returns the accumulator at the
    matching [`El_end] (which it consumes).

    [on_data] folds interleaved text data (default: ignore).

    [stop_on], when it returns [true] for a child's tag, terminates the fold
    early and returns the accumulator *without consuming that child* — the
    sentinel sibling is left for the caller. This expresses the "fold until a
    sentinel" pattern (e.g. folding a parent's children until a particular
    sibling that the caller will handle). *)

val fold_document :
  input:input ->
  dispatch:'acc dispatch ->
  ?on_data:(string -> 'acc -> 'acc) ->
  init:'acc ->
  unit ->
  'acc
(** [fold_document] is the top-level variant: it folds a sequence of sibling
    elements until end-of-input rather than until a matching [`El_end]. The GIR
    document is not wrapped in a single element, so the top-level
    [parse_document] loop needs this, not [fold_element]. *)
