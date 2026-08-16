(* Type Analysis Helpers for Property Type Introspection *)

open StdLabels

(** Type analysis helpers for property type introspection *)
module Type_analysis = struct
  (** [list_contains ~value list] returns [true] when [value] is a member of
      [list] (exact string comparison). *)
  let list_contains ~value list =
    List.exists list ~f:(fun candidate -> String.equal candidate value)

  (* Predicates moved to Filtering. *)

  (** Fold with map and index - combines fold_left_map with index tracking *)
  let fold_mapi ~f ~init list =
    let rec aux idx acc = function
      | [] -> (acc, [])
      | x :: xs ->
          let acc', y = f idx acc x in
          let final_acc, ys = aux (idx + 1) acc' xs in
          (final_acc, y :: ys)
    in
    aux 0 init list

  (** C type names treated as strings (e.g. ["gchar"], ["utf8"]). *)
  let string_base_types = [ "gchar"; "char"; "utf8"; "gchararray" ]

  (** C type names mapped to 32-bit signed integers. *)
  let int32_types =
    [ "gint"; "int"; "gint32"; "int32"; "gint16"; "int16"; "gint8"; "int8" ]

  (** C type names mapped to 32-bit unsigned integers. *)
  let uint32_types =
    [
      "guint";
      "uint";
      "guint32";
      "uint32";
      "guint16";
      "uint16";
      "guint8";
      "uint8";
    ]

  (** C type names mapped to 64-bit signed integers. *)
  let int64_types = [ "gint64"; "int64" ]

  (** C type names mapped to 64-bit unsigned integers. *)
  let uint64_types = [ "guint64"; "uint64" ]

  (** C type names mapped to [glong]-style signed long integers. *)
  let long_types = [ "glong"; "long"; "goffset"; "off_t" ]

  (** C type names mapped to [gulong]-style unsigned long integers. *)
  let ulong_types = [ "gulong"; "ulong" ]

  (** C type names mapped to [gssize]-style signed size integers. *)
  let ssize_types = [ "gssize"; "ssize_t" ]

  (** C type names mapped to [gsize]-style unsigned size integers. *)
  let size_types = [ "gsize"; "size_t" ]

  (** C type names mapped to single-precision floats. *)
  let float_types = [ "gfloat"; "float" ]

  (** C type names mapped to double-precision floats. *)
  let double_types = [ "gdouble"; "double" ]
end
