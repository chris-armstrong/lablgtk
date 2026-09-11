(* GENERATED CODE - DO NOT EDIT *)
(* ExpressionWatch: ExpressionWatch *)

type t = [ `expression_watch ] Gobject.obj
(** An opaque structure representing a watched `GtkExpression`.

    The contents of `GtkExpressionWatch` should only be accessed through the
    provided API. *)

external gtype : unit -> Gobject.Type.t = "ml_gtk_expression_watch_get_type"

(* Methods *)

external unwatch : t -> unit = "ml_gtk_expression_watch_unwatch"
(** Stops watching an expression.

    See [method@Gtk.Expression.watch] for how the watch was established. *)

external ref : t -> t = "ml_gtk_expression_watch_ref"
(** Acquires a reference on the given `GtkExpressionWatch`. *)

external evaluate : t -> Gobject.Value.t -> bool
  = "ml_gtk_expression_watch_evaluate"
(** Evaluates the watched expression and on success stores the result in
    `value`.

    This is equivalent to calling [method@Gtk.Expression.evaluate] with the
    expression and this pointer originally used to create `watch`. *)
