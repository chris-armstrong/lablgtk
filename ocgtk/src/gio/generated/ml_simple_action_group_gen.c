/* GENERATED CODE - DO NOT EDIT */
/* C bindings for SimpleActionGroup */

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

#if GLIB_CHECK_VERSION(2,28,0)


CAMLexport CAMLprim value ml_g_simple_action_group_new(value unit)
{
CAMLparam1(unit);

GSimpleActionGroup *obj = g_simple_action_group_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GSimpleActionGroup(obj));
}
CAMLexport CAMLprim value ml_g_simple_action_group_remove(value self, value arg1)
{
CAMLparam2(self, arg1);

g_simple_action_group_remove(GSimpleActionGroup_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_simple_action_group_lookup(value self, value arg1)
{
CAMLparam2(self, arg1);

GAction* result = g_simple_action_group_lookup(GSimpleActionGroup_val(self), String_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GAction(result));
}

CAMLexport CAMLprim value ml_g_simple_action_group_insert(value self, value arg1)
{
CAMLparam2(self, arg1);

g_simple_action_group_insert(GSimpleActionGroup_val(self), GAction_val(arg1));
CAMLreturn(Val_unit);
}

GType g_simple_action_group_get_type (void);


CAMLprim value ml_gio_simple_action_group_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_simple_action_group_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_simple_action_group_new(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("SimpleActionGroup requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_simple_action_group_insert(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SimpleActionGroup requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_simple_action_group_lookup(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SimpleActionGroup requires GLib >= 2.28");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_simple_action_group_remove(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SimpleActionGroup requires GLib >= 2.28");
return Val_unit;
}


#endif
