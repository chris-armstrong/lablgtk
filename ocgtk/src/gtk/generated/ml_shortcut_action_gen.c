/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ShortcutAction */

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


CAMLexport CAMLprim value ml_gtk_shortcut_action_parse_string(value arg1)
{
CAMLparam1(arg1);

GtkShortcutAction *obj = gtk_shortcut_action_parse_string(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkShortcutAction(obj));
}
CAMLexport CAMLprim value ml_gtk_shortcut_action_to_string(value self)
{
CAMLparam1(self);

char* result = gtk_shortcut_action_to_string(GtkShortcutAction_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_shortcut_action_activate(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gboolean result = gtk_shortcut_action_activate(GtkShortcutAction_val(self), GtkShortcutActionFlags_val(arg1), GtkWidget_val(arg2), Option_val(arg3, GVariant_val, NULL));
CAMLreturn(Val_bool(result));
}


CAMLprim value ml_gtk_shortcut_action_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_shortcut_action_get_type()));
}
