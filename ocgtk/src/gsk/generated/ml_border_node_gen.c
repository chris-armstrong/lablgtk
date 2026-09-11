/* GENERATED CODE - DO NOT EDIT */
/* C bindings for BorderNode */

#include <gtk/gtk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <gsk/gsk.h>
/* Include library-specific type conversions and forward declarations */
#include "gsk_decls.h"


CAMLexport CAMLprim value ml_gsk_border_node_new(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);
    int arg2_length = Wosize_val(arg2);
    float* c_arg2 = (float*)g_malloc(sizeof(float) * arg2_length);
    for (int i = 0; i < arg2_length; i++) {
      c_arg2[i] = Double_val(Field(arg2, i));
    }
    int arg3_length = Wosize_val(arg3);
    GdkRGBA* c_arg3 = (GdkRGBA*)g_malloc(sizeof(GdkRGBA) * arg3_length);
    for (int i = 0; i < arg3_length; i++) {
      c_arg3[i] = *GdkRGBA_val(Field(arg3, i));
    }

GskBorderNode *obj = gsk_border_node_new(GskRoundedRect_val(arg1), c_arg2, c_arg3);
if (obj) g_object_ref_sink(obj);

    g_free(c_arg2);
    g_free(c_arg3);
CAMLreturn(Val_GskBorderNode(obj));
}
CAMLexport CAMLprim value ml_gsk_border_node_get_widths(value self)
{
CAMLparam1(self);

const float* result = gsk_border_node_get_widths(GskBorderNode_val(self));
    int result_length = 4;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, caml_copy_double(result[i]));
    }
CAMLreturn(ml_result);
}

CAMLexport CAMLprim value ml_gsk_border_node_get_outline(value self)
{
CAMLparam1(self);

const GskRoundedRect* result = gsk_border_node_get_outline(GskBorderNode_val(self));
CAMLreturn(Val_GskRoundedRect(result));
}

CAMLexport CAMLprim value ml_gsk_border_node_get_colors(value self)
{
CAMLparam1(self);

const GdkRGBA* result = gsk_border_node_get_colors(GskBorderNode_val(self));
    int result_length = 4;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, Val_GdkRGBA(&result[i]));
    }
CAMLreturn(ml_result);
}

GType gsk_border_node_get_type (void);


CAMLprim value ml_gsk_border_node_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_border_node_get_type()));
}
