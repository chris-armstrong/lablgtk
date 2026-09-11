/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TreeDragSource */

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


CAMLexport CAMLprim value ml_gtk_tree_drag_source_row_draggable(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_tree_drag_source_row_draggable(GtkTreeDragSource_val(self), GtkTreePath_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_tree_drag_source_drag_data_get(value self, value arg1)
{
CAMLparam2(self, arg1);

GdkContentProvider* result = gtk_tree_drag_source_drag_data_get(GtkTreeDragSource_val(self), GtkTreePath_val(arg1));
CAMLreturn(Val_option(result, Val_GdkContentProvider));
}

CAMLexport CAMLprim value ml_gtk_tree_drag_source_drag_data_delete(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_tree_drag_source_drag_data_delete(GtkTreeDragSource_val(self), GtkTreePath_val(arg1));
CAMLreturn(Val_bool(result));
}
CAMLexport CAMLprim value ml_gtk_tree_drag_source_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), GTK_TYPE_TREE_DRAG_SOURCE)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GtkTreeDragSource");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GtkTreeDragSource((GtkTreeDragSource*)gobj));
}


CAMLprim value ml_gtk_tree_drag_source_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_tree_drag_source_get_type()));
}
