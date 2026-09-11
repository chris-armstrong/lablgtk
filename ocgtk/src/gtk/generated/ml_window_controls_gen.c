/* GENERATED CODE - DO NOT EDIT */
/* C bindings for WindowControls */

#include <gtk/gtk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"
#include "converters.h"

#include <gtk/gtk.h>
/* Include library-specific type conversions and forward declarations */
#include "gtk_decls.h"


CAMLexport CAMLprim value ml_gtk_window_controls_new(value arg1)
{
CAMLparam1(arg1);

GtkWindowControls *obj = gtk_window_controls_new(GtkPackType_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkWindowControls(obj));
}
#if GTK_CHECK_VERSION(4,18,0)

CAMLexport CAMLprim value ml_gtk_window_controls_set_use_native_controls(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_window_controls_set_use_native_controls(GtkWindowControls_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_window_controls_set_use_native_controls(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("WindowControls requires GTK >= 4.18");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_window_controls_set_side(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_window_controls_set_side(GtkWindowControls_val(self), GtkPackType_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_window_controls_set_decoration_layout(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_window_controls_set_decoration_layout(GtkWindowControls_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,18,0)

CAMLexport CAMLprim value ml_gtk_window_controls_get_use_native_controls(value self)
{
CAMLparam1(self);

gboolean result = gtk_window_controls_get_use_native_controls(GtkWindowControls_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gtk_window_controls_get_use_native_controls(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("WindowControls requires GTK >= 4.18");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_window_controls_get_side(value self)
{
CAMLparam1(self);

GtkPackType result = gtk_window_controls_get_side(GtkWindowControls_val(self));
CAMLreturn(Val_GtkPackType(result));
}

CAMLexport CAMLprim value ml_gtk_window_controls_get_empty(value self)
{
CAMLparam1(self);

gboolean result = gtk_window_controls_get_empty(GtkWindowControls_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_window_controls_get_decoration_layout(value self)
{
CAMLparam1(self);

const char* result = gtk_window_controls_get_decoration_layout(GtkWindowControls_val(self));
CAMLreturn(Val_option_string(result));
}

GType gtk_window_controls_get_type (void);


CAMLprim value ml_gtk_window_controls_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_window_controls_get_type()));
}
