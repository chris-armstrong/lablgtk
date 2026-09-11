/* GENERATED CODE - DO NOT EDIT */
/* C bindings for PixbufFormat */

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

#if GDK_PIXBUF_CHECK_VERSION(2,2,0)
/* Copy function for GdkPixbufFormat (value-like record with copy method) */
value copy_GdkPixbufFormat(const GdkPixbufFormat *ptr)
{
  if (ptr == NULL) return Val_none;
  GdkPixbufFormat *copy = g_boxed_copy(gdk_pixbuf_format_get_type(), ptr);
  return ml_gir_record_val_ptr_with_type(gdk_pixbuf_format_get_type(), copy);
}
#endif

#if GDK_PIXBUF_CHECK_VERSION(2,2,0)


#if GDK_PIXBUF_CHECK_VERSION(2,6,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_format_set_disabled(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_pixbuf_format_set_disabled(GdkPixbufFormat_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gdk_pixbuf_format_set_disabled(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("PixbufFormat requires GdkPixbuf >= 2.6");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_pixbuf_format_is_writable(value self)
{
CAMLparam1(self);

gboolean result = gdk_pixbuf_format_is_writable(GdkPixbufFormat_val(self));
CAMLreturn(Val_bool(result));
}

#if GDK_PIXBUF_CHECK_VERSION(2,6,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_format_is_scalable(value self)
{
CAMLparam1(self);

gboolean result = gdk_pixbuf_format_is_scalable(GdkPixbufFormat_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gdk_pixbuf_format_is_scalable(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PixbufFormat requires GdkPixbuf >= 2.6");
return Val_unit;
}
#endif

#if GDK_PIXBUF_CHECK_VERSION(2,36,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_format_is_save_option_supported(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gdk_pixbuf_format_is_save_option_supported(GdkPixbufFormat_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gdk_pixbuf_format_is_save_option_supported(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("PixbufFormat requires GdkPixbuf >= 2.36");
return Val_unit;
}
#endif

#if GDK_PIXBUF_CHECK_VERSION(2,6,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_format_is_disabled(value self)
{
CAMLparam1(self);

gboolean result = gdk_pixbuf_format_is_disabled(GdkPixbufFormat_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gdk_pixbuf_format_is_disabled(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PixbufFormat requires GdkPixbuf >= 2.6");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_pixbuf_format_get_name(value self)
{
CAMLparam1(self);

gchar* result = gdk_pixbuf_format_get_name(GdkPixbufFormat_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gdk_pixbuf_format_get_mime_types(value self)
{
CAMLparam1(self);

gchar** result = gdk_pixbuf_format_get_mime_types(GdkPixbufFormat_val(self));
    CAMLlocal2(ml_result, ml_result_opt);
    if (result == NULL) {
      ml_result_opt = Val_none;
    } else {
      int result_length = 0;
    while (result[result_length] != NULL) result_length++;
      ml_result = caml_alloc(result_length, 0);
      for (int i = 0; i < result_length; i++) {
        Store_field(ml_result, i, caml_copy_string(result[i]));
      }
      ml_result_opt = Val_some(ml_result);
            for (int i = 0; i < result_length; i++) {
      g_free((gpointer)result[i]);
    }
    g_free(result);
    }
CAMLreturn(ml_result_opt);
}

#if GDK_PIXBUF_CHECK_VERSION(2,6,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_format_get_license(value self)
{
CAMLparam1(self);

gchar* result = gdk_pixbuf_format_get_license(GdkPixbufFormat_val(self));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_gdk_pixbuf_format_get_license(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PixbufFormat requires GdkPixbuf >= 2.6");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_pixbuf_format_get_extensions(value self)
{
CAMLparam1(self);

gchar** result = gdk_pixbuf_format_get_extensions(GdkPixbufFormat_val(self));
    CAMLlocal2(ml_result, ml_result_opt);
    if (result == NULL) {
      ml_result_opt = Val_none;
    } else {
      int result_length = 0;
    while (result[result_length] != NULL) result_length++;
      ml_result = caml_alloc(result_length, 0);
      for (int i = 0; i < result_length; i++) {
        Store_field(ml_result, i, caml_copy_string(result[i]));
      }
      ml_result_opt = Val_some(ml_result);
            for (int i = 0; i < result_length; i++) {
      g_free((gpointer)result[i]);
    }
    g_free(result);
    }
CAMLreturn(ml_result_opt);
}

CAMLexport CAMLprim value ml_gdk_pixbuf_format_get_description(value self)
{
CAMLparam1(self);

gchar* result = gdk_pixbuf_format_get_description(GdkPixbufFormat_val(self));
CAMLreturn(Val_option_string(result));
}


CAMLprim value ml_gdk_pixbuf_pixbuf_format_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_pixbuf_format_get_type()));
}

#else


CAMLexport CAMLprim value ml_gdk_pixbuf_format_get_description(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PixbufFormat requires GdkPixbuf >= 2.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_pixbuf_format_get_extensions(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PixbufFormat requires GdkPixbuf >= 2.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_pixbuf_format_get_license(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PixbufFormat requires GdkPixbuf >= 2.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_pixbuf_format_get_mime_types(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PixbufFormat requires GdkPixbuf >= 2.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_pixbuf_format_get_name(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PixbufFormat requires GdkPixbuf >= 2.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_pixbuf_format_is_disabled(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PixbufFormat requires GdkPixbuf >= 2.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_pixbuf_format_is_save_option_supported(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("PixbufFormat requires GdkPixbuf >= 2.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_pixbuf_format_is_scalable(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PixbufFormat requires GdkPixbuf >= 2.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_pixbuf_format_is_writable(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PixbufFormat requires GdkPixbuf >= 2.2");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_pixbuf_format_set_disabled(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("PixbufFormat requires GdkPixbuf >= 2.2");
return Val_unit;
}


#endif
