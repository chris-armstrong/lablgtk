/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ZlibCompressor */

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

CAMLexport CAMLprim value ml_g_zlib_compressor_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GZlibCompressor *obj = g_zlib_compressor_new(GioZlibCompressorFormat_val(arg1), Int_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GZlibCompressor(obj));
}
#else

CAMLexport CAMLprim value ml_g_zlib_compressor_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("ZlibCompressor requires GLib >= 2.24");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,86,0)

CAMLexport CAMLprim value ml_g_zlib_compressor_set_os(value self, value arg1)
{
CAMLparam2(self, arg1);

g_zlib_compressor_set_os(GZlibCompressor_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_zlib_compressor_set_os(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ZlibCompressor requires GLib >= 2.86");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_zlib_compressor_set_file_info(value self, value arg1)
{
CAMLparam2(self, arg1);

g_zlib_compressor_set_file_info(GZlibCompressor_val(self), Option_val(arg1, GFileInfo_val, NULL));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_zlib_compressor_set_file_info(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ZlibCompressor requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,86,0)

CAMLexport CAMLprim value ml_g_zlib_compressor_get_os(value self)
{
CAMLparam1(self);

int result = g_zlib_compressor_get_os(GZlibCompressor_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_g_zlib_compressor_get_os(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ZlibCompressor requires GLib >= 2.86");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_g_zlib_compressor_get_file_info(value self)
{
CAMLparam1(self);

GFileInfo* result = g_zlib_compressor_get_file_info(GZlibCompressor_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GFileInfo));
}

#else

CAMLexport CAMLprim value ml_g_zlib_compressor_get_file_info(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ZlibCompressor requires GLib >= 2.26");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,24,0)

CAMLexport CAMLprim value ml_g_zlib_compressor_get_format(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GZlibCompressor *obj = (GZlibCompressor *)GZlibCompressor_val(self);
    GZlibCompressorFormat prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "format");
if (pspec == NULL) caml_failwith("ml_g_zlib_compressor_get_format: property 'format' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "format", &prop_gvalue);
          prop_value = (GZlibCompressorFormat)g_value_get_enum(&prop_gvalue);

      result = Val_GioZlibCompressorFormat(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_g_zlib_compressor_get_format(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ZlibCompressor requires GLib >= 2.24");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,24,0)

CAMLexport CAMLprim value ml_g_zlib_compressor_get_level(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GZlibCompressor *obj = (GZlibCompressor *)GZlibCompressor_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "level");
if (pspec == NULL) caml_failwith("ml_g_zlib_compressor_get_level: property 'level' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "level", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_g_zlib_compressor_get_level(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ZlibCompressor requires GLib >= 2.24");
return Val_unit;
}
#endif

GType g_zlib_compressor_get_type (void);


CAMLprim value ml_gio_zlib_compressor_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_zlib_compressor_get_type()));
}
