/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Volume */

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


CAMLexport CAMLprim value ml_g_volume_should_automount(value self)
{
CAMLparam1(self);

gboolean result = g_volume_should_automount(GVolume_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_volume_mount_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_volume_mount_finish(GVolume_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_volume_get_uuid(value self)
{
CAMLparam1(self);

char* result = g_volume_get_uuid(GVolume_val(self));
CAMLreturn(Val_option_string(result));
}

#if GLIB_CHECK_VERSION(2,34,0)

CAMLexport CAMLprim value ml_g_volume_get_symbolic_icon(value self)
{
CAMLparam1(self);

GIcon* result = g_volume_get_symbolic_icon(GVolume_val(self));
CAMLreturn(Val_GIcon(result));
}

#else

CAMLexport CAMLprim value ml_g_volume_get_symbolic_icon(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Volume requires GLib >= 2.34");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_volume_get_sort_key(value self)
{
CAMLparam1(self);

const gchar* result = g_volume_get_sort_key(GVolume_val(self));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_g_volume_get_sort_key(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Volume requires GLib >= 2.32");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_volume_get_name(value self)
{
CAMLparam1(self);

char* result = g_volume_get_name(GVolume_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_g_volume_get_mount(value self)
{
CAMLparam1(self);

GMount* result = g_volume_get_mount(GVolume_val(self));
CAMLreturn(Val_option(result, Val_GMount));
}

CAMLexport CAMLprim value ml_g_volume_get_identifier(value self, value arg1)
{
CAMLparam2(self, arg1);

char* result = g_volume_get_identifier(GVolume_val(self), String_val(arg1));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_g_volume_get_icon(value self)
{
CAMLparam1(self);

GIcon* result = g_volume_get_icon(GVolume_val(self));
CAMLreturn(Val_GIcon(result));
}

CAMLexport CAMLprim value ml_g_volume_get_drive(value self)
{
CAMLparam1(self);

GDrive* result = g_volume_get_drive(GVolume_val(self));
CAMLreturn(Val_option(result, Val_GDrive));
}

#if GLIB_CHECK_VERSION(2,18,0)

CAMLexport CAMLprim value ml_g_volume_get_activation_root(value self)
{
CAMLparam1(self);

GFile* result = g_volume_get_activation_root(GVolume_val(self));
CAMLreturn(Val_option(result, Val_GFile));
}

#else

CAMLexport CAMLprim value ml_g_volume_get_activation_root(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Volume requires GLib >= 2.18");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_volume_enumerate_identifiers(value self)
{
CAMLparam1(self);

char** result = g_volume_enumerate_identifiers(GVolume_val(self));
    int result_length = 0;
    while (result[result_length] != NULL) result_length++;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, caml_copy_string(result[i]));
    }
    for (int i = 0; i < result_length; i++) {
      g_free((gpointer)result[i]);
    }
    g_free(result);
CAMLreturn(ml_result);
}

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_volume_eject_with_operation_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_volume_eject_with_operation_finish(GVolume_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_volume_eject_with_operation_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Volume requires GLib >= 2.22");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_volume_eject_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_volume_eject_finish(GVolume_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_volume_can_mount(value self)
{
CAMLparam1(self);

gboolean result = g_volume_can_mount(GVolume_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_volume_can_eject(value self)
{
CAMLparam1(self);

gboolean result = g_volume_can_eject(GVolume_val(self));
CAMLreturn(Val_bool(result));
}
CAMLexport CAMLprim value ml_gio_volume_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_VOLUME)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GVolume");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GVolume((GVolume*)gobj));
}

GType g_volume_get_type (void);


CAMLprim value ml_gio_volume_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_volume_get_type()));
}
