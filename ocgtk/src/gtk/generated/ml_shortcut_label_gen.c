/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ShortcutLabel */

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


CAMLexport CAMLprim value ml_gtk_shortcut_label_new(value arg1)
{
CAMLparam1(arg1);

GtkShortcutLabel *obj = gtk_shortcut_label_new(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkShortcutLabel(obj));
}
CAMLexport CAMLprim value ml_gtk_shortcut_label_set_disabled_text(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_shortcut_label_set_disabled_text(GtkShortcutLabel_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_shortcut_label_set_accelerator(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_shortcut_label_set_accelerator(GtkShortcutLabel_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_shortcut_label_get_disabled_text(value self)
{
CAMLparam1(self);

const char* result = gtk_shortcut_label_get_disabled_text(GtkShortcutLabel_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_shortcut_label_get_accelerator(value self)
{
CAMLparam1(self);

const char* result = gtk_shortcut_label_get_accelerator(GtkShortcutLabel_val(self));
CAMLreturn(Val_option_string(result));
}

GType gtk_shortcut_label_get_type (void);


CAMLprim value ml_gtk_shortcut_label_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_shortcut_label_get_type()));
}
