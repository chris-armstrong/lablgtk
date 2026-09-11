(* GENERATED CODE - DO NOT EDIT *)
(* PixbufSimpleAnim: PixbufSimpleAnim *)

type t = [ `pixbuf_simple_anim | `pixbuf_animation | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gdk_pixbuf_pixbuf_simple_anim_get_type"

external new_ : int -> int -> float -> t = "ml_gdk_pixbuf_simple_anim_new"
(** Create a new PixbufSimpleAnim *)

(* Methods *)

external set_loop : t -> bool -> unit = "ml_gdk_pixbuf_simple_anim_set_loop"
(** Sets whether @animation should loop indefinitely when it reaches the end. *)

external get_loop : t -> bool = "ml_gdk_pixbuf_simple_anim_get_loop"
(** Gets whether @animation should loop indefinitely when it reaches the end. *)

external add_frame : t -> Pixbuf.t -> unit
  = "ml_gdk_pixbuf_simple_anim_add_frame"
(** Adds a new frame to @animation. The @pixbuf must
have the dimensions specified when the animation
was constructed. *)

(* Properties *)
