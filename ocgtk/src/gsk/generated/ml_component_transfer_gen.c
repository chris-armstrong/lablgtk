/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ComponentTransfer */

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

#if GTK_CHECK_VERSION(4,20,0)
/* Conversion functions for GskComponentTransfer (opaque record with hidden fields) */
GskComponentTransfer *GskComponentTransfer_val(value v) {
  return (GskComponentTransfer *)ml_gir_record_ptr_val(v, "GskComponentTransfer");
}

value Val_GskComponentTransfer(const GskComponentTransfer *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(gsk_component_transfer_get_type(), ptr);
}

value Val_GskComponentTransfer_option(const GskComponentTransfer *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GskComponentTransfer(ptr));
}
#endif

#if GTK_CHECK_VERSION(4,20,0)


CAMLexport CAMLprim value ml_gsk_component_transfer_new_discrete(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
    int arg2_length = Wosize_val(arg2);
    float* c_arg2 = (float*)g_malloc(sizeof(float) * arg2_length);
    for (int i = 0; i < arg2_length; i++) {
      c_arg2[i] = Double_val(Field(arg2, i));
    }

GskComponentTransfer *obj = gsk_component_transfer_new_discrete(Int_val(arg1), c_arg2);

    g_free(c_arg2);
CAMLreturn(Val_GskComponentTransfer(obj));
}
CAMLexport CAMLprim value ml_gsk_component_transfer_new_gamma(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);

GskComponentTransfer *obj = gsk_component_transfer_new_gamma(Double_val(arg1), Double_val(arg2), Double_val(arg3));

CAMLreturn(Val_GskComponentTransfer(obj));
}
CAMLexport CAMLprim value ml_gsk_component_transfer_new_identity(value unit)
{
CAMLparam1(unit);

GskComponentTransfer *obj = gsk_component_transfer_new_identity();

CAMLreturn(Val_GskComponentTransfer(obj));
}
CAMLexport CAMLprim value ml_gsk_component_transfer_new_levels(value arg1)
{
CAMLparam1(arg1);

GskComponentTransfer *obj = gsk_component_transfer_new_levels(Double_val(arg1));

CAMLreturn(Val_GskComponentTransfer(obj));
}
CAMLexport CAMLprim value ml_gsk_component_transfer_new_linear(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GskComponentTransfer *obj = gsk_component_transfer_new_linear(Double_val(arg1), Double_val(arg2));

CAMLreturn(Val_GskComponentTransfer(obj));
}
CAMLexport CAMLprim value ml_gsk_component_transfer_new_table(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
    int arg2_length = Wosize_val(arg2);
    float* c_arg2 = (float*)g_malloc(sizeof(float) * arg2_length);
    for (int i = 0; i < arg2_length; i++) {
      c_arg2[i] = Double_val(Field(arg2, i));
    }

GskComponentTransfer *obj = gsk_component_transfer_new_table(Int_val(arg1), c_arg2);

    g_free(c_arg2);
CAMLreturn(Val_GskComponentTransfer(obj));
}
GType gsk_component_transfer_get_type (void);


CAMLprim value ml_gsk_component_transfer_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_component_transfer_get_type()));
}

#else


CAMLexport CAMLprim value ml_gsk_component_transfer_new_discrete(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("ComponentTransfer requires GTK >= 4.20");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_component_transfer_new_gamma(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("ComponentTransfer requires GTK >= 4.20");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_component_transfer_new_identity(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("ComponentTransfer requires GTK >= 4.20");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_component_transfer_new_levels(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("ComponentTransfer requires GTK >= 4.20");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_component_transfer_new_linear(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("ComponentTransfer requires GTK >= 4.20");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_component_transfer_new_table(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("ComponentTransfer requires GTK >= 4.20");
return Val_unit;
}


#endif
