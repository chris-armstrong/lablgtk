/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Device */

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


CAMLexport CAMLprim value ml_gdk_device_has_bidi_layouts(value self)
{
CAMLparam1(self);

gboolean result = gdk_device_has_bidi_layouts(GdkDevice_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_device_get_vendor_id(value self)
{
CAMLparam1(self);

const char* result = gdk_device_get_vendor_id(GdkDevice_val(self));
CAMLreturn(Val_option_string(result));
}

#if GTK_CHECK_VERSION(4,2,0)

CAMLexport CAMLprim value ml_gdk_device_get_timestamp(value self)
{
CAMLparam1(self);

guint32 result = gdk_device_get_timestamp(GdkDevice_val(self));
CAMLreturn(Val_uint32(result));
}

#else

CAMLexport CAMLprim value ml_gdk_device_get_timestamp(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Device requires GTK >= 4.2");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_device_get_surface_at_position(value self)
{
CAMLparam1(self);
double out1;
double out2;

GdkSurface* result = gdk_device_get_surface_at_position(GdkDevice_val(self), &out1, &out2);
if (result) g_object_ref_sink(result);
CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_option(result, Val_GdkSurface));
    Store_field(ret, 1, caml_copy_double(out1));
    Store_field(ret, 2, caml_copy_double(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gdk_device_get_source(value self)
{
CAMLparam1(self);

GdkInputSource result = gdk_device_get_source(GdkDevice_val(self));
CAMLreturn(Val_GdkInputSource(result));
}

CAMLexport CAMLprim value ml_gdk_device_get_seat(value self)
{
CAMLparam1(self);

GdkSeat* result = gdk_device_get_seat(GdkDevice_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GdkSeat(result));
}

CAMLexport CAMLprim value ml_gdk_device_get_scroll_lock_state(value self)
{
CAMLparam1(self);

gboolean result = gdk_device_get_scroll_lock_state(GdkDevice_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_device_get_product_id(value self)
{
CAMLparam1(self);

const char* result = gdk_device_get_product_id(GdkDevice_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gdk_device_get_num_touches(value self)
{
CAMLparam1(self);

guint result = gdk_device_get_num_touches(GdkDevice_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_device_get_num_lock_state(value self)
{
CAMLparam1(self);

gboolean result = gdk_device_get_num_lock_state(GdkDevice_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_device_get_name(value self)
{
CAMLparam1(self);

const char* result = gdk_device_get_name(GdkDevice_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gdk_device_get_modifier_state(value self)
{
CAMLparam1(self);

GdkModifierType result = gdk_device_get_modifier_state(GdkDevice_val(self));
CAMLreturn(Val_GdkModifierType(result));
}

#if GTK_CHECK_VERSION(4,18,0)

CAMLexport CAMLprim value ml_gdk_device_get_layout_names(value self)
{
CAMLparam1(self);

gchar** result = gdk_device_get_layout_names(GdkDevice_val(self));
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

#else

CAMLexport CAMLprim value ml_gdk_device_get_layout_names(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Device requires GTK >= 4.18");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_device_get_has_cursor(value self)
{
CAMLparam1(self);

gboolean result = gdk_device_get_has_cursor(GdkDevice_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_device_get_display(value self)
{
CAMLparam1(self);

GdkDisplay* result = gdk_device_get_display(GdkDevice_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GdkDisplay(result));
}

CAMLexport CAMLprim value ml_gdk_device_get_direction(value self)
{
CAMLparam1(self);

PangoDirection result = gdk_device_get_direction(GdkDevice_val(self));
CAMLreturn(Val_PangoDirection(result));
}

CAMLexport CAMLprim value ml_gdk_device_get_device_tool(value self)
{
CAMLparam1(self);

GdkDeviceTool* result = gdk_device_get_device_tool(GdkDevice_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkDeviceTool));
}

CAMLexport CAMLprim value ml_gdk_device_get_caps_lock_state(value self)
{
CAMLparam1(self);

gboolean result = gdk_device_get_caps_lock_state(GdkDevice_val(self));
CAMLreturn(Val_bool(result));
}

#if GTK_CHECK_VERSION(4,18,0)

CAMLexport CAMLprim value ml_gdk_device_get_active_layout_index(value self)
{
CAMLparam1(self);

gint result = gdk_device_get_active_layout_index(GdkDevice_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_gdk_device_get_active_layout_index(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Device requires GTK >= 4.18");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_device_get_n_axes(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GdkDevice *obj = (GdkDevice *)GdkDevice_val(self);
    guint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "n-axes");
if (pspec == NULL) caml_failwith("ml_gdk_device_get_n_axes: property 'n-axes' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "n-axes", &prop_gvalue);
          prop_value = g_value_get_uint(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

GType gdk_device_get_type (void);


CAMLprim value ml_gdk_device_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_device_get_type()));
}
