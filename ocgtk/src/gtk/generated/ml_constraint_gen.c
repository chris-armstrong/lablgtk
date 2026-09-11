/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Constraint */

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


CAMLexport CAMLprim value ml_gtk_constraint_new_native(value arg1, value arg2, value arg3, value arg4, value arg5, value arg6, value arg7, value arg8)
{
CAMLparam5(arg1, arg2, arg3, arg4, arg5);
CAMLxparam3(arg6, arg7, arg8);

GtkConstraint *obj = gtk_constraint_new(GtkConstraintTarget_val(arg1), GtkConstraintAttribute_val(arg2), GtkConstraintRelation_val(arg3), GtkConstraintTarget_val(arg4), GtkConstraintAttribute_val(arg5), Double_val(arg6), Double_val(arg7), Int_val(arg8));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkConstraint(obj));}

CAMLexport CAMLprim value ml_gtk_constraint_new_bytecode(value * argv, int argn)
{
return ml_gtk_constraint_new_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
}

CAMLexport CAMLprim value ml_gtk_constraint_new_constant(value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(arg1, arg2, arg3, arg4, arg5);

GtkConstraint *obj = gtk_constraint_new_constant(GtkConstraintTarget_val(arg1), GtkConstraintAttribute_val(arg2), GtkConstraintRelation_val(arg3), Double_val(arg4), Int_val(arg5));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkConstraint(obj));
}
CAMLexport CAMLprim value ml_gtk_constraint_is_required(value self)
{
CAMLparam1(self);

gboolean result = gtk_constraint_is_required(GtkConstraint_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_constraint_is_constant(value self)
{
CAMLparam1(self);

gboolean result = gtk_constraint_is_constant(GtkConstraint_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_constraint_is_attached(value self)
{
CAMLparam1(self);

gboolean result = gtk_constraint_is_attached(GtkConstraint_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_constraint_get_target_attribute(value self)
{
CAMLparam1(self);

GtkConstraintAttribute result = gtk_constraint_get_target_attribute(GtkConstraint_val(self));
CAMLreturn(Val_GtkConstraintAttribute(result));
}

CAMLexport CAMLprim value ml_gtk_constraint_get_target(value self)
{
CAMLparam1(self);

GtkConstraintTarget* result = gtk_constraint_get_target(GtkConstraint_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkConstraintTarget));
}

CAMLexport CAMLprim value ml_gtk_constraint_get_strength(value self)
{
CAMLparam1(self);

int result = gtk_constraint_get_strength(GtkConstraint_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_constraint_get_source_attribute(value self)
{
CAMLparam1(self);

GtkConstraintAttribute result = gtk_constraint_get_source_attribute(GtkConstraint_val(self));
CAMLreturn(Val_GtkConstraintAttribute(result));
}

CAMLexport CAMLprim value ml_gtk_constraint_get_source(value self)
{
CAMLparam1(self);

GtkConstraintTarget* result = gtk_constraint_get_source(GtkConstraint_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkConstraintTarget));
}

CAMLexport CAMLprim value ml_gtk_constraint_get_relation(value self)
{
CAMLparam1(self);

GtkConstraintRelation result = gtk_constraint_get_relation(GtkConstraint_val(self));
CAMLreturn(Val_GtkConstraintRelation(result));
}

CAMLexport CAMLprim value ml_gtk_constraint_get_multiplier(value self)
{
CAMLparam1(self);

double result = gtk_constraint_get_multiplier(GtkConstraint_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_constraint_get_constant(value self)
{
CAMLparam1(self);

double result = gtk_constraint_get_constant(GtkConstraint_val(self));
CAMLreturn(caml_copy_double(result));
}


CAMLprim value ml_gtk_constraint_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_constraint_get_type()));
}
