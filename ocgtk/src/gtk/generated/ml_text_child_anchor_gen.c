/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TextChildAnchor */

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


CAMLexport CAMLprim value ml_gtk_text_child_anchor_new(value unit)
{
CAMLparam1(unit);

GtkTextChildAnchor *obj = gtk_text_child_anchor_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkTextChildAnchor(obj));
}
#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gtk_text_child_anchor_new_with_replacement(value arg1)
{
CAMLparam1(arg1);

GtkTextChildAnchor *obj = gtk_text_child_anchor_new_with_replacement(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkTextChildAnchor(obj));
}
#else

CAMLexport CAMLprim value ml_gtk_text_child_anchor_new_with_replacement(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("TextChildAnchor requires GTK >= 4.6");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_text_child_anchor_get_widgets(value self)
{
CAMLparam1(self);
guint out1;

GtkWidget** result = gtk_text_child_anchor_get_widgets(GtkTextChildAnchor_val(self), &out1);
    int result_length = out1;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, Val_GtkWidget(result[i]));
    }
    g_free(result);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, ml_result);
    Store_field(ret, 1, Val_int(out1));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_text_child_anchor_get_deleted(value self)
{
CAMLparam1(self);

gboolean result = gtk_text_child_anchor_get_deleted(GtkTextChildAnchor_val(self));
CAMLreturn(Val_bool(result));
}

GType gtk_text_child_anchor_get_type (void);


CAMLprim value ml_gtk_text_child_anchor_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_text_child_anchor_get_type()));
}
