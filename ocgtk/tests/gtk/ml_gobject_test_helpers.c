/**************************************************************************/
/*                ocgtk - OCaml bindings for GTK4                         */
/**************************************************************************/

#include <glib.h>
#include <glib-object.h>

#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/fail.h>
#include <caml/custom.h>

extern int ml_closure_exception_flag;
extern gpointer ml_gobject_ext_of_val(value v);

#define GClosure_val(val) (*((GClosure**)Data_custom_val(val)))

static GType test_flags_type_id = G_TYPE_INVALID;

static void ensure_test_types(void)
{
    if (test_flags_type_id != G_TYPE_INVALID)
        return;

    static GFlagsValue test_flags_values[] = {
        { 1, (gchar *)"A", (gchar *)"A" },
        { 2, (gchar *)"B", (gchar *)"B" },
        { 3, (gchar *)"AB", (gchar *)"AB" },
        { 0, NULL, NULL }
    };

    test_flags_type_id = g_flags_register_static("TestFlags", test_flags_values);
}

CAMLprim value ml_test_invoke_closure_void(value closure_val)
{
    CAMLparam1(closure_val);
    GClosure *closure = GClosure_val(closure_val);

    g_closure_invoke(closure, NULL, 0, NULL, NULL);

    CAMLreturn(Val_unit);
}

CAMLprim value ml_test_invoke_closure_int(value closure_val, value arg_val)
{
    CAMLparam2(closure_val, arg_val);
    GClosure *closure = GClosure_val(closure_val);
    GValue param = G_VALUE_INIT;

    g_value_init(&param, G_TYPE_INT);
    g_value_set_int(&param, Int_val(arg_val));

    g_closure_invoke(closure, NULL, 1, &param, NULL);

    g_value_unset(&param);

    CAMLreturn(Val_unit);
}

CAMLprim value ml_test_invoke_closure_string(value closure_val, value arg_val)
{
    CAMLparam2(closure_val, arg_val);
    GClosure *closure = GClosure_val(closure_val);
    GValue param = G_VALUE_INIT;

    g_value_init(&param, G_TYPE_STRING);
    g_value_set_string(&param, String_val(arg_val));

    g_closure_invoke(closure, NULL, 1, &param, NULL);

    g_value_unset(&param);

    CAMLreturn(Val_unit);
}

CAMLprim value ml_test_invoke_closure_two_ints(value closure_val, value arg1_val, value arg2_val)
{
    CAMLparam3(closure_val, arg1_val, arg2_val);
    GClosure *closure = GClosure_val(closure_val);
    GValue params[2] = {G_VALUE_INIT, G_VALUE_INIT};

    g_value_init(&params[0], G_TYPE_INT);
    g_value_set_int(&params[0], Int_val(arg1_val));

    g_value_init(&params[1], G_TYPE_INT);
    g_value_set_int(&params[1], Int_val(arg2_val));

    g_closure_invoke(closure, NULL, 2, params, NULL);

    g_value_unset(&params[0]);
    g_value_unset(&params[1]);

    CAMLreturn(Val_unit);
}

CAMLprim value ml_test_invoke_closure_boolean(value closure_val, value arg_val)
{
    CAMLparam2(closure_val, arg_val);
    GClosure *closure = GClosure_val(closure_val);
    GValue param = G_VALUE_INIT;

    g_value_init(&param, G_TYPE_BOOLEAN);
    g_value_set_boolean(&param, Bool_val(arg_val));

    g_closure_invoke(closure, NULL, 1, &param, NULL);

    g_value_unset(&param);

    CAMLreturn(Val_unit);
}

CAMLprim value ml_test_invoke_closure_double(value closure_val, value arg_val)
{
    CAMLparam2(closure_val, arg_val);
    GClosure *closure = GClosure_val(closure_val);
    GValue param = G_VALUE_INIT;

    g_value_init(&param, G_TYPE_DOUBLE);
    g_value_set_double(&param, Double_val(arg_val));

    g_closure_invoke(closure, NULL, 1, &param, NULL);

    g_value_unset(&param);

    CAMLreturn(Val_unit);
}

