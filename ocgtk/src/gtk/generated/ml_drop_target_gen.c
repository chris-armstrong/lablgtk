/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DropTarget */

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


CAMLexport CAMLprim value ml_gtk_drop_target_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GtkDropTarget *obj = gtk_drop_target_new(GType_val(arg1), GdkDragAction_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkDropTarget(obj));
}
CAMLexport CAMLprim value ml_gtk_drop_target_set_preload(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_drop_target_set_preload(GtkDropTarget_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_drop_target_set_gtypes(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
    int arg1_length = 0;
    GType* c_arg1 = NULL;
    
    if (Is_some(arg1)) {
        value array = Some_val(arg1);
        arg1_length = Wosize_val(array);
        c_arg1 = (GType*)g_malloc(sizeof(GType) * arg1_length);
        for (int i = 0; i < arg1_length; i++) {
          c_arg1[i] = GType_val(Field(array, i));
        }
    }

gtk_drop_target_set_gtypes(GtkDropTarget_val(self), c_arg1, Gsize_val(arg2));
    if (c_arg1) g_free(c_arg1);
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_drop_target_set_actions(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_drop_target_set_actions(GtkDropTarget_val(self), GdkDragAction_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_drop_target_reject(value self)
{
CAMLparam1(self);

gtk_drop_target_reject(GtkDropTarget_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_drop_target_get_value(value self)
{
CAMLparam1(self);

const GValue* result = gtk_drop_target_get_value(GtkDropTarget_val(self));
CAMLreturn(Val_option(result, Val_GValue_copy));
}

CAMLexport CAMLprim value ml_gtk_drop_target_get_preload(value self)
{
CAMLparam1(self);

gboolean result = gtk_drop_target_get_preload(GtkDropTarget_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_drop_target_get_gtypes(value self)
{
CAMLparam1(self);
gsize out1;

const GType* result = gtk_drop_target_get_gtypes(GtkDropTarget_val(self), &out1);
    CAMLlocal2(ml_result, ml_result_opt);
    if (result == NULL) {
      ml_result_opt = Val_none;
    } else {
      int result_length = out1;
      ml_result = caml_alloc(result_length, 0);
      for (int i = 0; i < result_length; i++) {
        Store_field(ml_result, i, Val_GType(result[i]));
      }
      ml_result_opt = Val_some(ml_result);
          }
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, ml_result_opt);
    Store_field(ret, 1, Val_gsize(out1));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_drop_target_get_formats(value self)
{
CAMLparam1(self);

GdkContentFormats* result = gtk_drop_target_get_formats(GtkDropTarget_val(self));
if (result) result = g_boxed_copy(gdk_content_formats_get_type(), result);
CAMLreturn(Val_option(result, Val_GdkContentFormats));
}

CAMLexport CAMLprim value ml_gtk_drop_target_get_drop(value self)
{
CAMLparam1(self);

GdkDrop* result = gtk_drop_target_get_drop(GtkDropTarget_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkDrop));
}

#if GTK_CHECK_VERSION(4,4,0)

CAMLexport CAMLprim value ml_gtk_drop_target_get_current_drop(value self)
{
CAMLparam1(self);

GdkDrop* result = gtk_drop_target_get_current_drop(GtkDropTarget_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkDrop));
}

#else

CAMLexport CAMLprim value ml_gtk_drop_target_get_current_drop(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DropTarget requires GTK >= 4.4");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_drop_target_get_actions(value self)
{
CAMLparam1(self);

GdkDragAction result = gtk_drop_target_get_actions(GtkDropTarget_val(self));
CAMLreturn(Val_GdkDragAction(result));
}


CAMLprim value ml_gtk_drop_target_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_drop_target_get_type()));
}
