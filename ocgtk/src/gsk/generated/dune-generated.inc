; Auto-generated library for generated C bindings
; Regenerate by running gir_gen

(rule
 (targets cflag-gsk.sexp clink-gsk.sexp)
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
   cflag-gsk.sexp
   --libs-out
   clink-gsk.sexp)))

(library
 (name ocgtk_gsk_generated_stubs)
 (public_name ocgtk.gsk.generated_stubs)
 (wrapped false)
 (modules)  ; No OCaml modules, only C stubs
 (libraries ocgtk.gdk ocgtk.gdkpixbuf ocgtk.gio ocgtk.graphene ocgtk.pango ocgtk.pangocairo ocgtk.cairo ocgtk_common)  ; Dependencies and common for header files
 (foreign_stubs
  (language c)
  (names
   ml_gsk_enums_gen
   ml_blend_node_gen
   ml_blur_node_gen
   ml_border_node_gen
   ml_cairo_node_gen
   ml_cairo_renderer_gen
   ml_clip_node_gen
   ml_color_matrix_node_gen
   ml_color_node_gen
   ml_color_stop_gen
   ml_component_transfer_gen
   ml_component_transfer_node_gen
   ml_conic_gradient_node_gen
   ml_container_node_gen
   ml_cross_fade_node_gen
   ml_debug_node_gen
   ml_fill_node_gen
   ml_gl_shader_gen
   ml_gl_shader_node_gen
   ml_inset_shadow_node_gen
   ml_linear_gradient_node_gen
   ml_mask_node_gen
   ml_opacity_node_gen
   ml_outset_shadow_node_gen
   ml_parse_location_gen
   ml_path_builder_gen
   ml_path_gen
   ml_path_measure_gen
   ml_path_point_gen
   ml_radial_gradient_node_gen
   ml_render_node_gen
   ml_renderer_gen
   ml_repeat_node_gen
   ml_repeating_linear_gradient_node_gen
   ml_repeating_radial_gradient_node_gen
   ml_rounded_clip_node_gen
   ml_rounded_rect_gen
   ml_shader_args_builder_gen
   ml_shadow_gen
   ml_shadow_node_gen
   ml_stroke_gen
   ml_stroke_node_gen
   ml_subsurface_node_gen
   ml_text_node_gen
   ml_texture_node_gen
   ml_texture_scale_node_gen
   ml_transform_gen
   ml_transform_node_gen
  )
  (flags -fPIC -Igenerated -Icore -I../common (:include cflag-gsk.sexp) -Wno-deprecated-declarations -Wno-incompatible-pointer-types -Wno-int-conversion))
 (c_library_flags (:include clink-gsk.sexp)))

