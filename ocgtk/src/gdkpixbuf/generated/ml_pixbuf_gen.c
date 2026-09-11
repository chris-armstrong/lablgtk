/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Pixbuf */

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


CAMLexport CAMLprim value ml_gdk_pixbuf_new(value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(arg1, arg2, arg3, arg4, arg5);

GdkPixbuf *obj = gdk_pixbuf_new(GdkPixbufColorspace_val(arg1), Bool_val(arg2), Int_val(arg3), Int_val(arg4), Int_val(arg5));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GdkPixbuf(obj));
}
#if GDK_PIXBUF_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_new_from_bytes_native(value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7)
{
CAMLparam5(arg1, arg2, arg3, arg4, arg5);
CAMLxparam2(arg6, arg7);

GdkPixbuf *obj = gdk_pixbuf_new_from_bytes(GBytes_val(arg1), GdkPixbufColorspace_val(arg2), Bool_val(arg3), Int_val(arg4), Int_val(arg5), Int_val(arg6), Int_val(arg7));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GdkPixbuf(obj));}

CAMLexport CAMLprim value ml_gdk_pixbuf_new_from_bytes_bytecode(value * argv, int argn)
{
return ml_gdk_pixbuf_new_from_bytes_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

#else

CAMLexport CAMLprim value ml_gdk_pixbuf_new_from_bytes(value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7)
{
CAMLparam7(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
(void)arg6;
(void)arg7;
caml_failwith("Pixbuf requires GdkPixbuf >= 2.32");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_pixbuf_new_from_file(value arg1)
{
CAMLparam1(arg1);
GError *error = NULL;
    
GdkPixbuf *obj = gdk_pixbuf_new_from_file(String_val(arg1), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GdkPixbuf(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
#if GDK_PIXBUF_CHECK_VERSION(2,6,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_new_from_file_at_scale(value arg1, value arg2, value arg3, value arg4)
{
CAMLparam4(arg1, arg2, arg3, arg4);
GError *error = NULL;
    
GdkPixbuf *obj = gdk_pixbuf_new_from_file_at_scale(String_val(arg1), Int_val(arg2), Int_val(arg3), Bool_val(arg4), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GdkPixbuf(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
#else

CAMLexport CAMLprim value ml_gdk_pixbuf_new_from_file_at_scale(value arg1, value arg2, value arg3, value arg4)
{
CAMLparam4(arg1, arg2, arg3, arg4);
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("Pixbuf requires GdkPixbuf >= 2.6");
return Val_unit;
}
#endif

#if GDK_PIXBUF_CHECK_VERSION(2,4,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_new_from_file_at_size(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);
GError *error = NULL;
    
GdkPixbuf *obj = gdk_pixbuf_new_from_file_at_size(String_val(arg1), Int_val(arg2), Int_val(arg3), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GdkPixbuf(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
#else

CAMLexport CAMLprim value ml_gdk_pixbuf_new_from_file_at_size(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Pixbuf requires GdkPixbuf >= 2.4");
return Val_unit;
}
#endif

#if GDK_PIXBUF_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_new_from_resource(value arg1)
{
CAMLparam1(arg1);
GError *error = NULL;
    
GdkPixbuf *obj = gdk_pixbuf_new_from_resource(String_val(arg1), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GdkPixbuf(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
#else

CAMLexport CAMLprim value ml_gdk_pixbuf_new_from_resource(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("Pixbuf requires GdkPixbuf >= 2.26");
return Val_unit;
}
#endif

#if GDK_PIXBUF_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_new_from_resource_at_scale(value arg1, value arg2, value arg3, value arg4)
{
CAMLparam4(arg1, arg2, arg3, arg4);
GError *error = NULL;
    
GdkPixbuf *obj = gdk_pixbuf_new_from_resource_at_scale(String_val(arg1), Int_val(arg2), Int_val(arg3), Bool_val(arg4), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GdkPixbuf(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
#else

CAMLexport CAMLprim value ml_gdk_pixbuf_new_from_resource_at_scale(value arg1, value arg2, value arg3, value arg4)
{
CAMLparam4(arg1, arg2, arg3, arg4);
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("Pixbuf requires GdkPixbuf >= 2.26");
return Val_unit;
}
#endif

#if GDK_PIXBUF_CHECK_VERSION(2,14,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_new_from_stream(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
GError *error = NULL;
    
GdkPixbuf *obj = gdk_pixbuf_new_from_stream(GInputStream_val(arg1), Option_val(arg2, GCancellable_val, NULL), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GdkPixbuf(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
#else

CAMLexport CAMLprim value ml_gdk_pixbuf_new_from_stream(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("Pixbuf requires GdkPixbuf >= 2.14");
return Val_unit;
}
#endif

#if GDK_PIXBUF_CHECK_VERSION(2,14,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_new_from_stream_at_scale(value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(arg1, arg2, arg3, arg4, arg5);
GError *error = NULL;
    
GdkPixbuf *obj = gdk_pixbuf_new_from_stream_at_scale(GInputStream_val(arg1), Int_val(arg2), Int_val(arg3), Bool_val(arg4), Option_val(arg5, GCancellable_val, NULL), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GdkPixbuf(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
#else

CAMLexport CAMLprim value ml_gdk_pixbuf_new_from_stream_at_scale(value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(arg1, arg2, arg3, arg4, arg5);
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
caml_failwith("Pixbuf requires GdkPixbuf >= 2.14");
return Val_unit;
}
#endif

#if GDK_PIXBUF_CHECK_VERSION(2,24,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_new_from_stream_finish(value arg1)
{
CAMLparam1(arg1);
GError *error = NULL;
    
GdkPixbuf *obj = gdk_pixbuf_new_from_stream_finish(GAsyncResult_val(arg1), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GdkPixbuf(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
#else

CAMLexport CAMLprim value ml_gdk_pixbuf_new_from_stream_finish(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("Pixbuf requires GdkPixbuf >= 2.24");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_pixbuf_new_from_xpm_data(value arg1)
{
CAMLparam1(arg1);
    int arg1_length = Wosize_val(arg1);
    const char** c_arg1 = (const char**)g_malloc(sizeof(const char*) * (arg1_length + 1));
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = String_val(Field(arg1, i));
    }
    c_arg1[arg1_length] = NULL;

GdkPixbuf *obj = gdk_pixbuf_new_from_xpm_data(c_arg1);
if (obj) g_object_ref_sink(obj);

    g_free(c_arg1);
CAMLreturn(Val_GdkPixbuf(obj));
}
#if GDK_PIXBUF_CHECK_VERSION(2,2,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_set_option(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = gdk_pixbuf_set_option(GdkPixbuf_val(self), String_val(arg1), String_val(arg2));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gdk_pixbuf_set_option(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Pixbuf requires GdkPixbuf >= 2.2");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_pixbuf_scale_simple(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

GdkPixbuf* result = gdk_pixbuf_scale_simple(GdkPixbuf_val(self), Int_val(arg1), Int_val(arg2), GdkPixbufInterpType_val(arg3));
CAMLreturn(Val_option(result, Val_GdkPixbuf));
}

CAMLexport CAMLprim value ml_gdk_pixbuf_scale_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7, value arg8, value arg9, value arg10)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam5(arg5, arg6, arg7, arg8, arg9);
CAMLxparam1(arg10);

gdk_pixbuf_scale(GdkPixbuf_val(self), GdkPixbuf_val(arg1), Int_val(arg2), Int_val(arg3), Int_val(arg4), Int_val(arg5), Double_val(arg6), Double_val(arg7), Double_val(arg8), Double_val(arg9), GdkPixbufInterpType_val(arg10));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gdk_pixbuf_scale_bytecode(value * argv, int argn)
{
return ml_gdk_pixbuf_scale_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], argv[10]);
}

CAMLexport CAMLprim value ml_gdk_pixbuf_savev(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
GError *error = NULL;
    int arg3_length = 0;
    const char** c_arg3 = NULL;
    
    if (Is_some(arg3)) {
        value array = Some_val(arg3);
        arg3_length = Wosize_val(array);
        c_arg3 = (const char**)g_malloc(sizeof(const char*) * (arg3_length + 1));
        for (int i = 0; i < arg3_length; i++) {
          c_arg3[i] = String_val(Field(array, i));
        }
        c_arg3[arg3_length] = NULL;
    }
    int arg4_length = 0;
    const char** c_arg4 = NULL;
    
    if (Is_some(arg4)) {
        value array = Some_val(arg4);
        arg4_length = Wosize_val(array);
        c_arg4 = (const char**)g_malloc(sizeof(const char*) * (arg4_length + 1));
        for (int i = 0; i < arg4_length; i++) {
          c_arg4[i] = String_val(Field(array, i));
        }
        c_arg4[arg4_length] = NULL;
    }

gboolean result = gdk_pixbuf_savev(GdkPixbuf_val(self), String_val(arg1), String_val(arg2), c_arg3, c_arg4, &error);
    if (c_arg3) g_free(c_arg3);
    if (c_arg4) g_free(c_arg4);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#if GDK_PIXBUF_CHECK_VERSION(2,36,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_save_to_streamv_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);
GError *error = NULL;
    int arg3_length = 0;
    const char** c_arg3 = NULL;
    
    if (Is_some(arg3)) {
        value array = Some_val(arg3);
        arg3_length = Wosize_val(array);
        c_arg3 = (const char**)g_malloc(sizeof(const char*) * (arg3_length + 1));
        for (int i = 0; i < arg3_length; i++) {
          c_arg3[i] = String_val(Field(array, i));
        }
        c_arg3[arg3_length] = NULL;
    }
    int arg4_length = 0;
    const char** c_arg4 = NULL;
    
    if (Is_some(arg4)) {
        value array = Some_val(arg4);
        arg4_length = Wosize_val(array);
        c_arg4 = (const char**)g_malloc(sizeof(const char*) * (arg4_length + 1));
        for (int i = 0; i < arg4_length; i++) {
          c_arg4[i] = String_val(Field(array, i));
        }
        c_arg4[arg4_length] = NULL;
    }

gboolean result = gdk_pixbuf_save_to_streamv(GdkPixbuf_val(self), GOutputStream_val(arg1), String_val(arg2), c_arg3, c_arg4, Option_val(arg5, GCancellable_val, NULL), &error);
    if (c_arg3) g_free(c_arg3);
    if (c_arg4) g_free(c_arg4);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));}

CAMLexport CAMLprim value ml_gdk_pixbuf_save_to_streamv_bytecode(value * argv, int argn)
{
return ml_gdk_pixbuf_save_to_streamv_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

#else

CAMLexport CAMLprim value ml_gdk_pixbuf_save_to_streamv(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
caml_failwith("Pixbuf requires GdkPixbuf >= 2.36");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_pixbuf_saturate_and_pixelate(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gdk_pixbuf_saturate_and_pixelate(GdkPixbuf_val(self), GdkPixbuf_val(arg1), Double_val(arg2), Bool_val(arg3));
CAMLreturn(Val_unit);
}

#if GDK_PIXBUF_CHECK_VERSION(2,6,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_rotate_simple(value self, value arg1)
{
CAMLparam2(self, arg1);

GdkPixbuf* result = gdk_pixbuf_rotate_simple(GdkPixbuf_val(self), GdkPixbufPixbufRotation_val(arg1));
CAMLreturn(Val_option(result, Val_GdkPixbuf));
}

#else

CAMLexport CAMLprim value ml_gdk_pixbuf_rotate_simple(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Pixbuf requires GdkPixbuf >= 2.6");
return Val_unit;
}
#endif

#if GDK_PIXBUF_CHECK_VERSION(2,36,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_remove_option(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gdk_pixbuf_remove_option(GdkPixbuf_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gdk_pixbuf_remove_option(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Pixbuf requires GdkPixbuf >= 2.36");
return Val_unit;
}
#endif

#if GDK_PIXBUF_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_read_pixel_bytes(value self)
{
CAMLparam1(self);

GBytes* result = gdk_pixbuf_read_pixel_bytes(GdkPixbuf_val(self));
CAMLreturn(Val_GBytes(result));
}

#else

CAMLexport CAMLprim value ml_gdk_pixbuf_read_pixel_bytes(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Pixbuf requires GdkPixbuf >= 2.32");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_pixbuf_new_subpixbuf(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

GdkPixbuf* result = gdk_pixbuf_new_subpixbuf(GdkPixbuf_val(self), Int_val(arg1), Int_val(arg2), Int_val(arg3), Int_val(arg4));
CAMLreturn(Val_GdkPixbuf(result));
}

CAMLexport CAMLprim value ml_gdk_pixbuf_get_width(value self)
{
CAMLparam1(self);

int result = gdk_pixbuf_get_width(GdkPixbuf_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_pixbuf_get_rowstride(value self)
{
CAMLparam1(self);

int result = gdk_pixbuf_get_rowstride(GdkPixbuf_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_pixbuf_get_option(value self, value arg1)
{
CAMLparam2(self, arg1);

const gchar* result = gdk_pixbuf_get_option(GdkPixbuf_val(self), String_val(arg1));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gdk_pixbuf_get_n_channels(value self)
{
CAMLparam1(self);

int result = gdk_pixbuf_get_n_channels(GdkPixbuf_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_pixbuf_get_height(value self)
{
CAMLparam1(self);

int result = gdk_pixbuf_get_height(GdkPixbuf_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_pixbuf_get_has_alpha(value self)
{
CAMLparam1(self);

gboolean result = gdk_pixbuf_get_has_alpha(GdkPixbuf_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_pixbuf_get_colorspace(value self)
{
CAMLparam1(self);

GdkColorspace result = gdk_pixbuf_get_colorspace(GdkPixbuf_val(self));
CAMLreturn(Val_GdkPixbufColorspace(result));
}

#if GDK_PIXBUF_CHECK_VERSION(2,26,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_get_byte_length(value self)
{
CAMLparam1(self);

gsize result = gdk_pixbuf_get_byte_length(GdkPixbuf_val(self));
CAMLreturn(Val_gsize(result));
}

#else

CAMLexport CAMLprim value ml_gdk_pixbuf_get_byte_length(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Pixbuf requires GdkPixbuf >= 2.26");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_pixbuf_get_bits_per_sample(value self)
{
CAMLparam1(self);

int result = gdk_pixbuf_get_bits_per_sample(GdkPixbuf_val(self));
CAMLreturn(Val_int(result));
}

#if GDK_PIXBUF_CHECK_VERSION(2,6,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_flip(value self, value arg1)
{
CAMLparam2(self, arg1);

GdkPixbuf* result = gdk_pixbuf_flip(GdkPixbuf_val(self), Bool_val(arg1));
CAMLreturn(Val_option(result, Val_GdkPixbuf));
}

#else

CAMLexport CAMLprim value ml_gdk_pixbuf_flip(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Pixbuf requires GdkPixbuf >= 2.6");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_pixbuf_fill(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_pixbuf_fill(GdkPixbuf_val(self), UInt32_val(arg1));
CAMLreturn(Val_unit);
}

#if GDK_PIXBUF_CHECK_VERSION(2,36,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_copy_options(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gdk_pixbuf_copy_options(GdkPixbuf_val(self), GdkPixbuf_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gdk_pixbuf_copy_options(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Pixbuf requires GdkPixbuf >= 2.36");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_pixbuf_copy_area_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam3(arg5, arg6, arg7);

gdk_pixbuf_copy_area(GdkPixbuf_val(self), Int_val(arg1), Int_val(arg2), Int_val(arg3), Int_val(arg4), GdkPixbuf_val(arg5), Int_val(arg6), Int_val(arg7));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gdk_pixbuf_copy_area_bytecode(value * argv, int argn)
{
return ml_gdk_pixbuf_copy_area_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
}

CAMLexport CAMLprim value ml_gdk_pixbuf_copy(value self)
{
CAMLparam1(self);

GdkPixbuf* result = gdk_pixbuf_copy(GdkPixbuf_val(self));
CAMLreturn(Val_option(result, Val_GdkPixbuf));
}

CAMLexport CAMLprim value ml_gdk_pixbuf_composite_color_simple_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam3(arg5, arg6, arg7);

GdkPixbuf* result = gdk_pixbuf_composite_color_simple(GdkPixbuf_val(self), Int_val(arg1), Int_val(arg2), GdkPixbufInterpType_val(arg3), Int_val(arg4), Int_val(arg5), UInt32_val(arg6), UInt32_val(arg7));
CAMLreturn(Val_option(result, Val_GdkPixbuf));}

CAMLexport CAMLprim value ml_gdk_pixbuf_composite_color_simple_bytecode(value * argv, int argn)
{
return ml_gdk_pixbuf_composite_color_simple_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
}

CAMLexport CAMLprim value ml_gdk_pixbuf_composite_color_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7, value arg8, value arg9, value arg10, value arg11, value arg12, value arg13, value arg14, value arg15, value arg16)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam5(arg5, arg6, arg7, arg8, arg9);
CAMLxparam5(arg10, arg11, arg12, arg13, arg14);
CAMLxparam2(arg15, arg16);

gdk_pixbuf_composite_color(GdkPixbuf_val(self), GdkPixbuf_val(arg1), Int_val(arg2), Int_val(arg3), Int_val(arg4), Int_val(arg5), Double_val(arg6), Double_val(arg7), Double_val(arg8), Double_val(arg9), GdkPixbufInterpType_val(arg10), Int_val(arg11), Int_val(arg12), Int_val(arg13), Int_val(arg14), UInt32_val(arg15), UInt32_val(arg16));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gdk_pixbuf_composite_color_bytecode(value * argv, int argn)
{
return ml_gdk_pixbuf_composite_color_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], argv[10], argv[11], argv[12], argv[13], argv[14], argv[15], argv[16]);
}

CAMLexport CAMLprim value ml_gdk_pixbuf_composite_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7, value arg8, value arg9, value arg10, value arg11)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam5(arg5, arg6, arg7, arg8, arg9);
CAMLxparam2(arg10, arg11);

gdk_pixbuf_composite(GdkPixbuf_val(self), GdkPixbuf_val(arg1), Int_val(arg2), Int_val(arg3), Int_val(arg4), Int_val(arg5), Double_val(arg6), Double_val(arg7), Double_val(arg8), Double_val(arg9), GdkPixbufInterpType_val(arg10), Int_val(arg11));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gdk_pixbuf_composite_bytecode(value * argv, int argn)
{
return ml_gdk_pixbuf_composite_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], argv[10], argv[11]);
}

#if GDK_PIXBUF_CHECK_VERSION(2,12,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_apply_embedded_orientation(value self)
{
CAMLparam1(self);

GdkPixbuf* result = gdk_pixbuf_apply_embedded_orientation(GdkPixbuf_val(self));
CAMLreturn(Val_option(result, Val_GdkPixbuf));
}

#else

CAMLexport CAMLprim value ml_gdk_pixbuf_apply_embedded_orientation(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Pixbuf requires GdkPixbuf >= 2.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_pixbuf_get_pixel_bytes(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GdkPixbuf *obj = (GdkPixbuf *)GdkPixbuf_val(self);
    GBytes* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "pixel-bytes");
if (pspec == NULL) caml_failwith("ml_gdk_pixbuf_get_pixel_bytes: property 'pixel-bytes' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "pixel-bytes", &prop_gvalue);
          prop_value = (GBytes*)g_value_get_pointer(&prop_gvalue);

      result = Val_GBytes(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

GType gdk_pixbuf_get_type (void);


CAMLprim value ml_gdk_pixbuf_pixbuf_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_pixbuf_get_type()));
}
