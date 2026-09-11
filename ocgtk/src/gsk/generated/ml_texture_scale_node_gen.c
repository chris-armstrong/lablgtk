/* GENERATED CODE - DO NOT EDIT */
/* C bindings for TextureScaleNode */

#include <gtk/gtk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <gsk/gsk.h>
/* Include library-specific type conversions and forward declarations */
#include "gsk_decls.h"

#if GTK_CHECK_VERSION(4,10,0)


CAMLexport CAMLprim value ml_gsk_texture_scale_node_new(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);

GskTextureScaleNode *obj = gsk_texture_scale_node_new(GdkTexture_val(arg1), graphene_rect_t_val(arg2), GskScalingFilter_val(arg3));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GskTextureScaleNode(obj));
}
CAMLexport CAMLprim value ml_gsk_texture_scale_node_get_texture(value self)
{
CAMLparam1(self);

GdkTexture* result = gsk_texture_scale_node_get_texture(GskTextureScaleNode_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GdkTexture(result));
}

CAMLexport CAMLprim value ml_gsk_texture_scale_node_get_filter(value self)
{
CAMLparam1(self);

GskScalingFilter result = gsk_texture_scale_node_get_filter(GskTextureScaleNode_val(self));
CAMLreturn(Val_GskScalingFilter(result));
}

GType gsk_texture_scale_node_get_type (void);


CAMLprim value ml_gsk_texture_scale_node_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_texture_scale_node_get_type()));
}

#else


CAMLexport CAMLprim value ml_gsk_texture_scale_node_new(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("TextureScaleNode requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_texture_scale_node_get_filter(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TextureScaleNode requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_texture_scale_node_get_texture(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("TextureScaleNode requires GTK >= 4.10");
return Val_unit;
}


#endif
