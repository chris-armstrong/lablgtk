/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Calendar */

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


CAMLexport CAMLprim value ml_gtk_calendar_new(value unit)
{
CAMLparam1(unit);

GtkCalendar *obj = gtk_calendar_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkCalendar(obj));
}
CAMLexport CAMLprim value ml_gtk_calendar_unmark_day(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_calendar_unmark_day(GtkCalendar_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gtk_calendar_set_year(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_calendar_set_year(GtkCalendar_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_calendar_set_year(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Calendar requires GTK >= 4.14");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_calendar_set_show_week_numbers(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_calendar_set_show_week_numbers(GtkCalendar_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_calendar_set_show_heading(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_calendar_set_show_heading(GtkCalendar_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_calendar_set_show_day_names(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_calendar_set_show_day_names(GtkCalendar_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gtk_calendar_set_month(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_calendar_set_month(GtkCalendar_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_calendar_set_month(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Calendar requires GTK >= 4.14");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gtk_calendar_set_day(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_calendar_set_day(GtkCalendar_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_calendar_set_day(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Calendar requires GTK >= 4.14");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_calendar_mark_day(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_calendar_mark_day(GtkCalendar_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gtk_calendar_get_year(value self)
{
CAMLparam1(self);

int result = gtk_calendar_get_year(GtkCalendar_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_gtk_calendar_get_year(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Calendar requires GTK >= 4.14");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_calendar_get_show_week_numbers(value self)
{
CAMLparam1(self);

gboolean result = gtk_calendar_get_show_week_numbers(GtkCalendar_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_calendar_get_show_heading(value self)
{
CAMLparam1(self);

gboolean result = gtk_calendar_get_show_heading(GtkCalendar_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_calendar_get_show_day_names(value self)
{
CAMLparam1(self);

gboolean result = gtk_calendar_get_show_day_names(GtkCalendar_val(self));
CAMLreturn(Val_bool(result));
}

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gtk_calendar_get_month(value self)
{
CAMLparam1(self);

int result = gtk_calendar_get_month(GtkCalendar_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_gtk_calendar_get_month(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Calendar requires GTK >= 4.14");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_calendar_get_day_is_marked(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_calendar_get_day_is_marked(GtkCalendar_val(self), Int_val(arg1));
CAMLreturn(Val_bool(result));
}

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gtk_calendar_get_day(value self)
{
CAMLparam1(self);

int result = gtk_calendar_get_day(GtkCalendar_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_gtk_calendar_get_day(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Calendar requires GTK >= 4.14");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_calendar_clear_marks(value self)
{
CAMLparam1(self);

gtk_calendar_clear_marks(GtkCalendar_val(self));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_calendar_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_calendar_get_type()));
}
