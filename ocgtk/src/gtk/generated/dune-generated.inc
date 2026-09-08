; Auto-generated library for generated C bindings
; Regenerate by running gir_gen

(rule
 (targets cflag-gtk.sexp clink-gtk.sexp)
 (action
  (run
   %{exe:../configurator/config_flags.exe}
   --pkg
   cairo-gobject
   --pkg
   gdk-pixbuf-2.0
   --pkg
   gio-2.0
   --pkg-optional
   gio-unix-2.0
   --pkg
   graphene-gobject-1.0
   --pkg
   gtk4
   --pkg
   pango
   --pkg
   pangocairo
   --cflags-out
   cflag-gtk.sexp
   --libs-out
   clink-gtk.sexp)))

(library
 (name ocgtk_gtk_generated_stubs_batch_0)
 (public_name ocgtk.gtk.generated_stubs_batch_0)
 (wrapped false)
 (modules)  ; No OCaml modules, only C stubs
 (libraries ocgtk.gdk ocgtk.gdkpixbuf ocgtk.gio ocgtk.graphene ocgtk.gsk ocgtk.pango ocgtk.pangocairo ocgtk.cairo ocgtk_common)  ; Dependencies and common for header files
 (foreign_stubs
  (language c)
  (names
   ml_gtk_enums_gen
   ml_about_dialog_gen
   ml_accessible_gen
   ml_accessible_list_gen
   ml_accessible_range_gen
   ml_accessible_text_gen
   ml_accessible_text_range_gen
   ml_action_bar_gen
   ml_actionable_gen
   ml_activate_action_gen
   ml_adjustment_gen
   ml_alert_dialog_gen
   ml_alternative_trigger_gen
   ml_any_filter_gen
   ml_app_chooser_button_gen
   ml_app_chooser_dialog_gen
   ml_app_chooser_gen
   ml_app_chooser_widget_gen
   ml_application_gen
   ml_application_window_gen
   ml_aspect_frame_gen
   ml_assistant_gen
   ml_assistant_page_gen
   ml_at_context_gen
   ml_bin_layout_gen
   ml_bitset_gen
   ml_bitset_iter_gen
   ml_bookmark_list_gen
   ml_bool_filter_gen
   ml_border_gen
   ml_box_gen
   ml_box_layout_gen
   ml_buildable_gen
   ml_buildable_parse_context_gen
   ml_buildable_parser_gen
   ml_builder_c_scope_gen
   ml_builder_gen
   ml_builder_list_item_factory_gen
   ml_builder_scope_gen
   ml_button_gen
   ml_c_closure_expression_gen
   ml_calendar_gen
   ml_callback_action_gen
   ml_cell_area_box_gen
   ml_cell_area_context_gen
   ml_cell_area_gen
   ml_cell_editable_gen
   ml_cell_layout_gen
   ml_cell_renderer_accel_gen
   ml_cell_renderer_combo_gen
   ml_cell_renderer_gen
   ml_cell_renderer_pixbuf_gen
   ml_cell_renderer_progress_gen
   ml_cell_renderer_spin_gen
   ml_cell_renderer_spinner_gen
   ml_cell_renderer_text_gen
   ml_cell_renderer_toggle_gen
   ml_cell_view_gen
   ml_center_box_gen
   ml_center_layout_gen
   ml_check_button_gen
   ml_closure_expression_gen
   ml_color_button_gen
   ml_color_chooser_dialog_gen
   ml_color_chooser_gen
   ml_color_chooser_widget_gen
   ml_color_dialog_button_gen
   ml_color_dialog_gen
   ml_column_view_cell_gen
   ml_column_view_column_gen
   ml_column_view_gen
   ml_column_view_row_gen
   ml_column_view_sorter_gen
   ml_combo_box_gen
   ml_combo_box_text_gen
   ml_constant_expression_gen
   ml_constraint_gen
   ml_constraint_guide_gen
   ml_constraint_layout_child_gen
   ml_constraint_layout_gen
  )
  (flags -fPIC -Igenerated -Icore -I../common (:include cflag-gtk.sexp) -Wno-deprecated-declarations -Wno-incompatible-pointer-types -Wno-int-conversion))
 (c_library_flags (:include clink-gtk.sexp)))

