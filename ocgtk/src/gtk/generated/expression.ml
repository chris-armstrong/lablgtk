(* GENERATED CODE - DO NOT EDIT *)
(* Expression: Expression *)

type t = [ `expression ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_expression_get_type"

(* Methods *)

external unref : t -> unit = "ml_gtk_expression_unref"
(** Releases a reference on the given `GtkExpression`.

    If the reference was the last, the resources associated to the `self` are
    freed. *)

external ref : t -> t = "ml_gtk_expression_ref"
(** Acquires a reference on the given `GtkExpression`. *)

external is_static : t -> bool = "ml_gtk_expression_is_static"
(** Checks if the expression is static.

    A static expression will never change its result when
    [method@Gtk.Expression.evaluate] is called on it with the same arguments.

    That means a call to [method@Gtk.Expression.watch] is not necessary because
    it will never trigger a notify. *)

external get_value_type : t -> Gobject.Type.t
  = "ml_gtk_expression_get_value_type"
(** Gets the `GType` that this expression evaluates to.

    This type is constant and will not change over the lifetime of this
    expression. *)

external evaluate :
  t -> [ `object_ ] Gobject.obj option -> Gobject.Value.t -> bool
  = "ml_gtk_expression_evaluate"
(** Evaluates the given expression and on success stores the result
in @value.

The `GType` of `value` will be the type given by
[method@Gtk.Expression.get_value_type].

It is possible that expressions cannot be evaluated - for example
when the expression references objects that have been destroyed or
set to `NULL`. In that case `value` will remain empty and `FALSE`
will be returned. *)

external bind :
  t ->
  [ `object_ ] Gobject.obj ->
  string ->
  [ `object_ ] Gobject.obj option ->
  Expression_watch.t = "ml_gtk_expression_bind"
(** Bind `target`'s property named `property` to `self`.

    The value that `self` evaluates to is set via `g_object_set()` on `target`.
    This is repeated whenever `self` changes to ensure that the object's
    property stays synchronized with `self`.

    If `self`'s evaluation fails, `target`'s `property` is not updated. You can
    ensure that this doesn't happen by using a fallback expression.

    Note that this function takes ownership of `self`. If you want to keep it
    around, you should [method@Gtk.Expression.ref] it beforehand. *)
