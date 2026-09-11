/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ListItem */

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


CAMLexport CAMLprim value ml_gtk_list_item_set_selectable(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_list_item_set_selectable(GtkListItem_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_list_item_set_focusable(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_list_item_set_focusable(GtkListItem_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_list_item_set_focusable(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ListItem requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_list_item_set_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_list_item_set_child(GtkListItem_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_list_item_set_activatable(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_list_item_set_activatable(GtkListItem_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_list_item_set_accessible_label(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_list_item_set_accessible_label(GtkListItem_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_list_item_set_accessible_label(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ListItem requires GTK >= 4.12");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_list_item_set_accessible_description(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_list_item_set_accessible_description(GtkListItem_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_list_item_set_accessible_description(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ListItem requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_list_item_get_selected(value self)
{
CAMLparam1(self);

gboolean result = gtk_list_item_get_selected(GtkListItem_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_list_item_get_selectable(value self)
{
CAMLparam1(self);

gboolean result = gtk_list_item_get_selectable(GtkListItem_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_list_item_get_position(value self)
{
CAMLparam1(self);

guint result = gtk_list_item_get_position(GtkListItem_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_list_item_get_item(value self)
{
CAMLparam1(self);

gpointer result = gtk_list_item_get_item(GtkListItem_val(self));
CAMLreturn(ml_gobject_val_of_ext(result));
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_list_item_get_focusable(value self)
{
CAMLparam1(self);

gboolean result = gtk_list_item_get_focusable(GtkListItem_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gtk_list_item_get_focusable(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ListItem requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_list_item_get_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_list_item_get_child(GtkListItem_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_list_item_get_activatable(value self)
{
CAMLparam1(self);

gboolean result = gtk_list_item_get_activatable(GtkListItem_val(self));
CAMLreturn(Val_bool(result));
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_list_item_get_accessible_label(value self)
{
CAMLparam1(self);

const char* result = gtk_list_item_get_accessible_label(GtkListItem_val(self));
CAMLreturn(caml_copy_string(result));
}

#else

CAMLexport CAMLprim value ml_gtk_list_item_get_accessible_label(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ListItem requires GTK >= 4.12");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_list_item_get_accessible_description(value self)
{
CAMLparam1(self);

const char* result = gtk_list_item_get_accessible_description(GtkListItem_val(self));
CAMLreturn(caml_copy_string(result));
}

#else

CAMLexport CAMLprim value ml_gtk_list_item_get_accessible_description(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ListItem requires GTK >= 4.12");
return Val_unit;
}
#endif


CAMLprim value ml_gtk_list_item_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_list_item_get_type()));
}
