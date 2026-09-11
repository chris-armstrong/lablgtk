/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TextureDownloader */

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

#if GTK_CHECK_VERSION(4,10,0)
/* Conversion functions for GdkTextureDownloader (opaque record with hidden fields) */
GdkTextureDownloader *GdkTextureDownloader_val(value v) {
  return (GdkTextureDownloader *)ml_gir_record_ptr_val(v, "GdkTextureDownloader");
}

value Val_GdkTextureDownloader(const GdkTextureDownloader *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(gdk_texture_downloader_get_type(), ptr);
}

value Val_GdkTextureDownloader_option(const GdkTextureDownloader *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GdkTextureDownloader(ptr));
}
#endif

#if GTK_CHECK_VERSION(4,10,0)


CAMLexport CAMLprim value ml_gdk_texture_downloader_new(value arg1)
{
CAMLparam1(arg1);

GdkTextureDownloader *obj = gdk_texture_downloader_new(GdkTexture_val(arg1));

CAMLreturn(Val_GdkTextureDownloader(obj));
}
CAMLexport CAMLprim value ml_gdk_texture_downloader_set_texture(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_texture_downloader_set_texture(GdkTextureDownloader_val(self), GdkTexture_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_texture_downloader_set_format(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_texture_downloader_set_format(GdkTextureDownloader_val(self), GdkMemoryFormat_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,16,0)

CAMLexport CAMLprim value ml_gdk_texture_downloader_set_color_state(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_texture_downloader_set_color_state(GdkTextureDownloader_val(self), GdkColorState_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gdk_texture_downloader_set_color_state(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TextureDownloader requires GTK >= 4.16");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_texture_downloader_get_texture(value self)
{
CAMLparam1(self);

GdkTexture* result = gdk_texture_downloader_get_texture(GdkTextureDownloader_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GdkTexture(result));
}

CAMLexport CAMLprim value ml_gdk_texture_downloader_get_format(value self)
{
CAMLparam1(self);

GdkMemoryFormat result = gdk_texture_downloader_get_format(GdkTextureDownloader_val(self));
CAMLreturn(Val_GdkMemoryFormat(result));
}

#if GTK_CHECK_VERSION(4,16,0)

CAMLexport CAMLprim value ml_gdk_texture_downloader_get_color_state(value self)
{
CAMLparam1(self);

GdkColorState* result = gdk_texture_downloader_get_color_state(GdkTextureDownloader_val(self));
CAMLreturn(Val_GdkColorState(result));
}

#else

CAMLexport CAMLprim value ml_gdk_texture_downloader_get_color_state(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TextureDownloader requires GTK >= 4.16");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gdk_texture_downloader_download_bytes_with_planes(value self)
{
CAMLparam1(self);
gsize out1[4];
gsize out2[4];

GBytes* result = gdk_texture_downloader_download_bytes_with_planes(GdkTextureDownloader_val(self), out1, out2);
    int out1_length = 4;
    CAMLlocal1(ml_out1);
    ml_out1 = caml_alloc(out1_length, 0);
    for (int i = 0; i < out1_length; i++) {
      Store_field(ml_out1, i, Val_gsize(&out1[i]));
    }
    int out2_length = 4;
    CAMLlocal1(ml_out2);
    ml_out2 = caml_alloc(out2_length, 0);
    for (int i = 0; i < out2_length; i++) {
      Store_field(ml_out2, i, Val_gsize(&out2[i]));
    }

CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_GBytes(result));
    Store_field(ret, 1, ml_out1);
    Store_field(ret, 2, ml_out2);
    CAMLreturn(ret);
}

#else

CAMLexport CAMLprim value ml_gdk_texture_downloader_download_bytes_with_planes(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TextureDownloader requires GTK >= 4.20");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_texture_downloader_download_bytes(value self)
{
CAMLparam1(self);
gsize out1;

GBytes* result = gdk_texture_downloader_download_bytes(GdkTextureDownloader_val(self), &out1);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_GBytes(result));
    Store_field(ret, 1, Val_gsize(out1));
    CAMLreturn(ret);
}


CAMLprim value ml_gdk_texture_downloader_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_texture_downloader_get_type()));
}

#else


CAMLexport CAMLprim value ml_gdk_texture_downloader_new(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("TextureDownloader requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_texture_downloader_download_bytes(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TextureDownloader requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_texture_downloader_download_bytes_with_planes(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TextureDownloader requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_texture_downloader_get_color_state(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TextureDownloader requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_texture_downloader_get_format(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TextureDownloader requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_texture_downloader_get_texture(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TextureDownloader requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_texture_downloader_set_color_state(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TextureDownloader requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_texture_downloader_set_format(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TextureDownloader requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_texture_downloader_set_texture(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TextureDownloader requires GTK >= 4.10");
return Val_unit;
}


#endif
