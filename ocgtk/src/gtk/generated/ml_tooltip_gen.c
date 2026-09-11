/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Tooltip */

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


CAMLexport CAMLprim value ml_gtk_tooltip_set_tip_area(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tooltip_set_tip_area(GtkTooltip_val(self), GdkRectangle_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tooltip_set_text(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tooltip_set_text(GtkTooltip_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tooltip_set_markup(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tooltip_set_markup(GtkTooltip_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tooltip_set_icon_from_icon_name(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tooltip_set_icon_from_icon_name(GtkTooltip_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tooltip_set_icon_from_gicon(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tooltip_set_icon_from_gicon(GtkTooltip_val(self), Option_val(arg1, GIcon_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tooltip_set_icon(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tooltip_set_icon(GtkTooltip_val(self), Option_val(arg1, GdkPaintable_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_tooltip_set_custom(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_tooltip_set_custom(GtkTooltip_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

GType gtk_tooltip_get_type (void);


CAMLprim value ml_gtk_tooltip_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_tooltip_get_type()));
}
