/* GENERATED CODE - DO NOT EDIT */
/* C bindings for EmojiChooser */

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


CAMLexport CAMLprim value ml_gtk_emoji_chooser_new(value unit)
{
CAMLparam1(unit);

GtkEmojiChooser *obj = gtk_emoji_chooser_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkEmojiChooser(obj));
}
GType gtk_emoji_chooser_get_type (void);


CAMLprim value ml_gtk_emoji_chooser_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_emoji_chooser_get_type()));
}
