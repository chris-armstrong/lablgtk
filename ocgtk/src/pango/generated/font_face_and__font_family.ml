(* GENERATED CODE - DO NOT EDIT *)
(* Combined modules for cyclic dependencies *)

module rec Font_face : sig
  type t = [ `font_face | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_pango_font_face_get_type"

  (* Methods *)

  external list_sizes : t -> int array option * int
    = "ml_pango_font_face_list_sizes"
  (** List the available sizes for a font.

  This is only applicable to bitmap fonts. For scalable fonts, stores
  %NULL at the location pointed to by @sizes and 0 at the location pointed
  to by @n_sizes. The sizes returned are in Pango units and are sorted
  in ascending order. *)

  external is_synthesized : t -> bool = "ml_pango_font_face_is_synthesized"
  (** Returns whether a `PangoFontFace` is synthesized.

      This will be the case if the underlying font rendering engine creates this
      face from another face, by shearing, emboldening, lightening or modifying
      it in some other way. *)

  external get_family : t -> Font_family.t = "ml_pango_font_face_get_family"
  (** Gets the `PangoFontFamily` that @face belongs to. *)

  external get_face_name : t -> string = "ml_pango_font_face_get_face_name"
  (** Gets a name representing the style of this face.

      Note that a font family may contain multiple faces with the same name
      (e.g. a variable and a non-variable face for the same style). *)

  external describe : t -> Font_description.t = "ml_pango_font_face_describe"
  (** Returns a font description that matches the face.

      The resulting font description will have the family, style, variant,
      weight and stretch of the face, but its size field will be unset. *)
end = struct
  type t = [ `font_face | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_pango_font_face_get_type"

  (* Methods *)

  external list_sizes : t -> int array option * int
    = "ml_pango_font_face_list_sizes"
  (** List the available sizes for a font.

  This is only applicable to bitmap fonts. For scalable fonts, stores
  %NULL at the location pointed to by @sizes and 0 at the location pointed
  to by @n_sizes. The sizes returned are in Pango units and are sorted
  in ascending order. *)

  external is_synthesized : t -> bool = "ml_pango_font_face_is_synthesized"
  (** Returns whether a `PangoFontFace` is synthesized.

      This will be the case if the underlying font rendering engine creates this
      face from another face, by shearing, emboldening, lightening or modifying
      it in some other way. *)

  external get_family : t -> Font_family.t = "ml_pango_font_face_get_family"
  (** Gets the `PangoFontFamily` that @face belongs to. *)

  external get_face_name : t -> string = "ml_pango_font_face_get_face_name"
  (** Gets a name representing the style of this face.

      Note that a font family may contain multiple faces with the same name
      (e.g. a variable and a non-variable face for the same style). *)

  external describe : t -> Font_description.t = "ml_pango_font_face_describe"
  (** Returns a font description that matches the face.

      The resulting font description will have the family, style, variant,
      weight and stretch of the face, but its size field will be unset. *)
end

and Font_family : sig
  type t = [ `font_family | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_pango_font_family_get_type"

  (* Methods *)

  external list_faces : t -> Font_face.t array * int
    = "ml_pango_font_family_list_faces"
  (** Lists the different font faces that make up @family.

  The faces in a family share a common design, but differ in slant, weight,
  width and other aspects.

  Note that the returned faces are not in any particular order, and
  multiple faces may have the same name or characteristics.

  `PangoFontFamily` also implemented the [iface@Gio.ListModel] interface
  for enumerating faces. *)

  external is_variable : t -> bool = "ml_pango_font_family_is_variable"
  (** A variable font is a font which has axes that can be modified to produce
      different faces.

      Such axes are also known as _variations_; see
      [method@Pango.FontDescription.set_variations] for more information. *)

  external is_monospace : t -> bool = "ml_pango_font_family_is_monospace"
  (** A monospace font is a font designed for text display where the the
      characters form a regular grid.

      For Western languages this would mean that the advance width of all
      characters are the same, but this categorization also includes Asian fonts
      which include double-width characters: characters that occupy two grid
      cells. g_unichar_iswide() returns a result that indicates whether a
      character is typically double-width in a monospace font.

      The best way to find out the grid-cell size is to call
      [method@Pango.FontMetrics.get_approximate_digit_width], since the results
      of [method@Pango.FontMetrics.get_approximate_char_width] may be affected
      by double-width characters. *)

  external get_name : t -> string = "ml_pango_font_family_get_name"
  (** Gets the name of the family.

      The name is unique among all fonts for the font backend and can be used in
      a `PangoFontDescription` to specify that a face from this family is
      desired. *)

  external get_face : t -> string option -> Font_face.t option
    = "ml_pango_font_family_get_face"
  (** Gets the `PangoFontFace` of @family with the given name. *)

  (* Properties *)

  external get_item_type : t -> Gobject.Type.t
    = "ml_pango_font_family_get_item_type"
  (** Get property: item-type *)

  external get_n_items : t -> int = "ml_pango_font_family_get_n_items"
  (** Get property: n-items *)
end = struct
  type t = [ `font_family | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_pango_font_family_get_type"

  (* Methods *)

  external list_faces : t -> Font_face.t array * int
    = "ml_pango_font_family_list_faces"
  (** Lists the different font faces that make up @family.

  The faces in a family share a common design, but differ in slant, weight,
  width and other aspects.

  Note that the returned faces are not in any particular order, and
  multiple faces may have the same name or characteristics.

  `PangoFontFamily` also implemented the [iface@Gio.ListModel] interface
  for enumerating faces. *)

  external is_variable : t -> bool = "ml_pango_font_family_is_variable"
  (** A variable font is a font which has axes that can be modified to produce
      different faces.

      Such axes are also known as _variations_; see
      [method@Pango.FontDescription.set_variations] for more information. *)

  external is_monospace : t -> bool = "ml_pango_font_family_is_monospace"
  (** A monospace font is a font designed for text display where the the
      characters form a regular grid.

      For Western languages this would mean that the advance width of all
      characters are the same, but this categorization also includes Asian fonts
      which include double-width characters: characters that occupy two grid
      cells. g_unichar_iswide() returns a result that indicates whether a
      character is typically double-width in a monospace font.

      The best way to find out the grid-cell size is to call
      [method@Pango.FontMetrics.get_approximate_digit_width], since the results
      of [method@Pango.FontMetrics.get_approximate_char_width] may be affected
      by double-width characters. *)

  external get_name : t -> string = "ml_pango_font_family_get_name"
  (** Gets the name of the family.

      The name is unique among all fonts for the font backend and can be used in
      a `PangoFontDescription` to specify that a face from this family is
      desired. *)

  external get_face : t -> string option -> Font_face.t option
    = "ml_pango_font_family_get_face"
  (** Gets the `PangoFontFace` of @family with the given name. *)

  (* Properties *)

  external get_item_type : t -> Gobject.Type.t
    = "ml_pango_font_family_get_item_type"
  (** Get property: item-type *)

  external get_n_items : t -> int = "ml_pango_font_family_get_n_items"
  (** Get property: n-items *)
end
