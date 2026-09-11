/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Seekable */

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


CAMLexport CAMLprim value ml_g_seekable_truncate(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

gboolean result = g_seekable_truncate(GSeekable_val(self), Int64_val(arg1), Option_val(arg2, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_seekable_tell(value self)
{
CAMLparam1(self);

goffset result = g_seekable_tell(GSeekable_val(self));
CAMLreturn(caml_copy_int64(result));
}

CAMLexport CAMLprim value ml_g_seekable_can_truncate(value self)
{
CAMLparam1(self);

gboolean result = g_seekable_can_truncate(GSeekable_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_seekable_can_seek(value self)
{
CAMLparam1(self);

gboolean result = g_seekable_can_seek(GSeekable_val(self));
CAMLreturn(Val_bool(result));
}
CAMLexport CAMLprim value ml_gio_seekable_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_SEEKABLE)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GSeekable");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GSeekable((GSeekable*)gobj));
}


CAMLprim value ml_gio_seekable_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_seekable_get_type()));
}
