/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ColorState */

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
/* Conversion functions for GdkColorState (opaque record with hidden fields) */
GdkColorState *GdkColorState_val(value v) {
  return (GdkColorState *)ml_gir_record_ptr_val(v, "GdkColorState");
}

value Val_GdkColorState(const GdkColorState *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(gdk_color_state_get_type(), ptr);
}

value Val_GdkColorState_option(const GdkColorState *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GdkColorState(ptr));
}
#endif

#if GTK_CHECK_VERSION(4,16,0)


CAMLexport CAMLprim value ml_gdk_color_state_ref(value self)
{
CAMLparam1(self);

GdkColorState* result = gdk_color_state_ref(GdkColorState_val(self));
CAMLreturn(Val_GdkColorState(result));
}

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gdk_color_state_equivalent(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gdk_color_state_equivalent(GdkColorState_val(self), GdkColorState_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gdk_color_state_equivalent(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ColorState requires GTK >= 4.20");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_color_state_equal(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gdk_color_state_equal(GdkColorState_val(self), GdkColorState_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_color_state_create_cicp_params(value self)
{
CAMLparam1(self);

GdkCicpParams* result = gdk_color_state_create_cicp_params(GdkColorState_val(self));
CAMLreturn(Val_option(result, Val_GdkCicpParams));
}

GType gdk_color_state_get_type (void);


CAMLprim value ml_gdk_color_state_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_color_state_get_type()));
}

#else


CAMLexport CAMLprim value ml_gdk_color_state_create_cicp_params(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ColorState requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_color_state_equal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ColorState requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_color_state_equivalent(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ColorState requires GTK >= 4.16");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_color_state_ref(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ColorState requires GTK >= 4.16");
return Val_unit;
}


#endif
