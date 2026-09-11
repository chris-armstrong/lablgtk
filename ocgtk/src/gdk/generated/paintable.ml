(* GENERATED CODE - DO NOT EDIT *)
(* Paintable: Paintable *)

type t = [ `paintable ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gdk_paintable_get_type"
external from_gobject : 'a Gobject.obj -> t = "ml_gdk_paintable_from_gobject"

(* Methods *)

external snapshot : t -> Snapshot.t -> float -> float -> unit
  = "ml_gdk_paintable_snapshot"
(** Snapshots the given paintable with the given @width and @height.

The paintable is drawn at the current (0,0) offset of the @snapshot.
If @width and @height are not larger than zero, this function will
do nothing. *)

external invalidate_size : t -> unit = "ml_gdk_paintable_invalidate_size"
(** Called by implementations of `GdkPaintable` to invalidate their size.

As long as the size is not invalidated, @paintable must return the same
values for its intrinsic width, height and aspect ratio.

This function will emit the [signal@Gdk.Paintable::invalidate-size]
signal.

If a @paintable reports the %GDK_PAINTABLE_STATIC_SIZE flag,
it must not call this function. *)

external invalidate_contents : t -> unit
  = "ml_gdk_paintable_invalidate_contents"
(** Called by implementations of `GdkPaintable` to invalidate their contents.

Unless the contents are invalidated, implementations must guarantee that
multiple calls of [method@Gdk.Paintable.snapshot] produce the same output.

This function will emit the [signal@Gdk.Paintable::invalidate-contents]
signal.

If a @paintable reports the %GDK_PAINTABLE_STATIC_CONTENTS flag,
it must not call this function. *)

external get_intrinsic_width : t -> int = "ml_gdk_paintable_get_intrinsic_width"
(** Gets the preferred width the @paintable would like to be displayed at.

Consumers of this interface can use this to reserve enough space to draw
the paintable.

This is a purely informational value and does not in any way limit the
values that may be passed to [method@Gdk.Paintable.snapshot].

If the @paintable does not have a preferred width, it returns 0.
Negative values are never returned. *)

external get_intrinsic_height : t -> int
  = "ml_gdk_paintable_get_intrinsic_height"
(** Gets the preferred height the @paintable would like to be displayed at.

Consumers of this interface can use this to reserve enough space to draw
the paintable.

This is a purely informational value and does not in any way limit the
values that may be passed to [method@Gdk.Paintable.snapshot].

If the @paintable does not have a preferred height, it returns 0.
Negative values are never returned. *)

external get_intrinsic_aspect_ratio : t -> float
  = "ml_gdk_paintable_get_intrinsic_aspect_ratio"
(** Gets the preferred aspect ratio the @paintable would like to be displayed at.

The aspect ratio is the width divided by the height, so a value of 0.5
means that the @paintable prefers to be displayed twice as high as it
is wide. Consumers of this interface can use this to preserve aspect
ratio when displaying the paintable.

This is a purely informational value and does not in any way limit the
values that may be passed to [method@Gdk.Paintable.snapshot].

Usually when a @paintable returns nonzero values from
[method@Gdk.Paintable.get_intrinsic_width] and
[method@Gdk.Paintable.get_intrinsic_height] the aspect ratio
should conform to those values, though that is not required.

If the @paintable does not have a preferred aspect ratio,
it returns 0. Negative values are never returned. *)

external get_flags : t -> Gdk_enums.paintableflags
  = "ml_gdk_paintable_get_flags"
(** Get flags for the paintable.

    This is oftentimes useful for optimizations.

    See [flags@Gdk.PaintableFlags] for the flags and what they mean. *)

external get_current_image : t -> t = "ml_gdk_paintable_get_current_image"
(** Gets an immutable paintable for the current contents displayed by @paintable.

This is useful when you want to retain the current state of an animation,
for example to take a screenshot of a running animation.

If the @paintable is already immutable, it will return itself. *)

external compute_concrete_size :
  t -> float -> float -> float -> float -> float * float
  = "ml_gdk_paintable_compute_concrete_size"
(** Compute a concrete size for the `GdkPaintable`.

Applies the sizing algorithm outlined in the
[CSS Image spec](https://drafts.csswg.org/css-images-3/#default-sizing)
to the given @paintable. See that link for more details.

It is not necessary to call this function when both @specified_width
and @specified_height are known, but it is useful to call this
function in GtkWidget:measure implementations to compute the
other dimension when only one dimension is given. *)

let on_invalidate_contents ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"invalidate-contents" ~callback
    ~after:(Option.value after ~default:false)

let on_invalidate_size ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"invalidate-size" ~callback
    ~after:(Option.value after ~default:false)
