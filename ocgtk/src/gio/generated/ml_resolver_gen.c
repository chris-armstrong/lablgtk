/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Resolver */

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


#if GLIB_CHECK_VERSION(2,78,0)

CAMLexport CAMLprim value ml_g_resolver_set_timeout(value self, value arg1)
{
CAMLparam2(self, arg1);

g_resolver_set_timeout(GResolver_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_resolver_set_timeout(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Resolver requires GLib >= 2.78");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_resolver_set_default(value self)
{
CAMLparam1(self);

g_resolver_set_default(GResolver_val(self));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_resolver_set_default(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Resolver requires GLib >= 2.22");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_resolver_lookup_service_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

CAMLlocal3(result, item, cell);
    GList* c_result = g_resolver_lookup_service_finish(GResolver_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) {
        Val_GList_with(c_result, result, item, cell, Val_GSrvTarget((gpointer)_tmp->data));
    g_list_free(c_result);
        CAMLreturn(Res_Ok(result));
    } else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_resolver_lookup_service_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Resolver requires GLib >= 2.22");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_resolver_lookup_service(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
GError *error = NULL;

CAMLlocal3(result, item, cell);
    GList* c_result = g_resolver_lookup_service(GResolver_val(self), String_val(arg1), String_val(arg2), String_val(arg3), Option_val(arg4, GCancellable_val, NULL), &error);
if (error == NULL) {
        Val_GList_with(c_result, result, item, cell, Val_GSrvTarget((gpointer)_tmp->data));
    g_list_free(c_result);
        CAMLreturn(Res_Ok(result));
    } else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_resolver_lookup_service(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("Resolver requires GLib >= 2.22");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,34,0)

CAMLexport CAMLprim value ml_g_resolver_lookup_records_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

CAMLlocal3(result, item, cell);
    GList* c_result = g_resolver_lookup_records_finish(GResolver_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) {
        Val_GList_with(c_result, result, item, cell, Val_GVariant((gpointer)_tmp->data));
    g_list_free(c_result);
        CAMLreturn(Res_Ok(result));
    } else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_resolver_lookup_records_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Resolver requires GLib >= 2.34");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,34,0)

CAMLexport CAMLprim value ml_g_resolver_lookup_records(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
GError *error = NULL;

CAMLlocal3(result, item, cell);
    GList* c_result = g_resolver_lookup_records(GResolver_val(self), String_val(arg1), GioResolverRecordType_val(arg2), Option_val(arg3, GCancellable_val, NULL), &error);
if (error == NULL) {
        Val_GList_with(c_result, result, item, cell, Val_GVariant((gpointer)_tmp->data));
    g_list_free(c_result);
        CAMLreturn(Res_Ok(result));
    } else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_resolver_lookup_records(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Resolver requires GLib >= 2.34");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,60,0)

CAMLexport CAMLprim value ml_g_resolver_lookup_by_name_with_flags_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

CAMLlocal3(result, item, cell);
    GList* c_result = g_resolver_lookup_by_name_with_flags_finish(GResolver_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) {
        Val_GList_with(c_result, result, item, cell, Val_GInetAddress((gpointer)_tmp->data));
    g_list_free(c_result);
        CAMLreturn(Res_Ok(result));
    } else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_resolver_lookup_by_name_with_flags_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Resolver requires GLib >= 2.60");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,60,0)

CAMLexport CAMLprim value ml_g_resolver_lookup_by_name_with_flags(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
GError *error = NULL;

CAMLlocal3(result, item, cell);
    GList* c_result = g_resolver_lookup_by_name_with_flags(GResolver_val(self), String_val(arg1), GioResolverNameLookupFlags_val(arg2), Option_val(arg3, GCancellable_val, NULL), &error);
if (error == NULL) {
        Val_GList_with(c_result, result, item, cell, Val_GInetAddress((gpointer)_tmp->data));
    g_list_free(c_result);
        CAMLreturn(Res_Ok(result));
    } else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_resolver_lookup_by_name_with_flags(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Resolver requires GLib >= 2.60");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_resolver_lookup_by_name_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

CAMLlocal3(result, item, cell);
    GList* c_result = g_resolver_lookup_by_name_finish(GResolver_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) {
        Val_GList_with(c_result, result, item, cell, Val_GInetAddress((gpointer)_tmp->data));
    g_list_free(c_result);
        CAMLreturn(Res_Ok(result));
    } else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_resolver_lookup_by_name_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Resolver requires GLib >= 2.22");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_resolver_lookup_by_name(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

CAMLlocal3(result, item, cell);
    GList* c_result = g_resolver_lookup_by_name(GResolver_val(self), String_val(arg1), Option_val(arg2, GCancellable_val, NULL), &error);
if (error == NULL) {
        Val_GList_with(c_result, result, item, cell, Val_GInetAddress((gpointer)_tmp->data));
    g_list_free(c_result);
        CAMLreturn(Res_Ok(result));
    } else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_resolver_lookup_by_name(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Resolver requires GLib >= 2.22");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_resolver_lookup_by_address_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gchar* result = g_resolver_lookup_by_address_finish(GResolver_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(caml_copy_string(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_resolver_lookup_by_address_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Resolver requires GLib >= 2.22");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,22,0)

CAMLexport CAMLprim value ml_g_resolver_lookup_by_address(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

gchar* result = g_resolver_lookup_by_address(GResolver_val(self), GInetAddress_val(arg1), Option_val(arg2, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(caml_copy_string(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_resolver_lookup_by_address(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Resolver requires GLib >= 2.22");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,78,0)

CAMLexport CAMLprim value ml_g_resolver_get_timeout(value self)
{
CAMLparam1(self);

unsigned result = g_resolver_get_timeout(GResolver_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_g_resolver_get_timeout(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Resolver requires GLib >= 2.78");
return Val_unit;
}
#endif


CAMLprim value ml_gio_resolver_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_resolver_get_type()));
}
