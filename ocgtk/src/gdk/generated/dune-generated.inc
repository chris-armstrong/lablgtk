; Auto-generated library for generated C bindings
; Regenerate by running gir_gen

(rule
 (targets cflag-gdk.sexp clink-gdk.sexp)
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
   gtk4
   --pkg
   pango
   --pkg
   pangocairo
   --cflags-out
   cflag-gdk.sexp
   --libs-out
   clink-gdk.sexp)))

(library
 (name ocgtk_gdk_generated_stubs)
 (public_name ocgtk.gdk.generated_stubs)
 (wrapped false)
 (modules)  ; No OCaml modules, only C stubs
 (libraries ocgtk.gdkpixbuf ocgtk.gio ocgtk.pango ocgtk.pangocairo ocgtk.cairo ocgtk_common)  ; Dependencies and common for header files
 (foreign_stubs
  (language c)
  (names
   ml_gdk_enums_gen
   ml_app_launch_context_gen
   ml_button_event_gen
   ml_cairo_context_gen
   ml_cicp_params_gen
   ml_clipboard_gen
   ml_color_state_gen
   ml_content_deserializer_gen
   ml_content_formats_builder_gen
   ml_content_formats_gen
   ml_content_provider_gen
   ml_content_serializer_gen
   ml_crossing_event_gen
   ml_cursor_gen
   ml_delete_event_gen
   ml_device_gen
   ml_device_pad_gen
   ml_device_tool_gen
   ml_display_gen
   ml_display_manager_gen
   ml_dmabuf_formats_gen
   ml_dmabuf_texture_builder_gen
   ml_dmabuf_texture_gen
   ml_dnd_event_gen
   ml_drag_gen
   ml_drag_surface_gen
   ml_drag_surface_size_gen
   ml_draw_context_gen
   ml_drop_gen
   ml_event_gen
   ml_event_sequence_gen
   ml_file_list_gen
   ml_focus_event_gen
   ml_frame_clock_gen
   ml_frame_timings_gen
   ml_gl_context_gen
   ml_gl_texture_builder_gen
   ml_gl_texture_gen
   ml_grab_broken_event_gen
   ml_key_event_gen
   ml_keymap_key_gen
   ml_memory_texture_builder_gen
   ml_memory_texture_gen
   ml_monitor_gen
   ml_motion_event_gen
   ml_pad_event_gen
   ml_paintable_gen
   ml_popup_gen
   ml_popup_layout_gen
   ml_proximity_event_gen
   ml_rectangle_gen
   ml_rgb_a_gen
   ml_scroll_event_gen
   ml_seat_gen
   ml_snapshot_gen
   ml_surface_gen
   ml_texture_downloader_gen
   ml_texture_gen
   ml_time_coord_gen
   ml_toplevel_gen
   ml_toplevel_layout_gen
   ml_toplevel_size_gen
   ml_touch_event_gen
   ml_touchpad_event_gen
   ml_vulkan_context_gen
  )
  (flags -fPIC -Igenerated -Icore -I../common (:include cflag-gdk.sexp) -Wno-deprecated-declarations -Wno-incompatible-pointer-types -Wno-int-conversion))
 (c_library_flags (:include clink-gdk.sexp)))

