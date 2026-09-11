/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ConstraintLayout */

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


CAMLexport CAMLprim value ml_gtk_constraint_layout_new(value unit)
{
CAMLparam1(unit);

GtkConstraintLayout *obj = gtk_constraint_layout_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkConstraintLayout(obj));
}
CAMLexport CAMLprim value ml_gtk_constraint_layout_remove_guide(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_constraint_layout_remove_guide(GtkConstraintLayout_val(self), GtkConstraintGuide_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_constraint_layout_remove_constraint(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_constraint_layout_remove_constraint(GtkConstraintLayout_val(self), GtkConstraint_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_constraint_layout_remove_all_constraints(value self)
{
CAMLparam1(self);

gtk_constraint_layout_remove_all_constraints(GtkConstraintLayout_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_constraint_layout_observe_guides(value self)
{
CAMLparam1(self);

GListModel* result = gtk_constraint_layout_observe_guides(GtkConstraintLayout_val(self));
CAMLreturn(Val_GListModel(result));
}

CAMLexport CAMLprim value ml_gtk_constraint_layout_observe_constraints(value self)
{
CAMLparam1(self);

GListModel* result = gtk_constraint_layout_observe_constraints(GtkConstraintLayout_val(self));
CAMLreturn(Val_GListModel(result));
}

CAMLexport CAMLprim value ml_gtk_constraint_layout_add_guide(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_constraint_layout_add_guide(GtkConstraintLayout_val(self), GtkConstraintGuide_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_constraint_layout_add_constraint(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_constraint_layout_add_constraint(GtkConstraintLayout_val(self), GtkConstraint_val(arg1));
CAMLreturn(Val_unit);
}

GType gtk_constraint_layout_get_type (void);


CAMLprim value ml_gtk_constraint_layout_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_constraint_layout_get_type()));
}
