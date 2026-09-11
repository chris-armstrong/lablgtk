/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Editable */

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


CAMLexport CAMLprim value ml_gtk_editable_set_width_chars(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_editable_set_width_chars(GtkEditable_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_editable_set_text(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_editable_set_text(GtkEditable_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_editable_set_position(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_editable_set_position(GtkEditable_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_editable_set_max_width_chars(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_editable_set_max_width_chars(GtkEditable_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_editable_set_enable_undo(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_editable_set_enable_undo(GtkEditable_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_editable_set_editable(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_editable_set_editable(GtkEditable_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_editable_set_alignment(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_editable_set_alignment(GtkEditable_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_editable_select_region(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_editable_select_region(GtkEditable_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_editable_insert_text(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
int inout3 = Int_val(arg3);

gtk_editable_insert_text(GtkEditable_val(self), String_val(arg1), Int_val(arg2), &inout3);
CAMLreturn(Val_int(inout3));
}

CAMLexport CAMLprim value ml_gtk_editable_init_delegate(value self)
{
CAMLparam1(self);

gtk_editable_init_delegate(GtkEditable_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_editable_get_width_chars(value self)
{
CAMLparam1(self);

int result = gtk_editable_get_width_chars(GtkEditable_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_editable_get_text(value self)
{
CAMLparam1(self);

const char* result = gtk_editable_get_text(GtkEditable_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_editable_get_selection_bounds(value self)
{
CAMLparam1(self);
int out1;
int out2;

gboolean result = gtk_editable_get_selection_bounds(GtkEditable_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_int(out1));
    Store_field(ret, 2, Val_int(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_editable_get_position(value self)
{
CAMLparam1(self);

int result = gtk_editable_get_position(GtkEditable_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_editable_get_max_width_chars(value self)
{
CAMLparam1(self);

int result = gtk_editable_get_max_width_chars(GtkEditable_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_editable_get_enable_undo(value self)
{
CAMLparam1(self);

gboolean result = gtk_editable_get_enable_undo(GtkEditable_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_editable_get_editable(value self)
{
CAMLparam1(self);

gboolean result = gtk_editable_get_editable(GtkEditable_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_editable_get_delegate(value self)
{
CAMLparam1(self);

GtkEditable* result = gtk_editable_get_delegate(GtkEditable_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkEditable));
}

CAMLexport CAMLprim value ml_gtk_editable_get_chars(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

char* result = gtk_editable_get_chars(GtkEditable_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_editable_get_alignment(value self)
{
CAMLparam1(self);

float result = gtk_editable_get_alignment(GtkEditable_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_editable_finish_delegate(value self)
{
CAMLparam1(self);

gtk_editable_finish_delegate(GtkEditable_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_editable_delete_text(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_editable_delete_text(GtkEditable_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_editable_delete_selection(value self)
{
CAMLparam1(self);

gtk_editable_delete_selection(GtkEditable_val(self));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,10,0)

CAMLexport CAMLprim value ml_gtk_editable_delegate_get_accessible_platform_state(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_editable_delegate_get_accessible_platform_state(GtkEditable_val(self), GtkAccessiblePlatformState_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gtk_editable_delegate_get_accessible_platform_state(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Editable requires GTK >= 4.10");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_editable_get_selection_bound(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkEditable *obj = (GtkEditable *)GtkEditable_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "selection-bound");
if (pspec == NULL) caml_failwith("ml_gtk_editable_get_selection_bound: property 'selection-bound' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "selection-bound", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}
CAMLexport CAMLprim value ml_gtk_editable_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), GTK_TYPE_EDITABLE)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GtkEditable");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GtkEditable((GtkEditable*)gobj));
}


CAMLprim value ml_gtk_editable_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_editable_get_type()));
}