(library
 (name ocgtk_gtk_generated_stubs_batch_1)
 (public_name ocgtk.gtk.generated_stubs_batch_1)
 (wrapped false)
 (modules)  ; No OCaml modules, only C stubs
 (libraries ocgtk.gdk ocgtk.gdkpixbuf ocgtk.gio ocgtk.graphene ocgtk.gsk ocgtk.pango ocgtk.pangocairo ocgtk.cairo ocgtk_common)  ; Dependencies and common for header files
 (foreign_stubs
  (language c)
  (names
   ml_constraint_target_gen
   ml_css_location_gen
   ml_css_provider_gen
   ml_css_section_gen
   ml_css_style_change_gen
   ml_custom_filter_gen
   ml_custom_layout_gen
   ml_custom_sorter_gen
   ml_dialog_gen
   ml_directory_list_gen
   ml_drag_icon_gen
   ml_drag_source_gen
   ml_drawing_area_gen
   ml_drop_controller_motion_gen
   ml_drop_down_gen
   ml_drop_target_async_gen
   ml_drop_target_gen
   ml_editable_gen
   ml_editable_label_gen
   ml_emoji_chooser_gen
   ml_entry_buffer_gen
   ml_entry_completion_gen
   ml_entry_gen
   ml_event_controller_focus_gen
   ml_event_controller_gen
   ml_event_controller_key_gen
   ml_event_controller_legacy_gen
   ml_event_controller_motion_gen
   ml_event_controller_scroll_gen
   ml_every_filter_gen
   ml_expander_gen
   ml_expression_gen
   ml_expression_watch_gen
   ml_file_chooser_dialog_gen
   ml_file_chooser_gen
   ml_file_chooser_native_gen
   ml_file_chooser_widget_gen
   ml_file_dialog_gen
   ml_file_filter_gen
   ml_file_launcher_gen
   ml_filter_gen
   ml_filter_list_model_gen
   ml_fixed_gen
   ml_fixed_layout_child_gen
   ml_fixed_layout_gen
   ml_flatten_list_model_gen
   ml_flow_box_child_gen
   ml_flow_box_gen
   ml_font_button_gen
   ml_font_chooser_dialog_gen
   ml_font_chooser_gen
   ml_font_chooser_widget_gen
   ml_font_dialog_button_gen
   ml_font_dialog_gen
   ml_frame_gen
   ml_gesture_click_gen
   ml_gesture_drag_gen
   ml_gesture_gen
   ml_gesture_long_press_gen
   ml_gesture_pan_gen
   ml_gesture_rotate_gen
   ml_gesture_single_gen
   ml_gesture_stylus_gen
   ml_gesture_swipe_gen
   ml_gesture_zoom_gen
   ml_gl_area_gen
   ml_graphics_offload_gen
   ml_grid_gen
   ml_grid_layout_child_gen
   ml_grid_layout_gen
   ml_grid_view_gen
   ml_header_bar_gen
   ml_icon_paintable_gen
   ml_icon_theme_gen
   ml_icon_view_gen
   ml_im_context_gen
   ml_im_context_simple_gen
   ml_im_multicontext_gen
   ml_image_gen
   ml_info_bar_gen
  )
  (flags -fPIC -Igenerated -Icore -I../common (:include cflag-gtk.sexp) -Wno-deprecated-declarations -Wno-incompatible-pointer-types -Wno-int-conversion))
 (c_library_flags (:include clink-gtk.sexp)))

(library
 (name ocgtk_gtk_generated_stubs_batch_2)
 (public_name ocgtk.gtk.generated_stubs_batch_2)
 (wrapped false)
 (modules)  ; No OCaml modules, only C stubs
 (libraries ocgtk.gdk ocgtk.gdkpixbuf ocgtk.gio ocgtk.graphene ocgtk.gsk ocgtk.pango ocgtk.pangocairo ocgtk.cairo ocgtk_common)  ; Dependencies and common for header files
 (foreign_stubs
  (language c)
  (names
   ml_inscription_gen
   ml_keyval_trigger_gen
   ml_label_gen
   ml_layout_child_gen
   ml_layout_manager_gen
   ml_level_bar_gen
   ml_link_button_gen
   ml_list_base_gen
   ml_list_box_gen
   ml_list_box_row_gen
   ml_list_header_gen
   ml_list_item_factory_gen
   ml_list_item_gen
   ml_list_store_gen
   ml_list_view_gen
   ml_lock_button_gen
   ml_map_list_model_gen
   ml_media_controls_gen
   ml_media_file_gen
   ml_media_stream_gen
   ml_menu_button_gen
   ml_message_dialog_gen
   ml_mnemonic_action_gen
   ml_mnemonic_trigger_gen
   ml_mount_operation_gen
   ml_multi_filter_gen
   ml_multi_selection_gen
   ml_multi_sorter_gen
   ml_named_action_gen
   ml_native_dialog_gen
   ml_native_gen
   ml_never_trigger_gen
   ml_no_selection_gen
   ml_notebook_gen
   ml_notebook_page_gen
   ml_nothing_action_gen
   ml_numeric_sorter_gen
   ml_object_expression_gen
   ml_orientable_gen
   ml_overlay_gen
   ml_overlay_layout_child_gen
   ml_overlay_layout_gen
   ml_pad_action_entry_gen
   ml_pad_controller_gen
   ml_page_range_gen
   ml_page_setup_gen
   ml_paned_gen
   ml_paper_size_gen
   ml_param_spec_expression_gen
   ml_password_entry_buffer_gen
   ml_password_entry_gen
   ml_picture_gen
   ml_popover_gen
   ml_popover_menu_bar_gen
   ml_popover_menu_gen
   ml_print_context_gen
   ml_print_dialog_gen
   ml_print_operation_gen
   ml_print_operation_preview_gen
   ml_print_settings_gen
   ml_print_setup_gen
   ml_progress_bar_gen
   ml_property_expression_gen
   ml_range_gen
   ml_recent_data_gen
   ml_recent_info_gen
   ml_recent_manager_gen
   ml_requested_size_gen
   ml_requisition_gen
   ml_revealer_gen
   ml_root_gen
   ml_scale_button_gen
   ml_scale_gen
   ml_scroll_info_gen
   ml_scrollable_gen
   ml_scrollbar_gen
   ml_scrolled_window_gen
   ml_search_bar_gen
   ml_search_entry_gen
   ml_section_model_gen
  )
  (flags -fPIC -Igenerated -Icore -I../common (:include cflag-gtk.sexp) -Wno-deprecated-declarations -Wno-incompatible-pointer-types -Wno-int-conversion))
 (c_library_flags (:include clink-gtk.sexp)))

