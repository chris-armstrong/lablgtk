(* GENERATED CODE - DO NOT EDIT *)
(* Combined modules for cyclic dependencies *)

module rec Context : sig
  type t = [ `context | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_pango_context_get_type"

  external new_ : unit -> t = "ml_pango_context_new"
  (** Create a new Context *)

  (* Methods *)

  external set_round_glyph_positions : t -> bool -> unit
    = "ml_pango_context_set_round_glyph_positions"
  (** Sets whether font rendering with this context should round glyph positions
      and widths to integral positions, in device units.

      This is useful when the renderer can't handle subpixel positioning of
      glyphs.

      The default value is to round glyph positions, to remain compatible with
      previous Pango behavior. *)

  external set_matrix : t -> Matrix.t option -> unit
    = "ml_pango_context_set_matrix"
  (** Sets the transformation matrix that will be applied when rendering with
      this context.

      Note that reported metrics are in the user space coordinates before the
      application of the matrix, not device-space coordinates after the
      application of the matrix. So, they don't scale with the matrix, though
      they may change slightly for different matrices, depending on how the text
      is fit to the pixel grid. *)

  external set_language : t -> Language.t option -> unit
    = "ml_pango_context_set_language"
  (** Sets the global language tag for the context.

      The default language for the locale of the running process can be found
      using [func@Pango.Language.get_default]. *)

  external set_gravity_hint : t -> Pango_enums.gravityhint -> unit
    = "ml_pango_context_set_gravity_hint"
  (** Sets the gravity hint for the context.

      The gravity hint is used in laying vertical text out, and is only relevant
      if gravity of the context as returned by
      [method@Pango.Context.get_gravity] is set to %PANGO_GRAVITY_EAST or
      %PANGO_GRAVITY_WEST. *)

  external set_font_map : t -> Font_map.t option -> unit
    = "ml_pango_context_set_font_map"
  (** Sets the font map to be searched when fonts are looked-up in this context.

      This is only for internal use by Pango backends, a `PangoContext` obtained
      via one of the recommended methods should already have a suitable font
      map. *)

  external set_font_description : t -> Font_description.t -> unit
    = "ml_pango_context_set_font_description"
  (** Set the default font description for the context *)

  external set_base_gravity : t -> Pango_enums.gravity -> unit
    = "ml_pango_context_set_base_gravity"
  (** Sets the base gravity for the context.

      The base gravity is used in laying vertical text out. *)

  external set_base_dir : t -> Pango_enums.direction -> unit
    = "ml_pango_context_set_base_dir"
  (** Sets the base direction for the context.

  The base direction is used in applying the Unicode bidirectional
  algorithm; if the @direction is %PANGO_DIRECTION_LTR or
  %PANGO_DIRECTION_RTL, then the value will be used as the paragraph
  direction in the Unicode bidirectional algorithm. A value of
  %PANGO_DIRECTION_WEAK_LTR or %PANGO_DIRECTION_WEAK_RTL is used only
  for paragraphs that do not contain any strong characters themselves. *)

  external load_fontset :
    t -> Font_description.t -> Language.t -> Fontset.t option
    = "ml_pango_context_load_fontset"
  (** Load a set of fonts in the context that can be used to render
  a font matching @desc. *)

  external load_font : t -> Font_description.t -> Font.t option
    = "ml_pango_context_load_font"
  (** Loads the font in one of the fontmaps in the context
  that is the closest match for @desc. *)

  external list_families :
    t -> Font_face_and__font_family.Font_family.t array * int
    = "ml_pango_context_list_families"
  (** List all families for a context. *)

  external get_serial : t -> int = "ml_pango_context_get_serial"
  (** Returns the current serial number of @context.

  The serial number is initialized to an small number larger than zero
  when a new context is created and is increased whenever the context
  is changed using any of the setter functions, or the `PangoFontMap` it
  uses to find fonts has changed. The serial may wrap, but will never
  have the value 0. Since it can wrap, never compare it with "less than",
  always use "not equals".

  This can be used to automatically detect changes to a `PangoContext`,
  and is only useful when implementing objects that need update when their
  `PangoContext` changes, like `PangoLayout`. *)

  external get_round_glyph_positions : t -> bool
    = "ml_pango_context_get_round_glyph_positions"
  (** Returns whether font rendering with this context should round glyph
      positions and widths. *)

  external get_metrics :
    t -> Font_description.t option -> Language.t option -> Font_metrics.t
    = "ml_pango_context_get_metrics"
  (** Get overall metric information for a particular font description.

      Since the metrics may be substantially different for different scripts, a
      language tag can be provided to indicate that the metrics should be
      retrieved that correspond to the script(s) used by that language.

      The `PangoFontDescription` is interpreted in the same way as by
      [func@itemize], and the family name may be a comma separated list of
      names. If characters from multiple of these families would be used to
      render the string, then the returned fonts would be a composite of the
      metrics for the fonts loaded for the individual families. *)

  external get_matrix : t -> Matrix.t option = "ml_pango_context_get_matrix"
  (** Gets the transformation matrix that will be applied when rendering with
      this context.

      See [method@Pango.Context.set_matrix]. *)

  external get_language : t -> Language.t = "ml_pango_context_get_language"
  (** Retrieves the global language tag for the context. *)

  external get_gravity_hint : t -> Pango_enums.gravityhint
    = "ml_pango_context_get_gravity_hint"
  (** Retrieves the gravity hint for the context.

      See [method@Pango.Context.set_gravity_hint] for details. *)

  external get_gravity : t -> Pango_enums.gravity
    = "ml_pango_context_get_gravity"
  (** Retrieves the gravity for the context.

      This is similar to [method@Pango.Context.get_base_gravity], except for
      when the base gravity is %PANGO_GRAVITY_AUTO for which
      [func@Pango.Gravity.get_for_matrix] is used to return the gravity from the
      current context matrix. *)

  external get_font_map : t -> Font_map.t option
    = "ml_pango_context_get_font_map"
  (** Gets the `PangoFontMap` used to look up fonts for this context. *)

  external get_font_description : t -> Font_description.t option
    = "ml_pango_context_get_font_description"
  (** Retrieve the default font description for the context. *)

  external get_base_gravity : t -> Pango_enums.gravity
    = "ml_pango_context_get_base_gravity"
  (** Retrieves the base gravity for the context.

      See [method@Pango.Context.set_base_gravity]. *)

  external get_base_dir : t -> Pango_enums.direction
    = "ml_pango_context_get_base_dir"
  (** Retrieves the base direction for the context.

      See [method@Pango.Context.set_base_dir]. *)

  external changed : t -> unit = "ml_pango_context_changed"
  (** Forces a change in the context, which will cause any `PangoLayout` using
      this context to re-layout.

      This function is only useful when implementing a new backend for Pango,
      something applications won't do. Backends should call this function if
      they have attached extra data to the context and such data is changed. *)
end

and Font : sig
  type t = [ `font | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_pango_font_get_type"

  (* Methods *)

  external serialize : t -> Glib_bytes.t = "ml_pango_font_serialize"
  (** Serializes the @font in a way that can be uniquely identified.

  There are no guarantees about the format of the output across different
  versions of Pango.

  The intended use of this function is testing, benchmarking and debugging.
  The format is not meant as a permanent storage format.

  To recreate a font from its serialized form, use [func@Pango.Font.deserialize]. *)

  external has_char : t -> int -> bool = "ml_pango_font_has_char"
  (** Returns whether the font provides a glyph for this character. *)

  external get_metrics : t -> Language.t option -> Font_metrics.t
    = "ml_pango_font_get_metrics"
  (** Gets overall metric information for a font.

  Since the metrics may be substantially different for different scripts,
  a language tag can be provided to indicate that the metrics should be
  retrieved that correspond to the script(s) used by that language.

  If @font is %NULL, this function gracefully sets some sane values in the
  output variables and returns. *)

  external get_glyph_extents : t -> int -> Rectangle.t * Rectangle.t
    = "ml_pango_font_get_glyph_extents"
  (** Gets the logical and ink extents of a glyph within a font.

  The coordinate system for each rectangle has its origin at the
  base line and horizontal origin of the character with increasing
  coordinates extending to the right and down. The macros PANGO_ASCENT(),
  PANGO_DESCENT(), PANGO_LBEARING(), and PANGO_RBEARING() can be used to convert
  from the extents rectangle to more traditional font metrics. The units
  of the rectangles are in 1/PANGO_SCALE of a device unit.

  If @font is %NULL, this function gracefully sets some sane values in the
  output variables and returns. *)

  external get_font_map : t -> Font_map.t option = "ml_pango_font_get_font_map"
  (** Gets the font map for which the font was created.

      Note that the font maintains a *weak* reference to the font map, so if all
      references to font map are dropped, the font map will be finalized even if
      there are fonts created with the font map that are still alive. In that
      case this function will return %NULL.

      It is the responsibility of the user to ensure that the font map is kept
      alive. In most uses this is not an issue as a `PangoContext` holds a
      reference to the font map. *)

  external get_face : t -> Font_face_and__font_family.Font_face.t option
    = "ml_pango_font_get_face"
  (** Gets the `PangoFontFace` to which @font belongs.

  Note that this function can return `NULL` in cases
  where the font outlives its font map. *)

  external get_coverage : t -> Language.t -> Coverage.t
    = "ml_pango_font_get_coverage"
  (** Computes the coverage map for a given font and language tag. *)

  external describe_with_absolute_size : t -> Font_description.t
    = "ml_pango_font_describe_with_absolute_size"
  (** Returns a description of the font, with absolute font size set in device
      units.

      Use [method@Pango.Font.describe] if you want the font size in points. *)

  external describe : t -> Font_description.t = "ml_pango_font_describe"
  (** Returns a description of the font, with font size set in points.

      Use [method@Pango.Font.describe_with_absolute_size] if you want the font
      size in device units. *)
end

and Font_map : sig
  type t = [ `font_map | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_pango_font_map_get_type"

  (* Methods *)

  external reload_font :
    t -> Font.t -> float -> Context.t option -> string option -> Font.t
    = "ml_pango_font_map_reload_font"
  (** Returns a new font that is like @font, except that it is scaled
  by @scale, its backend-dependent configuration (e.g. cairo font options)
  is replaced by the one in @context, and its variations are replaced
  by @variations.

  Note that the scaling here is meant to be linear, so this
  scaling can be used to render a font on a hi-dpi display
  without changing its optical size. *)

  external load_fontset :
    t -> Context.t -> Font_description.t -> Language.t -> Fontset.t option
    = "ml_pango_font_map_load_fontset"
  (** Load a set of fonts in the fontmap that can be used to render
  a font matching @desc. *)

  external load_font : t -> Context.t -> Font_description.t -> Font.t option
    = "ml_pango_font_map_load_font"
  (** Load the font in the fontmap that is the closest match for @desc. *)

  external list_families :
    t -> Font_face_and__font_family.Font_family.t array * int
    = "ml_pango_font_map_list_families"
  (** List all families for a fontmap.

      Note that the returned families are not in any particular order.

      `PangoFontMap` also implemented the [iface@Gio.ListModel] interface for
      enumerating families. *)

  external get_serial : t -> int = "ml_pango_font_map_get_serial"
  (** Returns the current serial number of @fontmap.

  The serial number is initialized to an small number larger than zero
  when a new fontmap is created and is increased whenever the fontmap
  is changed. It may wrap, but will never have the value 0. Since it can
  wrap, never compare it with "less than", always use "not equals".

  The fontmap can only be changed using backend-specific API, like changing
  fontmap resolution.

  This can be used to automatically detect changes to a `PangoFontMap`,
  like in `PangoContext`. *)

  external get_family :
    t -> string -> Font_face_and__font_family.Font_family.t option
    = "ml_pango_font_map_get_family"
  (** Gets a font family by name. *)

  external create_context : t -> Context.t = "ml_pango_font_map_create_context"
  (** Creates a `PangoContext` connected to @fontmap.

  This is equivalent to [ctor@Pango.Context.new] followed by
  [method@Pango.Context.set_font_map].

  If you are using Pango as part of a higher-level system,
  that system may have it's own way of create a `PangoContext`.
  For instance, the GTK toolkit has, among others,
  gtk_widget_get_pango_context(). Use those instead. *)

  external changed : t -> unit = "ml_pango_font_map_changed"
  (** Forces a change in the fontmap, which will cause any `PangoContext` using
      this fontmap to change.

      This function is only useful when implementing a new backend for Pango,
      something applications won't do. Backends should call this function if
      they have attached extra data to the fontmap and such data is changed. *)

  external add_font_file : t -> string -> (bool, GError.t) result
    = "ml_pango_font_map_add_font_file"
  (** Loads a font file with one or more fonts into the `PangoFontMap`.

      The added fonts will take precedence over preexisting fonts with the same
      name. *)

  (* Properties *)

  external get_item_type : t -> Gobject.Type.t
    = "ml_pango_font_map_get_item_type"
  (** Get property: item-type *)

  external get_n_items : t -> int = "ml_pango_font_map_get_n_items"
  (** Get property: n-items *)
end

and Fontset : sig
  type t = [ `fontset | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_pango_fontset_get_type"

  (* Methods *)

  external get_metrics : t -> Font_metrics.t = "ml_pango_fontset_get_metrics"
  (** Get overall metric information for the fonts in the fontset. *)

  external get_font : t -> int -> Font.t = "ml_pango_fontset_get_font"
  (** Returns the font in the fontset that contains the best glyph for a Unicode
      character. *)
end
