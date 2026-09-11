/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ColorChooser */

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


CAMLexport CAMLprim value ml_gtk_color_chooser_set_use_alpha(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_color_chooser_set_use_alpha(GtkColorChooser_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_color_chooser_set_rgba(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_color_chooser_set_rgba(GtkColorChooser_val(self), GdkRGBA_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_color_chooser_get_use_alpha(value self)
{
CAMLparam1(self);

gboolean result = gtk_color_chooser_get_use_alpha(GtkColorChooser_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_color_chooser_get_rgba(value self)
{
CAMLparam1(self);
GdkRGBA out1;

gtk_color_chooser_get_rgba(GtkColorChooser_val(self), &out1);
CAMLreturn(Val_GdkRGBA(&out1));
}

CAMLexport CAMLprim value ml_gtk_color_chooser_add_palette(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
    int arg4_length = 0;
    GdkRGBA* c_arg4 = NULL;
    
    if (Is_some(arg4)) {
        value array = Some_val(arg4);
        arg4_length = Wosize_val(array);
        c_arg4 = (GdkRGBA*)g_malloc(sizeof(GdkRGBA) * arg4_length);
        for (int i = 0; i < arg4_length; i++) {
          c_arg4[i] = *GdkRGBA_val(Field(array, i));
        }
    }

gtk_color_chooser_add_palette(GtkColorChooser_val(self), GtkOrientation_val(arg1), arg4_length, Int_val(arg3), c_arg4);
    if (c_arg4) g_free(c_arg4);
CAMLreturn(Val_unit);
}
CAMLexport CAMLprim value ml_gtk_color_chooser_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), GTK_TYPE_COLOR_CHOOSER)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GtkColorChooser");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GtkColorChooser((GtkColorChooser*)gobj));
}


CAMLprim value ml_gtk_color_chooser_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_color_chooser_get_type()));
}