(library
 (name ocgtk_gtk_generated_stubs_batch_3)
 (public_name ocgtk.gtk.generated_stubs_batch_3)
 (wrapped false)
 (modules)  ; No OCaml modules, only C stubs
 (libraries ocgtk.gdk ocgtk.gdkpixbuf ocgtk.gio ocgtk.graphene ocgtk.gsk ocgtk.pango ocgtk.pangocairo ocgtk.cairo ocgtk_common)  ; Dependencies and common for header files
 (foreign_stubs
  (language c)
  (names
   ml_selection_filter_model_gen
   ml_selection_model_gen
   ml_separator_gen
   ml_settings_gen
   ml_shortcut_action_gen
   ml_shortcut_controller_gen
   ml_shortcut_gen
   ml_shortcut_label_gen
   ml_shortcut_manager_gen
   ml_shortcut_trigger_gen
   ml_shortcuts_group_gen
   ml_shortcuts_section_gen
   ml_shortcuts_shortcut_gen
   ml_shortcuts_window_gen
   ml_signal_action_gen
   ml_signal_list_item_factory_gen
   ml_single_selection_gen
   ml_size_group_gen
   ml_slice_list_model_gen
   ml_snapshot_gen
   ml_sort_list_model_gen
   ml_sorter_gen
   ml_spin_button_gen
   ml_spinner_gen
   ml_stack_gen
   ml_stack_page_gen
   ml_stack_sidebar_gen
   ml_stack_switcher_gen
   ml_statusbar_gen
   ml_string_filter_gen
   ml_string_list_gen
   ml_string_object_gen
   ml_string_sorter_gen
   ml_style_context_gen
   ml_style_provider_gen
   ml_switch_gen
   ml_symbolic_paintable_gen
   ml_text_buffer_gen
   ml_text_child_anchor_gen
   ml_text_gen
   ml_text_iter_gen
   ml_text_mark_gen
   ml_text_tag_gen
   ml_text_tag_table_gen
   ml_text_view_gen
   ml_toggle_button_gen
   ml_tooltip_gen
   ml_tree_drag_dest_gen
   ml_tree_drag_source_gen
   ml_tree_expander_gen
   ml_tree_iter_gen
   ml_tree_list_model_gen
   ml_tree_list_row_gen
   ml_tree_list_row_sorter_gen
   ml_tree_model_filter_gen
   ml_tree_model_gen
   ml_tree_model_sort_gen
   ml_tree_path_gen
   ml_tree_row_reference_gen
   ml_tree_selection_gen
   ml_tree_sortable_gen
   ml_tree_store_gen
   ml_tree_view_column_gen
   ml_tree_view_gen
   ml_uri_launcher_gen
   ml_video_gen
   ml_viewport_gen
   ml_volume_button_gen
   ml_widget_gen
   ml_widget_paintable_gen
   ml_window_controls_gen
   ml_window_gen
   ml_window_group_gen
   ml_window_handle_gen
  )
  (flags -fPIC -Igenerated -Icore -I../common (:include cflag-gtk.sexp) -Wno-deprecated-declarations -Wno-incompatible-pointer-types -Wno-int-conversion))
 (c_library_flags (:include clink-gtk.sexp)))

(library
 (name ocgtk_gtk_generated_stubs)
 (public_name ocgtk.gtk.generated_stubs)
 (wrapped false)
 (modules)  ; No OCaml modules, only C stubs
 (libraries ocgtk_gtk_generated_stubs_batch_0 ocgtk_gtk_generated_stubs_batch_1 ocgtk_gtk_generated_stubs_batch_2 ocgtk_gtk_generated_stubs_batch_3))
