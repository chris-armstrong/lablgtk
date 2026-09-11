/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ShortcutTrigger */

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


CAMLexport CAMLprim value ml_gtk_shortcut_trigger_parse_string(value arg1)
{
CAMLparam1(arg1);

GtkShortcutTrigger *obj = gtk_shortcut_trigger_parse_string(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkShortcutTrigger(obj));
}
CAMLexport CAMLprim value ml_gtk_shortcut_trigger_trigger(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

GdkKeyMatch result = gtk_shortcut_trigger_trigger(GtkShortcutTrigger_val(self), GdkEvent_val(arg1), Bool_val(arg2));
CAMLreturn(Val_GdkKeyMatch(result));
}

CAMLexport CAMLprim value ml_gtk_shortcut_trigger_to_string(value self)
{
CAMLparam1(self);

char* result = gtk_shortcut_trigger_to_string(GtkShortcutTrigger_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_shortcut_trigger_to_label(value self, value arg1)
{
CAMLparam2(self, arg1);

char* result = gtk_shortcut_trigger_to_label(GtkShortcutTrigger_val(self), GdkDisplay_val(arg1));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_shortcut_trigger_hash(value self)
{
CAMLparam1(self);

guint result = gtk_shortcut_trigger_hash(GtkShortcutTrigger_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_shortcut_trigger_equal(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_shortcut_trigger_equal(GtkShortcutTrigger_val(self), GtkShortcutTrigger_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_shortcut_trigger_compare(value self, value arg1)
{
CAMLparam2(self, arg1);

int result = gtk_shortcut_trigger_compare(GtkShortcutTrigger_val(self), GtkShortcutTrigger_val(arg1));
CAMLreturn(Val_int(result));
}

GType gtk_shortcut_trigger_get_type (void);


CAMLprim value ml_gtk_shortcut_trigger_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_shortcut_trigger_get_type()));
}
