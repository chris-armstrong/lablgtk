/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FileList */

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

#if GTK_CHECK_VERSION(4,6,0)
/* Conversion functions for GdkFileList (opaque record with hidden fields) */
GdkFileList *GdkFileList_val(value v) {
  return (GdkFileList *)ml_gir_record_ptr_val(v, "GdkFileList");
}

value Val_GdkFileList(const GdkFileList *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(gdk_file_list_get_type(), ptr);
}

value Val_GdkFileList_option(const GdkFileList *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GdkFileList(ptr));
}
#endif

#if GTK_CHECK_VERSION(4,6,0)


#if GTK_CHECK_VERSION(4,8,0)

CAMLexport CAMLprim value ml_gdk_file_list_new_from_array(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
    int arg1_length = Wosize_val(arg1);
    GFile** c_arg1 = (GFile**)g_malloc(sizeof(GFile*) * arg1_length);
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = GFile_val(Field(arg1, i));
    }

GdkFileList *obj = gdk_file_list_new_from_array(c_arg1, Gsize_val(arg2));

    g_free(c_arg1);
CAMLreturn(Val_GdkFileList(obj));
}
#else

CAMLexport CAMLprim value ml_gdk_file_list_new_from_array(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("FileList requires GTK >= 4.8");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,8,0)

CAMLexport CAMLprim value ml_gdk_file_list_new_from_list(value arg1)
{
CAMLparam1(arg1);
    GSList* arg1_list = NULL;
    GSList_val_with(arg1, arg1_list, (gpointer)GFile_val(Field(_iter, 0)));

GdkFileList *obj = gdk_file_list_new_from_list(arg1_list);

    g_slist_free(arg1_list);
CAMLreturn(Val_GdkFileList(obj));
}
#else

CAMLexport CAMLprim value ml_gdk_file_list_new_from_list(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("FileList requires GTK >= 4.8");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_file_list_get_files(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = gdk_file_list_get_files(GdkFileList_val(self));
Val_GSList_with(c_result, result, item, cell, Val_GFile((gpointer)_tmp->data));
    g_slist_free(c_result);
    CAMLreturn(result);
}

GType gdk_file_list_get_type (void);


CAMLprim value ml_gdk_file_list_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_file_list_get_type()));
}

#else


CAMLexport CAMLprim value ml_gdk_file_list_new_from_array(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("FileList requires GTK >= 4.6");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_file_list_new_from_list(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("FileList requires GTK >= 4.6");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_file_list_get_files(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FileList requires GTK >= 4.6");
return Val_unit;
}


#endif
