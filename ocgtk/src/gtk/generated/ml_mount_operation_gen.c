/* GENERATED CODE - DO NOT EDIT */
/* C bindings for MountOperation */

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


CAMLexport CAMLprim value ml_gtk_mount_operation_new(value arg1)
{
CAMLparam1(arg1);

GtkMountOperation *obj = gtk_mount_operation_new(Option_val(arg1, GtkWindow_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkMountOperation(obj));
}
CAMLexport CAMLprim value ml_gtk_mount_operation_set_parent(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_mount_operation_set_parent(GtkMountOperation_val(self), Option_val(arg1, GtkWindow_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_mount_operation_set_display(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_mount_operation_set_display(GtkMountOperation_val(self), GdkDisplay_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_mount_operation_is_showing(value self)
{
CAMLparam1(self);

gboolean result = gtk_mount_operation_is_showing(GtkMountOperation_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_mount_operation_get_parent(value self)
{
CAMLparam1(self);

GtkWindow* result = gtk_mount_operation_get_parent(GtkMountOperation_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWindow));
}

CAMLexport CAMLprim value ml_gtk_mount_operation_get_display(value self)
{
CAMLparam1(self);

GdkDisplay* result = gtk_mount_operation_get_display(GtkMountOperation_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GdkDisplay(result));
}

GType gtk_mount_operation_get_type (void);


CAMLprim value ml_gtk_mount_operation_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_mount_operation_get_type()));
}
