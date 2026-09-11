/* GENERATED CODE - DO NOT EDIT */
/* C bindings for AttrIterator */

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

/* Conversion functions for PangoAttrIterator (opaque record with hidden fields) */
PangoAttrIterator *PangoAttrIterator_val(value v) {
  return (PangoAttrIterator *)ml_gir_record_ptr_val(v, "PangoAttrIterator");
}

value Val_PangoAttrIterator(const PangoAttrIterator *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(pango_attr_iterator_get_type(), ptr);
}

value Val_PangoAttrIterator_option(const PangoAttrIterator *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_PangoAttrIterator(ptr));
}


CAMLexport CAMLprim value ml_pango_attr_iterator_range(value self)
{
CAMLparam1(self);
int out1;
int out2;

pango_attr_iterator_range(PangoAttrIterator_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out1));
    Store_field(ret, 1, Val_int(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_pango_attr_iterator_next(value self)
{
CAMLparam1(self);

gboolean result = pango_attr_iterator_next(PangoAttrIterator_val(self));
CAMLreturn(Val_bool(result));
}

#if PANGO_VERSION_CHECK(1,2,0)

CAMLexport CAMLprim value ml_pango_attr_iterator_get_attrs(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = pango_attr_iterator_get_attrs(PangoAttrIterator_val(self));
Val_GSList_with(c_result, result, item, cell, Val_PangoAttribute((gpointer)_tmp->data));
    g_slist_free(c_result);
    CAMLreturn(result);
}

#else

CAMLexport CAMLprim value ml_pango_attr_iterator_get_attrs(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("AttrIterator requires Pango >= 1.2");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_attr_iterator_get(value self, value arg1)
{
CAMLparam2(self, arg1);

PangoAttribute* result = pango_attr_iterator_get(PangoAttrIterator_val(self), PangoAttrType_val(arg1));
if (result) result = g_boxed_copy(pango_attribute_get_type(), result);
CAMLreturn(Val_option(result, Val_PangoAttribute));
}

CAMLexport CAMLprim value ml_pango_attr_iterator_destroy(value self)
{
CAMLparam1(self);

pango_attr_iterator_destroy(PangoAttrIterator_val(self));
CAMLreturn(Val_unit);
}

GType pango_attr_iterator_get_type (void);


CAMLprim value ml_pango_attr_iterator_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(pango_attr_iterator_get_type()));
}
