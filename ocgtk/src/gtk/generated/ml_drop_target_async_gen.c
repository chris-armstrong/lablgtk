/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DropTargetAsync */

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


CAMLexport CAMLprim value ml_gtk_drop_target_async_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GtkDropTargetAsync *obj = gtk_drop_target_async_new(Option_val(arg1, GdkContentFormats_val, NULL), GdkDragAction_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkDropTargetAsync(obj));
}
CAMLexport CAMLprim value ml_gtk_drop_target_async_set_formats(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_drop_target_async_set_formats(GtkDropTargetAsync_val(self), Option_val(arg1, GdkContentFormats_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_drop_target_async_set_actions(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_drop_target_async_set_actions(GtkDropTargetAsync_val(self), GdkDragAction_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_drop_target_async_reject_drop(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_drop_target_async_reject_drop(GtkDropTargetAsync_val(self), GdkDrop_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_drop_target_async_get_formats(value self)
{
CAMLparam1(self);

GdkContentFormats* result = gtk_drop_target_async_get_formats(GtkDropTargetAsync_val(self));
CAMLreturn(Val_option(result, Val_GdkContentFormats));
}

CAMLexport CAMLprim value ml_gtk_drop_target_async_get_actions(value self)
{
CAMLparam1(self);

GdkDragAction result = gtk_drop_target_async_get_actions(GtkDropTargetAsync_val(self));
CAMLreturn(Val_GdkDragAction(result));
}

GType gtk_drop_target_async_get_type (void);


CAMLprim value ml_gtk_drop_target_async_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_drop_target_async_get_type()));
}
