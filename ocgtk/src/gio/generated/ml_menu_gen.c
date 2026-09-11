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
if (obj) g_object_ref_sink(obj);

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

GType g_menu_get_type (void);


CAMLprim value ml_gio_menu_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_menu_get_type()));
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
