/* GENERATED CODE - DO NOT EDIT */
/* C bindings for UriLauncher */

#include <gtk/gtk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"
#include "converters.h"

#include <gtk/gtk.h>
/* Include library-specific type conversions and forward declarations */
#include "gtk_decls.h"

#if GTK_CHECK_VERSION(4,10,0)


CAMLexport CAMLprim value ml_gtk_uri_launcher_new(value arg1)
{
CAMLparam1(arg1);

GtkUriLauncher *obj = gtk_uri_launcher_new(String_option_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkUriLauncher(obj));
}
CAMLexport CAMLprim value ml_gtk_uri_launcher_set_uri(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_uri_launcher_set_uri(GtkUriLauncher_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_uri_launcher_launch_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = gtk_uri_launcher_launch_finish(GtkUriLauncher_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gtk_uri_launcher_get_uri(value self)
{
CAMLparam1(self);

const char* result = gtk_uri_launcher_get_uri(GtkUriLauncher_val(self));
CAMLreturn(Val_option_string(result));
}

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gtk_uri_launcher_can_launch(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_uri_launcher_can_launch(GtkUriLauncher_val(self), Option_val(arg1, GtkWindow_val, NULL));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gtk_uri_launcher_can_launch(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("UriLauncher requires GTK >= 4.20");
return Val_unit;
}
#endif

GType gtk_uri_launcher_get_type (void);


CAMLprim value ml_gtk_uri_launcher_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_uri_launcher_get_type()));
}

#else


CAMLexport CAMLprim value ml_gtk_uri_launcher_new(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("UriLauncher requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_uri_launcher_can_launch(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("UriLauncher requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_uri_launcher_get_uri(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("UriLauncher requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_uri_launcher_launch_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("UriLauncher requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_uri_launcher_set_uri(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("UriLauncher requires GTK >= 4.10");
return Val_unit;
}


#endif
