(** Hand-written (not GIR-generated): install a style provider for the
    default display, i.e. app-wide. See ml_gtk.c. *)

(** [GTK_STYLE_PROVIDER_PRIORITY_APPLICATION]. *)
val priority_application : int

(** Adds [provider] to the default display at [priority].
    Raises [Failure] if GTK has no default display yet. *)
external add_provider_for_default_display : Style_provider.t -> int -> unit
  = "ml_gtk_add_provider_for_default_display"

(** The [GtkSettings] of the default display ([gtk_settings_get_default]).
    Raises [Failure] if GTK has not been initialised yet. *)
external settings_default : unit -> Settings.t = "ml_gtk_settings_get_default"
