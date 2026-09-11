(* GENERATED CODE - DO NOT EDIT *)
(* Snapshot: Snapshot *)

type t = [ `snapshot | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_snapshot_get_type"

external new_ : unit -> t = "ml_gtk_snapshot_new"
(** Create a new Snapshot *)

(* Methods *)

external translate_3d : t -> Ocgtk_graphene.Graphene.Wrappers.Point3_d.t -> unit
  = "ml_gtk_snapshot_translate_3d"
(** Translates @snapshot's coordinate system by @point. *)

external translate : t -> Ocgtk_graphene.Graphene.Wrappers.Point.t -> unit
  = "ml_gtk_snapshot_translate"
(** Translates @snapshot's coordinate system by @point in 2-dimensional space. *)

external transform_matrix :
  t -> Ocgtk_graphene.Graphene.Wrappers.Matrix.t -> unit
  = "ml_gtk_snapshot_transform_matrix"
(** Transforms @snapshot's coordinate system with the given @matrix. *)

external transform : t -> Ocgtk_gsk.Gsk.Wrappers.Transform.t option -> unit
  = "ml_gtk_snapshot_transform"
(** Transforms @snapshot's coordinate system with the given @transform. *)

external to_paintable :
  t ->
  Ocgtk_graphene.Graphene.Wrappers.Size.t option ->
  Ocgtk_gdk.Gdk.Wrappers.Paintable.t option = "ml_gtk_snapshot_to_paintable"
(** Returns a paintable encapsulating the render node
that was constructed by @snapshot.

After calling this function, it is no longer possible to
add more nodes to @snapshot. The only function that should
be called after this is [method@GObject.Object.unref]. *)

external to_node : t -> Ocgtk_gsk.Gsk.Wrappers.Render_node.t option
  = "ml_gtk_snapshot_to_node"
(** Returns the render node that was constructed
by @snapshot.

Note that this function may return %NULL if nothing has been
added to the snapshot or if its content does not produce pixels
to be rendered.

After calling this function, it is no longer possible to
add more nodes to @snapshot. The only function that should
be called after this is [method@GObject.Object.unref]. *)

external scale_3d : t -> float -> float -> float -> unit
  = "ml_gtk_snapshot_scale_3d"
(** Scales @snapshot's coordinate system by the given factors. *)

external scale : t -> float -> float -> unit = "ml_gtk_snapshot_scale"
(** Scales @snapshot's coordinate system in 2-dimensional space by
the given factors.

Use [method@Gtk.Snapshot.scale_3d] to scale in all 3 dimensions. *)

external save : t -> unit = "ml_gtk_snapshot_save"
(** Makes a copy of the current state of @snapshot and saves it
on an internal stack.

When [method@Gtk.Snapshot.restore] is called, @snapshot will
be restored to the saved state.

Multiple calls to [method@Gtk.Snapshot.save] and [method@Gtk.Snapshot.restore]
can be nested; each call to `gtk_snapshot_restore()` restores the state from
the matching paired `gtk_snapshot_save()`.

It is necessary to clear all saved states with corresponding
calls to `gtk_snapshot_restore()`. *)

external rotate_3d :
  t -> float -> Ocgtk_graphene.Graphene.Wrappers.Vec3.t -> unit
  = "ml_gtk_snapshot_rotate_3d"
(** Rotates @snapshot's coordinate system by @angle degrees around @axis.

For a rotation in 2D space, use [method@Gsk.Transform.rotate]. *)

external rotate : t -> float -> unit = "ml_gtk_snapshot_rotate"
(** Rotates @@snapshot's coordinate system by @angle degrees in 2D space -
or in 3D speak, rotates around the Z axis. The rotation happens around
the origin point of (0, 0) in the @snapshot's current coordinate system.

To rotate around axes other than the Z axis, use [method@Gsk.Transform.rotate_3d]. *)

external restore : t -> unit = "ml_gtk_snapshot_restore"
(** Restores @snapshot to the state saved by a preceding call to
[method@Snapshot.save] and removes that state from the stack of
saved states. *)

external render_layout :
  t ->
  Style_context.t ->
  float ->
  float ->
  Ocgtk_pango.Pango.Wrappers.Layout.t ->
  unit = "ml_gtk_snapshot_render_layout"
(** Creates a render node for rendering @layout according to the style
information in @context, and appends it to the current node of @snapshot,
without changing the current node. *)

external render_insertion_cursor :
  t ->
  Style_context.t ->
  float ->
  float ->
  Ocgtk_pango.Pango.Wrappers.Layout.t ->
  int ->
  Ocgtk_pango.Pango.direction ->
  unit
  = "ml_gtk_snapshot_render_insertion_cursor_bytecode"
    "ml_gtk_snapshot_render_insertion_cursor_native"
(** Draws a text caret using @snapshot at the specified index of @layout. *)

external render_frame :
  t -> Style_context.t -> float -> float -> float -> float -> unit
  = "ml_gtk_snapshot_render_frame_bytecode"
    "ml_gtk_snapshot_render_frame_native"
(** Creates a render node for the CSS border according to @context,
and appends it to the current node of @snapshot, without changing
the current node. *)

external render_focus :
  t -> Style_context.t -> float -> float -> float -> float -> unit
  = "ml_gtk_snapshot_render_focus_bytecode"
    "ml_gtk_snapshot_render_focus_native"
(** Creates a render node for the focus outline according to @context,
and appends it to the current node of @snapshot, without changing
the current node. *)

external render_background :
  t -> Style_context.t -> float -> float -> float -> float -> unit
  = "ml_gtk_snapshot_render_background_bytecode"
    "ml_gtk_snapshot_render_background_native"
(** Creates a render node for the CSS background according to @context,
and appends it to the current node of @snapshot, without changing
the current node. *)

external push_stroke :
  t -> Ocgtk_gsk.Gsk.Wrappers.Path.t -> Ocgtk_gsk.Gsk.Wrappers.Stroke.t -> unit
  = "ml_gtk_snapshot_push_stroke"
(** Strokes the given @path with the attributes given by @stroke and
an image.

The image is recorded until the next call to [method@Gtk.Snapshot.pop].

Note that the strokes are subject to the same transformation as
everything else, so uneven scaling will cause horizontal and vertical
strokes to have different widths.

If you want to stroke the path with a color, [method@Gtk.Snapshot.append_stroke]
may be more convenient. *)

external push_shadow :
  t -> Ocgtk_gsk.Gsk.Wrappers.Shadow.t array -> Gsize.t -> unit
  = "ml_gtk_snapshot_push_shadow"
(** Applies a shadow to an image.

    The image is recorded until the next call to [method@Gtk.Snapshot.pop]. *)

external push_rounded_clip : t -> Ocgtk_gsk.Gsk.Wrappers.Rounded_rect.t -> unit
  = "ml_gtk_snapshot_push_rounded_clip"
(** Clips an image to a rounded rectangle.

    The image is recorded until the next call to [method@Gtk.Snapshot.pop]. *)

external push_repeat :
  t ->
  Ocgtk_graphene.Graphene.Wrappers.Rect.t ->
  Ocgtk_graphene.Graphene.Wrappers.Rect.t option ->
  unit = "ml_gtk_snapshot_push_repeat"
(** Creates a node that repeats the child node.

    The child is recorded until the next call to [method@Gtk.Snapshot.pop]. *)

external push_opacity : t -> float -> unit = "ml_gtk_snapshot_push_opacity"
(** Modifies the opacity of an image.

    The image is recorded until the next call to [method@Gtk.Snapshot.pop]. *)

external push_mask : t -> Ocgtk_gsk.Gsk.maskmode -> unit
  = "ml_gtk_snapshot_push_mask"
(** Until the first call to [method@Gtk.Snapshot.pop], the mask image for the
    mask operation will be recorded.

    After that call, the source image will be recorded until the second call to
    [method@Gtk.Snapshot.pop].

    Calling this function requires 2 subsequent calls to gtk_snapshot_pop(). *)

external push_gl_shader :
  t ->
  Ocgtk_gsk.Gsk.Wrappers.Gl_shader.t ->
  Ocgtk_graphene.Graphene.Wrappers.Rect.t ->
  Glib_bytes.t ->
  unit = "ml_gtk_snapshot_push_gl_shader"
(** Push a [class@Gsk.GLShaderNode].

The node uses the given [class@Gsk.GLShader] and uniform values
Additionally this takes a list of @n_children other nodes
which will be passed to the [class@Gsk.GLShaderNode].

The @take_args argument is a block of data to use for uniform
arguments, as per types and offsets defined by the @shader.
Normally this is generated by [method@Gsk.GLShader.format_args]
or [struct@Gsk.ShaderArgsBuilder].

The snapshotter takes ownership of @take_args, so the caller should
not free it after this.

If the renderer doesn't support GL shaders, or if there is any
problem when compiling the shader, then the node will draw pink.
You should use [method@Gsk.GLShader.compile] to ensure the @shader
will work for the renderer before using it.

If the shader requires textures (see [method@Gsk.GLShader.get_n_textures]),
then it is expected that you call [method@Gtk.Snapshot.gl_shader_pop_texture]
the number of times that are required. Each of these calls will generate
a node that is added as a child to the `GskGLShaderNode`, which in turn
will render these offscreen and pass as a texture to the shader.

Once all textures (if any) are pop:ed, you must call the regular
[method@Gtk.Snapshot.pop].

If you want to use pre-existing textures as input to the shader rather
than rendering new ones, use [method@Gtk.Snapshot.append_texture] to
push a texture node. These will be used directly rather than being
re-rendered.

For details on how to write shaders, see [class@Gsk.GLShader]. *)

external push_fill :
  t -> Ocgtk_gsk.Gsk.Wrappers.Path.t -> Ocgtk_gsk.Gsk.fillrule -> unit
  = "ml_gtk_snapshot_push_fill"
(** Fills the area given by @path and @fill_rule with an image and discards everything
outside of it.

The image is recorded until the next call to [method@Gtk.Snapshot.pop].

If you want to fill the path with a color, [method@Gtk.Snapshot.append_fill]
than rendering new ones, use [method@Gtk.Snapshot.append_fill]
may be more convenient. *)

external push_cross_fade : t -> float -> unit
  = "ml_gtk_snapshot_push_cross_fade"
(** Snapshots a cross-fade operation between two images with the
given @progress.

Until the first call to [method@Gtk.Snapshot.pop], the start image
will be snapshot. After that call, the end image will be recorded
until the second call to [method@Gtk.Snapshot.pop].

Calling this function requires two subsequent calls
to [method@Gtk.Snapshot.pop]. *)

external push_component_transfer :
  t ->
  Ocgtk_gsk.Gsk.Wrappers.Component_transfer.t ->
  Ocgtk_gsk.Gsk.Wrappers.Component_transfer.t ->
  Ocgtk_gsk.Gsk.Wrappers.Component_transfer.t ->
  Ocgtk_gsk.Gsk.Wrappers.Component_transfer.t ->
  unit = "ml_gtk_snapshot_push_component_transfer"
(** Modifies the colors of an image by applying a transfer function for each
    component.

    The transfer functions operate on unpremultiplied colors.

    The image is recorded until the next call to [method@Gtk.Snapshot.pop]. *)

external push_color_matrix :
  t ->
  Ocgtk_graphene.Graphene.Wrappers.Matrix.t ->
  Ocgtk_graphene.Graphene.Wrappers.Vec4.t ->
  unit = "ml_gtk_snapshot_push_color_matrix"
(** Modifies the colors of an image by applying an affine transformation in RGB
    space.

    In particular, the colors will be transformed by applying

    pixel = transpose(color_matrix) * pixel + color_offset

    for every pixel. The transformation operates on unpremultiplied colors, with
    color components ordered R, G, B, A.

    The image is recorded until the next call to [method@Gtk.Snapshot.pop]. *)

external push_clip : t -> Ocgtk_graphene.Graphene.Wrappers.Rect.t -> unit
  = "ml_gtk_snapshot_push_clip"
(** Clips an image to a rectangle.

    The image is recorded until the next call to [method@Gtk.Snapshot.pop]. *)

external push_blur : t -> float -> unit = "ml_gtk_snapshot_push_blur"
(** Blurs an image.

    The image is recorded until the next call to [method@Gtk.Snapshot.pop]. *)

external push_blend : t -> Ocgtk_gsk.Gsk.blendmode -> unit
  = "ml_gtk_snapshot_push_blend"
(** Blends together two images with the given blend mode.

    Until the first call to [method@Gtk.Snapshot.pop], the bottom image for the
    blend operation will be recorded. After that call, the top image to be
    blended will be recorded until the second call to [method@Gtk.Snapshot.pop].

    Calling this function requires two subsequent calls to
    [method@Gtk.Snapshot.pop]. *)

external pop : t -> unit = "ml_gtk_snapshot_pop"
(** Removes the top element from the stack of render nodes, and appends it to
    the node underneath it. *)

external perspective : t -> float -> unit = "ml_gtk_snapshot_perspective"
(** Applies a perspective projection transform.

    See [method@Gsk.Transform.perspective] for a discussion on the details. *)

external gl_shader_pop_texture : t -> unit
  = "ml_gtk_snapshot_gl_shader_pop_texture"
(** Removes the top element from the stack of render nodes and adds it to the
    nearest [class@Gsk.GLShaderNode] below it.

    This must be called the same number of times as the number of textures is
    needed for the shader in [method@Gtk.Snapshot.push_gl_shader]. *)

external append_texture :
  t ->
  Ocgtk_gdk.Gdk.Wrappers.Texture.t ->
  Ocgtk_graphene.Graphene.Wrappers.Rect.t ->
  unit = "ml_gtk_snapshot_append_texture"
(** Creates a new render node drawing the @texture
into the given @bounds and appends it to the
current render node of @snapshot.

If the texture needs to be scaled to fill @bounds,
linear filtering is used. See [method@Gtk.Snapshot.append_scaled_texture]
if you need other filtering, such as nearest-neighbour. *)

external append_stroke :
  t ->
  Ocgtk_gsk.Gsk.Wrappers.Path.t ->
  Ocgtk_gsk.Gsk.Wrappers.Stroke.t ->
  Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t ->
  unit = "ml_gtk_snapshot_append_stroke"
(** A convenience method to stroke a path with a color.

    See [method@Gtk.Snapshot.push_stroke] if you need to stroke a path with more
    complex content than a color. *)

external append_scaled_texture :
  t ->
  Ocgtk_gdk.Gdk.Wrappers.Texture.t ->
  Ocgtk_gsk.Gsk.scalingfilter ->
  Ocgtk_graphene.Graphene.Wrappers.Rect.t ->
  unit = "ml_gtk_snapshot_append_scaled_texture"
(** Creates a new render node drawing the @texture
into the given @bounds and appends it to the
current render node of @snapshot.

In contrast to [method@Gtk.Snapshot.append_texture],
this function provides control about how the filter
that is used when scaling. *)

external append_repeating_radial_gradient :
  t ->
  Ocgtk_graphene.Graphene.Wrappers.Rect.t ->
  Ocgtk_graphene.Graphene.Wrappers.Point.t ->
  float ->
  float ->
  float ->
  float ->
  Ocgtk_gsk.Gsk.Wrappers.Color_stop.t array ->
  Gsize.t ->
  unit
  = "ml_gtk_snapshot_append_repeating_radial_gradient_bytecode"
    "ml_gtk_snapshot_append_repeating_radial_gradient_native"
(** Appends a repeating radial gradient node with the given stops to @snapshot. *)

external append_repeating_linear_gradient :
  t ->
  Ocgtk_graphene.Graphene.Wrappers.Rect.t ->
  Ocgtk_graphene.Graphene.Wrappers.Point.t ->
  Ocgtk_graphene.Graphene.Wrappers.Point.t ->
  Ocgtk_gsk.Gsk.Wrappers.Color_stop.t array ->
  Gsize.t ->
  unit
  = "ml_gtk_snapshot_append_repeating_linear_gradient_bytecode"
    "ml_gtk_snapshot_append_repeating_linear_gradient_native"
(** Appends a repeating linear gradient node with the given stops to @snapshot. *)

external append_radial_gradient :
  t ->
  Ocgtk_graphene.Graphene.Wrappers.Rect.t ->
  Ocgtk_graphene.Graphene.Wrappers.Point.t ->
  float ->
  float ->
  float ->
  float ->
  Ocgtk_gsk.Gsk.Wrappers.Color_stop.t array ->
  Gsize.t ->
  unit
  = "ml_gtk_snapshot_append_radial_gradient_bytecode"
    "ml_gtk_snapshot_append_radial_gradient_native"
(** Appends a radial gradient node with the given stops to @snapshot. *)

external append_outset_shadow :
  t ->
  Ocgtk_gsk.Gsk.Wrappers.Rounded_rect.t ->
  Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t ->
  float ->
  float ->
  float ->
  float ->
  unit
  = "ml_gtk_snapshot_append_outset_shadow_bytecode"
    "ml_gtk_snapshot_append_outset_shadow_native"
(** Appends an outset shadow node around the box given by @outline. *)

external append_node : t -> Ocgtk_gsk.Gsk.Wrappers.Render_node.t -> unit
  = "ml_gtk_snapshot_append_node"
(** Appends @node to the current render node of @snapshot,
without changing the current node.

If @snapshot does not have a current node yet, @node
will become the initial node. *)

external append_linear_gradient :
  t ->
  Ocgtk_graphene.Graphene.Wrappers.Rect.t ->
  Ocgtk_graphene.Graphene.Wrappers.Point.t ->
  Ocgtk_graphene.Graphene.Wrappers.Point.t ->
  Ocgtk_gsk.Gsk.Wrappers.Color_stop.t array ->
  Gsize.t ->
  unit
  = "ml_gtk_snapshot_append_linear_gradient_bytecode"
    "ml_gtk_snapshot_append_linear_gradient_native"
(** Appends a linear gradient node with the given stops to @snapshot. *)

external append_layout :
  t ->
  Ocgtk_pango.Pango.Wrappers.Layout.t ->
  Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t ->
  unit = "ml_gtk_snapshot_append_layout"
(** Creates render nodes for rendering @layout in the given foregound @color
and appends them to the current node of @snapshot without changing the
current node. The current theme's foreground color for a widget can be
obtained with [method@Gtk.Widget.get_color].

Note that if the layout does not produce any visible output, then nodes
may not be added to the @snapshot. *)

external append_inset_shadow :
  t ->
  Ocgtk_gsk.Gsk.Wrappers.Rounded_rect.t ->
  Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t ->
  float ->
  float ->
  float ->
  float ->
  unit
  = "ml_gtk_snapshot_append_inset_shadow_bytecode"
    "ml_gtk_snapshot_append_inset_shadow_native"
(** Appends an inset shadow into the box given by @outline. *)

external append_fill :
  t ->
  Ocgtk_gsk.Gsk.Wrappers.Path.t ->
  Ocgtk_gsk.Gsk.fillrule ->
  Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t ->
  unit = "ml_gtk_snapshot_append_fill"
(** A convenience method to fill a path with a color.

    See [method@Gtk.Snapshot.push_fill] if you need to fill a path with more
    complex content than a color. *)

external append_conic_gradient :
  t ->
  Ocgtk_graphene.Graphene.Wrappers.Rect.t ->
  Ocgtk_graphene.Graphene.Wrappers.Point.t ->
  float ->
  Ocgtk_gsk.Gsk.Wrappers.Color_stop.t array ->
  Gsize.t ->
  unit
  = "ml_gtk_snapshot_append_conic_gradient_bytecode"
    "ml_gtk_snapshot_append_conic_gradient_native"
(** Appends a conic gradient node with the given stops to @snapshot. *)

external append_color :
  t ->
  Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t ->
  Ocgtk_graphene.Graphene.Wrappers.Rect.t ->
  unit = "ml_gtk_snapshot_append_color"
(** Creates a new render node drawing the @color into the
given @bounds and appends it to the current render node
of @snapshot.

You should try to avoid calling this function if
@color is transparent. *)

external append_cairo :
  t ->
  Ocgtk_graphene.Graphene.Wrappers.Rect.t ->
  Ocgtk_cairo.Cairo.Wrappers.Context.t = "ml_gtk_snapshot_append_cairo"
(** Creates a new [class@Gsk.CairoNode] and appends it to the current
render node of @snapshot, without changing the current node. *)

external append_border :
  t ->
  Ocgtk_gsk.Gsk.Wrappers.Rounded_rect.t ->
  float array ->
  Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t array ->
  unit = "ml_gtk_snapshot_append_border"
(** Appends a stroked border rectangle inside the given @outline.

The four sides of the border can have different widths and colors. *)
