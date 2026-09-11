/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Item */

#include <pango/pango.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <pango/pango.h>
/* Include library-specific type conversions and forward declarations */
#include "pango_decls.h"

/* Copy function for PangoItem (value-like record with copy method) */
value copy_PangoItem(const PangoItem *ptr)
{
  if (ptr == NULL) return Val_none;
  PangoItem *copy = g_boxed_copy(pango_item_get_type(), ptr);
  return ml_gir_record_val_ptr_with_type(pango_item_get_type(), copy);
}


CAMLexport CAMLprim value ml_pango_item_new(value unit)
{
CAMLparam1(unit);

PangoItem *obj = pango_item_new();

CAMLreturn(Val_PangoItem(obj));
}
CAMLexport CAMLprim value ml_pango_item_split(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

PangoItem* result = pango_item_split(PangoItem_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_PangoItem(result));
}

#if PANGO_VERSION_CHECK(1,54,0)

CAMLexport CAMLprim value ml_pango_item_get_char_offset(value self)
{
CAMLparam1(self);

int result = pango_item_get_char_offset(PangoItem_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_pango_item_get_char_offset(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Item requires Pango >= 1.54");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,44,0)

CAMLexport CAMLprim value ml_pango_item_apply_attrs(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_item_apply_attrs(PangoItem_val(self), PangoAttrIterator_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_pango_item_apply_attrs(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Item requires Pango >= 1.44");
return Val_unit;
}
#endif


CAMLprim value ml_pango_item_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(pango_item_get_type()));
}
