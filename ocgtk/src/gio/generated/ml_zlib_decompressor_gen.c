/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ZlibDecompressor */

#include <gio/gio.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <gio/gio.h>
/* Include library-specific type conversions and forward declarations */
#include "gio_decls.h"


#if GLIB_CHECK_VERSION(2,24,0)

CAMLexport CAMLprim value ml_g_zlib_decompressor_new(value arg1)
{
CAMLparam1(arg1);

GZlibDecompressor *obj = g_zlib_decompressor_new(GioZlibCompressorFormat_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GZlibDecompressor(obj));
}
#else

CAMLexport CAMLprim value ml_g_zlib_decompressor_new(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("ZlibDecompressor requires GLib >= 2.24");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_zlib_decompressor_get_file_info(value self)
{
CAMLparam1(self);

GFileInfo* result = g_zlib_decompressor_get_file_info(GZlibDecompressor_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GFileInfo));
}

#else

CAMLexport CAMLprim value ml_g_zlib_decompressor_get_file_info(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ZlibDecompressor requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,24,0)

CAMLexport CAMLprim value ml_g_zlib_decompressor_get_format(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GZlibDecompressor *obj = (GZlibDecompressor *)GZlibDecompressor_val(self);
    GZlibCompressorFormat prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "format");
if (pspec == NULL) caml_failwith("ml_g_zlib_decompressor_get_format: property 'format' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "format", &prop_gvalue);
          prop_value = (GZlibCompressorFormat)g_value_get_enum(&prop_gvalue);

      result = Val_GioZlibCompressorFormat(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_g_zlib_decompressor_get_format(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ZlibDecompressor requires GLib >= 2.24");
return Val_unit;
}
#endif

GType g_zlib_decompressor_get_type (void);


CAMLprim value ml_gio_zlib_decompressor_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_zlib_decompressor_get_type()));
}
