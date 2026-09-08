/* test_gvalue_safety_stubs.c — OCaml C stubs for the GValue safety tests.
 *
 * ml_test_plain_record_new allocates a gir_record custom block with no
 * registered GType (box->type == 0, plain g_free finalizer). It is used to
 * check that ml_g_value_set_boxed rejects non-boxed records before GLib
 * ever sees the pointer.
 *
 * ml_test_gdk_rectangle_create mirrors the helper in
 * test_signal_value_enum_flags_stubs.c: a gir_record carrying the
 * gdk_rectangle_get_type() boxed GType. */

#include <string.h>
#include <glib.h>
#include <gtk/gtk.h>

#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/fail.h>

extern value ml_gir_record_val_ptr(const void *src);
extern value ml_gir_record_val_ptr_with_type(GType type, const void *src);

CAMLprim value ml_test_plain_record_new(value unit)
{
    CAMLparam1(unit);
    gpointer payload = g_malloc0(64);
    CAMLreturn(ml_gir_record_val_ptr(payload));
}

CAMLprim value ml_test_gdk_rectangle_create(value x_v, value y_v, value w_v,
                                            value h_v)
{
    CAMLparam4(x_v, y_v, w_v, h_v);
    GdkRectangle *r = g_new(GdkRectangle, 1);
    if (r == NULL) caml_raise_out_of_memory();
    r->x      = Int_val(x_v);
    r->y      = Int_val(y_v);
    r->width  = Int_val(w_v);
    r->height = Int_val(h_v);
    CAMLreturn(ml_gir_record_val_ptr_with_type(gdk_rectangle_get_type(), r));
}