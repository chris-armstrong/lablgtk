/* GENERATED CODE - DO NOT EDIT */
/* C bindings for PopupLayout */

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

/* Conversion functions for GdkPopupLayout (opaque record with hidden fields) */
GdkPopupLayout *GdkPopupLayout_val(value v) {
  return (GdkPopupLayout *)ml_gir_record_ptr_val(v, "GdkPopupLayout");
}

value Val_GdkPopupLayout(const GdkPopupLayout *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(gdk_popup_layout_get_type(), ptr);
}

value Val_GdkPopupLayout_option(const GdkPopupLayout *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GdkPopupLayout(ptr));
}


CAMLexport CAMLprim value ml_gdk_popup_layout_new(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);

GdkPopupLayout *obj = gdk_popup_layout_new(GdkRectangle_val(arg1), GdkGravity_val(arg2), GdkGravity_val(arg3));

CAMLreturn(Val_GdkPopupLayout(obj));
}
CAMLexport CAMLprim value ml_gdk_popup_layout_set_surface_anchor(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_popup_layout_set_surface_anchor(GdkPopupLayout_val(self), GdkGravity_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,2,0)

CAMLexport CAMLprim value ml_gdk_popup_layout_set_shadow_width(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

gdk_popup_layout_set_shadow_width(GdkPopupLayout_val(self), Int_val(arg1), Int_val(arg2), Int_val(arg3), Int_val(arg4));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gdk_popup_layout_set_shadow_width(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("PopupLayout requires GTK >= 4.2");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_popup_layout_set_rect_anchor(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_popup_layout_set_rect_anchor(GdkPopupLayout_val(self), GdkGravity_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_popup_layout_set_offset(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gdk_popup_layout_set_offset(GdkPopupLayout_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_popup_layout_set_anchor_rect(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_popup_layout_set_anchor_rect(GdkPopupLayout_val(self), GdkRectangle_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_popup_layout_set_anchor_hints(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_popup_layout_set_anchor_hints(GdkPopupLayout_val(self), GdkAnchorHints_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_popup_layout_ref(value self)
{
CAMLparam1(self);

GdkPopupLayout* result = gdk_popup_layout_ref(GdkPopupLayout_val(self));
CAMLreturn(Val_GdkPopupLayout(result));
}

CAMLexport CAMLprim value ml_gdk_popup_layout_get_surface_anchor(value self)
{
CAMLparam1(self);

GdkGravity result = gdk_popup_layout_get_surface_anchor(GdkPopupLayout_val(self));
CAMLreturn(Val_GdkGravity(result));
}

#if GTK_CHECK_VERSION(4,2,0)

CAMLexport CAMLprim value ml_gdk_popup_layout_get_shadow_width(value self)
{
CAMLparam1(self);
int out1;
int out2;
int out3;
int out4;

gdk_popup_layout_get_shadow_width(GdkPopupLayout_val(self), &out1, &out2, &out3, &out4);
CAMLlocal1(ret);
    ret = caml_alloc(4, 0);
    Store_field(ret, 0, Val_int(out1));
    Store_field(ret, 1, Val_int(out2));
    Store_field(ret, 2, Val_int(out3));
    Store_field(ret, 3, Val_int(out4));
    CAMLreturn(ret);
}

#else

CAMLexport CAMLprim value ml_gdk_popup_layout_get_shadow_width(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PopupLayout requires GTK >= 4.2");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_popup_layout_get_rect_anchor(value self)
{
CAMLparam1(self);

GdkGravity result = gdk_popup_layout_get_rect_anchor(GdkPopupLayout_val(self));
CAMLreturn(Val_GdkGravity(result));
}

CAMLexport CAMLprim value ml_gdk_popup_layout_get_offset(value self)
{
CAMLparam1(self);
int out1;
int out2;

gdk_popup_layout_get_offset(GdkPopupLayout_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out1));
    Store_field(ret, 1, Val_int(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gdk_popup_layout_get_anchor_rect(value self)
{
CAMLparam1(self);

const GdkRectangle* result = gdk_popup_layout_get_anchor_rect(GdkPopupLayout_val(self));
if (result) result = g_boxed_copy(gdk_rectangle_get_type(), result);
CAMLreturn(Val_GdkRectangle(result));
}

CAMLexport CAMLprim value ml_gdk_popup_layout_get_anchor_hints(value self)
{
CAMLparam1(self);

GdkAnchorHints result = gdk_popup_layout_get_anchor_hints(GdkPopupLayout_val(self));
CAMLreturn(Val_GdkAnchorHints(result));
}

CAMLexport CAMLprim value ml_gdk_popup_layout_equal(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gdk_popup_layout_equal(GdkPopupLayout_val(self), GdkPopupLayout_val(arg1));
CAMLreturn(Val_bool(result));
}


CAMLprim value ml_gdk_popup_layout_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_popup_layout_get_type()));
}
