/* GENERATED CODE - DO NOT EDIT */
/* C bindings for BuilderListItemFactory */

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


CAMLexport CAMLprim value ml_gtk_builder_list_item_factory_new_from_bytes(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GtkBuilderListItemFactory *obj = gtk_builder_list_item_factory_new_from_bytes(Option_val(arg1, GtkBuilderScope_val, NULL), GBytes_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkBuilderListItemFactory(obj));
}
CAMLexport CAMLprim value ml_gtk_builder_list_item_factory_new_from_resource(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GtkBuilderListItemFactory *obj = gtk_builder_list_item_factory_new_from_resource(Option_val(arg1, GtkBuilderScope_val, NULL), String_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkBuilderListItemFactory(obj));
}
CAMLexport CAMLprim value ml_gtk_builder_list_item_factory_get_scope(value self)
{
CAMLparam1(self);

GtkBuilderScope* result = gtk_builder_list_item_factory_get_scope(GtkBuilderListItemFactory_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkBuilderScope));
}

CAMLexport CAMLprim value ml_gtk_builder_list_item_factory_get_resource(value self)
{
CAMLparam1(self);

const char* result = gtk_builder_list_item_factory_get_resource(GtkBuilderListItemFactory_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_builder_list_item_factory_get_bytes(value self)
{
CAMLparam1(self);

GBytes* result = gtk_builder_list_item_factory_get_bytes(GtkBuilderListItemFactory_val(self));
CAMLreturn(Val_GBytes(result));
}


CAMLprim value ml_gtk_builder_list_item_factory_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_builder_list_item_factory_get_type()));
}
