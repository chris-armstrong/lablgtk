/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Emblem */

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


#if GLIB_CHECK_VERSION(2,18,0)

CAMLexport CAMLprim value ml_g_emblem_new(value arg1)
{
CAMLparam1(arg1);

GEmblem *obj = g_emblem_new(GIcon_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GEmblem(obj));
}
#else

CAMLexport CAMLprim value ml_g_emblem_new(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("Emblem requires GLib >= 2.18");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,18,0)

CAMLexport CAMLprim value ml_g_emblem_new_with_origin(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GEmblem *obj = g_emblem_new_with_origin(GIcon_val(arg1), GioEmblemOrigin_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GEmblem(obj));
}
#else

CAMLexport CAMLprim value ml_g_emblem_new_with_origin(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("Emblem requires GLib >= 2.18");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,18,0)

CAMLexport CAMLprim value ml_g_emblem_get_origin(value self)
{
CAMLparam1(self);

GEmblemOrigin result = g_emblem_get_origin(GEmblem_val(self));
CAMLreturn(Val_GioEmblemOrigin(result));
}

#else

CAMLexport CAMLprim value ml_g_emblem_get_origin(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Emblem requires GLib >= 2.18");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,18,0)

CAMLexport CAMLprim value ml_g_emblem_get_icon(value self)
{
CAMLparam1(self);

GIcon* result = g_emblem_get_icon(GEmblem_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GIcon(result));
}

#else

CAMLexport CAMLprim value ml_g_emblem_get_icon(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Emblem requires GLib >= 2.18");
return Val_unit;
}
#endif

GType g_emblem_get_type (void);


CAMLprim value ml_gio_emblem_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_emblem_get_type()));
}
