/* GENERATED CODE - DO NOT EDIT */
/* C bindings for MenuButton */

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


CAMLexport CAMLprim value ml_gtk_menu_button_new(value unit)
{
CAMLparam1(unit);

GtkMenuButton *obj = gtk_menu_button_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkMenuButton(obj));
}
CAMLexport CAMLprim value ml_gtk_menu_button_set_use_underline(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_menu_button_set_use_underline(GtkMenuButton_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,4,0)

CAMLexport CAMLprim value ml_gtk_menu_button_set_primary(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_menu_button_set_primary(GtkMenuButton_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_menu_button_set_primary(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MenuButton requires GTK >= 4.4");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_menu_button_set_popover(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_menu_button_set_popover(GtkMenuButton_val(self), Option_val(arg1, GtkPopover_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_menu_button_set_menu_model(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_menu_button_set_menu_model(GtkMenuButton_val(self), Option_val(arg1, GMenuModel_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_menu_button_set_label(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_menu_button_set_label(GtkMenuButton_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_menu_button_set_icon_name(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_menu_button_set_icon_name(GtkMenuButton_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_menu_button_set_has_frame(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_menu_button_set_has_frame(GtkMenuButton_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_menu_button_set_direction(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_menu_button_set_direction(GtkMenuButton_val(self), GtkArrowType_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gtk_menu_button_set_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_menu_button_set_child(GtkMenuButton_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_menu_button_set_child(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MenuButton requires GTK >= 4.6");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_menu_button_set_can_shrink(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_menu_button_set_can_shrink(GtkMenuButton_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_menu_button_set_can_shrink(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MenuButton requires GTK >= 4.12");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,4,0)

CAMLexport CAMLprim value ml_gtk_menu_button_set_always_show_arrow(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_menu_button_set_always_show_arrow(GtkMenuButton_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_menu_button_set_always_show_arrow(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MenuButton requires GTK >= 4.4");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,10,0)

CAMLexport CAMLprim value ml_gtk_menu_button_set_active(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_menu_button_set_active(GtkMenuButton_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_menu_button_set_active(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("MenuButton requires GTK >= 4.10");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_menu_button_popup(value self)
{
CAMLparam1(self);

gtk_menu_button_popup(GtkMenuButton_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_menu_button_popdown(value self)
{
CAMLparam1(self);

gtk_menu_button_popdown(GtkMenuButton_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_menu_button_get_use_underline(value self)
{
CAMLparam1(self);

gboolean result = gtk_menu_button_get_use_underline(GtkMenuButton_val(self));
CAMLreturn(Val_bool(result));
}

#if GTK_CHECK_VERSION(4,4,0)

CAMLexport CAMLprim value ml_gtk_menu_button_get_primary(value self)
{
CAMLparam1(self);

gboolean result = gtk_menu_button_get_primary(GtkMenuButton_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gtk_menu_button_get_primary(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MenuButton requires GTK >= 4.4");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_menu_button_get_popover(value self)
{
CAMLparam1(self);

GtkPopover* result = gtk_menu_button_get_popover(GtkMenuButton_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkPopover));
}

CAMLexport CAMLprim value ml_gtk_menu_button_get_menu_model(value self)
{
CAMLparam1(self);

GMenuModel* result = gtk_menu_button_get_menu_model(GtkMenuButton_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GMenuModel));
}

CAMLexport CAMLprim value ml_gtk_menu_button_get_label(value self)
{
CAMLparam1(self);

const char* result = gtk_menu_button_get_label(GtkMenuButton_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_menu_button_get_icon_name(value self)
{
CAMLparam1(self);

const char* result = gtk_menu_button_get_icon_name(GtkMenuButton_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_menu_button_get_has_frame(value self)
{
CAMLparam1(self);

gboolean result = gtk_menu_button_get_has_frame(GtkMenuButton_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_menu_button_get_direction(value self)
{
CAMLparam1(self);

GtkArrowType result = gtk_menu_button_get_direction(GtkMenuButton_val(self));
CAMLreturn(Val_GtkArrowType(result));
}

#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gtk_menu_button_get_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_menu_button_get_child(GtkMenuButton_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

#else

CAMLexport CAMLprim value ml_gtk_menu_button_get_child(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MenuButton requires GTK >= 4.6");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_menu_button_get_can_shrink(value self)
{
CAMLparam1(self);

gboolean result = gtk_menu_button_get_can_shrink(GtkMenuButton_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gtk_menu_button_get_can_shrink(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MenuButton requires GTK >= 4.12");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,4,0)

CAMLexport CAMLprim value ml_gtk_menu_button_get_always_show_arrow(value self)
{
CAMLparam1(self);

gboolean result = gtk_menu_button_get_always_show_arrow(GtkMenuButton_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gtk_menu_button_get_always_show_arrow(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MenuButton requires GTK >= 4.4");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,10,0)

CAMLexport CAMLprim value ml_gtk_menu_button_get_active(value self)
{
CAMLparam1(self);

gboolean result = gtk_menu_button_get_active(GtkMenuButton_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gtk_menu_button_get_active(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MenuButton requires GTK >= 4.10");
return Val_unit;
}
#endif

GType gtk_menu_button_get_type (void);


CAMLprim value ml_gtk_menu_button_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_menu_button_get_type()));
}
