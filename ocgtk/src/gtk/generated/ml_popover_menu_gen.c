/* GENERATED CODE - DO NOT EDIT */
/* C bindings for PopoverMenu */

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


CAMLexport CAMLprim value ml_gtk_popover_menu_new_from_model(value arg1)
{
CAMLparam1(arg1);

GtkPopoverMenu *obj = gtk_popover_menu_new_from_model(Option_val(arg1, GMenuModel_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkPopoverMenu(obj));
}
CAMLexport CAMLprim value ml_gtk_popover_menu_new_from_model_full(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GtkPopoverMenu *obj = gtk_popover_menu_new_from_model_full(GMenuModel_val(arg1), GtkPopoverMenuFlags_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkPopoverMenu(obj));
}
CAMLexport CAMLprim value ml_gtk_popover_menu_set_menu_model(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_popover_menu_set_menu_model(GtkPopoverMenu_val(self), Option_val(arg1, GMenuModel_val, NULL));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gtk_popover_menu_set_flags(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_popover_menu_set_flags(GtkPopoverMenu_val(self), GtkPopoverMenuFlags_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_popover_menu_set_flags(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("PopoverMenu requires GTK >= 4.14");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_popover_menu_remove_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_popover_menu_remove_child(GtkPopoverMenu_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_popover_menu_get_menu_model(value self)
{
CAMLparam1(self);

GMenuModel* result = gtk_popover_menu_get_menu_model(GtkPopoverMenu_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GMenuModel));
}

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gtk_popover_menu_get_flags(value self)
{
CAMLparam1(self);

GtkPopoverMenuFlags result = gtk_popover_menu_get_flags(GtkPopoverMenu_val(self));
CAMLreturn(Val_GtkPopoverMenuFlags(result));
}

#else

CAMLexport CAMLprim value ml_gtk_popover_menu_get_flags(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PopoverMenu requires GTK >= 4.14");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_popover_menu_add_child(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = gtk_popover_menu_add_child(GtkPopoverMenu_val(self), GtkWidget_val(arg1), String_val(arg2));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_popover_menu_get_visible_submenu(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkPopoverMenu *obj = (GtkPopoverMenu *)GtkPopoverMenu_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "visible-submenu");
if (pspec == NULL) caml_failwith("ml_gtk_popover_menu_get_visible_submenu: property 'visible-submenu' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "visible-submenu", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_popover_menu_set_visible_submenu(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkPopoverMenu *obj = (GtkPopoverMenu *)GtkPopoverMenu_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "visible-submenu");
if (pspec == NULL) caml_failwith("ml_gtk_popover_menu_set_visible_submenu: property 'visible-submenu' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "visible-submenu", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

GType gtk_popover_menu_get_type (void);


CAMLprim value ml_gtk_popover_menu_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_popover_menu_get_type()));
}
