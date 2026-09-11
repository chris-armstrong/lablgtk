/* GENERATED CODE - DO NOT EDIT */
/* C bindings for PadController */

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


CAMLexport CAMLprim value ml_gtk_pad_controller_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GtkPadController *obj = gtk_pad_controller_new(GActionGroup_val(arg1), Option_val(arg2, GdkDevice_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkPadController(obj));
}
CAMLexport CAMLprim value ml_gtk_pad_controller_set_action_entries(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
    int arg1_length = Wosize_val(arg1);
    GtkPadActionEntry* c_arg1 = (GtkPadActionEntry*)g_malloc(sizeof(GtkPadActionEntry) * arg1_length);
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = *GtkPadActionEntry_val(Field(arg1, i));
    }

gtk_pad_controller_set_action_entries(GtkPadController_val(self), c_arg1, Int_val(arg2));
    g_free(c_arg1);
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_pad_controller_set_action_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);

gtk_pad_controller_set_action(GtkPadController_val(self), GtkPadActionType_val(arg1), Int_val(arg2), Int_val(arg3), String_val(arg4), String_val(arg5));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gtk_pad_controller_set_action_bytecode(value * argv, int argn)
{
return ml_gtk_pad_controller_set_action_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLexport CAMLprim value ml_gtk_pad_controller_get_action_group(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkPadController *obj = (GtkPadController *)GtkPadController_val(self);
    GActionGroup *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "action-group");
if (pspec == NULL) caml_failwith("ml_gtk_pad_controller_get_action_group: property 'action-group' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "action-group", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GActionGroup(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_pad_controller_get_pad(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkPadController *obj = (GtkPadController *)GtkPadController_val(self);
    GdkDevice *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "pad");
if (pspec == NULL) caml_failwith("ml_gtk_pad_controller_get_pad: property 'pad' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "pad", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GdkDevice(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

GType gtk_pad_controller_get_type (void);


CAMLprim value ml_gtk_pad_controller_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_pad_controller_get_type()));
}
