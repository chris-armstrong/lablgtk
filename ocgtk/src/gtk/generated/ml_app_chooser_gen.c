/* GENERATED CODE - DO NOT EDIT */
/* C bindings for AppChooser */

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


CAMLexport CAMLprim value ml_gtk_app_chooser_refresh(value self)
{
CAMLparam1(self);

gtk_app_chooser_refresh(GtkAppChooser_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_app_chooser_get_content_type(value self)
{
CAMLparam1(self);

char* result = gtk_app_chooser_get_content_type(GtkAppChooser_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_app_chooser_get_app_info(value self)
{
CAMLparam1(self);

GAppInfo* result = gtk_app_chooser_get_app_info(GtkAppChooser_val(self));
CAMLreturn(Val_option(result, Val_GAppInfo));
}
CAMLexport CAMLprim value ml_gtk_app_chooser_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), GTK_TYPE_APP_CHOOSER)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GtkAppChooser");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GtkAppChooser((GtkAppChooser*)gobj));
}


CAMLprim value ml_gtk_app_chooser_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_app_chooser_get_type()));
}
