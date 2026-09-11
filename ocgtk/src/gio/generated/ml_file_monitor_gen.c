/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FileMonitor */

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


CAMLexport CAMLprim value ml_g_file_monitor_set_rate_limit(value self, value arg1)
{
CAMLparam2(self, arg1);

g_file_monitor_set_rate_limit(GFileMonitor_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_file_monitor_is_cancelled(value self)
{
CAMLparam1(self);

gboolean result = g_file_monitor_is_cancelled(GFileMonitor_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_file_monitor_emit_event(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

g_file_monitor_emit_event(GFileMonitor_val(self), GFile_val(arg1), Option_val(arg2, GFile_val, NULL), GioFileMonitorEvent_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_file_monitor_cancel(value self)
{
CAMLparam1(self);

gboolean result = g_file_monitor_cancel(GFileMonitor_val(self));
CAMLreturn(Val_bool(result));
}


CAMLprim value ml_gio_file_monitor_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_file_monitor_get_type()));
}
