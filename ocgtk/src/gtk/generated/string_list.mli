(* GENERATED CODE - DO NOT EDIT *)
(* StringList: StringList *)

type t = [ `string_list | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_string_list_get_type"

external new_ : string array option -> t = "ml_gtk_string_list_new"
(** Create a new StringList *)

(* Methods *)

external take : t -> string -> unit = "ml_gtk_string_list_take"
(** Adds @string to self at the end, and takes
ownership of it.

This variant of [method@Gtk.StringList.append]
is convenient for formatting strings:

```c
gtk_string_list_take (self, g_strdup_print ("%d dollars", lots));
``` *)

external splice : t -> int -> int -> string array option -> unit
  = "ml_gtk_string_list_splice"
(** Changes @self by removing @n_removals strings and adding @additions
to it.

This function is more efficient than [method@Gtk.StringList.append]
and [method@Gtk.StringList.remove], because it only emits the
::items-changed signal once for the change.

This function copies the strings in @additions.

The parameters @position and @n_removals must be correct (ie:
@position + @n_removals must be less than or equal to the length
of the list at the time this function is called). *)

external remove : t -> int -> unit = "ml_gtk_string_list_remove"
(** Removes the string at @position from @self.

@position must be smaller than the current
length of the list. *)

external get_string : t -> int -> string option
  = "ml_gtk_string_list_get_string"
(** Gets the string that is at @position in @self.

If @self does not contain @position items, %NULL is returned.

This function returns the const char *. To get the
object wrapping it, use g_list_model_get_item(). *)

external find : t -> string -> int = "ml_gtk_string_list_find"
(** Gets the position of the @string in @self.

If @self does not contain @string item, `G_MAXUINT` is returned. *)

external append : t -> string -> unit = "ml_gtk_string_list_append"
(** Appends @string to @self.

The @string will be copied. See
[method@Gtk.StringList.take] for a way to avoid that. *)

(* Properties *)

external get_item_type : t -> Gobject.Type.t
  = "ml_gtk_string_list_get_item_type"
(** Get property: item-type *)

external get_n_items : t -> int = "ml_gtk_string_list_get_n_items"
(** Get property: n-items *)
