/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Notification */

#include <gio/gio.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <gio/gio.h>
/* Include library-specific type conversions and forward declarations */
#include "gio_decls.h"

#if GLIB_CHECK_VERSION(2,40,0)


CAMLexport CAMLprim value ml_g_notification_new(value arg1)
{
CAMLparam1(arg1);

GNotification *obj = g_notification_new(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GNotification(obj));
}
CAMLexport CAMLprim value ml_g_notification_set_urgent(value self, value arg1)
{
CAMLparam2(self, arg1);

g_notification_set_urgent(GNotification_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_notification_set_title(value self, value arg1)
{
CAMLparam2(self, arg1);

g_notification_set_title(GNotification_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_notification_set_priority(value self, value arg1)
{
CAMLparam2(self, arg1);

g_notification_set_priority(GNotification_val(self), GioNotificationPriority_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_notification_set_icon(value self, value arg1)
{
CAMLparam2(self, arg1);

g_notification_set_icon(GNotification_val(self), GIcon_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_notification_set_default_action_and_target_value(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_notification_set_default_action_and_target_value(GNotification_val(self), String_val(arg1), Option_val(arg2, GVariant_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_notification_set_default_action(value self, value arg1)
{
CAMLparam2(self, arg1);

g_notification_set_default_action(GNotification_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

#if GLIB_CHECK_VERSION(2,70,0)

CAMLexport CAMLprim value ml_g_notification_set_category(value self, value arg1)
{
CAMLparam2(self, arg1);

g_notification_set_category(GNotification_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_notification_set_category(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Notification requires GLib >= 2.70");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_notification_set_body(value self, value arg1)
{
CAMLparam2(self, arg1);

g_notification_set_body(GNotification_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_notification_add_button_with_target_value(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

g_notification_add_button_with_target_value(GNotification_val(self), String_val(arg1), String_val(arg2), Option_val(arg3, GVariant_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_notification_add_button(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_notification_add_button(GNotification_val(self), String_val(arg1), String_val(arg2));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gio_notification_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_notification_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_notification_new(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("Notification requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_notification_add_button(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Notification requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_notification_add_button_with_target_value(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("Notification requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_notification_set_body(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Notification requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_notification_set_category(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Notification requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_notification_set_default_action(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Notification requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_notification_set_default_action_and_target_value(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Notification requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_notification_set_icon(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Notification requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_notification_set_priority(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Notification requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_notification_set_title(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Notification requires GLib >= 2.40");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_notification_set_urgent(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Notification requires GLib >= 2.40");
return Val_unit;
}


#endif
