/* GENERATED CODE - DO NOT EDIT */
/* C bindings for PixbufSimpleAnim */

#include <gdk-pixbuf/gdk-pixbuf.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <gdk-pixbuf/gdk-pixbuf.h>
/* Include library-specific type conversions and forward declarations */
#include "gdkpixbuf_decls.h"


#if GDK_PIXBUF_CHECK_VERSION(2,8,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_simple_anim_new(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);

GdkPixbufSimpleAnim *obj = gdk_pixbuf_simple_anim_new(Int_val(arg1), Int_val(arg2), Double_val(arg3));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GdkPixbufSimpleAnim(obj));
}
#else

CAMLexport CAMLprim value ml_gdk_pixbuf_simple_anim_new(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("PixbufSimpleAnim requires GdkPixbuf >= 2.8");
return Val_unit;
}
#endif

#if GDK_PIXBUF_CHECK_VERSION(2,18,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_simple_anim_set_loop(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_pixbuf_simple_anim_set_loop(GdkPixbufSimpleAnim_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gdk_pixbuf_simple_anim_set_loop(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("PixbufSimpleAnim requires GdkPixbuf >= 2.18");
return Val_unit;
}
#endif

#if GDK_PIXBUF_CHECK_VERSION(2,18,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_simple_anim_get_loop(value self)
{
CAMLparam1(self);

gboolean result = gdk_pixbuf_simple_anim_get_loop(GdkPixbufSimpleAnim_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gdk_pixbuf_simple_anim_get_loop(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PixbufSimpleAnim requires GdkPixbuf >= 2.18");
return Val_unit;
}
#endif

#if GDK_PIXBUF_CHECK_VERSION(2,8,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_simple_anim_add_frame(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_pixbuf_simple_anim_add_frame(GdkPixbufSimpleAnim_val(self), GdkPixbuf_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gdk_pixbuf_simple_anim_add_frame(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("PixbufSimpleAnim requires GdkPixbuf >= 2.8");
return Val_unit;
}
#endif

GType gdk_pixbuf_simple_anim_get_type (void);


CAMLprim value ml_gdk_pixbuf_pixbuf_simple_anim_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_pixbuf_simple_anim_get_type()));
}
