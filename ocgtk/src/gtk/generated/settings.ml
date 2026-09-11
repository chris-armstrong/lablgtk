(* GENERATED CODE - DO NOT EDIT *)
(* Settings: Settings *)

type t = [ `settings | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_settings_get_type"

(* Methods *)

external reset_property : t -> string -> unit = "ml_gtk_settings_reset_property"
(** Undoes the effect of calling g_object_set() to install an
    application-specific value for a setting.

    After this call, the setting will again follow the session-wide value for
    this setting. *)

(* Properties *)

external get_gtk_alternative_button_order : t -> bool
  = "ml_gtk_settings_get_gtk_alternative_button_order"
(** Get property: gtk-alternative-button-order *)

external set_gtk_alternative_button_order : t -> bool -> unit
  = "ml_gtk_settings_set_gtk_alternative_button_order"
(** Set property: gtk-alternative-button-order *)

external get_gtk_alternative_sort_arrows : t -> bool
  = "ml_gtk_settings_get_gtk_alternative_sort_arrows"
(** Get property: gtk-alternative-sort-arrows *)

external set_gtk_alternative_sort_arrows : t -> bool -> unit
  = "ml_gtk_settings_set_gtk_alternative_sort_arrows"
(** Set property: gtk-alternative-sort-arrows *)

external get_gtk_application_prefer_dark_theme : t -> bool
  = "ml_gtk_settings_get_gtk_application_prefer_dark_theme"
(** Get property: gtk-application-prefer-dark-theme *)

external set_gtk_application_prefer_dark_theme : t -> bool -> unit
  = "ml_gtk_settings_set_gtk_application_prefer_dark_theme"
(** Set property: gtk-application-prefer-dark-theme *)

external get_gtk_cursor_aspect_ratio : t -> float
  = "ml_gtk_settings_get_gtk_cursor_aspect_ratio"
(** Get property: gtk-cursor-aspect-ratio *)

external set_gtk_cursor_aspect_ratio : t -> float -> unit
  = "ml_gtk_settings_set_gtk_cursor_aspect_ratio"
(** Set property: gtk-cursor-aspect-ratio *)

external get_gtk_cursor_blink : t -> bool
  = "ml_gtk_settings_get_gtk_cursor_blink"
(** Get property: gtk-cursor-blink *)

external set_gtk_cursor_blink : t -> bool -> unit
  = "ml_gtk_settings_set_gtk_cursor_blink"
(** Set property: gtk-cursor-blink *)

external get_gtk_cursor_blink_time : t -> int
  = "ml_gtk_settings_get_gtk_cursor_blink_time"
(** Get property: gtk-cursor-blink-time *)

external set_gtk_cursor_blink_time : t -> int -> unit
  = "ml_gtk_settings_set_gtk_cursor_blink_time"
(** Set property: gtk-cursor-blink-time *)

external get_gtk_cursor_blink_timeout : t -> int
  = "ml_gtk_settings_get_gtk_cursor_blink_timeout"
(** Get property: gtk-cursor-blink-timeout *)

external set_gtk_cursor_blink_timeout : t -> int -> unit
  = "ml_gtk_settings_set_gtk_cursor_blink_timeout"
(** Set property: gtk-cursor-blink-timeout *)

external get_gtk_cursor_theme_name : t -> string
  = "ml_gtk_settings_get_gtk_cursor_theme_name"
(** Get property: gtk-cursor-theme-name *)

external set_gtk_cursor_theme_name : t -> string -> unit
  = "ml_gtk_settings_set_gtk_cursor_theme_name"
(** Set property: gtk-cursor-theme-name *)

external get_gtk_cursor_theme_size : t -> int
  = "ml_gtk_settings_get_gtk_cursor_theme_size"
(** Get property: gtk-cursor-theme-size *)

external set_gtk_cursor_theme_size : t -> int -> unit
  = "ml_gtk_settings_set_gtk_cursor_theme_size"
(** Set property: gtk-cursor-theme-size *)

external get_gtk_decoration_layout : t -> string
  = "ml_gtk_settings_get_gtk_decoration_layout"
(** Get property: gtk-decoration-layout *)

external set_gtk_decoration_layout : t -> string -> unit
  = "ml_gtk_settings_set_gtk_decoration_layout"
(** Set property: gtk-decoration-layout *)

external get_gtk_dialogs_use_header : t -> bool
  = "ml_gtk_settings_get_gtk_dialogs_use_header"
(** Get property: gtk-dialogs-use-header *)

external set_gtk_dialogs_use_header : t -> bool -> unit
  = "ml_gtk_settings_set_gtk_dialogs_use_header"
(** Set property: gtk-dialogs-use-header *)

external get_gtk_dnd_drag_threshold : t -> int
  = "ml_gtk_settings_get_gtk_dnd_drag_threshold"
(** Get property: gtk-dnd-drag-threshold *)

external set_gtk_dnd_drag_threshold : t -> int -> unit
  = "ml_gtk_settings_set_gtk_dnd_drag_threshold"
(** Set property: gtk-dnd-drag-threshold *)

external get_gtk_double_click_distance : t -> int
  = "ml_gtk_settings_get_gtk_double_click_distance"
(** Get property: gtk-double-click-distance *)

external set_gtk_double_click_distance : t -> int -> unit
  = "ml_gtk_settings_set_gtk_double_click_distance"
(** Set property: gtk-double-click-distance *)

external get_gtk_double_click_time : t -> int
  = "ml_gtk_settings_get_gtk_double_click_time"
(** Get property: gtk-double-click-time *)

external set_gtk_double_click_time : t -> int -> unit
  = "ml_gtk_settings_set_gtk_double_click_time"
(** Set property: gtk-double-click-time *)

external get_gtk_enable_accels : t -> bool
  = "ml_gtk_settings_get_gtk_enable_accels"
(** Get property: gtk-enable-accels *)

external set_gtk_enable_accels : t -> bool -> unit
  = "ml_gtk_settings_set_gtk_enable_accels"
(** Set property: gtk-enable-accels *)

external get_gtk_enable_animations : t -> bool
  = "ml_gtk_settings_get_gtk_enable_animations"
(** Get property: gtk-enable-animations *)

external set_gtk_enable_animations : t -> bool -> unit
  = "ml_gtk_settings_set_gtk_enable_animations"
(** Set property: gtk-enable-animations *)

external get_gtk_enable_event_sounds : t -> bool
  = "ml_gtk_settings_get_gtk_enable_event_sounds"
(** Get property: gtk-enable-event-sounds *)

external set_gtk_enable_event_sounds : t -> bool -> unit
  = "ml_gtk_settings_set_gtk_enable_event_sounds"
(** Set property: gtk-enable-event-sounds *)

external get_gtk_enable_input_feedback_sounds : t -> bool
  = "ml_gtk_settings_get_gtk_enable_input_feedback_sounds"
(** Get property: gtk-enable-input-feedback-sounds *)

external set_gtk_enable_input_feedback_sounds : t -> bool -> unit
  = "ml_gtk_settings_set_gtk_enable_input_feedback_sounds"
(** Set property: gtk-enable-input-feedback-sounds *)

external get_gtk_enable_primary_paste : t -> bool
  = "ml_gtk_settings_get_gtk_enable_primary_paste"
(** Get property: gtk-enable-primary-paste *)

external set_gtk_enable_primary_paste : t -> bool -> unit
  = "ml_gtk_settings_set_gtk_enable_primary_paste"
(** Set property: gtk-enable-primary-paste *)

external get_gtk_entry_password_hint_timeout : t -> int
  = "ml_gtk_settings_get_gtk_entry_password_hint_timeout"
(** Get property: gtk-entry-password-hint-timeout *)

external set_gtk_entry_password_hint_timeout : t -> int -> unit
  = "ml_gtk_settings_set_gtk_entry_password_hint_timeout"
(** Set property: gtk-entry-password-hint-timeout *)

external get_gtk_entry_select_on_focus : t -> bool
  = "ml_gtk_settings_get_gtk_entry_select_on_focus"
(** Get property: gtk-entry-select-on-focus *)

external set_gtk_entry_select_on_focus : t -> bool -> unit
  = "ml_gtk_settings_set_gtk_entry_select_on_focus"
(** Set property: gtk-entry-select-on-focus *)

external get_gtk_error_bell : t -> bool = "ml_gtk_settings_get_gtk_error_bell"
(** Get property: gtk-error-bell *)

external set_gtk_error_bell : t -> bool -> unit
  = "ml_gtk_settings_set_gtk_error_bell"
(** Set property: gtk-error-bell *)

external get_gtk_font_name : t -> string = "ml_gtk_settings_get_gtk_font_name"
(** Get property: gtk-font-name *)

external set_gtk_font_name : t -> string -> unit
  = "ml_gtk_settings_set_gtk_font_name"
(** Set property: gtk-font-name *)

external get_gtk_font_rendering : t -> Gtk_enums.fontrendering
  = "ml_gtk_settings_get_gtk_font_rendering"
(** Get property: gtk-font-rendering *)

external set_gtk_font_rendering : t -> Gtk_enums.fontrendering -> unit
  = "ml_gtk_settings_set_gtk_font_rendering"
(** Set property: gtk-font-rendering *)

external get_gtk_fontconfig_timestamp : t -> int
  = "ml_gtk_settings_get_gtk_fontconfig_timestamp"
(** Get property: gtk-fontconfig-timestamp *)

external set_gtk_fontconfig_timestamp : t -> int -> unit
  = "ml_gtk_settings_set_gtk_fontconfig_timestamp"
(** Set property: gtk-fontconfig-timestamp *)

external get_gtk_hint_font_metrics : t -> bool
  = "ml_gtk_settings_get_gtk_hint_font_metrics"
(** Get property: gtk-hint-font-metrics *)

external set_gtk_hint_font_metrics : t -> bool -> unit
  = "ml_gtk_settings_set_gtk_hint_font_metrics"
(** Set property: gtk-hint-font-metrics *)

external get_gtk_icon_theme_name : t -> string
  = "ml_gtk_settings_get_gtk_icon_theme_name"
(** Get property: gtk-icon-theme-name *)

external set_gtk_icon_theme_name : t -> string -> unit
  = "ml_gtk_settings_set_gtk_icon_theme_name"
(** Set property: gtk-icon-theme-name *)

external get_gtk_im_module : t -> string = "ml_gtk_settings_get_gtk_im_module"
(** Get property: gtk-im-module *)

external set_gtk_im_module : t -> string -> unit
  = "ml_gtk_settings_set_gtk_im_module"
(** Set property: gtk-im-module *)

external get_gtk_interface_color_scheme : t -> Gtk_enums.interfacecolorscheme
  = "ml_gtk_settings_get_gtk_interface_color_scheme"
(** Get property: gtk-interface-color-scheme *)

external set_gtk_interface_color_scheme :
  t -> Gtk_enums.interfacecolorscheme -> unit
  = "ml_gtk_settings_set_gtk_interface_color_scheme"
(** Set property: gtk-interface-color-scheme *)

external get_gtk_interface_contrast : t -> Gtk_enums.interfacecontrast
  = "ml_gtk_settings_get_gtk_interface_contrast"
(** Get property: gtk-interface-contrast *)

external set_gtk_interface_contrast : t -> Gtk_enums.interfacecontrast -> unit
  = "ml_gtk_settings_set_gtk_interface_contrast"
(** Set property: gtk-interface-contrast *)

external get_gtk_keynav_use_caret : t -> bool
  = "ml_gtk_settings_get_gtk_keynav_use_caret"
(** Get property: gtk-keynav-use-caret *)

external set_gtk_keynav_use_caret : t -> bool -> unit
  = "ml_gtk_settings_set_gtk_keynav_use_caret"
(** Set property: gtk-keynav-use-caret *)

external get_gtk_label_select_on_focus : t -> bool
  = "ml_gtk_settings_get_gtk_label_select_on_focus"
(** Get property: gtk-label-select-on-focus *)

external set_gtk_label_select_on_focus : t -> bool -> unit
  = "ml_gtk_settings_set_gtk_label_select_on_focus"
(** Set property: gtk-label-select-on-focus *)

external get_gtk_long_press_time : t -> int
  = "ml_gtk_settings_get_gtk_long_press_time"
(** Get property: gtk-long-press-time *)

external set_gtk_long_press_time : t -> int -> unit
  = "ml_gtk_settings_set_gtk_long_press_time"
(** Set property: gtk-long-press-time *)

external get_gtk_overlay_scrolling : t -> bool
  = "ml_gtk_settings_get_gtk_overlay_scrolling"
(** Get property: gtk-overlay-scrolling *)

external set_gtk_overlay_scrolling : t -> bool -> unit
  = "ml_gtk_settings_set_gtk_overlay_scrolling"
(** Set property: gtk-overlay-scrolling *)

external get_gtk_primary_button_warps_slider : t -> bool
  = "ml_gtk_settings_get_gtk_primary_button_warps_slider"
(** Get property: gtk-primary-button-warps-slider *)

external set_gtk_primary_button_warps_slider : t -> bool -> unit
  = "ml_gtk_settings_set_gtk_primary_button_warps_slider"
(** Set property: gtk-primary-button-warps-slider *)

external get_gtk_print_backends : t -> string
  = "ml_gtk_settings_get_gtk_print_backends"
(** Get property: gtk-print-backends *)

external set_gtk_print_backends : t -> string -> unit
  = "ml_gtk_settings_set_gtk_print_backends"
(** Set property: gtk-print-backends *)

external get_gtk_print_preview_command : t -> string
  = "ml_gtk_settings_get_gtk_print_preview_command"
(** Get property: gtk-print-preview-command *)

external set_gtk_print_preview_command : t -> string -> unit
  = "ml_gtk_settings_set_gtk_print_preview_command"
(** Set property: gtk-print-preview-command *)

external get_gtk_recent_files_enabled : t -> bool
  = "ml_gtk_settings_get_gtk_recent_files_enabled"
(** Get property: gtk-recent-files-enabled *)

external set_gtk_recent_files_enabled : t -> bool -> unit
  = "ml_gtk_settings_set_gtk_recent_files_enabled"
(** Set property: gtk-recent-files-enabled *)

external get_gtk_recent_files_max_age : t -> int
  = "ml_gtk_settings_get_gtk_recent_files_max_age"
(** Get property: gtk-recent-files-max-age *)

external set_gtk_recent_files_max_age : t -> int -> unit
  = "ml_gtk_settings_set_gtk_recent_files_max_age"
(** Set property: gtk-recent-files-max-age *)

external get_gtk_shell_shows_app_menu : t -> bool
  = "ml_gtk_settings_get_gtk_shell_shows_app_menu"
(** Get property: gtk-shell-shows-app-menu *)

external set_gtk_shell_shows_app_menu : t -> bool -> unit
  = "ml_gtk_settings_set_gtk_shell_shows_app_menu"
(** Set property: gtk-shell-shows-app-menu *)

external get_gtk_shell_shows_desktop : t -> bool
  = "ml_gtk_settings_get_gtk_shell_shows_desktop"
(** Get property: gtk-shell-shows-desktop *)

external set_gtk_shell_shows_desktop : t -> bool -> unit
  = "ml_gtk_settings_set_gtk_shell_shows_desktop"
(** Set property: gtk-shell-shows-desktop *)

external get_gtk_shell_shows_menubar : t -> bool
  = "ml_gtk_settings_get_gtk_shell_shows_menubar"
(** Get property: gtk-shell-shows-menubar *)

external set_gtk_shell_shows_menubar : t -> bool -> unit
  = "ml_gtk_settings_set_gtk_shell_shows_menubar"
(** Set property: gtk-shell-shows-menubar *)

external get_gtk_show_status_shapes : t -> bool
  = "ml_gtk_settings_get_gtk_show_status_shapes"
(** Get property: gtk-show-status-shapes *)

external set_gtk_show_status_shapes : t -> bool -> unit
  = "ml_gtk_settings_set_gtk_show_status_shapes"
(** Set property: gtk-show-status-shapes *)

external get_gtk_sound_theme_name : t -> string
  = "ml_gtk_settings_get_gtk_sound_theme_name"
(** Get property: gtk-sound-theme-name *)

external set_gtk_sound_theme_name : t -> string -> unit
  = "ml_gtk_settings_set_gtk_sound_theme_name"
(** Set property: gtk-sound-theme-name *)

external get_gtk_split_cursor : t -> bool
  = "ml_gtk_settings_get_gtk_split_cursor"
(** Get property: gtk-split-cursor *)

external set_gtk_split_cursor : t -> bool -> unit
  = "ml_gtk_settings_set_gtk_split_cursor"
(** Set property: gtk-split-cursor *)

external get_gtk_theme_name : t -> string = "ml_gtk_settings_get_gtk_theme_name"
(** Get property: gtk-theme-name *)

external set_gtk_theme_name : t -> string -> unit
  = "ml_gtk_settings_set_gtk_theme_name"
(** Set property: gtk-theme-name *)

external get_gtk_titlebar_double_click : t -> string
  = "ml_gtk_settings_get_gtk_titlebar_double_click"
(** Get property: gtk-titlebar-double-click *)

external set_gtk_titlebar_double_click : t -> string -> unit
  = "ml_gtk_settings_set_gtk_titlebar_double_click"
(** Set property: gtk-titlebar-double-click *)

external get_gtk_titlebar_middle_click : t -> string
  = "ml_gtk_settings_get_gtk_titlebar_middle_click"
(** Get property: gtk-titlebar-middle-click *)

external set_gtk_titlebar_middle_click : t -> string -> unit
  = "ml_gtk_settings_set_gtk_titlebar_middle_click"
(** Set property: gtk-titlebar-middle-click *)

external get_gtk_titlebar_right_click : t -> string
  = "ml_gtk_settings_get_gtk_titlebar_right_click"
(** Get property: gtk-titlebar-right-click *)

external set_gtk_titlebar_right_click : t -> string -> unit
  = "ml_gtk_settings_set_gtk_titlebar_right_click"
(** Set property: gtk-titlebar-right-click *)

external get_gtk_xft_antialias : t -> int
  = "ml_gtk_settings_get_gtk_xft_antialias"
(** Get property: gtk-xft-antialias *)

external set_gtk_xft_antialias : t -> int -> unit
  = "ml_gtk_settings_set_gtk_xft_antialias"
(** Set property: gtk-xft-antialias *)

external get_gtk_xft_dpi : t -> int = "ml_gtk_settings_get_gtk_xft_dpi"
(** Get property: gtk-xft-dpi *)

external set_gtk_xft_dpi : t -> int -> unit = "ml_gtk_settings_set_gtk_xft_dpi"
(** Set property: gtk-xft-dpi *)

external get_gtk_xft_hinting : t -> int = "ml_gtk_settings_get_gtk_xft_hinting"
(** Get property: gtk-xft-hinting *)

external set_gtk_xft_hinting : t -> int -> unit
  = "ml_gtk_settings_set_gtk_xft_hinting"
(** Set property: gtk-xft-hinting *)

external get_gtk_xft_hintstyle : t -> string
  = "ml_gtk_settings_get_gtk_xft_hintstyle"
(** Get property: gtk-xft-hintstyle *)

external set_gtk_xft_hintstyle : t -> string -> unit
  = "ml_gtk_settings_set_gtk_xft_hintstyle"
(** Set property: gtk-xft-hintstyle *)

external get_gtk_xft_rgba : t -> string = "ml_gtk_settings_get_gtk_xft_rgba"
(** Get property: gtk-xft-rgba *)

external set_gtk_xft_rgba : t -> string -> unit
  = "ml_gtk_settings_set_gtk_xft_rgba"
(** Set property: gtk-xft-rgba *)
