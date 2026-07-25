module Gir_direction = struct
  type t = Types.gir_direction = In | Out | InOut

  let is_in = function In | InOut -> true | Out -> false
  let is_in_only = function In -> true | Out | InOut -> false
  let has_output = function Out | InOut -> true | In -> false
end

(* String-level predicates — the single source of the [GLib.*] container-name
   literals. Both the [gir_type]-level and [gir_array]-level predicates below
   delegate here, and the GIR parser routes its raw [type_name] checks through
   [is_hash_table_name] so no other module spells these literals. *)

let is_glist_name name = CCString.equal name "GLib.List"
let is_gslist_name name = CCString.equal name "GLib.SList"
let is_hash_table_name name = CCString.equal name "GLib.HashTable"

(* [gir_type]-level predicates. *)

let is_glist (gt : Types.gir_type) = is_glist_name gt.name
let is_gslist (gt : Types.gir_type) = is_gslist_name gt.name
let is_list (gt : Types.gir_type) = is_glist gt || is_gslist gt
let is_hash_table (gt : Types.gir_type) = is_hash_table_name gt.name

(* [gir_array]-level predicates. A container's [array_name] is an [string
   option] (set by the parser for GList/GSList/GPtrArray/HashTable/...); route
   the option handling through the shared name predicate so the literal lives
   in one place. *)

let is_hash_table_array (arr : Types.gir_array) =
  match arr.array_name with Some n -> is_hash_table_name n | None -> false
