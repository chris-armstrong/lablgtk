/* GENERATED CODE - DO NOT EDIT */
/* C bindings for VolumeMonitor */

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


CAMLexport CAMLprim value ml_g_volume_monitor_get_volumes(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = g_volume_monitor_get_volumes(GVolumeMonitor_val(self));
Val_GList_with(c_result, result, item, cell, Val_GVolume((gpointer)_tmp->data));
    g_list_free(c_result);
    CAMLreturn(result);
}

CAMLexport CAMLprim value ml_g_volume_monitor_get_volume_for_uuid(value self, value arg1)
{
CAMLparam2(self, arg1);

GVolume* result = g_volume_monitor_get_volume_for_uuid(GVolumeMonitor_val(self), String_val(arg1));
CAMLreturn(Val_option(result, Val_GVolume));
}

CAMLexport CAMLprim value ml_g_volume_monitor_get_mounts(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = g_volume_monitor_get_mounts(GVolumeMonitor_val(self));
Val_GList_with(c_result, result, item, cell, Val_GMount((gpointer)_tmp->data));
    g_list_free(c_result);
    CAMLreturn(result);
}

CAMLexport CAMLprim value ml_g_volume_monitor_get_mount_for_uuid(value self, value arg1)
{
CAMLparam2(self, arg1);

GMount* result = g_volume_monitor_get_mount_for_uuid(GVolumeMonitor_val(self), String_val(arg1));
CAMLreturn(Val_option(result, Val_GMount));
}

CAMLexport CAMLprim value ml_g_volume_monitor_get_connected_drives(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = g_volume_monitor_get_connected_drives(GVolumeMonitor_val(self));
Val_GList_with(c_result, result, item, cell, Val_GDrive((gpointer)_tmp->data));
    g_list_free(c_result);
    CAMLreturn(result);
}

GType g_volume_monitor_get_type (void);


CAMLprim value ml_gio_volume_monitor_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_volume_monitor_get_type()));
}
