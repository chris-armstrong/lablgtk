/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DmabufTexture */

#include <gtk/gtk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <gdk/gdk.h>
/* Include library-specific type conversions and forward declarations */
#include "gdk_decls.h"

#if GTK_CHECK_VERSION(4,14,0)



CAMLprim value ml_gdk_dmabuf_texture_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_dmabuf_texture_get_type()));
}

#else


#endif
