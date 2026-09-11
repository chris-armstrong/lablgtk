/* GENERATED CODE - DO NOT EDIT */
/* C bindings for PathPoint */

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

#if GTK_CHECK_VERSION(4,14,0)
/* Copy function for GskPathPoint (value-like record with copy method) */
value copy_GskPathPoint(const GskPathPoint *ptr)
{
  if (ptr == NULL) return Val_none;
  GskPathPoint *copy = g_boxed_copy(gsk_path_point_get_type(), ptr);
  return ml_gir_record_val_ptr_with_type(gsk_path_point_get_type(), copy);
}
#endif

#if GTK_CHECK_VERSION(4,14,0)


CAMLexport CAMLprim value ml_gsk_path_point_get_tangent(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
graphene_vec2_t out3;

gsk_path_point_get_tangent(GskPathPoint_val(self), GskPath_val(arg1), GskPathDirection_val(arg2), &out3);
CAMLreturn(Val_graphene_vec2_t(&out3));
}

CAMLexport CAMLprim value ml_gsk_path_point_get_rotation(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

float result = gsk_path_point_get_rotation(GskPathPoint_val(self), GskPath_val(arg1), GskPathDirection_val(arg2));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gsk_path_point_get_position(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_point_t out2;

gsk_path_point_get_position(GskPathPoint_val(self), GskPath_val(arg1), &out2);
CAMLreturn(Val_graphene_point_t(&out2));
}

CAMLexport CAMLprim value ml_gsk_path_point_get_distance(value self, value arg1)
{
CAMLparam2(self, arg1);

float result = gsk_path_point_get_distance(GskPathPoint_val(self), GskPathMeasure_val(arg1));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gsk_path_point_get_curvature(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
graphene_point_t out3;

float result = gsk_path_point_get_curvature(GskPathPoint_val(self), GskPath_val(arg1), GskPathDirection_val(arg2), &out3);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, caml_copy_double(result));
    Store_field(ret, 1, Val_graphene_point_t(&out3));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gsk_path_point_equal(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gsk_path_point_equal(GskPathPoint_val(self), GskPathPoint_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gsk_path_point_compare(value self, value arg1)
{
CAMLparam2(self, arg1);

int result = gsk_path_point_compare(GskPathPoint_val(self), GskPathPoint_val(arg1));
CAMLreturn(Val_int(result));
}

GType gsk_path_point_get_type (void);


CAMLprim value ml_gsk_path_point_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_path_point_get_type()));
}

#else


CAMLexport CAMLprim value ml_gsk_path_point_compare(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("PathPoint requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_point_equal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("PathPoint requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_point_get_curvature(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("PathPoint requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_point_get_distance(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("PathPoint requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_point_get_position(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("PathPoint requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_point_get_rotation(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("PathPoint requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_point_get_tangent(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("PathPoint requires GTK >= 4.14");
return Val_unit;
}


#endif
