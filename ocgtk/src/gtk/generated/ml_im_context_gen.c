/* GENERATED CODE - DO NOT EDIT */
/* C bindings for IMContext */

#include <gtk/gtk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"
#include "converters.h"

#include <gtk/gtk.h>
/* Include library-specific type conversions and forward declarations */
#include "gtk_decls.h"


CAMLexport CAMLprim value ml_gtk_im_context_set_use_preedit(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_im_context_set_use_preedit(GtkIMContext_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,2,0)

CAMLexport CAMLprim value ml_gtk_im_context_set_surrounding_with_selection(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

gtk_im_context_set_surrounding_with_selection(GtkIMContext_val(self), String_val(arg1), Int_val(arg2), Int_val(arg3), Int_val(arg4));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_im_context_set_surrounding_with_selection(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("IMContext requires GTK >= 4.2");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_im_context_set_surrounding(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_im_context_set_surrounding(GtkIMContext_val(self), String_val(arg1), Int_val(arg2), Int_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_im_context_set_cursor_location(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_im_context_set_cursor_location(GtkIMContext_val(self), GdkRectangle_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_im_context_set_client_widget(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_im_context_set_client_widget(GtkIMContext_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_im_context_reset(value self)
{
CAMLparam1(self);

gtk_im_context_reset(GtkIMContext_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_im_context_focus_out(value self)
{
CAMLparam1(self);

gtk_im_context_focus_out(GtkIMContext_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_im_context_focus_in(value self)
{
CAMLparam1(self);

gtk_im_context_focus_in(GtkIMContext_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_im_context_filter_keypress(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_im_context_filter_keypress(GtkIMContext_val(self), GdkEvent_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_im_context_filter_key_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam3(arg5, arg6, arg7);

gboolean result = gtk_im_context_filter_key(GtkIMContext_val(self), Bool_val(arg1), GdkSurface_val(arg2), GdkDevice_val(arg3), UInt32_val(arg4), Int_val(arg5), GdkModifierType_val(arg6), Int_val(arg7));
CAMLreturn(Val_bool(result));}

CAMLexport CAMLprim value ml_gtk_im_context_filter_key_bytecode(value * argv, int argn)
{
return ml_gtk_im_context_filter_key_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
}

CAMLexport CAMLprim value ml_gtk_im_context_delete_surrounding(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = gtk_im_context_delete_surrounding(GtkIMContext_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_bool(result));
}

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gtk_im_context_activate_osk(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_im_context_activate_osk(GtkIMContext_val(self), Option_val(arg1, GdkEvent_val, NULL));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gtk_im_context_activate_osk(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("IMContext requires GTK >= 4.14");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_im_context_get_input_hints(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkIMContext *obj = (GtkIMContext *)GtkIMContext_val(self);
    GtkInputHints prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "input-hints");
if (pspec == NULL) caml_failwith("ml_gtk_im_context_get_input_hints: property 'input-hints' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "input-hints", &prop_gvalue);
          prop_value = (GtkInputHints)g_value_get_flags(&prop_gvalue);

      result = Val_GtkInputHints(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_im_context_set_input_hints(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkIMContext *obj = (GtkIMContext *)GtkIMContext_val(self);
    GtkInputHints c_value = GtkInputHints_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "input-hints");
if (pspec == NULL) caml_failwith("ml_gtk_im_context_set_input_hints: property 'input-hints' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_flags(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "input-hints", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_im_context_get_input_purpose(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkIMContext *obj = (GtkIMContext *)GtkIMContext_val(self);
    GtkInputPurpose prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "input-purpose");
if (pspec == NULL) caml_failwith("ml_gtk_im_context_get_input_purpose: property 'input-purpose' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "input-purpose", &prop_gvalue);
          prop_value = (GtkInputPurpose)g_value_get_enum(&prop_gvalue);

      result = Val_GtkInputPurpose(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_im_context_set_input_purpose(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkIMContext *obj = (GtkIMContext *)GtkIMContext_val(self);
    GtkInputPurpose c_value = GtkInputPurpose_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "input-purpose");
if (pspec == NULL) caml_failwith("ml_gtk_im_context_set_input_purpose: property 'input-purpose' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "input-purpose", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

GType gtk_im_context_get_type (void);


CAMLprim value ml_gtk_im_context_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_im_context_get_type()));
}
