/* GENERATED CODE - DO NOT EDIT */
/* C bindings for CellRenderer */

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


CAMLexport CAMLprim value ml_gtk_cell_renderer_stop_editing(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_cell_renderer_stop_editing(GtkCellRenderer_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_start_editing_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam2(arg5, arg6);

GtkCellEditable* result = gtk_cell_renderer_start_editing(GtkCellRenderer_val(self), Option_val(arg1, GdkEvent_val, NULL), GtkWidget_val(arg2), String_val(arg3), GdkRectangle_val(arg4), GdkRectangle_val(arg5), GtkCellRendererState_val(arg6));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkCellEditable));}

CAMLexport CAMLprim value ml_gtk_cell_renderer_start_editing_bytecode(value * argv, int argn)
{
return ml_gtk_cell_renderer_start_editing_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_snapshot_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);

gtk_cell_renderer_snapshot(GtkCellRenderer_val(self), GtkSnapshot_val(arg1), GtkWidget_val(arg2), GdkRectangle_val(arg3), GdkRectangle_val(arg4), GtkCellRendererState_val(arg5));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_snapshot_bytecode(value * argv, int argn)
{
return ml_gtk_cell_renderer_snapshot_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_set_visible(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_cell_renderer_set_visible(GtkCellRenderer_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_set_sensitive(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_cell_renderer_set_sensitive(GtkCellRenderer_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_set_padding(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_cell_renderer_set_padding(GtkCellRenderer_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_set_is_expander(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_cell_renderer_set_is_expander(GtkCellRenderer_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_set_is_expanded(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_cell_renderer_set_is_expanded(GtkCellRenderer_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_set_fixed_size(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_cell_renderer_set_fixed_size(GtkCellRenderer_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_set_alignment(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_cell_renderer_set_alignment(GtkCellRenderer_val(self), Double_val(arg1), Double_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_is_activatable(value self)
{
CAMLparam1(self);

gboolean result = gtk_cell_renderer_is_activatable(GtkCellRenderer_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_get_visible(value self)
{
CAMLparam1(self);

gboolean result = gtk_cell_renderer_get_visible(GtkCellRenderer_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_get_state(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

GtkStateFlags result = gtk_cell_renderer_get_state(GtkCellRenderer_val(self), Option_val(arg1, GtkWidget_val, NULL), GtkCellRendererState_val(arg2));
CAMLreturn(Val_GtkStateFlags(result));
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_get_sensitive(value self)
{
CAMLparam1(self);

gboolean result = gtk_cell_renderer_get_sensitive(GtkCellRenderer_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_get_request_mode(value self)
{
CAMLparam1(self);

GtkSizeRequestMode result = gtk_cell_renderer_get_request_mode(GtkCellRenderer_val(self));
CAMLreturn(Val_GtkSizeRequestMode(result));
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_get_preferred_width_for_height(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
int out3;
int out4;

gtk_cell_renderer_get_preferred_width_for_height(GtkCellRenderer_val(self), GtkWidget_val(arg1), Int_val(arg2), &out3, &out4);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out3));
    Store_field(ret, 1, Val_int(out4));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_get_preferred_width(value self, value arg1)
{
CAMLparam2(self, arg1);
int out2;
int out3;

gtk_cell_renderer_get_preferred_width(GtkCellRenderer_val(self), GtkWidget_val(arg1), &out2, &out3);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out2));
    Store_field(ret, 1, Val_int(out3));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_get_preferred_size(value self, value arg1)
{
CAMLparam2(self, arg1);
GtkRequisition out2;
GtkRequisition out3;

gtk_cell_renderer_get_preferred_size(GtkCellRenderer_val(self), GtkWidget_val(arg1), &out2, &out3);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_GtkRequisition(&out2));
    Store_field(ret, 1, Val_GtkRequisition(&out3));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_get_preferred_height_for_width(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
int out3;
int out4;

gtk_cell_renderer_get_preferred_height_for_width(GtkCellRenderer_val(self), GtkWidget_val(arg1), Int_val(arg2), &out3, &out4);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out3));
    Store_field(ret, 1, Val_int(out4));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_get_preferred_height(value self, value arg1)
{
CAMLparam2(self, arg1);
int out2;
int out3;

gtk_cell_renderer_get_preferred_height(GtkCellRenderer_val(self), GtkWidget_val(arg1), &out2, &out3);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out2));
    Store_field(ret, 1, Val_int(out3));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_get_padding(value self)
{
CAMLparam1(self);
int out1;
int out2;

gtk_cell_renderer_get_padding(GtkCellRenderer_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out1));
    Store_field(ret, 1, Val_int(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_get_is_expander(value self)
{
CAMLparam1(self);

gboolean result = gtk_cell_renderer_get_is_expander(GtkCellRenderer_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_get_is_expanded(value self)
{
CAMLparam1(self);

gboolean result = gtk_cell_renderer_get_is_expanded(GtkCellRenderer_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_get_fixed_size(value self)
{
CAMLparam1(self);
int out1;
int out2;

gtk_cell_renderer_get_fixed_size(GtkCellRenderer_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out1));
    Store_field(ret, 1, Val_int(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_get_alignment(value self)
{
CAMLparam1(self);
float out1;
float out2;

gtk_cell_renderer_get_alignment(GtkCellRenderer_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, caml_copy_double(out1));
    Store_field(ret, 1, caml_copy_double(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_get_aligned_area(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
GdkRectangle out4;

gtk_cell_renderer_get_aligned_area(GtkCellRenderer_val(self), GtkWidget_val(arg1), GtkCellRendererState_val(arg2), GdkRectangle_val(arg3), &out4);
CAMLreturn(Val_GdkRectangle(&out4));
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_activate_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam2(arg5, arg6);

gboolean result = gtk_cell_renderer_activate(GtkCellRenderer_val(self), GdkEvent_val(arg1), GtkWidget_val(arg2), String_val(arg3), GdkRectangle_val(arg4), GdkRectangle_val(arg5), GtkCellRendererState_val(arg6));
CAMLreturn(Val_bool(result));}

CAMLexport CAMLprim value ml_gtk_cell_renderer_activate_bytecode(value * argv, int argn)
{
return ml_gtk_cell_renderer_activate_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_set_cell_background(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRenderer *obj = (GtkCellRenderer *)GtkCellRenderer_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "cell-background");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_set_cell_background: property 'cell-background' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "cell-background", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_get_cell_background_rgba(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRenderer *obj = (GtkCellRenderer *)GtkCellRenderer_val(self);
    GdkRGBA *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "cell-background-rgba");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_get_cell_background_rgba: property 'cell-background-rgba' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "cell-background-rgba", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GdkRGBA(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_set_cell_background_rgba(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRenderer *obj = (GtkCellRenderer *)GtkCellRenderer_val(self);
    GdkRGBA *c_value = GdkRGBA_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "cell-background-rgba");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_set_cell_background_rgba: property 'cell-background-rgba' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          caml_failwith("unsupported property type");
g_object_set_property(G_OBJECT(obj), "cell-background-rgba", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_get_cell_background_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRenderer *obj = (GtkCellRenderer *)GtkCellRenderer_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "cell-background-set");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_get_cell_background_set: property 'cell-background-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "cell-background-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_set_cell_background_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRenderer *obj = (GtkCellRenderer *)GtkCellRenderer_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "cell-background-set");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_set_cell_background_set: property 'cell-background-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "cell-background-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_get_editing(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRenderer *obj = (GtkCellRenderer *)GtkCellRenderer_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "editing");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_get_editing: property 'editing' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "editing", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_get_height(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRenderer *obj = (GtkCellRenderer *)GtkCellRenderer_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "height");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_get_height: property 'height' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "height", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_set_height(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRenderer *obj = (GtkCellRenderer *)GtkCellRenderer_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "height");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_set_height: property 'height' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "height", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_get_mode(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRenderer *obj = (GtkCellRenderer *)GtkCellRenderer_val(self);
    GtkCellRendererMode prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "mode");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_get_mode: property 'mode' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "mode", &prop_gvalue);
          prop_value = (GtkCellRendererMode)g_value_get_enum(&prop_gvalue);

      result = Val_GtkCellRendererMode(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_set_mode(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRenderer *obj = (GtkCellRenderer *)GtkCellRenderer_val(self);
    GtkCellRendererMode c_value = GtkCellRendererMode_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "mode");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_set_mode: property 'mode' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "mode", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_get_width(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRenderer *obj = (GtkCellRenderer *)GtkCellRenderer_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "width");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_get_width: property 'width' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "width", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_set_width(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRenderer *obj = (GtkCellRenderer *)GtkCellRenderer_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "width");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_set_width: property 'width' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "width", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_get_xalign(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRenderer *obj = (GtkCellRenderer *)GtkCellRenderer_val(self);
    gfloat prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "xalign");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_get_xalign: property 'xalign' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "xalign", &prop_gvalue);
          prop_value = g_value_get_float(&prop_gvalue);

      result = caml_copy_double(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_set_xalign(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRenderer *obj = (GtkCellRenderer *)GtkCellRenderer_val(self);
    gfloat c_value = Double_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "xalign");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_set_xalign: property 'xalign' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_float(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "xalign", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_get_xpad(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRenderer *obj = (GtkCellRenderer *)GtkCellRenderer_val(self);
    guint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "xpad");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_get_xpad: property 'xpad' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "xpad", &prop_gvalue);
          prop_value = g_value_get_uint(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_set_xpad(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRenderer *obj = (GtkCellRenderer *)GtkCellRenderer_val(self);
    guint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "xpad");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_set_xpad: property 'xpad' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_uint(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "xpad", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_get_yalign(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRenderer *obj = (GtkCellRenderer *)GtkCellRenderer_val(self);
    gfloat prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "yalign");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_get_yalign: property 'yalign' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "yalign", &prop_gvalue);
          prop_value = g_value_get_float(&prop_gvalue);

      result = caml_copy_double(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_set_yalign(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRenderer *obj = (GtkCellRenderer *)GtkCellRenderer_val(self);
    gfloat c_value = Double_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "yalign");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_set_yalign: property 'yalign' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_float(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "yalign", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_cell_renderer_get_ypad(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkCellRenderer *obj = (GtkCellRenderer *)GtkCellRenderer_val(self);
    guint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "ypad");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_get_ypad: property 'ypad' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "ypad", &prop_gvalue);
          prop_value = g_value_get_uint(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_cell_renderer_set_ypad(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkCellRenderer *obj = (GtkCellRenderer *)GtkCellRenderer_val(self);
    guint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "ypad");
if (pspec == NULL) caml_failwith("ml_gtk_cell_renderer_set_ypad: property 'ypad' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_uint(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "ypad", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

GType gtk_cell_renderer_get_type (void);


CAMLprim value ml_gtk_cell_renderer_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_cell_renderer_get_type()));
}
