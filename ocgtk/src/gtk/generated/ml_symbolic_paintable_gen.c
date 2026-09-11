/* GENERATED CODE - DO NOT EDIT */
/* C bindings for SymbolicPaintable */

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

#if GTK_CHECK_VERSION(4,6,0)


CAMLexport CAMLprim value ml_gtk_symbolic_paintable_snapshot_symbolic_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);
    int arg4_length = Wosize_val(arg4);
    GdkRGBA* c_arg4 = (GdkRGBA*)g_malloc(sizeof(GdkRGBA) * arg4_length);
    for (int i = 0; i < arg4_length; i++) {
      c_arg4[i] = *GdkRGBA_val(Field(arg4, i));
    }

gtk_symbolic_paintable_snapshot_symbolic(GtkSymbolicPaintable_val(self), GdkSnapshot_val(arg1), Double_val(arg2), Double_val(arg3), c_arg4, Gsize_val(arg5));
    g_free(c_arg4);
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gtk_symbolic_paintable_snapshot_symbolic_bytecode(value * argv, int argn)
{
return ml_gtk_symbolic_paintable_snapshot_symbolic_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}
CAMLexport CAMLprim value ml_gtk_symbolic_paintable_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), GTK_TYPE_SYMBOLIC_PAINTABLE)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GtkSymbolicPaintable");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GtkSymbolicPaintable((GtkSymbolicPaintable*)gobj));
}

GType gtk_symbolic_paintable_get_type (void);


CAMLprim value ml_gtk_symbolic_paintable_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_symbolic_paintable_get_type()));
}

#else


CAMLexport CAMLprim value ml_gtk_symbolic_paintable_snapshot_symbolic(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
(void)arg5;
caml_failwith("SymbolicPaintable requires GTK >= 4.6");
return Val_unit;
}

CAMLexport CAMLprim value ml_gtk_symbolic_paintable_from_gobject(value obj)
{
    CAMLparam1(obj);
    (void)obj;
    caml_failwith("SymbolicPaintable requires GTK >= 4.6");
    return Val_unit;
}


#endif
