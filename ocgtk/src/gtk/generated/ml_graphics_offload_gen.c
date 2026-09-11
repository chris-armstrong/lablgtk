/* GENERATED CODE - DO NOT EDIT */
/* C bindings for GraphicsOffload */

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

#if GTK_CHECK_VERSION(4,14,0)


CAMLexport CAMLprim value ml_gtk_graphics_offload_new(value arg1)
{
CAMLparam1(arg1);

GtkGraphicsOffload *obj = gtk_graphics_offload_new(Option_val(arg1, GtkWidget_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkGraphicsOffload(obj));
}
CAMLexport CAMLprim value ml_gtk_graphics_offload_set_enabled(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_graphics_offload_set_enabled(GtkGraphicsOffload_val(self), GtkGraphicsOffloadEnabled_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_graphics_offload_set_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_graphics_offload_set_child(GtkGraphicsOffload_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,16,0)

CAMLexport CAMLprim value ml_gtk_graphics_offload_set_black_background(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_graphics_offload_set_black_background(GtkGraphicsOffload_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_graphics_offload_set_black_background(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("GraphicsOffload requires GTK >= 4.16");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_graphics_offload_get_enabled(value self)
{
CAMLparam1(self);

GtkGraphicsOffloadEnabled result = gtk_graphics_offload_get_enabled(GtkGraphicsOffload_val(self));
CAMLreturn(Val_GtkGraphicsOffloadEnabled(result));
}

CAMLexport CAMLprim value ml_gtk_graphics_offload_get_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_graphics_offload_get_child(GtkGraphicsOffload_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

#if GTK_CHECK_VERSION(4,16,0)

CAMLexport CAMLprim value ml_gtk_graphics_offload_get_black_background(value self)
{
CAMLparam1(self);

gboolean result = gtk_graphics_offload_get_black_background(GtkGraphicsOffload_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gtk_graphics_offload_get_black_background(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("GraphicsOffload requires GTK >= 4.16");
return Val_unit;
}
#endif

GType gtk_graphics_offload_get_type (void);


CAMLprim value ml_gtk_graphics_offload_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_graphics_offload_get_type()));
}

#else


CAMLexport CAMLprim value ml_gtk_graphics_offload_new(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("GraphicsOffload requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_graphics_offload_get_black_background(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("GraphicsOffload requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_graphics_offload_get_child(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("GraphicsOffload requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_graphics_offload_get_enabled(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("GraphicsOffload requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_graphics_offload_set_black_background(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("GraphicsOffload requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_graphics_offload_set_child(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("GraphicsOffload requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_graphics_offload_set_enabled(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("GraphicsOffload requires GTK >= 4.14");
return Val_unit;
}


#endif
