; Auto-generated library for generated C bindings
; Regenerate by running gir_gen

(rule
 (targets cflag-graphene.sexp clink-graphene.sexp)
 (action
  (run
   %{exe:../configurator/config_flags.exe}
   --pkg
   graphene-gobject-1.0
   --cflags-out
   cflag-graphene.sexp
   --libs-out
   clink-graphene.sexp)))

(library
 (name ocgtk_graphene_generated_stubs)
 (public_name ocgtk.graphene.generated_stubs)
 (wrapped false)
 (modules)  ; No OCaml modules, only C stubs
 (libraries ocgtk_common)  ; Depend on common for header files
 (foreign_stubs
  (language c)
  (names
   ml_graphene_enums_gen
   ml_box_gen
   ml_euler_gen
   ml_frustum_gen
   ml_matrix_gen
   ml_plane_gen
   ml_point3_d_gen
   ml_point_gen
   ml_quad_gen
   ml_quaternion_gen
   ml_ray_gen
   ml_rect_gen
   ml_simd4_f_gen
   ml_simd4_x4_f_gen
   ml_size_gen
   ml_sphere_gen
   ml_triangle_gen
   ml_vec2_gen
   ml_vec3_gen
   ml_vec4_gen
  )
  (flags -fPIC -Igenerated -Icore -I../common (:include cflag-graphene.sexp) -Wno-deprecated-declarations -Wno-incompatible-pointer-types -Wno-int-conversion))
 (c_library_flags (:include clink-graphene.sexp)))

