/* GENERATED CODE - DO NOT EDIT */
/* C bindings for PixbufAnimationIter */

#include <gdk-pixbuf/gdk-pixbuf.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <gdk-pixbuf/gdk-pixbuf.h>
/* Include library-specific type conversions and forward declarations */
#include "gdkpixbuf_decls.h"


CAMLexport CAMLprim value ml_gdk_pixbuf_animation_iter_on_currently_loading_frame(value self)
{
CAMLparam1(self);

gboolean result = gdk_pixbuf_animation_iter_on_currently_loading_frame(GdkPixbufAnimationIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_pixbuf_animation_iter_get_pixbuf(value self)
{
CAMLparam1(self);

GdkPixbuf* result = gdk_pixbuf_animation_iter_get_pixbuf(GdkPixbufAnimationIter_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GdkPixbuf(result));
}

CAMLexport CAMLprim value ml_gdk_pixbuf_animation_iter_get_delay_time(value self)
{
CAMLparam1(self);

int result = gdk_pixbuf_animation_iter_get_delay_time(GdkPixbufAnimationIter_val(self));
CAMLreturn(Val_int(result));
}


CAMLprim value ml_gdk_pixbuf_pixbuf_animation_iter_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_pixbuf_animation_iter_get_type()));
}
