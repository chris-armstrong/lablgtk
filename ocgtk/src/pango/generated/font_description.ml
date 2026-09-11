(* GENERATED CODE - DO NOT EDIT *)
(* FontDescription: FontDescription *)

type t = [ `font_description ] Gobject.obj
(** A `PangoFontDescription` describes a font in an implementation-independent
    manner.

    `PangoFontDescription` structures are used both to list what fonts are
    available on the system and also for specifying the characteristics of a
    font to load. *)

external gtype : unit -> Gobject.Type.t = "ml_pango_font_description_get_type"

external new_ : unit -> t = "ml_pango_font_description_new"
(** Create a new FontDescription *)

(* Methods *)

external unset_fields : t -> Pango_enums.fontmask -> unit
  = "ml_pango_font_description_unset_fields"
(** Unsets some of the fields in a `PangoFontDescription`.

    The unset fields will get back to their default values. *)

external to_string : t -> string = "ml_pango_font_description_to_string"
(** Creates a string representation of a font description.

    See [func@Pango.FontDescription.from_string] for a description of the format
    of the string representation. The family list in the string description will
    only have a terminating comma if the last word of the list is a valid style
    option. *)

external to_filename : t -> string option
  = "ml_pango_font_description_to_filename"
(** Creates a filename representation of a font description.

    The filename is identical to the result from calling
    [method@Pango.FontDescription.to_string], but with underscores instead of
    characters that are untypical in filenames, and in lower case only. *)

external set_weight : t -> Pango_enums.weight -> unit
  = "ml_pango_font_description_set_weight"
(** Sets the weight field of a font description.

    The weight field specifies how bold or light the font should be. In addition
    to the values of the [enum@Pango.Weight] enumeration, other intermediate
    numeric values are possible. *)

external set_variations_static : t -> string -> unit
  = "ml_pango_font_description_set_variations_static"
(** Sets the variations field of a font description.

This is like [method@Pango.FontDescription.set_variations], except
that no copy of @variations is made. The caller must make sure that
the string passed in stays around until @desc has been freed
or the name is set again. This function can be used if
@variations is a static string such as a C string literal,
or if @desc is only needed temporarily. *)

external set_variations : t -> string option -> unit
  = "ml_pango_font_description_set_variations"
(** Sets the variations field of a font description.

    OpenType font variations allow to select a font instance by specifying
    values for a number of axes, such as width or weight.

    The format of the variations string is

    AXIS1=VALUE,AXIS2=VALUE...

    with each AXIS a 4 character tag that identifies a font axis, and each VALUE
    a floating point number. Unknown axes are ignored, and values are clamped to
    their allowed range.

    Pango does not currently have a way to find supported axes of a font. Both
    harfbuzz and freetype have API for this. See for example
    [hb_ot_var_get_axis_infos](https://harfbuzz.github.io/harfbuzz-hb-ot-var.html#hb-ot-var-get-axis-infos).
*)

external set_variant : t -> Pango_enums.variant -> unit
  = "ml_pango_font_description_set_variant"
(** Sets the variant field of a font description.

    The [enum@Pango.Variant] can either be %PANGO_VARIANT_NORMAL or
    %PANGO_VARIANT_SMALL_CAPS. *)

external set_style : t -> Pango_enums.style -> unit
  = "ml_pango_font_description_set_style"
(** Sets the style field of a `PangoFontDescription`.

    The [enum@Pango.Style] enumeration describes whether the font is slanted and
    the manner in which it is slanted; it can be either %PANGO_STYLE_NORMAL,
    %PANGO_STYLE_ITALIC, or %PANGO_STYLE_OBLIQUE.

    Most fonts will either have a italic style or an oblique style, but not
    both, and font matching in Pango will match italic specifications with
    oblique fonts and vice-versa if an exact match is not found. *)

external set_stretch : t -> Pango_enums.stretch -> unit
  = "ml_pango_font_description_set_stretch"
(** Sets the stretch field of a font description.

    The [enum@Pango.Stretch] field specifies how narrow or wide the font should
    be. *)

external set_size : t -> int -> unit = "ml_pango_font_description_set_size"
(** Sets the size field of a font description in fractional points.

    This is mutually exclusive with
    [method@Pango.FontDescription.set_absolute_size]. *)

external set_gravity : t -> Pango_enums.gravity -> unit
  = "ml_pango_font_description_set_gravity"
(** Sets the gravity field of a font description.

The gravity field
specifies how the glyphs should be rotated. If @gravity is
%PANGO_GRAVITY_AUTO, this actually unsets the gravity mask on
the font description.

This function is seldom useful to the user. Gravity should normally
be set on a `PangoContext`. *)

external set_features_static : t -> string -> unit
  = "ml_pango_font_description_set_features_static"
(** Sets the features field of a font description.

This is like [method@Pango.FontDescription.set_features], except
that no copy of @featuresis made. The caller must make sure that
the string passed in stays around until @desc has been freed
or the name is set again. This function can be used if
@features is a static string such as a C string literal,
or if @desc is only needed temporarily. *)

external set_features : t -> string option -> unit
  = "ml_pango_font_description_set_features"
(** Sets the features field of a font description.

    OpenType font features allow to enable or disable certain optional features
    of a font, such as tabular numbers.

    The format of the features string is comma-separated list of feature
    assignments, with each assignment being one of these forms:

    FEATURE=n

    where FEATURE must be a 4 character tag that identifies and OpenType
    feature, and n an integer (depending on the feature, the allowed values may
    be 0, 1 or bigger numbers). Unknown features are ignored.

    Note that font features set in this way are enabled for the entire text that
    is using the font, which is not appropriate for all OpenType features. The
    intended use case is to select character variations (features cv01 - c99),
    style sets (ss01 - ss20) and the like.

    Pango does not currently have a way to find supported OpenType features of a
    font. Both harfbuzz and freetype have API for this. See for example
    [hb_ot_layout_table_get_feature_tags](https://harfbuzz.github.io/harfbuzz-hb-ot-layout.html#hb-ot-layout-table-get-feature-tags).

    Features that are not supported by the font are silently ignored. *)

external set_family_static : t -> string -> unit
  = "ml_pango_font_description_set_family_static"
(** Sets the family name field of a font description, without copying the string.

This is like [method@Pango.FontDescription.set_family], except that no
copy of @family is made. The caller must make sure that the
string passed in stays around until @desc has been freed or the
name is set again. This function can be used if @family is a static
string such as a C string literal, or if @desc is only needed temporarily. *)

external set_family : t -> string -> unit
  = "ml_pango_font_description_set_family"
(** Sets the family name field of a font description.

    The family name represents a family of related font styles, and will resolve
    to a particular `PangoFontFamily`. In some uses of `PangoFontDescription`,
    it is also possible to use a comma separated list of family names for this
    field. *)

external set_color : t -> Pango_enums.fontcolor -> unit
  = "ml_pango_font_description_set_color"
(** Sets the color field of a font description.

    This field determines whether the font description should match fonts that
    have color glyphs, or fonts that don't. *)

external set_absolute_size : t -> float -> unit
  = "ml_pango_font_description_set_absolute_size"
(** Sets the size field of a font description, in device units.

    This is mutually exclusive with [method@Pango.FontDescription.set_size]
    which sets the font size in points. *)

external merge_static : t -> t -> bool -> unit
  = "ml_pango_font_description_merge_static"
(** Merges the fields that are set in @desc_to_merge into the fields in
@desc, without copying allocated fields.

This is like [method@Pango.FontDescription.merge], but only a shallow copy
is made of the family name and other allocated fields. @desc can only
be used until @desc_to_merge is modified or freed. This is meant to
be used when the merged font description is only needed temporarily. *)

external merge : t -> t option -> bool -> unit
  = "ml_pango_font_description_merge"
(** Merges the fields that are set in @desc_to_merge into the fields in
@desc.

If @replace_existing is %FALSE, only fields in @desc that
are not already set are affected. If %TRUE, then fields that are
already set will be replaced as well.

If @desc_to_merge is %NULL, this function performs nothing. *)

external hash : t -> int = "ml_pango_font_description_hash"
(** Computes a hash of a `PangoFontDescription` structure.

This is suitable to be used, for example, as an argument
to g_hash_table_new(). The hash value is independent of @desc->mask. *)

external get_weight : t -> Pango_enums.weight
  = "ml_pango_font_description_get_weight"
(** Gets the weight field of a font description.

    See [method@Pango.FontDescription.set_weight]. *)

external get_variations : t -> string option
  = "ml_pango_font_description_get_variations"
(** Gets the variations field of a font description.

    See [method@Pango.FontDescription.set_variations]. *)

external get_variant : t -> Pango_enums.variant
  = "ml_pango_font_description_get_variant"
(** Gets the variant field of a `PangoFontDescription`.

    See [method@Pango.FontDescription.set_variant]. *)

external get_style : t -> Pango_enums.style
  = "ml_pango_font_description_get_style"
(** Gets the style field of a `PangoFontDescription`.

    See [method@Pango.FontDescription.set_style]. *)

external get_stretch : t -> Pango_enums.stretch
  = "ml_pango_font_description_get_stretch"
(** Gets the stretch field of a font description.

    See [method@Pango.FontDescription.set_stretch]. *)

external get_size_is_absolute : t -> bool
  = "ml_pango_font_description_get_size_is_absolute"
(** Determines whether the size of the font is in points (not absolute) or
    device units (absolute).

    See [method@Pango.FontDescription.set_size] and
    [method@Pango.FontDescription.set_absolute_size]. *)

external get_size : t -> int = "ml_pango_font_description_get_size"
(** Gets the size field of a font description.

    See [method@Pango.FontDescription.set_size]. *)

external get_set_fields : t -> Pango_enums.fontmask
  = "ml_pango_font_description_get_set_fields"
(** Determines which fields in a font description have been set. *)

external get_gravity : t -> Pango_enums.gravity
  = "ml_pango_font_description_get_gravity"
(** Gets the gravity field of a font description.

    See [method@Pango.FontDescription.set_gravity]. *)

external get_features : t -> string option
  = "ml_pango_font_description_get_features"
(** Gets the features field of a font description.

    See [method@Pango.FontDescription.set_features]. *)

external get_family : t -> string option
  = "ml_pango_font_description_get_family"
(** Gets the family name field of a font description.

    See [method@Pango.FontDescription.set_family]. *)

external get_color : t -> Pango_enums.fontcolor
  = "ml_pango_font_description_get_color"
(** Returns the color field of the font description.

    This field determines whether the font description should match fonts that
    have color glyphs, or fonts that don't. *)

external equal : t -> t -> bool = "ml_pango_font_description_equal"
(** Compares two font descriptions for equality.

    Two font descriptions are considered equal if the fonts they describe are
    provably identical. This means that their masks do not have to match, as
    long as other fields are all the same. (Two font descriptions may result in
    identical fonts being loaded, but still compare %FALSE.) *)

external copy_static : t -> t option = "ml_pango_font_description_copy_static"
(** Make a copy of a `PangoFontDescription`, but don't duplicate
allocated fields.

This is like [method@Pango.FontDescription.copy], but only a shallow
copy is made of the family name and other allocated fields. The result
can only be used until @desc is modified or freed. This is meant
to be used when the copy is only needed temporarily. *)

external better_match : t -> t option -> t -> bool
  = "ml_pango_font_description_better_match"
(** Determines if the style attributes of @new_match are a closer match
for @desc than those of @old_match are, or if @old_match is %NULL,
determines if @new_match is a match at all.

Approximate matching is done for weight and style; other style attributes
must match exactly. Style attributes are all attributes other than family
and size-related attributes. Approximate matching for style considers
%PANGO_STYLE_OBLIQUE and %PANGO_STYLE_ITALIC as matches, but not as good
a match as when the styles are equal.

Note that @old_match must match @desc. *)
