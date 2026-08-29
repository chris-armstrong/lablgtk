/**************************************************************************/
/*                ocgtk - OCaml bindings for GTK4                         */
/*                                                                        */
/*    This program is free software; you can redistribute it              */
/*    and/or modify it under the terms of the GNU Library General         */
/*    Public License version 2, as published by the           */
/*    Free Software Foundation with the exception described in file       */
/*    COPYING which comes with the library.                               */
/*                                                                        */
/*    Based on lablgtk3 /https://github.com/garrigue/lablgtk/             */
/*                                                                        */
/**************************************************************************/

#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>

#include "wrappers.h"

/* ========== Initialization and Main Loop ========== */

/* GTK4 Note: gtk_init_check() no longer takes argc/argv parameters.
 * Command-line argument parsing is now handled by GtkApplication.
 * We keep the argv parameter for API compatibility but just return it unchanged. */
CAMLprim value ml_gtk_init(value argv)
{
  CAMLparam1(argv);

  /* GTK4: gtk_init_check has signature: gboolean gtk_init_check(void) */
  if (!gtk_init_check()) {
    caml_failwith("GTK initialization failed");
  }

  /* Return argv unchanged (GTK4 doesn't process it) */
  CAMLreturn(argv);
}

/* GTK4 Note: gtk_main/gtk_main_quit were removed.
 * For testing, we use GLib's main loop directly.
 * Production apps should use GtkApplication (Phase 6.2). */

static GMainLoop *main_loop = NULL;

CAMLprim value ml_gtk_main(value unit)
{
  CAMLparam1(unit);

  if (main_loop == NULL) {
    main_loop = g_main_loop_new(NULL, FALSE);
  }

  g_main_loop_run(main_loop);

  CAMLreturn(Val_unit);
}


/* ========== Main Loop ========== */

CAMLprim value ml_gtk_main_quit(value unit)
{
  CAMLparam1(unit);

  if (main_loop != NULL) {
    g_main_loop_quit(main_loop);
  }

  CAMLreturn(Val_unit);
}

CAMLprim value ml_gtk_main_iteration_do(value block)
{
  CAMLparam1(block);
  GMainContext *context = g_main_context_default();
  gboolean result = g_main_context_iteration(context, Bool_val(block));
  CAMLreturn(Val_bool(result));
}

/* ========== Version ========== */

/* Runtime version — from the GTK shared library actually loaded */
CAMLprim value ml_gtk_get_major_version(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_int(gtk_get_major_version()));
}

CAMLprim value ml_gtk_get_minor_version(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_int(gtk_get_minor_version()));
}

CAMLprim value ml_gtk_get_micro_version(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_int(gtk_get_micro_version()));
}

/* Compile-time version — from the GTK headers used to build this library */
CAMLprim value ml_gtk_compile_major_version(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_int(GTK_MAJOR_VERSION));
}

CAMLprim value ml_gtk_compile_minor_version(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_int(GTK_MINOR_VERSION));
}

CAMLprim value ml_gtk_compile_micro_version(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_int(GTK_MICRO_VERSION));
}

/* ========== Style providers (hand-written; not in the GIR-generated set) ========== */

#include "gtk_decls.h"

/* gtk_style_context_add_provider_for_display for the default display.
 * Both arguments are borrowed (transfer none): GTK takes its own reference
 * on the provider, so no ref-sink bookkeeping is needed here.
 * Fails if GTK has no default display yet — call after gtk_init. */
CAMLprim value ml_gtk_add_provider_for_default_display(value provider, value priority)
{
  CAMLparam2(provider, priority);
  GdkDisplay *display = gdk_display_get_default();
  if (display == NULL) {
    caml_failwith("ml_gtk_add_provider_for_default_display: no default GdkDisplay");
  }
  gtk_style_context_add_provider_for_display(display,
                                             GtkStyleProvider_val(provider),
                                             (guint)Int_val(priority));
  CAMLreturn(Val_unit);
}

/* gtk_settings_get_default(): the GtkSettings object for the default display,
 * the only handle on gtk-interface-color-scheme / gtk-application-prefer-dark-
 * theme. GIR marks the return transfer-none, so we follow the convention the
 * generated bindings use for a borrowed object return (see
 * ml_gtk_widget_get_settings in generated/ml_widget_gen.c): g_object_ref_sink()
 * before wrapping, because ocgtk's wrapper (common/wrappers.h) claims a
 * reference the OCaml finalizer later drops with one g_object_unref. Returns
 * NULL before gtk_init, which we turn into a Failure rather than wrap.
 * Wrapper macro: Val_GtkSettings (generated/gtk_decls.h). */
CAMLprim value ml_gtk_settings_get_default(value unit)
{
  CAMLparam1(unit);
  GtkSettings *result = gtk_settings_get_default();
  if (result == NULL) {
    caml_failwith("ml_gtk_settings_get_default: no default GtkSettings (call after gtk_init)");
  }
  g_object_ref_sink(result);
  CAMLreturn(Val_GtkSettings(result));
}
