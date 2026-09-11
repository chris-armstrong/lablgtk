/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Drive */

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


#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_drive_stop_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_drive_stop_finish(GDrive_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_drive_stop_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Drive requires GLib >= 2.22");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_drive_start_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_drive_start_finish(GDrive_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_drive_start_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Drive requires GLib >= 2.22");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_drive_poll_for_media_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_drive_poll_for_media_finish(GDrive_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#if GLIB_CHECK_VERSION(2,50,0)

CAMLexport CAMLprim value ml_g_drive_is_removable(value self)
{
CAMLparam1(self);

gboolean result = g_drive_is_removable(GDrive_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_drive_is_removable(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Drive requires GLib >= 2.50");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_drive_is_media_removable(value self)
{
CAMLparam1(self);

gboolean result = g_drive_is_media_removable(GDrive_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_drive_is_media_check_automatic(value self)
{
CAMLparam1(self);

gboolean result = g_drive_is_media_check_automatic(GDrive_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_drive_has_volumes(value self)
{
CAMLparam1(self);

gboolean result = g_drive_has_volumes(GDrive_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_drive_has_media(value self)
{
CAMLparam1(self);

gboolean result = g_drive_has_media(GDrive_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_drive_get_volumes(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = g_drive_get_volumes(GDrive_val(self));
Val_GList_with(c_result, result, item, cell, Val_GVolume((gpointer)_tmp->data));
    g_list_free(c_result);
    CAMLreturn(result);
}

#if GLIB_CHECK_VERSION(2,34,0)

CAMLexport CAMLprim value ml_g_drive_get_symbolic_icon(value self)
{
CAMLparam1(self);

GIcon* result = g_drive_get_symbolic_icon(GDrive_val(self));
CAMLreturn(Val_GIcon(result));
}

#else

CAMLexport CAMLprim value ml_g_drive_get_symbolic_icon(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Drive requires GLib >= 2.34");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_drive_get_start_stop_type(value self)
{
CAMLparam1(self);

GDriveStartStopType result = g_drive_get_start_stop_type(GDrive_val(self));
CAMLreturn(Val_GioDriveStartStopType(result));
}

#else

CAMLexport CAMLprim value ml_g_drive_get_start_stop_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Drive requires GLib >= 2.22");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,32,0)

CAMLexport CAMLprim value ml_g_drive_get_sort_key(value self)
{
CAMLparam1(self);

const gchar* result = g_drive_get_sort_key(GDrive_val(self));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_g_drive_get_sort_key(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Drive requires GLib >= 2.32");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_drive_get_name(value self)
{
CAMLparam1(self);

char* result = g_drive_get_name(GDrive_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_g_drive_get_identifier(value self, value arg1)
{
CAMLparam2(self, arg1);

char* result = g_drive_get_identifier(GDrive_val(self), String_val(arg1));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_g_drive_get_icon(value self)
{
CAMLparam1(self);

GIcon* result = g_drive_get_icon(GDrive_val(self));
CAMLreturn(Val_GIcon(result));
}

CAMLexport CAMLprim value ml_g_drive_enumerate_identifiers(value self)
{
CAMLparam1(self);

char** result = g_drive_enumerate_identifiers(GDrive_val(self));
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

CAMLexport CAMLprim value ml_g_drive_eject_with_operation_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_drive_eject_with_operation_finish(GDrive_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_drive_eject_with_operation_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Drive requires GLib >= 2.22");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_drive_eject_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_drive_eject_finish(GDrive_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_drive_can_stop(value self)
{
CAMLparam1(self);

gboolean result = g_drive_can_stop(GDrive_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_drive_can_stop(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Drive requires GLib >= 2.22");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_drive_can_start_degraded(value self)
{
CAMLparam1(self);

gboolean result = g_drive_can_start_degraded(GDrive_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_drive_can_start_degraded(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Drive requires GLib >= 2.22");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_drive_can_start(value self)
{
CAMLparam1(self);

gboolean result = g_drive_can_start(GDrive_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_drive_can_start(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Drive requires GLib >= 2.22");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_drive_can_poll_for_media(value self)
{
CAMLparam1(self);

gboolean result = g_drive_can_poll_for_media(GDrive_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_drive_can_eject(value self)
{
CAMLparam1(self);

gboolean result = g_drive_can_eject(GDrive_val(self));
CAMLreturn(Val_bool(result));
}
CAMLexport CAMLprim value ml_gio_drive_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_DRIVE)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GDrive");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GDrive((GDrive*)gobj));
}

GType g_drive_get_type (void);


CAMLprim value ml_gio_drive_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_drive_get_type()));
}
