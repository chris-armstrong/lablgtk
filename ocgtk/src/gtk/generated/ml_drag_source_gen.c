/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DragSource */

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


CAMLexport CAMLprim value ml_gtk_drag_source_new(value unit)
{
CAMLparam1(unit);

GtkDragSource *obj = gtk_drag_source_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkDragSource(obj));
}
CAMLexport CAMLprim value ml_gtk_drag_source_set_icon(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_drag_source_set_icon(GtkDragSource_val(self), Option_val(arg1, GdkPaintable_val, NULL), Int_val(arg2), Int_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_drag_source_set_content(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_drag_source_set_content(GtkDragSource_val(self), Option_val(arg1, GdkContentProvider_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_drag_source_set_actions(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_drag_source_set_actions(GtkDragSource_val(self), GdkDragAction_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_drag_source_get_drag(value self)
{
CAMLparam1(self);

GdkDrag* result = gtk_drag_source_get_drag(GtkDragSource_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkDrag));
}

CAMLexport CAMLprim value ml_gtk_drag_source_get_content(value self)
{
CAMLparam1(self);

GdkContentProvider* result = gtk_drag_source_get_content(GtkDragSource_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkContentProvider));
}

CAMLexport CAMLprim value ml_gtk_drag_source_get_actions(value self)
{
CAMLparam1(self);

GdkDragAction result = gtk_drag_source_get_actions(GtkDragSource_val(self));
CAMLreturn(Val_GdkDragAction(result));
}

CAMLexport CAMLprim value ml_gtk_drag_source_drag_cancel(value self)
{
CAMLparam1(self);

gtk_drag_source_drag_cancel(GtkDragSource_val(self));
CAMLreturn(Val_unit);
}

GType gtk_drag_source_get_type (void);


CAMLprim value ml_gtk_drag_source_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_drag_source_get_type()));
}
