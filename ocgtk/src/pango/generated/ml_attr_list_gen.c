/* GENERATED CODE - DO NOT EDIT */
/* C bindings for AttrList */

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

/* Conversion functions for PangoAttrList (opaque record with hidden fields) */
PangoAttrList *PangoAttrList_val(value v) {
  return (PangoAttrList *)ml_gir_record_ptr_val(v, "PangoAttrList");
}

value Val_PangoAttrList(const PangoAttrList *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(pango_attr_list_get_type(), ptr);
}

value Val_PangoAttrList_option(const PangoAttrList *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_PangoAttrList(ptr));
}


CAMLexport CAMLprim value ml_pango_attr_list_new(value unit)
{
CAMLparam1(unit);

PangoAttrList *obj = pango_attr_list_new();

CAMLreturn(Val_PangoAttrList(obj));
}
#if PANGO_VERSION_CHECK(1,44,0)

CAMLexport CAMLprim value ml_pango_attr_list_update(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

pango_attr_list_update(PangoAttrList_val(self), Int_val(arg1), Int_val(arg2), Int_val(arg3));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_pango_attr_list_update(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("AttrList requires Pango >= 1.44");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_pango_attr_list_to_string(value self)
{
CAMLparam1(self);

char* result = pango_attr_list_to_string(PangoAttrList_val(self));
CAMLreturn(caml_copy_string(result));
}

#else

CAMLexport CAMLprim value ml_pango_attr_list_to_string(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("AttrList requires Pango >= 1.50");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_attr_list_splice(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

pango_attr_list_splice(PangoAttrList_val(self), PangoAttrList_val(arg1), Int_val(arg2), Int_val(arg3));
CAMLreturn(Val_unit);
}

#if PANGO_VERSION_CHECK(1,10,0)

CAMLexport CAMLprim value ml_pango_attr_list_ref(value self)
{
CAMLparam1(self);

PangoAttrList* result = pango_attr_list_ref(PangoAttrList_val(self));
CAMLreturn(Val_PangoAttrList(result));
}

#else

CAMLexport CAMLprim value ml_pango_attr_list_ref(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("AttrList requires Pango >= 1.10");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_attr_list_insert_before(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_attr_list_insert_before(PangoAttrList_val(self), PangoAttribute_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_attr_list_insert(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_attr_list_insert(PangoAttrList_val(self), PangoAttribute_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_pango_attr_list_get_iterator(value self)
{
CAMLparam1(self);

PangoAttrIterator* result = pango_attr_list_get_iterator(PangoAttrList_val(self));
CAMLreturn(Val_PangoAttrIterator(result));
}

#if PANGO_VERSION_CHECK(1,44,0)

CAMLexport CAMLprim value ml_pango_attr_list_get_attributes(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = pango_attr_list_get_attributes(PangoAttrList_val(self));
Val_GSList_with(c_result, result, item, cell, Val_PangoAttribute((gpointer)_tmp->data));
    g_slist_free(c_result);
    CAMLreturn(result);
}

#else

CAMLexport CAMLprim value ml_pango_attr_list_get_attributes(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("AttrList requires Pango >= 1.44");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,46,0)

CAMLexport CAMLprim value ml_pango_attr_list_equal(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = pango_attr_list_equal(PangoAttrList_val(self), PangoAttrList_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_pango_attr_list_equal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("AttrList requires Pango >= 1.46");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_pango_attr_list_change(value self, value arg1)
{
CAMLparam2(self, arg1);

pango_attr_list_change(PangoAttrList_val(self), PangoAttribute_val(arg1));
CAMLreturn(Val_unit);
}

GType pango_attr_list_get_type (void);


CAMLprim value ml_pango_attr_list_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(pango_attr_list_get_type()));
}
