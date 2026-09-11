/* GENERATED CODE - DO NOT EDIT */
/* C bindings for GlyphItem */

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

/* Copy function for PangoGlyphItem (value-like record with copy method) */
value copy_PangoGlyphItem(const PangoGlyphItem *ptr)
{
  if (ptr == NULL) return Val_none;
  PangoGlyphItem *copy = g_boxed_copy(pango_glyph_item_get_type(), ptr);
  return ml_gir_record_val_ptr_with_type(pango_glyph_item_get_type(), copy);
}


#if PANGO_VERSION_CHECK(1,2,0)

CAMLexport CAMLprim value ml_pango_glyph_item_split(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

PangoGlyphItem* result = pango_glyph_item_split(PangoGlyphItem_val(self), String_val(arg1), Int_val(arg2));
CAMLreturn(Val_option(result, Val_PangoGlyphItem));
}

#else

CAMLexport CAMLprim value ml_pango_glyph_item_split(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("GlyphItem requires Pango >= 1.2");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,2,0)

CAMLexport CAMLprim value ml_pango_glyph_item_apply_attrs(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

CAMLlocal3(result, item, cell);
    GList* c_result = pango_glyph_item_apply_attrs(PangoGlyphItem_val(self), String_val(arg1), PangoAttrList_val(arg2));
Val_GSList_with(c_result, result, item, cell, Val_PangoGlyphItem((gpointer)_tmp->data));
    g_slist_free(c_result);
    CAMLreturn(result);
}

#else

CAMLexport CAMLprim value ml_pango_glyph_item_apply_attrs(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("GlyphItem requires Pango >= 1.2");
return Val_unit;
}
#endif

GType pango_glyph_item_get_type (void);


CAMLprim value ml_pango_glyph_item_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(pango_glyph_item_get_type()));
}
