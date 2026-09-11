(* GENERATED CODE - DO NOT EDIT *)
(* ThemedIcon: ThemedIcon *)

type t = [ `themed_icon | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_themed_icon_get_type"

external new_ : string -> t = "ml_g_themed_icon_new"
(** Create a new ThemedIcon *)

external new_from_names : string array -> int -> t
  = "ml_g_themed_icon_new_from_names"
(** Create a new ThemedIcon *)

external new_with_default_fallbacks : string -> t
  = "ml_g_themed_icon_new_with_default_fallbacks"
(** Create a new ThemedIcon *)

(* Methods *)

external prepend_name : t -> string -> unit = "ml_g_themed_icon_prepend_name"
(** Prepend a name to the list of icons from within @icon.

Note that doing so invalidates the hash computed by prior calls
to g_icon_hash(). *)

external get_names : t -> string array = "ml_g_themed_icon_get_names"
(** Gets the names of icons from within @icon. *)

external append_name : t -> string -> unit = "ml_g_themed_icon_append_name"
(** Append a name to the list of icons from within @icon.

Note that doing so invalidates the hash computed by prior calls
to g_icon_hash(). *)

(* Properties *)

external get_use_default_fallbacks : t -> bool
  = "ml_g_themed_icon_get_use_default_fallbacks"
(** Get property: use-default-fallbacks *)
