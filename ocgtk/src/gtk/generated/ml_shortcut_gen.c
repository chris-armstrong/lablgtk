/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Shortcut */

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


CAMLexport CAMLprim value ml_gtk_shortcut_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GtkShortcut *obj = gtk_shortcut_new(Option_val(arg1, GtkShortcutTrigger_val, NULL), Option_val(arg2, GtkShortcutAction_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkShortcut(obj));
}
CAMLexport CAMLprim value ml_gtk_shortcut_set_trigger(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_shortcut_set_trigger(GtkShortcut_val(self), Option_val(arg1, GtkShortcutTrigger_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_shortcut_set_arguments(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_shortcut_set_arguments(GtkShortcut_val(self), Option_val(arg1, GVariant_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_shortcut_set_action(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_shortcut_set_action(GtkShortcut_val(self), Option_val(arg1, GtkShortcutAction_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_shortcut_get_trigger(value self)
{
CAMLparam1(self);

GtkShortcutTrigger* result = gtk_shortcut_get_trigger(GtkShortcut_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkShortcutTrigger));
}

CAMLexport CAMLprim value ml_gtk_shortcut_get_arguments(value self)
{
CAMLparam1(self);

GVariant* result = gtk_shortcut_get_arguments(GtkShortcut_val(self));
if (result) g_variant_ref(result);
CAMLreturn(Val_option(result, Val_GVariant));
}

CAMLexport CAMLprim value ml_gtk_shortcut_get_action(value self)
{
CAMLparam1(self);

GtkShortcutAction* result = gtk_shortcut_get_action(GtkShortcut_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkShortcutAction));
}


CAMLprim value ml_gtk_shortcut_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_shortcut_get_type()));
}
