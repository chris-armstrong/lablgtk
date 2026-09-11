/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Mount */

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


#if GLIB_CHECK_VERSION(2,20,0)

CAMLexport CAMLprim value ml_g_mount_unshadow(value self)
{
CAMLparam1(self);

g_mount_unshadow(GMount_val(self));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_mount_unshadow(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Mount requires GLib >= 2.20");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_mount_unmount_with_operation_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_mount_unmount_with_operation_finish(GMount_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_mount_unmount_with_operation_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Mount requires GLib >= 2.22");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_mount_unmount_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_mount_unmount_finish(GMount_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#if GLIB_CHECK_VERSION(2,20,0)

CAMLexport CAMLprim value ml_g_mount_shadow(value self)
{
CAMLparam1(self);

g_mount_shadow(GMount_val(self));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_mount_shadow(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Mount requires GLib >= 2.20");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_mount_remount_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_mount_remount_finish(GMount_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#if GLIB_CHECK_VERSION(2,20,0)

CAMLexport CAMLprim value ml_g_mount_is_shadowed(value self)
{
CAMLparam1(self);

gboolean result = g_mount_is_shadowed(GMount_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_mount_is_shadowed(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Mount requires GLib >= 2.20");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,18,0)

CAMLexport CAMLprim value ml_g_mount_guess_content_type_sync(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

gchar** result = g_mount_guess_content_type_sync(GMount_val(self), Bool_val(arg1), Option_val(arg2, GCancellable_val, NULL), &error);
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
if (error == NULL) CAMLreturn(Res_Ok(ml_result)); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_mount_guess_content_type_sync(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Mount requires GLib >= 2.18");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,18,0)

CAMLexport CAMLprim value ml_g_mount_guess_content_type_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gchar** result = g_mount_guess_content_type_finish(GMount_val(self), GAsyncResult_val(arg1), &error);
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
if (error == NULL) CAMLreturn(Res_Ok(ml_result)); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_mount_guess_content_type_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Mount requires GLib >= 2.18");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_mount_get_volume(value self)
{
CAMLparam1(self);

GVolume* result = g_mount_get_volume(GMount_val(self));
CAMLreturn(Val_option(result, Val_GVolume));
}

CAMLexport CAMLprim value ml_g_mount_get_uuid(value self)
{
CAMLparam1(self);

char* result = g_mount_get_uuid(GMount_val(self));
CAMLreturn(Val_option_string(result));
}

#if GLIB_CHECK_VERSION(2,34,0)

CAMLexport CAMLprim value ml_g_mount_get_symbolic_icon(value self)
{
CAMLparam1(self);

GIcon* result = g_mount_get_symbolic_icon(GMount_val(self));
CAMLreturn(Val_GIcon(result));
}

#else

CAMLexport CAMLprim value ml_g_mount_get_symbolic_icon(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Mount requires GLib >= 2.34");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_mount_get_sort_key(value self)
{
CAMLparam1(self);

const gchar* result = g_mount_get_sort_key(GMount_val(self));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_g_mount_get_sort_key(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Mount requires GLib >= 2.32");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_mount_get_root(value self)
{
CAMLparam1(self);

GFile* result = g_mount_get_root(GMount_val(self));
CAMLreturn(Val_GFile(result));
}

CAMLexport CAMLprim value ml_g_mount_get_name(value self)
{
CAMLparam1(self);

char* result = g_mount_get_name(GMount_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_g_mount_get_icon(value self)
{
CAMLparam1(self);

GIcon* result = g_mount_get_icon(GMount_val(self));
CAMLreturn(Val_GIcon(result));
}

CAMLexport CAMLprim value ml_g_mount_get_drive(value self)
{
CAMLparam1(self);

GDrive* result = g_mount_get_drive(GMount_val(self));
CAMLreturn(Val_option(result, Val_GDrive));
}

CAMLexport CAMLprim value ml_g_mount_get_default_location(value self)
{
CAMLparam1(self);

GFile* result = g_mount_get_default_location(GMount_val(self));
CAMLreturn(Val_GFile(result));
}

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_mount_eject_with_operation_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_mount_eject_with_operation_finish(GMount_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_mount_eject_with_operation_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Mount requires GLib >= 2.22");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_mount_eject_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_mount_eject_finish(GMount_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_mount_can_unmount(value self)
{
CAMLparam1(self);

gboolean result = g_mount_can_unmount(GMount_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_mount_can_eject(value self)
{
CAMLparam1(self);

gboolean result = g_mount_can_eject(GMount_val(self));
CAMLreturn(Val_bool(result));
}
CAMLexport CAMLprim value ml_gio_mount_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_MOUNT)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GMount");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GMount((GMount*)gobj));
}


CAMLprim value ml_gio_mount_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_mount_get_type()));
}
