/* GENERATED CODE - DO NOT EDIT */
/* C bindings for GLTexture */

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


CAMLexport CAMLprim value ml_gdk_gl_texture_release(value self)
{
CAMLparam1(self);

gdk_gl_texture_release(GdkGLTexture_val(self));
CAMLreturn(Val_unit);
}

GType gdk_gl_texture_get_type (void);


CAMLprim value ml_gdk_gl_texture_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_gl_texture_get_type()));
}
