/* GENERATED CODE - DO NOT EDIT */
/* C bindings for EntryBuffer */

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


CAMLexport CAMLprim value ml_gtk_entry_buffer_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GtkEntryBuffer *obj = gtk_entry_buffer_new(String_option_val(arg1), Int_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkEntryBuffer(obj));
}
CAMLexport CAMLprim value ml_gtk_entry_buffer_set_text(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_entry_buffer_set_text(GtkEntryBuffer_val(self), String_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_buffer_set_max_length(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_entry_buffer_set_max_length(GtkEntryBuffer_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_buffer_insert_text(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

guint result = gtk_entry_buffer_insert_text(GtkEntryBuffer_val(self), Int_val(arg1), String_val(arg2), Int_val(arg3));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_entry_buffer_get_text(value self)
{
CAMLparam1(self);

const char* result = gtk_entry_buffer_get_text(GtkEntryBuffer_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_entry_buffer_get_max_length(value self)
{
CAMLparam1(self);

int result = gtk_entry_buffer_get_max_length(GtkEntryBuffer_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_entry_buffer_get_length(value self)
{
CAMLparam1(self);

guint result = gtk_entry_buffer_get_length(GtkEntryBuffer_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_entry_buffer_get_bytes(value self)
{
CAMLparam1(self);

gsize result = gtk_entry_buffer_get_bytes(GtkEntryBuffer_val(self));
CAMLreturn(Val_gsize(result));
}

CAMLexport CAMLprim value ml_gtk_entry_buffer_emit_inserted_text(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gtk_entry_buffer_emit_inserted_text(GtkEntryBuffer_val(self), Int_val(arg1), String_val(arg2), Int_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_buffer_emit_deleted_text(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_entry_buffer_emit_deleted_text(GtkEntryBuffer_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_entry_buffer_delete_text(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

guint result = gtk_entry_buffer_delete_text(GtkEntryBuffer_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_int(result));
}


CAMLprim value ml_gtk_entry_buffer_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_entry_buffer_get_type()));
}
