/* GENERATED CODE - DO NOT EDIT */
/* C bindings for MediaStream */

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


CAMLexport CAMLprim value ml_gtk_media_stream_update(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_media_stream_update(GtkMediaStream_val(self), Int64_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_media_stream_unrealize(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_media_stream_unrealize(GtkMediaStream_val(self), GdkSurface_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,4,0)

CAMLexport CAMLprim value ml_gtk_media_stream_stream_unprepared(value self)
{
CAMLparam1(self);

gtk_media_stream_stream_unprepared(GtkMediaStream_val(self));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_media_stream_stream_unprepared(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MediaStream requires GTK >= 4.4");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,4,0)

CAMLexport CAMLprim value ml_gtk_media_stream_stream_prepared(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);

gtk_media_stream_stream_prepared(GtkMediaStream_val(self), Bool_val(arg1), Bool_val(arg2), Bool_val(arg3), Int64_val(arg4));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_media_stream_stream_prepared(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("MediaStream requires GTK >= 4.4");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,4,0)

CAMLexport CAMLprim value ml_gtk_media_stream_stream_ended(value self)
{
CAMLparam1(self);

gtk_media_stream_stream_ended(GtkMediaStream_val(self));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_media_stream_stream_ended(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("MediaStream requires GTK >= 4.4");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_media_stream_set_volume(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_media_stream_set_volume(GtkMediaStream_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_media_stream_set_playing(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_media_stream_set_playing(GtkMediaStream_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_media_stream_set_muted(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_media_stream_set_muted(GtkMediaStream_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_media_stream_set_loop(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_media_stream_set_loop(GtkMediaStream_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_media_stream_seek_success(value self)
{
CAMLparam1(self);

gtk_media_stream_seek_success(GtkMediaStream_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_media_stream_seek_failed(value self)
{
CAMLparam1(self);

gtk_media_stream_seek_failed(GtkMediaStream_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_media_stream_seek(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_media_stream_seek(GtkMediaStream_val(self), Int64_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_media_stream_realize(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_media_stream_realize(GtkMediaStream_val(self), GdkSurface_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_media_stream_play(value self)
{
CAMLparam1(self);

gtk_media_stream_play(GtkMediaStream_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_media_stream_pause(value self)
{
CAMLparam1(self);

gtk_media_stream_pause(GtkMediaStream_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_media_stream_is_seeking(value self)
{
CAMLparam1(self);

gboolean result = gtk_media_stream_is_seeking(GtkMediaStream_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_media_stream_is_seekable(value self)
{
CAMLparam1(self);

gboolean result = gtk_media_stream_is_seekable(GtkMediaStream_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_media_stream_is_prepared(value self)
{
CAMLparam1(self);

gboolean result = gtk_media_stream_is_prepared(GtkMediaStream_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_media_stream_has_video(value self)
{
CAMLparam1(self);

gboolean result = gtk_media_stream_has_video(GtkMediaStream_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_media_stream_has_audio(value self)
{
CAMLparam1(self);

gboolean result = gtk_media_stream_has_audio(GtkMediaStream_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_media_stream_get_volume(value self)
{
CAMLparam1(self);

double result = gtk_media_stream_get_volume(GtkMediaStream_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_media_stream_get_timestamp(value self)
{
CAMLparam1(self);

gint64 result = gtk_media_stream_get_timestamp(GtkMediaStream_val(self));
CAMLreturn(caml_copy_int64(result));
}

CAMLexport CAMLprim value ml_gtk_media_stream_get_playing(value self)
{
CAMLparam1(self);

gboolean result = gtk_media_stream_get_playing(GtkMediaStream_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_media_stream_get_muted(value self)
{
CAMLparam1(self);

gboolean result = gtk_media_stream_get_muted(GtkMediaStream_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_media_stream_get_loop(value self)
{
CAMLparam1(self);

gboolean result = gtk_media_stream_get_loop(GtkMediaStream_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_media_stream_get_error(value self)
{
CAMLparam1(self);

const GError* result = gtk_media_stream_get_error(GtkMediaStream_val(self));
CAMLreturn(Val_option(result, Val_GError));
}

CAMLexport CAMLprim value ml_gtk_media_stream_get_ended(value self)
{
CAMLparam1(self);

gboolean result = gtk_media_stream_get_ended(GtkMediaStream_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_media_stream_get_duration(value self)
{
CAMLparam1(self);

gint64 result = gtk_media_stream_get_duration(GtkMediaStream_val(self));
CAMLreturn(caml_copy_int64(result));
}

CAMLexport CAMLprim value ml_gtk_media_stream_gerror(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_media_stream_gerror(GtkMediaStream_val(self), GError_val(arg1));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_media_stream_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_media_stream_get_type()));
}
