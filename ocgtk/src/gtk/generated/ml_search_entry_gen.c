/* GENERATED CODE - DO NOT EDIT */
/* C bindings for SearchEntry */

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


CAMLexport CAMLprim value ml_gtk_search_entry_new(value unit)
{
CAMLparam1(unit);

GtkSearchEntry *obj = gtk_search_entry_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkSearchEntry(obj));
}
#if GTK_CHECK_VERSION(4,8,0)

CAMLexport CAMLprim value ml_gtk_search_entry_set_search_delay(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_search_entry_set_search_delay(GtkSearchEntry_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_search_entry_set_search_delay(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SearchEntry requires GTK >= 4.8");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,10,0)

CAMLexport CAMLprim value ml_gtk_search_entry_set_placeholder_text(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_search_entry_set_placeholder_text(GtkSearchEntry_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_search_entry_set_placeholder_text(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SearchEntry requires GTK >= 4.10");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_search_entry_set_key_capture_widget(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_search_entry_set_key_capture_widget(GtkSearchEntry_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gtk_search_entry_set_input_purpose(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_search_entry_set_input_purpose(GtkSearchEntry_val(self), GtkInputPurpose_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_search_entry_set_input_purpose(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SearchEntry requires GTK >= 4.14");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gtk_search_entry_set_input_hints(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_search_entry_set_input_hints(GtkSearchEntry_val(self), GtkInputHints_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_search_entry_set_input_hints(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SearchEntry requires GTK >= 4.14");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,8,0)

CAMLexport CAMLprim value ml_gtk_search_entry_get_search_delay(value self)
{
CAMLparam1(self);

guint result = gtk_search_entry_get_search_delay(GtkSearchEntry_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_gtk_search_entry_get_search_delay(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SearchEntry requires GTK >= 4.8");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,10,0)

CAMLexport CAMLprim value ml_gtk_search_entry_get_placeholder_text(value self)
{
CAMLparam1(self);

const char* result = gtk_search_entry_get_placeholder_text(GtkSearchEntry_val(self));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_gtk_search_entry_get_placeholder_text(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SearchEntry requires GTK >= 4.10");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_search_entry_get_key_capture_widget(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_search_entry_get_key_capture_widget(GtkSearchEntry_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gtk_search_entry_get_input_purpose(value self)
{
CAMLparam1(self);

GtkInputPurpose result = gtk_search_entry_get_input_purpose(GtkSearchEntry_val(self));
CAMLreturn(Val_GtkInputPurpose(result));
}

#else

CAMLexport CAMLprim value ml_gtk_search_entry_get_input_purpose(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SearchEntry requires GTK >= 4.14");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gtk_search_entry_get_input_hints(value self)
{
CAMLparam1(self);

GtkInputHints result = gtk_search_entry_get_input_hints(GtkSearchEntry_val(self));
CAMLreturn(Val_GtkInputHints(result));
}

#else

CAMLexport CAMLprim value ml_gtk_search_entry_get_input_hints(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SearchEntry requires GTK >= 4.14");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_search_entry_get_activates_default(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkSearchEntry *obj = (GtkSearchEntry *)GtkSearchEntry_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "activates-default");
if (pspec == NULL) caml_failwith("ml_gtk_search_entry_get_activates_default: property 'activates-default' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "activates-default", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gtk_search_entry_set_activates_default(value self, value new_value)
{
    CAMLparam2(self, new_value);
GtkSearchEntry *obj = (GtkSearchEntry *)GtkSearchEntry_val(self);
    gboolean *c_value = Bool_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "activates-default");
if (pspec == NULL) caml_failwith("ml_gtk_search_entry_set_activates_default: property 'activates-default' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_boolean(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "activates-default", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

GType gtk_search_entry_get_type (void);


CAMLprim value ml_gtk_search_entry_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_search_entry_get_type()));
}
