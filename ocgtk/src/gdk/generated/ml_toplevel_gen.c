/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Toplevel */

#include <gtk/gtk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <gdk/gdk.h>
/* Include library-specific type conversions and forward declarations */
#include "gdk_decls.h"


#if GTK_CHECK_VERSION(4,4,0)

CAMLexport CAMLprim value ml_gdk_toplevel_titlebar_gesture(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gdk_toplevel_titlebar_gesture(GdkToplevel_val(self), GdkTitlebarGesture_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gdk_toplevel_titlebar_gesture(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Toplevel requires GTK >= 4.4");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_toplevel_supports_edge_constraints(value self)
{
CAMLparam1(self);

gboolean result = gdk_toplevel_supports_edge_constraints(GdkToplevel_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_toplevel_show_window_menu(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gdk_toplevel_show_window_menu(GdkToplevel_val(self), GdkEvent_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_toplevel_set_transient_for(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_toplevel_set_transient_for(GdkToplevel_val(self), GdkSurface_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_toplevel_set_title(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_toplevel_set_title(GdkToplevel_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_toplevel_set_startup_id(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_toplevel_set_startup_id(GdkToplevel_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_toplevel_set_modal(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_toplevel_set_modal(GdkToplevel_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_toplevel_set_icon_list(value self, value arg1)
{
CAMLparam2(self, arg1);
    GList* arg1_list = NULL;
    GList_val_with(arg1, arg1_list, (gpointer)GdkTexture_val(Field(_iter, 0)));

gdk_toplevel_set_icon_list(GdkToplevel_val(self), arg1_list);
    g_list_free(arg1_list);
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gdk_toplevel_set_gravity(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_toplevel_set_gravity(GdkToplevel_val(self), GdkGravity_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gdk_toplevel_set_gravity(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Toplevel requires GTK >= 4.20");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_toplevel_set_deletable(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_toplevel_set_deletable(GdkToplevel_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_toplevel_set_decorated(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_toplevel_set_decorated(GdkToplevel_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_toplevel_restore_system_shortcuts(value self)
{
CAMLparam1(self);

gdk_toplevel_restore_system_shortcuts(GdkToplevel_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_toplevel_present(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_toplevel_present(GdkToplevel_val(self), GdkToplevelLayout_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_toplevel_minimize(value self)
{
CAMLparam1(self);

gboolean result = gdk_toplevel_minimize(GdkToplevel_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_toplevel_lower(value self)
{
CAMLparam1(self);

gboolean result = gdk_toplevel_lower(GdkToplevel_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_toplevel_inhibit_system_shortcuts(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_toplevel_inhibit_system_shortcuts(GdkToplevel_val(self), Option_val(arg1, GdkEvent_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_toplevel_get_state(value self)
{
CAMLparam1(self);

GdkToplevelState result = gdk_toplevel_get_state(GdkToplevel_val(self));
CAMLreturn(Val_GdkToplevelState(result));
}

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gdk_toplevel_get_gravity(value self)
{
CAMLparam1(self);

GdkGravity result = gdk_toplevel_get_gravity(GdkToplevel_val(self));
CAMLreturn(Val_GdkGravity(result));
}

#else

CAMLexport CAMLprim value ml_gdk_toplevel_get_gravity(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Toplevel requires GTK >= 4.20");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,20,0)

CAMLexport CAMLprim value ml_gdk_toplevel_get_capabilities(value self)
{
CAMLparam1(self);

GdkToplevelCapabilities result = gdk_toplevel_get_capabilities(GdkToplevel_val(self));
CAMLreturn(Val_GdkToplevelCapabilities(result));
}

#else

CAMLexport CAMLprim value ml_gdk_toplevel_get_capabilities(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Toplevel requires GTK >= 4.20");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_toplevel_focus(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_toplevel_focus(GdkToplevel_val(self), UInt32_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_toplevel_begin_resize_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5, value arg6)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam2(arg5, arg6);

gdk_toplevel_begin_resize(GdkToplevel_val(self), GdkSurfaceEdge_val(arg1), Option_val(arg2, GdkDevice_val, NULL), Int_val(arg3), Double_val(arg4), Double_val(arg5), UInt32_val(arg6));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gdk_toplevel_begin_resize_bytecode(value * argv, int argn)
{
return ml_gdk_toplevel_begin_resize_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

CAMLexport CAMLprim value ml_gdk_toplevel_begin_move_native(value self, value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
CAMLxparam1(arg5);

gdk_toplevel_begin_move(GdkToplevel_val(self), GdkDevice_val(arg1), Int_val(arg2), Double_val(arg3), Double_val(arg4), UInt32_val(arg5));
CAMLreturn(Val_unit);}

CAMLexport CAMLprim value ml_gdk_toplevel_begin_move_bytecode(value * argv, int argn)
{
return ml_gdk_toplevel_begin_move_native(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLexport CAMLprim value ml_gdk_toplevel_get_fullscreen_mode(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GdkToplevel *obj = (GdkToplevel *)GdkToplevel_val(self);
    GdkFullscreenMode prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "fullscreen-mode");
if (pspec == NULL) caml_failwith("ml_gdk_toplevel_get_fullscreen_mode: property 'fullscreen-mode' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "fullscreen-mode", &prop_gvalue);
          prop_value = (GdkFullscreenMode)g_value_get_enum(&prop_gvalue);

      result = Val_GdkFullscreenMode(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_gdk_toplevel_set_fullscreen_mode(value self, value new_value)
{
    CAMLparam2(self, new_value);
GdkToplevel *obj = (GdkToplevel *)GdkToplevel_val(self);
    GdkFullscreenMode c_value = GdkFullscreenMode_val(new_value);
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "fullscreen-mode");
if (pspec == NULL) caml_failwith("ml_gdk_toplevel_set_fullscreen_mode: property 'fullscreen-mode' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
          g_value_set_enum(&prop_gvalue, c_value);
g_object_set_property(G_OBJECT(obj), "fullscreen-mode", &prop_gvalue);
g_value_unset(&prop_gvalue);
    CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_toplevel_get_shortcuts_inhibited(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GdkToplevel *obj = (GdkToplevel *)GdkToplevel_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "shortcuts-inhibited");
if (pspec == NULL) caml_failwith("ml_gdk_toplevel_get_shortcuts_inhibited: property 'shortcuts-inhibited' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "shortcuts-inhibited", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}
CAMLexport CAMLprim value ml_gdk_toplevel_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), GDK_TYPE_TOPLEVEL)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GdkToplevel");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GdkToplevel((GdkToplevel*)gobj));
}


CAMLprim value ml_gdk_toplevel_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_toplevel_get_type()));
}
