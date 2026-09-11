/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DropControllerMotion */

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


CAMLexport CAMLprim value ml_gtk_drop_controller_motion_new(value unit)
{
CAMLparam1(unit);

GtkDropControllerMotion *obj = gtk_drop_controller_motion_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkDropControllerMotion(obj));
}
CAMLexport CAMLprim value ml_gtk_drop_controller_motion_is_pointer(value self)
{
CAMLparam1(self);

gboolean result = gtk_drop_controller_motion_is_pointer(GtkDropControllerMotion_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_drop_controller_motion_get_drop(value self)
{
CAMLparam1(self);

GdkDrop* result = gtk_drop_controller_motion_get_drop(GtkDropControllerMotion_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkDrop));
}

CAMLexport CAMLprim value ml_gtk_drop_controller_motion_contains_pointer(value self)
{
CAMLparam1(self);

gboolean result = gtk_drop_controller_motion_contains_pointer(GtkDropControllerMotion_val(self));
CAMLreturn(Val_bool(result));
}


CAMLprim value ml_gtk_drop_controller_motion_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_drop_controller_motion_get_type()));
}
