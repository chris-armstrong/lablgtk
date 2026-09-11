(* GENERATED CODE - DO NOT EDIT *)
(* DmabufFormats: DmabufFormats *)

type t = [ `dmabuf_formats ] Gobject.obj
(** Provides information about supported DMA buffer formats.

    You can query whether a given format is supported with
    [method@Gdk.DmabufFormats.contains] and you can iterate over the list of all
    supported formats with [method@Gdk.DmabufFormats.get_n_formats] and
    [method@Gdk.DmabufFormats.get_format].

    The list of supported formats is sorted by preference, with the best formats
    coming first.

    The list may contains (format, modifier) pairs where the modifier is
    `DMA_FORMAT_MOD_INVALID`, indicating that **_implicit modifiers_** may be
    used with this format.

    See [class@Gdk.DmabufTextureBuilder] for more information about DMA buffers.

    Note that DMA buffers only exist on Linux. *)

external gtype : unit -> Gobject.Type.t = "ml_gdk_dmabuf_formats_get_type"

(* Methods *)

external ref : t -> t = "ml_gdk_dmabuf_formats_ref"
(** Increases the reference count of @formats. *)

external get_n_formats : t -> Gsize.t = "ml_gdk_dmabuf_formats_get_n_formats"
(** Returns the number of formats that the @formats object
contains.

Note that DMA buffers are a Linux concept, so on other
platforms, [method@Gdk.DmabufFormats.get_n_formats] will
always return zero. *)

external get_format : t -> Gsize.t -> UInt32.t * UInt64.t
  = "ml_gdk_dmabuf_formats_get_format"
(** Gets the fourcc code and modifier for a format
that is contained in @formats. *)

external equal : t -> t option -> bool = "ml_gdk_dmabuf_formats_equal"
(** Returns whether @formats1 and @formats2 contain the
same dmabuf formats, in the same order. *)

external contains : t -> UInt32.t -> UInt64.t -> bool
  = "ml_gdk_dmabuf_formats_contains"
(** Returns whether a given format is contained in @formats. *)
