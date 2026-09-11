; Auto-generated library for generated C bindings
; Regenerate by running gir_gen

(rule
 (targets cflag-pango.sexp clink-pango.sexp)
 (action
  (run
   %{exe:../configurator/config_flags.exe}
   --pkg
   cairo-gobject
   --pkg
   gio-2.0
   --pkg-optional
   gio-unix-2.0
   --pkg
   pango
   --cflags-out
   cflag-pango.sexp
   --libs-out
   clink-pango.sexp)))

(library
 (name ocgtk_pango_generated_stubs)
 (public_name ocgtk.pango.generated_stubs)
 (wrapped false)
 (modules)  ; No OCaml modules, only C stubs
 (libraries ocgtk.gio ocgtk.cairo ocgtk_common)  ; Dependencies and common for header files
 (foreign_stubs
  (language c)
  (names
   ml_pango_enums_gen
   ml_analysis_gen
   ml_attr_class_gen
   ml_attr_color_gen
   ml_attr_float_gen
   ml_attr_font_desc_gen
   ml_attr_font_features_gen
   ml_attr_int_gen
   ml_attr_iterator_gen
   ml_attr_language_gen
   ml_attr_list_gen
   ml_attr_shape_gen
   ml_attr_size_gen
   ml_attr_string_gen
   ml_attribute_gen
   ml_color_gen
   ml_context_gen
   ml_coverage_gen
   ml_font_description_gen
   ml_font_face_gen
   ml_font_family_gen
   ml_font_gen
   ml_font_map_gen
   ml_font_metrics_gen
   ml_fontset_gen
   ml_fontset_simple_gen
   ml_glyph_geometry_gen
   ml_glyph_info_gen
   ml_glyph_item_gen
   ml_glyph_item_iter_gen
   ml_glyph_string_gen
   ml_glyph_vis_attr_gen
   ml_item_gen
   ml_language_gen
   ml_layout_gen
   ml_layout_iter_gen
   ml_layout_line_gen
   ml_log_attr_gen
   ml_matrix_gen
   ml_rectangle_gen
   ml_renderer_gen
   ml_script_iter_gen
   ml_tab_array_gen
  )
  (flags -fPIC -Igenerated -Icore -I../common (:include cflag-pango.sexp) -Wno-deprecated-declarations -Wno-incompatible-pointer-types -Wno-int-conversion))
 (c_library_flags (:include clink-pango.sexp)))

