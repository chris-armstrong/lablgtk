/* GENERATED CODE - DO NOT EDIT */
/* C bindings for EventController */

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


#if GTK_CHECK_VERSION(4,8,0)

CAMLexport CAMLprim value ml_gtk_event_controller_set_static_name(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_event_controller_set_static_name(GtkEventController_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_event_controller_set_static_name(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("EventController requires GTK >= 4.8");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_event_controller_set_propagation_phase(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_event_controller_set_propagation_phase(GtkEventController_val(self), GtkPropagationPhase_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_event_controller_set_propagation_limit(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_event_controller_set_propagation_limit(GtkEventController_val(self), GtkPropagationLimit_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_event_controller_set_name(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_event_controller_set_name(GtkEventController_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_event_controller_reset(value self)
{
CAMLparam1(self);

gtk_event_controller_reset(GtkEventController_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_event_controller_get_widget(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_event_controller_get_widget(GtkEventController_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_event_controller_get_propagation_phase(value self)
{
CAMLparam1(self);

GtkPropagationPhase result = gtk_event_controller_get_propagation_phase(GtkEventController_val(self));
CAMLreturn(Val_GtkPropagationPhase(result));
}

CAMLexport CAMLprim value ml_gtk_event_controller_get_propagation_limit(value self)
{
CAMLparam1(self);

GtkPropagationLimit result = gtk_event_controller_get_propagation_limit(GtkEventController_val(self));
CAMLreturn(Val_GtkPropagationLimit(result));
}

CAMLexport CAMLprim value ml_gtk_event_controller_get_name(value self)
{
CAMLparam1(self);

const char* result = gtk_event_controller_get_name(GtkEventController_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_event_controller_get_current_event_time(value self)
{
CAMLparam1(self);

guint32 result = gtk_event_controller_get_current_event_time(GtkEventController_val(self));
CAMLreturn(Val_uint32(result));
}

CAMLexport CAMLprim value ml_gtk_event_controller_get_current_event_state(value self)
{
CAMLparam1(self);

GdkModifierType result = gtk_event_controller_get_current_event_state(GtkEventController_val(self));
CAMLreturn(Val_GdkModifierType(result));
}

CAMLexport CAMLprim value ml_gtk_event_controller_get_current_event_device(value self)
{
CAMLparam1(self);

GdkDevice* result = gtk_event_controller_get_current_event_device(GtkEventController_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkDevice));
}

CAMLexport CAMLprim value ml_gtk_event_controller_get_current_event(value self)
{
CAMLparam1(self);

GdkEvent* result = gtk_event_controller_get_current_event(GtkEventController_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkEvent));
}


CAMLprim value ml_gtk_event_controller_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_event_controller_get_type()));
}
