/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ApplicationCommandLine */

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


#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_application_command_line_set_exit_status(value self, value arg1)
{
CAMLparam2(self, arg1);

g_application_command_line_set_exit_status(GApplicationCommandLine_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_application_command_line_set_exit_status(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ApplicationCommandLine requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,80,0)

CAMLexport CAMLprim value ml_g_application_command_line_printerr_literal(value self, value arg1)
{
CAMLparam2(self, arg1);

g_application_command_line_printerr_literal(GApplicationCommandLine_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_application_command_line_printerr_literal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ApplicationCommandLine requires GLib >= 2.80");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,80,0)

CAMLexport CAMLprim value ml_g_application_command_line_print_literal(value self, value arg1)
{
CAMLparam2(self, arg1);

g_application_command_line_print_literal(GApplicationCommandLine_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_application_command_line_print_literal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ApplicationCommandLine requires GLib >= 2.80");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_application_command_line_getenv(value self, value arg1)
{
CAMLparam2(self, arg1);

const gchar* result = g_application_command_line_getenv(GApplicationCommandLine_val(self), String_val(arg1));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_g_application_command_line_getenv(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ApplicationCommandLine requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,34,0)

CAMLexport CAMLprim value ml_g_application_command_line_get_stdin(value self)
{
CAMLparam1(self);

GInputStream* result = g_application_command_line_get_stdin(GApplicationCommandLine_val(self));
CAMLreturn(Val_option(result, Val_GInputStream));
}

#else

CAMLexport CAMLprim value ml_g_application_command_line_get_stdin(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ApplicationCommandLine requires GLib >= 2.34");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_application_command_line_get_platform_data(value self)
{
CAMLparam1(self);

GVariant* result = g_application_command_line_get_platform_data(GApplicationCommandLine_val(self));
CAMLreturn(Val_option(result, Val_GVariant));
}

#else

CAMLexport CAMLprim value ml_g_application_command_line_get_platform_data(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ApplicationCommandLine requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_application_command_line_get_is_remote(value self)
{
CAMLparam1(self);

gboolean result = g_application_command_line_get_is_remote(GApplicationCommandLine_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_application_command_line_get_is_remote(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ApplicationCommandLine requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_application_command_line_get_exit_status(value self)
{
CAMLparam1(self);

int result = g_application_command_line_get_exit_status(GApplicationCommandLine_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_g_application_command_line_get_exit_status(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ApplicationCommandLine requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_application_command_line_get_environ(value self)
{
CAMLparam1(self);

const gchar* const* result = g_application_command_line_get_environ(GApplicationCommandLine_val(self));
    int result_length = 0;
    while (result[result_length] != NULL) result_length++;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, caml_copy_string(result[i]));
    }
CAMLreturn(ml_result);
}

#else

CAMLexport CAMLprim value ml_g_application_command_line_get_environ(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ApplicationCommandLine requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_application_command_line_get_cwd(value self)
{
CAMLparam1(self);

const gchar* result = g_application_command_line_get_cwd(GApplicationCommandLine_val(self));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_g_application_command_line_get_cwd(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ApplicationCommandLine requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_application_command_line_get_arguments(value self)
{
CAMLparam1(self);
int out1;

gchar** result = g_application_command_line_get_arguments(GApplicationCommandLine_val(self), &out1);
    int result_length = out1;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, caml_copy_string(result[i]));
    }
    for (int i = 0; i < result_length; i++) {
      g_free((gpointer)result[i]);
    }
    g_free(result);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, ml_result);
    Store_field(ret, 1, Val_int(out1));
    CAMLreturn(ret);
}

#else

CAMLexport CAMLprim value ml_g_application_command_line_get_arguments(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ApplicationCommandLine requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,80,0)

CAMLexport CAMLprim value ml_g_application_command_line_done(value self)
{
CAMLparam1(self);

g_application_command_line_done(GApplicationCommandLine_val(self));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_application_command_line_done(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ApplicationCommandLine requires GLib >= 2.80");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,36,0)

CAMLexport CAMLprim value ml_g_application_command_line_create_file_for_arg(value self, value arg1)
{
CAMLparam2(self, arg1);

GFile* result = g_application_command_line_create_file_for_arg(GApplicationCommandLine_val(self), String_val(arg1));
CAMLreturn(Val_GFile(result));
}

#else

CAMLexport CAMLprim value ml_g_application_command_line_create_file_for_arg(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ApplicationCommandLine requires GLib >= 2.36");
return Val_unit;
}
#endif

GType g_application_command_line_get_type (void);


CAMLprim value ml_gio_application_command_line_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_application_command_line_get_type()));
}