/* Invoke a closure with two params: an int and an object typed with the
 * object's *concrete* GType (a large dynamic type id, unlike the fundamental
 * G_TYPE_OBJECT used by invoke_closure_mixed_return_bool). Used to exercise
 * the marshaller's argv handling: a raw C pointer stored in a scanned OCaml
 * block field is misread by the GC as a heap block whose header is the
 * GValue's g_type, so only large derived type ids actually make the GC walk
 * off the param array into the C stack. */
CAMLprim value ml_test_invoke_closure_int_object(value closure_val,
                                                   value int_arg,
                                                   value obj_arg)
{
    CAMLparam3(closure_val, int_arg, obj_arg);
    GClosure *closure = GClosure_val(closure_val);
    GValue params[2] = {G_VALUE_INIT, G_VALUE_INIT};
    GObject *obj = G_OBJECT(ml_gobject_ext_of_val(obj_arg));

    g_value_init(&params[0], G_TYPE_INT);
    g_value_set_int(&params[0], Int_val(int_arg));

    g_value_init(&params[1], G_OBJECT_TYPE(obj));
    g_value_set_object(&params[1], obj);

    g_closure_invoke(closure, NULL, 2, params, NULL);

    g_value_unset(&params[0]);
    g_value_unset(&params[1]);

    CAMLreturn(Val_unit);
}

CAMLprim value ml_test_reset_closure_exception_flag(value unit)
{
    CAMLparam1(unit);
    ml_closure_exception_flag = 0;
    CAMLreturn(Val_unit);
}

CAMLprim value ml_test_check_closure_exception_flag(value unit)
{
    CAMLparam1(unit);
    CAMLreturn(Val_bool(ml_closure_exception_flag));
}

CAMLprim value ml_test_invoke_closure_flags_return_bool(value closure_val, value flags_val)
{
    CAMLparam2(closure_val, flags_val);
    GClosure *closure = GClosure_val(closure_val);
    GValue param = G_VALUE_INIT;
    GValue return_value = G_VALUE_INIT;

    ensure_test_types();

    g_value_init(&param, test_flags_type_id);
    g_value_set_flags(&param, Int_val(flags_val));

    g_value_init(&return_value, G_TYPE_BOOLEAN);

    g_closure_invoke(closure, &return_value, 1, &param, NULL);

    gboolean result = g_value_get_boolean(&return_value);

    g_value_unset(&param);
    g_value_unset(&return_value);

    CAMLreturn(Val_bool(result));
}

CAMLprim value ml_test_invoke_closure_mixed_return_bool(value closure_val,
                                                         value int_arg,
                                                         value string_arg,
                                                         value obj_arg)
{
    CAMLparam4(closure_val, int_arg, string_arg, obj_arg);
    GClosure *closure = GClosure_val(closure_val);
    GValue params[3] = {G_VALUE_INIT, G_VALUE_INIT, G_VALUE_INIT};
    GValue return_value = G_VALUE_INIT;

    g_value_init(&params[0], G_TYPE_INT);
    g_value_set_int(&params[0], Int_val(int_arg));

    g_value_init(&params[1], G_TYPE_STRING);
    g_value_set_string(&params[1], String_val(string_arg));

    g_value_init(&params[2], G_TYPE_OBJECT);
    if (Is_block(obj_arg)) {
        g_value_set_object(&params[2], G_OBJECT(ml_gobject_ext_of_val(Some_val(obj_arg))));
    }

    g_value_init(&return_value, G_TYPE_BOOLEAN);

    g_closure_invoke(closure, &return_value, 3, params, NULL);

    gboolean result = g_value_get_boolean(&return_value);

    g_value_unset(&params[0]);
    g_value_unset(&params[1]);
    g_value_unset(&params[2]);
    g_value_unset(&return_value);

    CAMLreturn(Val_bool(result));
}

CAMLprim value ml_test_invoke_closure_return_int(value closure_val)
{
    CAMLparam1(closure_val);
    GClosure *closure = GClosure_val(closure_val);
    GValue return_value = G_VALUE_INIT;

    g_value_init(&return_value, G_TYPE_INT);

    g_closure_invoke(closure, &return_value, 0, NULL, NULL);

    gint result = g_value_get_int(&return_value);

    g_value_unset(&return_value);

    CAMLreturn(Val_int(result));
}
