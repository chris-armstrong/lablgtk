/* GENERATED CODE - DO NOT EDIT */
/* C bindings for MenuLinkIter */

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


CAMLexport CAMLprim value ml_g_menu_link_iter_next(value self)
{
CAMLparam1(self);

gboolean result = g_menu_link_iter_next(GMenuLinkIter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_menu_link_iter_get_value(value self)
{
CAMLparam1(self);

GMenuModel* result = g_menu_link_iter_get_value(GMenuLinkIter_val(self));
CAMLreturn(Val_GMenuModel(result));
}

CAMLexport CAMLprim value ml_g_menu_link_iter_get_name(value self)
{
CAMLparam1(self);

const gchar* result = g_menu_link_iter_get_name(GMenuLinkIter_val(self));
CAMLreturn(caml_copy_string(result));
}


CAMLprim value ml_gio_menu_link_iter_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_menu_link_iter_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_menu_link_iter_get_name(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MenuLinkIter requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_link_iter_get_value(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MenuLinkIter requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_menu_link_iter_next(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MenuLinkIter requires GLib >= 2.32");
return Val_unit;
}


#endif
