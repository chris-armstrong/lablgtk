/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Accessible */

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


#if GTK_CHECK_VERSION(4,18,0)

CAMLexport CAMLprim value ml_gtk_accessible_update_platform_state(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_accessible_update_platform_state(GtkAccessible_val(self), GtkAccessiblePlatformState_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_accessible_update_platform_state(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Accessible requires GTK >= 4.18");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,10,0)

CAMLexport CAMLprim value ml_gtk_accessible_update_next_accessible_sibling(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_accessible_update_next_accessible_sibling(GtkAccessible_val(self), Option_val(arg1, GtkAccessible_val, NULL));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_accessible_update_next_accessible_sibling(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Accessible requires GTK >= 4.10");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,10,0)

CAMLexport CAMLprim value ml_gtk_accessible_set_accessible_parent(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_accessible_set_accessible_parent(GtkAccessible_val(self), Option_val(arg1, GtkAccessible_val, NULL), Option_val(arg2, GtkAccessible_val, NULL));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_accessible_set_accessible_parent(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Accessible requires GTK >= 4.10");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_accessible_reset_state(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_accessible_reset_state(GtkAccessible_val(self), GtkAccessibleState_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_accessible_reset_relation(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_accessible_reset_relation(GtkAccessible_val(self), GtkAccessibleRelation_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_accessible_reset_property(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_accessible_reset_property(GtkAccessible_val(self), GtkAccessibleProperty_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,10,0)

CAMLexport CAMLprim value ml_gtk_accessible_get_platform_state(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_accessible_get_platform_state(GtkAccessible_val(self), GtkAccessiblePlatformState_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gtk_accessible_get_platform_state(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Accessible requires GTK >= 4.10");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,10,0)

CAMLexport CAMLprim value ml_gtk_accessible_get_next_accessible_sibling(value self)
{
CAMLparam1(self);

GtkAccessible* result = gtk_accessible_get_next_accessible_sibling(GtkAccessible_val(self));
CAMLreturn(Val_option(result, Val_GtkAccessible));
}

#else

CAMLexport CAMLprim value ml_gtk_accessible_get_next_accessible_sibling(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Accessible requires GTK >= 4.10");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,10,0)

CAMLexport CAMLprim value ml_gtk_accessible_get_first_accessible_child(value self)
{
CAMLparam1(self);

GtkAccessible* result = gtk_accessible_get_first_accessible_child(GtkAccessible_val(self));
CAMLreturn(Val_option(result, Val_GtkAccessible));
}

#else

CAMLexport CAMLprim value ml_gtk_accessible_get_first_accessible_child(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Accessible requires GTK >= 4.10");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,10,0)

CAMLexport CAMLprim value ml_gtk_accessible_get_bounds(value self)
{
CAMLparam1(self);
int out1;
int out2;
int out3;
int out4;

gboolean result = gtk_accessible_get_bounds(GtkAccessible_val(self), &out1, &out2, &out3, &out4);
CAMLlocal1(ret);
    ret = caml_alloc(5, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_int(out1));
    Store_field(ret, 2, Val_int(out2));
    Store_field(ret, 3, Val_int(out3));
    Store_field(ret, 4, Val_int(out4));
    CAMLreturn(ret);
}

#else

CAMLexport CAMLprim value ml_gtk_accessible_get_bounds(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Accessible requires GTK >= 4.10");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,10,0)

CAMLexport CAMLprim value ml_gtk_accessible_get_at_context(value self)
{
CAMLparam1(self);

GtkATContext* result = gtk_accessible_get_at_context(GtkAccessible_val(self));
CAMLreturn(Val_GtkATContext(result));
}

#else

CAMLexport CAMLprim value ml_gtk_accessible_get_at_context(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Accessible requires GTK >= 4.10");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_accessible_get_accessible_role(value self)
{
CAMLparam1(self);

GtkAccessibleRole result = gtk_accessible_get_accessible_role(GtkAccessible_val(self));
CAMLreturn(Val_GtkAccessibleRole(result));
}

#if GTK_CHECK_VERSION(4,10,0)

CAMLexport CAMLprim value ml_gtk_accessible_get_accessible_parent(value self)
{
CAMLparam1(self);

GtkAccessible* result = gtk_accessible_get_accessible_parent(GtkAccessible_val(self));
CAMLreturn(Val_option(result, Val_GtkAccessible));
}

#else

CAMLexport CAMLprim value ml_gtk_accessible_get_accessible_parent(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Accessible requires GTK >= 4.10");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gtk_accessible_announce(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_accessible_announce(GtkAccessible_val(self), String_val(arg1), GtkAccessibleAnnouncementPriority_val(arg2));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_accessible_announce(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Accessible requires GTK >= 4.14");
return Val_unit;
}
#endif
CAMLexport CAMLprim value ml_gtk_accessible_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), GTK_TYPE_ACCESSIBLE)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GtkAccessible");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GtkAccessible((GtkAccessible*)gobj));
}


CAMLprim value ml_gtk_accessible_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_accessible_get_type()));
}
