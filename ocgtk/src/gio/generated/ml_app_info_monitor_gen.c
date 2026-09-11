/* GENERATED CODE - DO NOT EDIT */
/* C bindings for AppInfoMonitor */

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

#if GLIB_CHECK_VERSION(2,40,0)



CAMLprim value ml_gio_app_info_monitor_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_app_info_monitor_get_type()));
}

#else


#endif
