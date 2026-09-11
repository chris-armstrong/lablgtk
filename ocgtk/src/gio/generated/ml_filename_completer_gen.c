/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FilenameCompleter */

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


CAMLexport CAMLprim value ml_g_filename_completer_new(value unit)
{
CAMLparam1(unit);

GFilenameCompleter *obj = g_filename_completer_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GFilenameCompleter(obj));
}
CAMLexport CAMLprim value ml_g_filename_completer_set_dirs_only(value self, value arg1)
{
CAMLparam2(self, arg1);

g_filename_completer_set_dirs_only(GFilenameCompleter_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_filename_completer_get_completions(value self, value arg1)
{
CAMLparam2(self, arg1);

char** result = g_filename_completer_get_completions(GFilenameCompleter_val(self), String_val(arg1));
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

CAMLexport CAMLprim value ml_g_filename_completer_get_completion_suffix(value self, value arg1)
{
CAMLparam2(self, arg1);

char* result = g_filename_completer_get_completion_suffix(GFilenameCompleter_val(self), String_val(arg1));
CAMLreturn(Val_option_string(result));
}

GType g_filename_completer_get_type (void);


CAMLprim value ml_gio_filename_completer_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_filename_completer_get_type()));
}
