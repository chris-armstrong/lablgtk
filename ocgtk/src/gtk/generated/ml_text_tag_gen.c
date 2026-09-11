/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TextTag */

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


CAMLexport CAMLprim value ml_gtk_text_tag_new(value arg1)
{
CAMLparam1(arg1);

GtkTextTag *obj = gtk_text_tag_new(String_option_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkTextTag(obj));
}
CAMLexport CAMLprim value ml_gtk_text_tag_set_priority(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_tag_set_priority(GtkTextTag_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_priority(value self)
{
CAMLparam1(self);

int result = gtk_text_tag_get_priority(GtkTextTag_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_text_tag_changed(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_text_tag_changed(GtkTextTag_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_accumulative_margin(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "accumulative-margin");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_accumulative_margin: property 'accumulative-margin' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "accumulative-margin", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_accumulative_margin(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "accumulative-margin");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_accumulative_margin: property 'accumulative-margin' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "accumulative-margin", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_allow_breaks(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "allow-breaks");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_allow_breaks: property 'allow-breaks' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "allow-breaks", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_allow_breaks(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "allow-breaks");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_allow_breaks: property 'allow-breaks' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "allow-breaks", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_allow_breaks_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "allow-breaks-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_allow_breaks_set: property 'allow-breaks-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "allow-breaks-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_allow_breaks_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "allow-breaks-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_allow_breaks_set: property 'allow-breaks-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "allow-breaks-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_set_background(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "background");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_background: property 'background' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "background", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_background_full_height(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "background-full-height");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_background_full_height: property 'background-full-height' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "background-full-height", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_background_full_height(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "background-full-height");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_background_full_height: property 'background-full-height' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "background-full-height", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_background_full_height_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "background-full-height-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_background_full_height_set: property 'background-full-height-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "background-full-height-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_background_full_height_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "background-full-height-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_background_full_height_set: property 'background-full-height-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "background-full-height-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_background_rgba(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    GdkRGBA *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "background-rgba");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_background_rgba: property 'background-rgba' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "background-rgba", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GdkRGBA(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_background_rgba(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    GdkRGBA *c_value = GdkRGBA_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "background-rgba");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_background_rgba: property 'background-rgba' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          caml_failwith("unsupported property type");
g_object_set_property(G_OBJECT(obj), "background-rgba", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_background_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "background-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_background_set: property 'background-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "background-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_background_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "background-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_background_set: property 'background-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "background-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_direction(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    GtkTextDirection prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "direction");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_direction: property 'direction' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "direction", &prop_gvalue);
          prop_value = (GtkTextDirection)g_value_get_enum(&prop_gvalue);

      result = Val_GtkTextDirection(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_direction(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    GtkTextDirection c_value = GtkTextDirection_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "direction");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_direction: property 'direction' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "direction", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_editable(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "editable");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_editable: property 'editable' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "editable", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_editable(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "editable");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_editable: property 'editable' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "editable", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_editable_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "editable-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_editable_set: property 'editable-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "editable-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_editable_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "editable-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_editable_set: property 'editable-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "editable-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_fallback(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "fallback");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_fallback: property 'fallback' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "fallback", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_fallback(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "fallback");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_fallback: property 'fallback' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "fallback", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_fallback_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "fallback-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_fallback_set: property 'fallback-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "fallback-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_fallback_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "fallback-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_fallback_set: property 'fallback-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "fallback-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_family(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "family");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_family: property 'family' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "family", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_family(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "family");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_family: property 'family' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "family", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_family_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "family-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_family_set: property 'family-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "family-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_family_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "family-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_family_set: property 'family-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "family-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_font(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "font");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_font: property 'font' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "font", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_font(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "font");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_font: property 'font' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "font", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_font_desc(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    PangoFontDescription *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "font-desc");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_font_desc: property 'font-desc' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "font-desc", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_PangoFontDescription(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_font_desc(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    PangoFontDescription *c_value = PangoFontDescription_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "font-desc");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_font_desc: property 'font-desc' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          caml_failwith("unsupported property type");
g_object_set_property(G_OBJECT(obj), "font-desc", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_font_features(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "font-features");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_font_features: property 'font-features' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "font-features", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_font_features(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "font-features");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_font_features: property 'font-features' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "font-features", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_font_features_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "font-features-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_font_features_set: property 'font-features-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "font-features-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_font_features_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "font-features-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_font_features_set: property 'font-features-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "font-features-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_set_foreground(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "foreground");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_foreground: property 'foreground' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "foreground", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_foreground_rgba(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    GdkRGBA *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "foreground-rgba");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_foreground_rgba: property 'foreground-rgba' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "foreground-rgba", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GdkRGBA(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_foreground_rgba(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    GdkRGBA *c_value = GdkRGBA_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "foreground-rgba");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_foreground_rgba: property 'foreground-rgba' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          caml_failwith("unsupported property type");
g_object_set_property(G_OBJECT(obj), "foreground-rgba", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_foreground_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "foreground-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_foreground_set: property 'foreground-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "foreground-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_foreground_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "foreground-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_foreground_set: property 'foreground-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "foreground-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_indent(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "indent");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_indent: property 'indent' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "indent", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_indent(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "indent");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_indent: property 'indent' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "indent", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_indent_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "indent-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_indent_set: property 'indent-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "indent-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_indent_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "indent-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_indent_set: property 'indent-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "indent-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_insert_hyphens(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "insert-hyphens");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_insert_hyphens: property 'insert-hyphens' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "insert-hyphens", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_insert_hyphens(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "insert-hyphens");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_insert_hyphens: property 'insert-hyphens' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "insert-hyphens", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_insert_hyphens_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "insert-hyphens-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_insert_hyphens_set: property 'insert-hyphens-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "insert-hyphens-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_insert_hyphens_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "insert-hyphens-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_insert_hyphens_set: property 'insert-hyphens-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "insert-hyphens-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_invisible(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "invisible");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_invisible: property 'invisible' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "invisible", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_invisible(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "invisible");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_invisible: property 'invisible' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "invisible", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_invisible_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "invisible-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_invisible_set: property 'invisible-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "invisible-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_invisible_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "invisible-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_invisible_set: property 'invisible-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "invisible-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_justification(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    GtkJustification prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "justification");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_justification: property 'justification' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "justification", &prop_gvalue);
          prop_value = (GtkJustification)g_value_get_enum(&prop_gvalue);

      result = Val_GtkJustification(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_justification(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    GtkJustification c_value = GtkJustification_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "justification");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_justification: property 'justification' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "justification", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_justification_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "justification-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_justification_set: property 'justification-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "justification-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_justification_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "justification-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_justification_set: property 'justification-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "justification-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_language(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "language");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_language: property 'language' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "language", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_language(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "language");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_language: property 'language' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "language", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_language_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "language-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_language_set: property 'language-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "language-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_language_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "language-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_language_set: property 'language-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "language-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_left_margin(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "left-margin");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_left_margin: property 'left-margin' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "left-margin", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_left_margin(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "left-margin");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_left_margin: property 'left-margin' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "left-margin", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_left_margin_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "left-margin-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_left_margin_set: property 'left-margin-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "left-margin-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_left_margin_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "left-margin-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_left_margin_set: property 'left-margin-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "left-margin-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_letter_spacing(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "letter-spacing");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_letter_spacing: property 'letter-spacing' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "letter-spacing", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_letter_spacing(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "letter-spacing");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_letter_spacing: property 'letter-spacing' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "letter-spacing", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_letter_spacing_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "letter-spacing-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_letter_spacing_set: property 'letter-spacing-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "letter-spacing-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_letter_spacing_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "letter-spacing-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_letter_spacing_set: property 'letter-spacing-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "letter-spacing-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gtk_text_tag_get_line_height(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gfloat prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "line-height");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_line_height: property 'line-height' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "line-height", &prop_gvalue);
          prop_value = g_value_get_float(&prop_gvalue);

      result = caml_copy_double(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_gtk_text_tag_get_line_height(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TextTag requires GTK >= 4.6");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gtk_text_tag_set_line_height(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gfloat c_value = Double_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "line-height");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_line_height: property 'line-height' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_float(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "line-height", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_text_tag_set_line_height(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TextTag requires GTK >= 4.6");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_text_tag_get_line_height_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "line-height-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_line_height_set: property 'line-height-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "line-height-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_line_height_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "line-height-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_line_height_set: property 'line-height-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "line-height-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_name(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "name");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_name: property 'name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "name", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_get_overline(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    PangoOverline prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "overline");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_overline: property 'overline' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "overline", &prop_gvalue);
          prop_value = (PangoOverline)g_value_get_enum(&prop_gvalue);

      result = Val_PangoOverline(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_overline(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    PangoOverline c_value = PangoOverline_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "overline");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_overline: property 'overline' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "overline", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_overline_rgba(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    GdkRGBA *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "overline-rgba");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_overline_rgba: property 'overline-rgba' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "overline-rgba", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GdkRGBA(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_overline_rgba(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    GdkRGBA *c_value = GdkRGBA_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "overline-rgba");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_overline_rgba: property 'overline-rgba' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          caml_failwith("unsupported property type");
g_object_set_property(G_OBJECT(obj), "overline-rgba", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_overline_rgba_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "overline-rgba-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_overline_rgba_set: property 'overline-rgba-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "overline-rgba-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_overline_rgba_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "overline-rgba-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_overline_rgba_set: property 'overline-rgba-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "overline-rgba-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_overline_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "overline-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_overline_set: property 'overline-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "overline-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_overline_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "overline-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_overline_set: property 'overline-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "overline-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_set_paragraph_background(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    ML_DECL_CONST_STRING(c_value, String_val(new_value));
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "paragraph-background");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_paragraph_background: property 'paragraph-background' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_string(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "paragraph-background", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_paragraph_background_rgba(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    GdkRGBA *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "paragraph-background-rgba");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_paragraph_background_rgba: property 'paragraph-background-rgba' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "paragraph-background-rgba", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GdkRGBA(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_paragraph_background_rgba(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    GdkRGBA *c_value = GdkRGBA_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "paragraph-background-rgba");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_paragraph_background_rgba: property 'paragraph-background-rgba' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          caml_failwith("unsupported property type");
g_object_set_property(G_OBJECT(obj), "paragraph-background-rgba", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_paragraph_background_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "paragraph-background-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_paragraph_background_set: property 'paragraph-background-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "paragraph-background-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_paragraph_background_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "paragraph-background-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_paragraph_background_set: property 'paragraph-background-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "paragraph-background-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_pixels_above_lines(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "pixels-above-lines");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_pixels_above_lines: property 'pixels-above-lines' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "pixels-above-lines", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_pixels_above_lines(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "pixels-above-lines");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_pixels_above_lines: property 'pixels-above-lines' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "pixels-above-lines", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_pixels_above_lines_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "pixels-above-lines-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_pixels_above_lines_set: property 'pixels-above-lines-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "pixels-above-lines-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_pixels_above_lines_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "pixels-above-lines-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_pixels_above_lines_set: property 'pixels-above-lines-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "pixels-above-lines-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_pixels_below_lines(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "pixels-below-lines");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_pixels_below_lines: property 'pixels-below-lines' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "pixels-below-lines", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_pixels_below_lines(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "pixels-below-lines");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_pixels_below_lines: property 'pixels-below-lines' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "pixels-below-lines", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_pixels_below_lines_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "pixels-below-lines-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_pixels_below_lines_set: property 'pixels-below-lines-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "pixels-below-lines-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_pixels_below_lines_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "pixels-below-lines-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_pixels_below_lines_set: property 'pixels-below-lines-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "pixels-below-lines-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_pixels_inside_wrap(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "pixels-inside-wrap");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_pixels_inside_wrap: property 'pixels-inside-wrap' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "pixels-inside-wrap", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_pixels_inside_wrap(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "pixels-inside-wrap");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_pixels_inside_wrap: property 'pixels-inside-wrap' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "pixels-inside-wrap", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_pixels_inside_wrap_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "pixels-inside-wrap-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_pixels_inside_wrap_set: property 'pixels-inside-wrap-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "pixels-inside-wrap-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_pixels_inside_wrap_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "pixels-inside-wrap-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_pixels_inside_wrap_set: property 'pixels-inside-wrap-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "pixels-inside-wrap-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_right_margin(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "right-margin");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_right_margin: property 'right-margin' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "right-margin", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_right_margin(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "right-margin");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_right_margin: property 'right-margin' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "right-margin", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_right_margin_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "right-margin-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_right_margin_set: property 'right-margin-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "right-margin-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_right_margin_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "right-margin-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_right_margin_set: property 'right-margin-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "right-margin-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_rise(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "rise");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_rise: property 'rise' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "rise", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_rise(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "rise");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_rise: property 'rise' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "rise", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_rise_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "rise-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_rise_set: property 'rise-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "rise-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_rise_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "rise-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_rise_set: property 'rise-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "rise-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_scale(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gdouble prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "scale");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_scale: property 'scale' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "scale", &prop_gvalue);
          prop_value = g_value_get_double(&prop_gvalue);

      result = caml_copy_double(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_scale(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gdouble c_value = Double_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "scale");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_scale: property 'scale' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_double(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "scale", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_scale_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "scale-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_scale_set: property 'scale-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "scale-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_scale_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "scale-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_scale_set: property 'scale-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "scale-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gtk_text_tag_get_sentence(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "sentence");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_sentence: property 'sentence' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "sentence", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_gtk_text_tag_get_sentence(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TextTag requires GTK >= 4.6");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gtk_text_tag_set_sentence(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "sentence");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_sentence: property 'sentence' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "sentence", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_text_tag_set_sentence(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TextTag requires GTK >= 4.6");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_text_tag_get_sentence_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "sentence-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_sentence_set: property 'sentence-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "sentence-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_sentence_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "sentence-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_sentence_set: property 'sentence-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "sentence-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_show_spaces(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    PangoShowFlags prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "show-spaces");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_show_spaces: property 'show-spaces' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "show-spaces", &prop_gvalue);
          prop_value = (PangoShowFlags)g_value_get_flags(&prop_gvalue);

      result = Val_PangoShowFlags(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_show_spaces(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    PangoShowFlags c_value = PangoShowFlags_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "show-spaces");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_show_spaces: property 'show-spaces' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_flags(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "show-spaces", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_show_spaces_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "show-spaces-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_show_spaces_set: property 'show-spaces-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "show-spaces-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_show_spaces_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "show-spaces-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_show_spaces_set: property 'show-spaces-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "show-spaces-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_size(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "size");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_size: property 'size' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "size", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_size(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "size");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_size: property 'size' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "size", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_size_points(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gdouble prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "size-points");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_size_points: property 'size-points' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "size-points", &prop_gvalue);
          prop_value = g_value_get_double(&prop_gvalue);

      result = caml_copy_double(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_size_points(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gdouble c_value = Double_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "size-points");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_size_points: property 'size-points' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_double(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "size-points", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_size_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "size-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_size_set: property 'size-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "size-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_size_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "size-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_size_set: property 'size-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "size-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_stretch(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    PangoStretch prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "stretch");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_stretch: property 'stretch' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "stretch", &prop_gvalue);
          prop_value = (PangoStretch)g_value_get_enum(&prop_gvalue);

      result = Val_PangoStretch(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_stretch(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    PangoStretch c_value = PangoStretch_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "stretch");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_stretch: property 'stretch' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "stretch", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_stretch_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "stretch-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_stretch_set: property 'stretch-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "stretch-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_stretch_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "stretch-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_stretch_set: property 'stretch-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "stretch-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_strikethrough(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "strikethrough");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_strikethrough: property 'strikethrough' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "strikethrough", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_strikethrough(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "strikethrough");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_strikethrough: property 'strikethrough' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "strikethrough", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_strikethrough_rgba(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    GdkRGBA *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "strikethrough-rgba");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_strikethrough_rgba: property 'strikethrough-rgba' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "strikethrough-rgba", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GdkRGBA(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_strikethrough_rgba(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    GdkRGBA *c_value = GdkRGBA_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "strikethrough-rgba");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_strikethrough_rgba: property 'strikethrough-rgba' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          caml_failwith("unsupported property type");
g_object_set_property(G_OBJECT(obj), "strikethrough-rgba", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_strikethrough_rgba_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "strikethrough-rgba-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_strikethrough_rgba_set: property 'strikethrough-rgba-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "strikethrough-rgba-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_strikethrough_rgba_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "strikethrough-rgba-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_strikethrough_rgba_set: property 'strikethrough-rgba-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "strikethrough-rgba-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_strikethrough_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "strikethrough-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_strikethrough_set: property 'strikethrough-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "strikethrough-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_strikethrough_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "strikethrough-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_strikethrough_set: property 'strikethrough-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "strikethrough-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_style(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    PangoStyle prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "style");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_style: property 'style' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "style", &prop_gvalue);
          prop_value = (PangoStyle)g_value_get_enum(&prop_gvalue);

      result = Val_PangoStyle(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_style(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    PangoStyle c_value = PangoStyle_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "style");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_style: property 'style' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "style", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_style_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "style-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_style_set: property 'style-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "style-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_style_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "style-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_style_set: property 'style-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "style-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_tabs(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    PangoTabArray *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "tabs");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_tabs: property 'tabs' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "tabs", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_PangoTabArray(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_tabs(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    PangoTabArray *c_value = PangoTabArray_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "tabs");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_tabs: property 'tabs' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          caml_failwith("unsupported property type");
g_object_set_property(G_OBJECT(obj), "tabs", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_tabs_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "tabs-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_tabs_set: property 'tabs-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "tabs-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_tabs_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "tabs-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_tabs_set: property 'tabs-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "tabs-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_gtk_text_tag_get_text_transform(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    PangoTextTransform prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "text-transform");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_text_transform: property 'text-transform' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "text-transform", &prop_gvalue);
          prop_value = (PangoTextTransform)g_value_get_enum(&prop_gvalue);

      result = Val_PangoTextTransform(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_gtk_text_tag_get_text_transform(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TextTag requires GTK >= 1.50");
return Val_unit;
}
#endif

#if PANGO_VERSION_CHECK(1,50,0)

CAMLexport CAMLprim value ml_gtk_text_tag_set_text_transform(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    PangoTextTransform c_value = PangoTextTransform_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "text-transform");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_text_transform: property 'text-transform' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "text-transform", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_text_tag_set_text_transform(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TextTag requires GTK >= 1.50");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_text_tag_get_text_transform_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "text-transform-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_text_transform_set: property 'text-transform-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "text-transform-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_text_transform_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "text-transform-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_text_transform_set: property 'text-transform-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "text-transform-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_underline(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    PangoUnderline prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "underline");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_underline: property 'underline' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "underline", &prop_gvalue);
          prop_value = (PangoUnderline)g_value_get_enum(&prop_gvalue);

      result = Val_PangoUnderline(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_underline(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    PangoUnderline c_value = PangoUnderline_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "underline");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_underline: property 'underline' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "underline", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_underline_rgba(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    GdkRGBA *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "underline-rgba");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_underline_rgba: property 'underline-rgba' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "underline-rgba", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GdkRGBA(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_underline_rgba(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    GdkRGBA *c_value = GdkRGBA_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "underline-rgba");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_underline_rgba: property 'underline-rgba' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          caml_failwith("unsupported property type");
g_object_set_property(G_OBJECT(obj), "underline-rgba", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_underline_rgba_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "underline-rgba-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_underline_rgba_set: property 'underline-rgba-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "underline-rgba-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_underline_rgba_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "underline-rgba-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_underline_rgba_set: property 'underline-rgba-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "underline-rgba-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_underline_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "underline-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_underline_set: property 'underline-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "underline-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_underline_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "underline-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_underline_set: property 'underline-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "underline-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_variant(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    PangoVariant prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "variant");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_variant: property 'variant' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "variant", &prop_gvalue);
          prop_value = (PangoVariant)g_value_get_enum(&prop_gvalue);

      result = Val_PangoVariant(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_variant(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    PangoVariant c_value = PangoVariant_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "variant");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_variant: property 'variant' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "variant", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_variant_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "variant-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_variant_set: property 'variant-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "variant-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_variant_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "variant-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_variant_set: property 'variant-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "variant-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_weight(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "weight");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_weight: property 'weight' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "weight", &prop_gvalue);
          prop_value = g_value_get_int(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_weight(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gint c_value = Int_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "weight");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_weight: property 'weight' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_int(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "weight", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_weight_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "weight-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_weight_set: property 'weight-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "weight-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_weight_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "weight-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_weight_set: property 'weight-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "weight-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gtk_text_tag_get_word(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "word");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_word: property 'word' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "word", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_gtk_text_tag_get_word(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TextTag requires GTK >= 4.6");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gtk_text_tag_set_word(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "word");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_word: property 'word' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "word", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_text_tag_set_word(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("TextTag requires GTK >= 4.6");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_text_tag_get_word_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "word-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_word_set: property 'word-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "word-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_word_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "word-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_word_set: property 'word-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "word-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_wrap_mode(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    GtkWrapMode prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "wrap-mode");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_wrap_mode: property 'wrap-mode' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "wrap-mode", &prop_gvalue);
          prop_value = (GtkWrapMode)g_value_get_enum(&prop_gvalue);

      result = Val_GtkWrapMode(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_wrap_mode(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    GtkWrapMode c_value = GtkWrapMode_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "wrap-mode");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_wrap_mode: property 'wrap-mode' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "wrap-mode", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_text_tag_get_wrap_mode_set(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "wrap-mode-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_get_wrap_mode_set: property 'wrap-mode-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "wrap-mode-set", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_text_tag_set_wrap_mode_set(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkTextTag *obj = (GtkTextTag *)GtkTextTag_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "wrap-mode-set");
if (pspec == NULL) caml_failwith("ml_gtk_text_tag_set_wrap_mode_set: property 'wrap-mode-set' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "wrap-mode-set", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_text_tag_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_text_tag_get_type()));
}
