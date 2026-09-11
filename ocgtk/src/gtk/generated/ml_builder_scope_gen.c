/* GENERATED CODE - DO NOT EDIT */
/* C bindings for BuilderScope */

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

CAMLexport CAMLprim value ml_gtk_builder_scope_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), GTK_TYPE_BUILDER_SCOPE)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GtkBuilderScope");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GtkBuilderScope((GtkBuilderScope*)gobj));
}

GType gtk_builder_scope_get_type (void);


CAMLprim value ml_gtk_builder_scope_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_builder_scope_get_type()));
}
