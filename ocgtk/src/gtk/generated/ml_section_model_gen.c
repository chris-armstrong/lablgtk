/* GENERATED CODE - DO NOT EDIT */
/* C bindings for SectionModel */

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

#if GTK_CHECK_VERSION(4,12,0)


CAMLexport CAMLprim value ml_gtk_section_model_sections_changed(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_section_model_sections_changed(GtkSectionModel_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_section_model_get_section(value self, value arg1)
{
CAMLparam2(self, arg1);
guint out2;
guint out3;

gtk_section_model_get_section(GtkSectionModel_val(self), Int_val(arg1), &out2, &out3);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out2));
    Store_field(ret, 1, Val_int(out3));
    CAMLreturn(ret);
}
CAMLexport CAMLprim value ml_gtk_section_model_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), GTK_TYPE_SECTION_MODEL)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GtkSectionModel");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GtkSectionModel((GtkSectionModel*)gobj));
}


CAMLprim value ml_gtk_section_model_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_section_model_get_type()));
}

#else


CAMLexport CAMLprim value ml_gtk_section_model_get_section(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SectionModel requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_section_model_sections_changed(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("SectionModel requires GTK >= 4.12");
return Val_unit;
}

CAMLexport CAMLprim value ml_gtk_section_model_from_gobject(value obj)
{
    CAMLparam1(obj);
    (void)obj;
    caml_failwith("SectionModel requires GTK >= 4.12");
    return Val_unit;
}


#endif
