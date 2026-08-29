/* GENERATED CODE - DO NOT EDIT */
/* C bindings for MenuItem */

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


CAMLexport CAMLprim value ml_g_menu_item_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GMenuItem *obj = g_menu_item_new(String_option_val(arg1), String_option_val(arg2));
/* g_menu_item_new is transfer-full and GMenuItem is NOT
 * GInitiallyUnowned -- the return is already a single owned, non-floating
 * reference, so the generator boilerplate g_object_ref_sink here added a
 * second reference nothing ever dropped (bounded leak per attach). Same
 * class as the ml_gdk_memory_texture_new fix in this commit. A companion
 * PR gates ref_sink on the constructor return transfer in gir_gen; once
 * that lands, regeneration will emit this stub as it stands here. */

CAMLreturn(Val_GMenuItem(obj));
}
#if GLIB_CHECK_VERSION(2,34,0)

CAMLexport CAMLprim value ml_g_menu_item_new_from_model(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GMenuItem *obj = g_menu_item_new_from_model(GMenuModel_val(arg1), Int_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GMenuItem(obj));
}
#else

CAMLexport CAMLprim value ml_g_menu_item_new_from_model(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("MenuItem requires GLib >= 2.34");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_menu_item_new_section(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GMenuItem *obj = g_menu_item_new_section(String_option_val(arg1), GMenuModel_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GMenuItem(obj));
}
CAMLexport CAMLprim value ml_g_menu_item_new_submenu(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GMenuItem *obj = g_menu_item_new_submenu(String_option_val(arg1), GMenuModel_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GMenuItem(obj));
}
CAMLexport CAMLprim value ml_g_menu_item_set_submenu(value self, value arg1)
{
CAMLparam2(self, arg1);

g_menu_item_set_submenu(GMenuItem_val(self), Option_val(arg1, GMenuModel_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_menu_item_set_section(value self, value arg1)
{
CAMLparam2(self, arg1);

g_menu_item_set_section(GMenuItem_val(self), Option_val(arg1, GMenuModel_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_menu_item_set_link(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_menu_item_set_link(GMenuItem_val(self), String_val(arg1), Option_val(arg2, GMenuModel_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_menu_item_set_label(value self, value arg1)
{
CAMLparam2(self, arg1);

g_menu_item_set_label(GMenuItem_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

#if GLIB_CHECK_VERSION(2,38,0)

CAMLexport CAMLprim value ml_g_menu_item_set_icon(value self, value arg1)
{
CAMLparam2(self, arg1);

g_menu_item_set_icon(GMenuItem_val(self), GIcon_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_menu_item_set_icon(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MenuItem requires GLib >= 2.38");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_menu_item_set_detailed_action(value self, value arg1)
{
CAMLparam2(self, arg1);

g_menu_item_set_detailed_action(GMenuItem_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_menu_item_set_attribute_value(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_menu_item_set_attribute_value(GMenuItem_val(self), String_val(arg1), Option_val(arg2, GVariant_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_menu_item_set_action_and_target_value(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_menu_item_set_action_and_target_value(GMenuItem_val(self), String_option_val(arg1), Option_val(arg2, GVariant_val, NULL));
CAMLreturn(Val_unit);
}

#if GLIB_CHECK_VERSION(2,34,0)

CAMLexport CAMLprim value ml_g_menu_item_get_link(value self, value arg1)
{
CAMLparam2(self, arg1);

GMenuModel* result = g_menu_item_get_link(GMenuItem_val(self), String_val(arg1));
CAMLreturn(Val_option(result, Val_GMenuModel));
}

#else

CAMLexport CAMLprim value ml_g_menu_item_get_link(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MenuItem requires GLib >= 2.34");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,34,0)

CAMLexport CAMLprim value ml_g_menu_item_get_attribute_value(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

GVariant* result = g_menu_item_get_attribute_value(GMenuItem_val(self), String_val(arg1), Option_val(arg2, GVariantType_val, NULL));
CAMLreturn(Val_option(result, Val_GVariant));
}

#else

CAMLexport CAMLprim value ml_g_menu_item_get_attribute_value(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("MenuItem requires GLib >= 2.34");
return Val_unit;
}
#endif

#else


CAMLexport CAMLprim value ml_g_menu_item_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("MenuItem requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_item_new_from_model(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("MenuItem requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_item_new_section(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("MenuItem requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_item_new_submenu(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("MenuItem requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_item_get_attribute_value(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("MenuItem requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_item_get_link(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MenuItem requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_item_set_action_and_target_value(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("MenuItem requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_item_set_attribute_value(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("MenuItem requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_item_set_detailed_action(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MenuItem requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_item_set_icon(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MenuItem requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_item_set_label(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MenuItem requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_item_set_link(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("MenuItem requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_item_set_section(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MenuItem requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_item_set_submenu(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MenuItem requires GLib >= 2.32");
return Val_unit;
}


#endif
