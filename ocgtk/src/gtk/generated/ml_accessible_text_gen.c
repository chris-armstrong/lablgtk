/* GENERATED CODE - DO NOT EDIT */
/* C bindings for AccessibleText */

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

#if GTK_CHECK_VERSION(4,14,0)


CAMLexport CAMLprim value ml_gtk_accessible_text_update_selection_bound(value self)
{
CAMLparam1(self);

gtk_accessible_text_update_selection_bound(GtkAccessibleText_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_accessible_text_update_contents(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_accessible_text_update_contents(GtkAccessibleText_val(self), GtkAccessibleTextContentChange_val(arg1), Int_val(arg2), Int_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_accessible_text_update_caret_position(value self)
{
CAMLparam1(self);

gtk_accessible_text_update_caret_position(GtkAccessibleText_val(self));
CAMLreturn(Val_unit);
}
CAMLexport CAMLprim value ml_gtk_accessible_text_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), GTK_TYPE_ACCESSIBLE_TEXT)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GtkAccessibleText");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GtkAccessibleText((GtkAccessibleText*)gobj));
}

GType gtk_accessible_text_get_type (void);


CAMLprim value ml_gtk_accessible_text_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_accessible_text_get_type()));
}

#else


CAMLexport CAMLprim value ml_gtk_accessible_text_update_caret_position(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("AccessibleText requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_accessible_text_update_contents(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("AccessibleText requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_accessible_text_update_selection_bound(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("AccessibleText requires GTK >= 4.14");
return Val_unit;
}

CAMLexport CAMLprim value ml_gtk_accessible_text_from_gobject(value obj)
{
    CAMLparam1(obj);
    (void)obj;
    caml_failwith("AccessibleText requires GTK >= 4.14");
    return Val_unit;
}


#endif
