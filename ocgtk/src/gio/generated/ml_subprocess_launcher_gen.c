/* GENERATED CODE - DO NOT EDIT */
/* C bindings for SubprocessLauncher */

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


CAMLexport CAMLprim value ml_g_subprocess_launcher_new(value arg1)
{
CAMLparam1(arg1);

GSubprocessLauncher *obj = g_subprocess_launcher_new(GioSubprocessFlags_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GSubprocessLauncher(obj));
}
CAMLexport CAMLprim value ml_g_subprocess_launcher_unsetenv(value self, value arg1)
{
CAMLparam2(self, arg1);

g_subprocess_launcher_unsetenv(GSubprocessLauncher_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

#if !(defined(_WIN32))

CAMLexport CAMLprim value ml_g_subprocess_launcher_take_stdout_fd(value self, value arg1)
{
CAMLparam2(self, arg1);

g_subprocess_launcher_take_stdout_fd(GSubprocessLauncher_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_subprocess_launcher_take_stdout_fd(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SubprocessLauncher is only available on non-windows");
return Val_unit;
}

#endif /* not windows */

#if !(defined(_WIN32))

CAMLexport CAMLprim value ml_g_subprocess_launcher_take_stdin_fd(value self, value arg1)
{
CAMLparam2(self, arg1);

g_subprocess_launcher_take_stdin_fd(GSubprocessLauncher_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_subprocess_launcher_take_stdin_fd(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SubprocessLauncher is only available on non-windows");
return Val_unit;
}

#endif /* not windows */

#if !(defined(_WIN32))

CAMLexport CAMLprim value ml_g_subprocess_launcher_take_stderr_fd(value self, value arg1)
{
CAMLparam2(self, arg1);

g_subprocess_launcher_take_stderr_fd(GSubprocessLauncher_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_subprocess_launcher_take_stderr_fd(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SubprocessLauncher is only available on non-windows");
return Val_unit;
}

#endif /* not windows */

#if !(defined(_WIN32))

CAMLexport CAMLprim value ml_g_subprocess_launcher_take_fd(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_subprocess_launcher_take_fd(GSubprocessLauncher_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_subprocess_launcher_take_fd(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("SubprocessLauncher is only available on non-windows");
return Val_unit;
}

#endif /* not windows */

CAMLexport CAMLprim value ml_g_subprocess_launcher_spawnv(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;
    int arg1_length = Wosize_val(arg1);
    const char** c_arg1 = (const char**)g_malloc(sizeof(const char*) * (arg1_length + 1));
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = String_val(Field(arg1, i));
    }
    c_arg1[arg1_length] = NULL;

GSubprocess* result = g_subprocess_launcher_spawnv(GSubprocessLauncher_val(self), c_arg1, &error);
    g_free(c_arg1);
if (error == NULL) CAMLreturn(Res_Ok(Val_GSubprocess(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_subprocess_launcher_setenv(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

g_subprocess_launcher_setenv(GSubprocessLauncher_val(self), String_val(arg1), String_val(arg2), Bool_val(arg3));
CAMLreturn(Val_unit);
}

#if !(defined(_WIN32))

CAMLexport CAMLprim value ml_g_subprocess_launcher_set_stdout_file_path(value self, value arg1)
{
CAMLparam2(self, arg1);

g_subprocess_launcher_set_stdout_file_path(GSubprocessLauncher_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_subprocess_launcher_set_stdout_file_path(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SubprocessLauncher is only available on non-windows");
return Val_unit;
}

#endif /* not windows */

#if !(defined(_WIN32))

CAMLexport CAMLprim value ml_g_subprocess_launcher_set_stdin_file_path(value self, value arg1)
{
CAMLparam2(self, arg1);

g_subprocess_launcher_set_stdin_file_path(GSubprocessLauncher_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_subprocess_launcher_set_stdin_file_path(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SubprocessLauncher is only available on non-windows");
return Val_unit;
}

#endif /* not windows */

#if !(defined(_WIN32))

CAMLexport CAMLprim value ml_g_subprocess_launcher_set_stderr_file_path(value self, value arg1)
{
CAMLparam2(self, arg1);

g_subprocess_launcher_set_stderr_file_path(GSubprocessLauncher_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_subprocess_launcher_set_stderr_file_path(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SubprocessLauncher is only available on non-windows");
return Val_unit;
}

#endif /* not windows */

CAMLexport CAMLprim value ml_g_subprocess_launcher_set_flags(value self, value arg1)
{
CAMLparam2(self, arg1);

g_subprocess_launcher_set_flags(GSubprocessLauncher_val(self), GioSubprocessFlags_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_subprocess_launcher_set_environ(value self, value arg1)
{
CAMLparam2(self, arg1);
    int arg1_length = Wosize_val(arg1);
    const char** c_arg1 = (const char**)g_malloc(sizeof(const char*) * (arg1_length + 1));
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = String_val(Field(arg1, i));
    }
    c_arg1[arg1_length] = NULL;

g_subprocess_launcher_set_environ(GSubprocessLauncher_val(self), c_arg1);
    g_free(c_arg1);
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_subprocess_launcher_set_cwd(value self, value arg1)
{
CAMLparam2(self, arg1);

g_subprocess_launcher_set_cwd(GSubprocessLauncher_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_subprocess_launcher_getenv(value self, value arg1)
{
CAMLparam2(self, arg1);

const gchar* result = g_subprocess_launcher_getenv(GSubprocessLauncher_val(self), String_val(arg1));
CAMLreturn(Val_option_string(result));
}

#if !(defined(_WIN32))

#if GLIB_CHECK_VERSION(2,68,0)

CAMLexport CAMLprim value ml_g_subprocess_launcher_close(value self)
{
CAMLparam1(self);

g_subprocess_launcher_close(GSubprocessLauncher_val(self));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_subprocess_launcher_close(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SubprocessLauncher requires GLib >= 2.68");
return Val_unit;
}
#endif

#else

CAMLexport CAMLprim value ml_g_subprocess_launcher_close(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SubprocessLauncher is only available on non-windows");
return Val_unit;
}

#endif /* not windows */

GType g_subprocess_launcher_get_type (void);


CAMLprim value ml_gio_subprocess_launcher_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_subprocess_launcher_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_subprocess_launcher_new(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("SubprocessLauncher requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_launcher_close(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SubprocessLauncher requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_launcher_getenv(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SubprocessLauncher requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_launcher_set_cwd(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SubprocessLauncher requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_launcher_set_environ(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SubprocessLauncher requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_launcher_set_flags(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SubprocessLauncher requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_launcher_set_stderr_file_path(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SubprocessLauncher requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_launcher_set_stdin_file_path(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SubprocessLauncher requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_launcher_set_stdout_file_path(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SubprocessLauncher requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_launcher_setenv(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("SubprocessLauncher requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_launcher_spawnv(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SubprocessLauncher requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_launcher_take_fd(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("SubprocessLauncher requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_launcher_take_stderr_fd(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SubprocessLauncher requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_launcher_take_stdin_fd(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SubprocessLauncher requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_launcher_take_stdout_fd(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SubprocessLauncher requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_subprocess_launcher_unsetenv(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SubprocessLauncher requires GLib >= 2.40");
return Val_unit;
}


#endif
