/* GENERATED CODE - DO NOT EDIT */
/* C bindings for CicpParams */

#include <gtk/gtk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <gdk/gdk.h>
/* Include library-specific type conversions and forward declarations */
#include "gdk_decls.h"

#if GTK_CHECK_VERSION(4,16,0)


CAMLexport CAMLprim value ml_gdk_cicp_params_new(value unit)
{
CAMLparam1(unit);

GdkCicpParams *obj = gdk_cicp_params_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GdkCicpParams(obj));
}
CAMLexport CAMLprim value ml_gdk_cicp_params_set_transfer_function(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_cicp_params_set_transfer_function(GdkCicpParams_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_cicp_params_set_range(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_cicp_params_set_range(GdkCicpParams_val(self), GdkCicpRange_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_cicp_params_set_matrix_coefficients(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_cicp_params_set_matrix_coefficients(GdkCicpParams_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_cicp_params_set_color_primaries(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_cicp_params_set_color_primaries(GdkCicpParams_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_cicp_params_get_transfer_function(value self)
{
CAMLparam1(self);

guint result = gdk_cicp_params_get_transfer_function(GdkCicpParams_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_cicp_params_get_range(value self)
{
CAMLparam1(self);

GdkCicpRange result = gdk_cicp_params_get_range(GdkCicpParams_val(self));
CAMLreturn(Val_GdkCicpRange(result));
}

CAMLexport CAMLprim value ml_gdk_cicp_params_get_matrix_coefficients(value self)
{
CAMLparam1(self);

guint result = gdk_cicp_params_get_matrix_coefficients(GdkCicpParams_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_cicp_params_get_color_primaries(value self)
{
CAMLparam1(self);

guint result = gdk_cicp_params_get_color_primaries(GdkCicpParams_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_cicp_params_build_color_state(value self)
{
CAMLparam1(self);
GError *error = NULL;

GdkColorState* result = gdk_cicp_params_build_color_state(GdkCicpParams_val(self), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GdkColorState(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

GType gdk_cicp_params_get_type (void);


CAMLprim value ml_gdk_cicp_params_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_cicp_params_get_type()));
}

#else


CAMLexport CAMLprim value ml_gdk_cicp_params_new(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("CicpParams requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_cicp_params_build_color_state(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("CicpParams requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_cicp_params_get_color_primaries(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("CicpParams requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_cicp_params_get_matrix_coefficients(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("CicpParams requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_cicp_params_get_range(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("CicpParams requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_cicp_params_get_transfer_function(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("CicpParams requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_cicp_params_set_color_primaries(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("CicpParams requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_cicp_params_set_matrix_coefficients(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("CicpParams requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_cicp_params_set_range(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("CicpParams requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_cicp_params_set_transfer_function(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("CicpParams requires GTK >= 4.16");
return Val_unit;
}


#endif
