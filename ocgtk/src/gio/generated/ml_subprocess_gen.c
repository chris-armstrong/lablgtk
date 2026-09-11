/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Subprocess */

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


CAMLexport CAMLprim value ml_g_subprocess_newv(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
    int arg1_length = Wosize_val(arg1);
    const char** c_arg1 = (const char**)g_malloc(sizeof(const char*) * (arg1_length + 1));
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = String_val(Field(arg1, i));
    }
    c_arg1[arg1_length] = NULL;
GError *error = NULL;
    
GSubprocess *obj = g_subprocess_newv(c_arg1, GioSubprocessFlags_val(arg2), &error);
if (obj) g_object_ref_sink(obj);

    g_free(c_arg1);
if (error == NULL) CAMLreturn(Res_Ok(Val_GSubprocess(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
CAMLexport CAMLprim value ml_g_subprocess_wait_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_subprocess_wait_finish(GSubprocess_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_subprocess_wait_check_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_subprocess_wait_check_finish(GSubprocess_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_subprocess_wait_check(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_subprocess_wait_check(GSubprocess_val(self), Option_val(arg1, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_subprocess_wait(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_subprocess_wait(GSubprocess_val(self), Option_val(arg1, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#if !(defined(_WIN32))

CAMLexport CAMLprim value ml_g_subprocess_send_signal(value self, value arg1)
{
CAMLparam2(self, arg1);

g_subprocess_send_signal(GSubprocess_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_subprocess_send_signal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Subprocess is only available on non-windows");
return Val_unit;
}

#endif /* not windows */

CAMLexport CAMLprim value ml_g_subprocess_get_term_sig(value self)
{
CAMLparam1(self);

gint result = g_subprocess_get_term_sig(GSubprocess_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_g_subprocess_get_successful(value self)
{
CAMLparam1(self);

gboolean result = g_subprocess_get_successful(GSubprocess_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_subprocess_get_stdout_pipe(value self)
{
CAMLparam1(self);

GInputStream* result = g_subprocess_get_stdout_pipe(GSubprocess_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GInputStream));
}

CAMLexport CAMLprim value ml_g_subprocess_get_stdin_pipe(value self)
{
CAMLparam1(self);

GOutputStream* result = g_subprocess_get_stdin_pipe(GSubprocess_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GOutputStream));
}

CAMLexport CAMLprim value ml_g_subprocess_get_stderr_pipe(value self)
{
CAMLparam1(self);

GInputStream* result = g_subprocess_get_stderr_pipe(GSubprocess_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GInputStream));
}

CAMLexport CAMLprim value ml_g_subprocess_get_status(value self)
{
CAMLparam1(self);

gint result = g_subprocess_get_status(GSubprocess_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_g_subprocess_get_if_signaled(value self)
{
CAMLparam1(self);

gboolean result = g_subprocess_get_if_signaled(GSubprocess_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_subprocess_get_if_exited(value self)
{
CAMLparam1(self);

gboolean result = g_subprocess_get_if_exited(GSubprocess_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_g_subprocess_get_identifier(value self)
{
CAMLparam1(self);

const gchar* result = g_subprocess_get_identifier(GSubprocess_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_g_subprocess_get_exit_status(value self)
{
CAMLparam1(self);

gint result = g_subprocess_get_exit_status(GSubprocess_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_g_subprocess_force_exit(value self)
{
CAMLparam1(self);

g_subprocess_force_exit(GSubprocess_val(self));
CAMLreturn(Val_unit);
}

GType g_subprocess_get_type (void);


CAMLprim value ml_gio_subprocess_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_subprocess_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_subprocess_newv(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("Subprocess requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_force_exit(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Subprocess requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_get_exit_status(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Subprocess requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_get_identifier(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Subprocess requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_get_if_exited(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Subprocess requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_get_if_signaled(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Subprocess requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_get_status(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Subprocess requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_get_stderr_pipe(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Subprocess requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_get_stdin_pipe(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Subprocess requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_get_stdout_pipe(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Subprocess requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_get_successful(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Subprocess requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_get_term_sig(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Subprocess requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_send_signal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Subprocess requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_wait(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Subprocess requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_wait_check(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Subprocess requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_wait_check_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Subprocess requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_wait_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Subprocess requires GLib >= 2.40");
return Val_unit;
}


#endif
