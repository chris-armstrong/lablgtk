/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TreeDragDest */

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


CAMLexport CAMLprim value ml_gtk_tree_drag_dest_row_drop_possible(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = gtk_tree_drag_dest_row_drop_possible(GtkTreeDragDest_val(self), GtkTreePath_val(arg1), GValue_val(arg2));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_drag_dest_drag_data_received(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = gtk_tree_drag_dest_drag_data_received(GtkTreeDragDest_val(self), GtkTreePath_val(arg1), GValue_val(arg2));
CAMLreturn(Val_bool(result));
}
CAMLexport CAMLprim value ml_gtk_tree_drag_dest_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), GTK_TYPE_TREE_DRAG_DEST)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GtkTreeDragDest");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GtkTreeDragDest((GtkTreeDragDest*)gobj));
}

GType gtk_tree_drag_dest_get_type (void);


CAMLprim value ml_gtk_tree_drag_dest_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_tree_drag_dest_get_type()));
}
