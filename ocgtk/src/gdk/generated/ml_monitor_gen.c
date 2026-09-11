/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Monitor */

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


CAMLexport CAMLprim value ml_gdk_monitor_is_valid(value self)
{
CAMLparam1(self);

gboolean result = gdk_monitor_is_valid(GdkMonitor_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_monitor_get_width_mm(value self)
{
CAMLparam1(self);

int result = gdk_monitor_get_width_mm(GdkMonitor_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_monitor_get_subpixel_layout(value self)
{
CAMLparam1(self);

GdkSubpixelLayout result = gdk_monitor_get_subpixel_layout(GdkMonitor_val(self));
CAMLreturn(Val_GdkSubpixelLayout(result));
}

CAMLexport CAMLprim value ml_gdk_monitor_get_scale_factor(value self)
{
CAMLparam1(self);

int result = gdk_monitor_get_scale_factor(GdkMonitor_val(self));
CAMLreturn(Val_int(result));
}

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gdk_monitor_get_scale(value self)
{
CAMLparam1(self);

double result = gdk_monitor_get_scale(GdkMonitor_val(self));
CAMLreturn(caml_copy_double(result));
}

#else

CAMLexport CAMLprim value ml_gdk_monitor_get_scale(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Monitor requires GTK >= 4.14");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_monitor_get_refresh_rate(value self)
{
CAMLparam1(self);

int result = gdk_monitor_get_refresh_rate(GdkMonitor_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_monitor_get_model(value self)
{
CAMLparam1(self);

const char* result = gdk_monitor_get_model(GdkMonitor_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gdk_monitor_get_manufacturer(value self)
{
CAMLparam1(self);

const char* result = gdk_monitor_get_manufacturer(GdkMonitor_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gdk_monitor_get_height_mm(value self)
{
CAMLparam1(self);

int result = gdk_monitor_get_height_mm(GdkMonitor_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_monitor_get_geometry(value self)
{
CAMLparam1(self);
GdkRectangle out1;

gdk_monitor_get_geometry(GdkMonitor_val(self), &out1);
CAMLreturn(Val_GdkRectangle(&out1));
}

CAMLexport CAMLprim value ml_gdk_monitor_get_display(value self)
{
CAMLparam1(self);

GdkDisplay* result = gdk_monitor_get_display(GdkMonitor_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GdkDisplay(result));
}

#if GTK_CHECK_VERSION(4,10,0)

CAMLexport CAMLprim value ml_gdk_monitor_get_description(value self)
{
CAMLparam1(self);

const char* result = gdk_monitor_get_description(GdkMonitor_val(self));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_gdk_monitor_get_description(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Monitor requires GTK >= 4.10");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_monitor_get_connector(value self)
{
CAMLparam1(self);

const char* result = gdk_monitor_get_connector(GdkMonitor_val(self));
CAMLreturn(Val_option_string(result));
}


CAMLprim value ml_gdk_monitor_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_monitor_get_type()));
}
