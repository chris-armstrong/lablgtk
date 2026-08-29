let priority_application = 600

external add_provider_for_default_display : Style_provider.t -> int -> unit
  = "ml_gtk_add_provider_for_default_display"

external settings_default : unit -> Settings.t = "ml_gtk_settings_get_default"
(** Hand-written (not GIR-generated): [gtk_settings_get_default], the only
    way to reach the display's colour-scheme settings. See ml_gtk.c. *)
