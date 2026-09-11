(* GENERATED CODE - DO NOT EDIT *)
(* Attribute: Attribute *)

type t = [ `attribute ] Gobject.obj
(** The `PangoAttribute` structure represents the common portions of all
    attributes.

    Particular types of attributes include this structure as their initial
    portion. The common portion of the attribute holds the range to which the
    value in the type-specific part of the attribute applies and should be
    initialized using [method@Pango.Attribute.init]. By default, an attribute
    will have an all-inclusive range of [0,%G_MAXUINT]. *)

external gtype : unit -> Gobject.Type.t = "ml_pango_attribute_get_type"

(* Methods *)

external init : t -> Attr_class.t -> unit = "ml_pango_attribute_init"
(** Initializes @attr's klass to @klass, it's start_index to
%PANGO_ATTR_INDEX_FROM_TEXT_BEGINNING and end_index to
%PANGO_ATTR_INDEX_TO_TEXT_END such that the attribute applies
to the entire text by default. *)

external equal : t -> t -> bool = "ml_pango_attribute_equal"
(** Compare two attributes for equality.

    This compares only the actual value of the two attributes and not the ranges
    that the attributes apply to. *)

external destroy : t -> unit = "ml_pango_attribute_destroy"
(** Destroy a `PangoAttribute` and free all associated memory. *)

external as_string : t -> Attr_string.t option = "ml_pango_attribute_as_string"
(** Returns the attribute cast to `PangoAttrString`.

    This is mainly useful for language bindings. *)

external as_size : t -> Attr_size.t option = "ml_pango_attribute_as_size"
(** Returns the attribute cast to `PangoAttrSize`.

    This is mainly useful for language bindings. *)

external as_shape : t -> Attr_shape.t option = "ml_pango_attribute_as_shape"
(** Returns the attribute cast to `PangoAttrShape`.

    This is mainly useful for language bindings. *)

external as_language : t -> Attr_language.t option
  = "ml_pango_attribute_as_language"
(** Returns the attribute cast to `PangoAttrLanguage`.

    This is mainly useful for language bindings. *)

external as_int : t -> Attr_int.t option = "ml_pango_attribute_as_int"
(** Returns the attribute cast to `PangoAttrInt`.

    This is mainly useful for language bindings. *)

external as_font_features : t -> Attr_font_features.t option
  = "ml_pango_attribute_as_font_features"
(** Returns the attribute cast to `PangoAttrFontFeatures`.

    This is mainly useful for language bindings. *)

external as_font_desc : t -> Attr_font_desc.t option
  = "ml_pango_attribute_as_font_desc"
(** Returns the attribute cast to `PangoAttrFontDesc`.

    This is mainly useful for language bindings. *)

external as_float : t -> Attr_float.t option = "ml_pango_attribute_as_float"
(** Returns the attribute cast to `PangoAttrFloat`.

    This is mainly useful for language bindings. *)

external as_color : t -> Attr_color.t option = "ml_pango_attribute_as_color"
(** Returns the attribute cast to `PangoAttrColor`.

    This is mainly useful for language bindings. *)
