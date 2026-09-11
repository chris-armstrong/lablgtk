/* GENERATED CODE - DO NOT EDIT */
/* C bindings for KeyEvent */

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


CAMLexport CAMLprim value ml_gdk_key_event_matches(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

GdkKeyMatch result = gdk_key_event_matches(GdkKeyEvent_val(self), Int_val(arg1), GdkModifierType_val(arg2));
CAMLreturn(Val_GdkKeyMatch(result));
}

CAMLexport CAMLprim value ml_gdk_key_event_is_modifier(value self)
{
CAMLparam1(self);

gboolean result = gdk_key_event_is_modifier(GdkKeyEvent_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_key_event_get_match(value self)
{
CAMLparam1(self);
guint out1;
GdkModifierType out2;

gboolean result = gdk_key_event_get_match(GdkKeyEvent_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_int(out1));
    Store_field(ret, 2, Val_GdkModifierType(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gdk_key_event_get_level(value self)
{
CAMLparam1(self);

guint result = gdk_key_event_get_level(GdkKeyEvent_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_key_event_get_layout(value self)
{
CAMLparam1(self);

guint result = gdk_key_event_get_layout(GdkKeyEvent_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_key_event_get_keyval(value self)
{
CAMLparam1(self);

guint result = gdk_key_event_get_keyval(GdkKeyEvent_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_key_event_get_keycode(value self)
{
CAMLparam1(self);

guint result = gdk_key_event_get_keycode(GdkKeyEvent_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_key_event_get_consumed_modifiers(value self)
{
CAMLparam1(self);

GdkModifierType result = gdk_key_event_get_consumed_modifiers(GdkKeyEvent_val(self));
CAMLreturn(Val_GdkModifierType(result));
}

GType gdk_key_event_get_type (void);


CAMLprim value ml_gdk_key_event_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_key_event_get_type()));
}
