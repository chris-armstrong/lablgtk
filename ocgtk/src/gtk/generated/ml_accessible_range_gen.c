/* GENERATED CODE - DO NOT EDIT */
/* C bindings for AccessibleRange */

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

CAMLexport CAMLprim value ml_gtk_accessible_range_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), GTK_TYPE_ACCESSIBLE_RANGE)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GtkAccessibleRange");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GtkAccessibleRange((GtkAccessibleRange*)gobj));
}

GType gtk_accessible_range_get_type (void);


CAMLprim value ml_gtk_accessible_range_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_accessible_range_get_type()));
}

#else

CAMLexport CAMLprim value ml_gtk_accessible_range_from_gobject(value obj)
{
    CAMLparam1(obj);
    (void)obj;
    caml_failwith("AccessibleRange requires GTK >= 4.10");
    return Val_unit;
}


#endif
