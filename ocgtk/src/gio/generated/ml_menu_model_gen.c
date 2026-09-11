/* GENERATED CODE - DO NOT EDIT */
/* C bindings for MenuModel */

#include <gio/gio.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <gio/gio.h>
/* Include library-specific type conversions and forward declarations */
#include "gio_decls.h"

#if GLIB_CHECK_VERSION(2,32,0)


CAMLexport CAMLprim value ml_g_menu_model_iterate_item_links(value self, value arg1)
{
CAMLparam2(self, arg1);

GMenuLinkIter* result = g_menu_model_iterate_item_links(GMenuModel_val(self), Int_val(arg1));
CAMLreturn(Val_GMenuLinkIter(result));
}

CAMLexport CAMLprim value ml_g_menu_model_iterate_item_attributes(value self, value arg1)
{
CAMLparam2(self, arg1);

GMenuAttributeIter* result = g_menu_model_iterate_item_attributes(GMenuModel_val(self), Int_val(arg1));
CAMLreturn(Val_GMenuAttributeIter(result));
}

CAMLexport CAMLprim value ml_g_menu_model_items_changed(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

g_menu_model_items_changed(GMenuModel_val(self), Int_val(arg1), Int_val(arg2), Int_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_menu_model_is_mutable(value self)
{
CAMLparam1(self);

gboolean result = g_menu_model_is_mutable(GMenuModel_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_menu_model_get_n_items(value self)
{
CAMLparam1(self);

gint result = g_menu_model_get_n_items(GMenuModel_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_g_menu_model_get_item_link(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

GMenuModel* result = g_menu_model_get_item_link(GMenuModel_val(self), Int_val(arg1), String_val(arg2));
CAMLreturn(Val_option(result, Val_GMenuModel));
}

CAMLexport CAMLprim value ml_g_menu_model_get_item_attribute_value(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

GVariant* result = g_menu_model_get_item_attribute_value(GMenuModel_val(self), Int_val(arg1), String_val(arg2), Option_val(arg3, GVariantType_val, NULL));
CAMLreturn(Val_option(result, Val_GVariant));
}

GType g_menu_model_get_type (void);


CAMLprim value ml_gio_menu_model_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_menu_model_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_menu_model_get_item_attribute_value(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("MenuModel requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_model_get_item_link(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("MenuModel requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_model_get_n_items(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MenuModel requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_model_is_mutable(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MenuModel requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_model_items_changed(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("MenuModel requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_model_iterate_item_attributes(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MenuModel requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_model_iterate_item_links(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MenuModel requires GLib >= 2.32");
return Val_unit;
}


#endif
