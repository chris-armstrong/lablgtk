/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Menu */

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


CAMLexport CAMLprim value ml_g_menu_new(value unit)
{
CAMLparam1(unit);

GMenu *obj = g_menu_new();
/* g_menu_new is transfer-full and GMenu is NOT
 * GInitiallyUnowned -- the return is already a single owned, non-floating
 * reference, so the generator boilerplate g_object_ref_sink here added a
 * second reference nothing ever dropped (bounded leak per attach). Same
 * class as the ml_gdk_memory_texture_new fix in this commit. A companion
 * PR gates ref_sink on the constructor return transfer in gir_gen; once
 * that lands, regeneration will emit this stub as it stands here. */

CAMLreturn(Val_GMenu(obj));
}
#if GLIB_CHECK_VERSION(2,38,0)

CAMLexport CAMLprim value ml_g_menu_remove_all(value self)
{
CAMLparam1(self);

g_menu_remove_all(GMenu_val(self));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_menu_remove_all(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Menu requires GLib >= 2.38");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_menu_remove(value self, value arg1)
{
CAMLparam2(self, arg1);

g_menu_remove(GMenu_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_menu_prepend_submenu(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_menu_prepend_submenu(GMenu_val(self), String_option_val(arg1), GMenuModel_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_menu_prepend_section(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_menu_prepend_section(GMenu_val(self), String_option_val(arg1), GMenuModel_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_menu_prepend_item(value self, value arg1)
{
CAMLparam2(self, arg1);

g_menu_prepend_item(GMenu_val(self), GMenuItem_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_menu_prepend(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_menu_prepend(GMenu_val(self), String_option_val(arg1), String_option_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_menu_insert_submenu(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

g_menu_insert_submenu(GMenu_val(self), Int_val(arg1), String_option_val(arg2), GMenuModel_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_menu_insert_section(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

g_menu_insert_section(GMenu_val(self), Int_val(arg1), String_option_val(arg2), GMenuModel_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_menu_insert_item(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_menu_insert_item(GMenu_val(self), Int_val(arg1), GMenuItem_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_menu_insert(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

g_menu_insert(GMenu_val(self), Int_val(arg1), String_option_val(arg2), String_option_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_menu_freeze(value self)
{
CAMLparam1(self);

g_menu_freeze(GMenu_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_menu_append_submenu(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_menu_append_submenu(GMenu_val(self), String_option_val(arg1), GMenuModel_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_menu_append_section(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_menu_append_section(GMenu_val(self), String_option_val(arg1), GMenuModel_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_menu_append_item(value self, value arg1)
{
CAMLparam2(self, arg1);

g_menu_append_item(GMenu_val(self), GMenuItem_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_menu_append(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_menu_append(GMenu_val(self), String_option_val(arg1), String_option_val(arg2));
CAMLreturn(Val_unit);
}

#else


CAMLexport CAMLprim value ml_g_menu_new(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("Menu requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_append(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Menu requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_append_item(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Menu requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_append_section(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Menu requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_append_submenu(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Menu requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_freeze(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Menu requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_insert(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Menu requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_insert_item(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Menu requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_insert_section(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Menu requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_insert_submenu(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Menu requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_prepend(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Menu requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_prepend_item(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Menu requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_prepend_section(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Menu requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_prepend_submenu(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Menu requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_remove(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Menu requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_remove_all(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Menu requires GLib >= 2.32");
return Val_unit;
}


#endif
