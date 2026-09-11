; Auto-generated library for generated C bindings
; Regenerate by running gir_gen

(rule
 (targets cflag-gio.sexp clink-gio.sexp)
 (action
  (run
   %{exe:../configurator/config_flags.exe}
   --pkg
   gio-2.0
   --pkg-optional
   gio-unix-2.0
   --cflags-out
   cflag-gio.sexp
   --libs-out
   clink-gio.sexp)))

(library
 (name ocgtk_gio_generated_stubs_batch_0)
 (public_name ocgtk.gio.generated_stubs_batch_0)
 (wrapped false)
 (modules)  ; No OCaml modules, only C stubs
 (libraries ocgtk_common)  ; Depend on common for header files
 (foreign_stubs
  (language c)
  (names
   ml_gio_enums_gen
   ml_action_entry_gen
   ml_action_gen
   ml_action_group_gen
   ml_action_map_gen
   ml_app_info_gen
   ml_app_info_monitor_gen
   ml_app_launch_context_gen
   ml_application_command_line_gen
   ml_application_gen
   ml_async_initable_gen
   ml_async_result_gen
   ml_buffered_input_stream_gen
   ml_buffered_output_stream_gen
   ml_bytes_icon_gen
   ml_cancellable_gen
   ml_charset_converter_gen
   ml_converter_gen
   ml_converter_input_stream_gen
   ml_converter_output_stream_gen
   ml_credentials_gen
   ml_d_bus_action_group_gen
   ml_d_bus_annotation_info_gen
   ml_d_bus_arg_info_gen
   ml_d_bus_auth_observer_gen
   ml_d_bus_connection_gen
   ml_d_bus_error_entry_gen
   ml_d_bus_interface_gen
   ml_d_bus_interface_info_gen
   ml_d_bus_interface_skeleton_gen
   ml_d_bus_interface_v_table_gen
   ml_d_bus_menu_model_gen
   ml_d_bus_message_gen
   ml_d_bus_method_info_gen
   ml_d_bus_method_invocation_gen
   ml_d_bus_node_info_gen
   ml_d_bus_object_gen
   ml_d_bus_object_manager_client_gen
   ml_d_bus_object_manager_gen
   ml_d_bus_object_manager_server_gen
   ml_d_bus_object_proxy_gen
   ml_d_bus_object_skeleton_gen
   ml_d_bus_property_info_gen
   ml_d_bus_proxy_gen
   ml_d_bus_server_gen
   ml_d_bus_signal_info_gen
   ml_d_bus_subtree_v_table_gen
   ml_data_input_stream_gen
   ml_data_output_stream_gen
   ml_datagram_based_gen
   ml_debug_controller_d_bus_gen
   ml_debug_controller_gen
   ml_drive_gen
   ml_dtls_client_connection_gen
   ml_dtls_connection_gen
   ml_dtls_server_connection_gen
   ml_emblem_gen
   ml_emblemed_icon_gen
   ml_file_attribute_info_gen
   ml_file_attribute_info_list_gen
   ml_file_attribute_matcher_gen
   ml_file_enumerator_gen
   ml_file_gen
   ml_file_icon_gen
   ml_file_info_gen
   ml_file_input_stream_gen
   ml_file_io_stream_gen
   ml_file_monitor_gen
   ml_file_output_stream_gen
   ml_filename_completer_gen
   ml_filter_input_stream_gen
   ml_filter_output_stream_gen
   ml_icon_gen
   ml_inet_address_gen
   ml_inet_address_mask_gen
   ml_inet_socket_address_gen
   ml_initable_gen
   ml_input_message_gen
   ml_input_stream_gen
   ml_input_vector_gen
  )
  (flags -fPIC -Igenerated -Icore -I../common (:include cflag-gio.sexp) -Wno-deprecated-declarations -Wno-incompatible-pointer-types -Wno-int-conversion))
 (c_library_flags (:include clink-gio.sexp)))

(library
 (name ocgtk_gio_generated_stubs_batch_1)
 (public_name ocgtk.gio.generated_stubs_batch_1)
 (wrapped false)
 (modules)  ; No OCaml modules, only C stubs
 (libraries ocgtk_common)  ; Depend on common for header files
 (foreign_stubs
  (language c)
  (names
   ml_io_extension_gen
   ml_io_extension_point_gen
   ml_io_module_gen
   ml_io_module_scope_gen
   ml_io_scheduler_job_gen
   ml_io_stream_adapter_gen
   ml_io_stream_gen
   ml_list_model_gen
   ml_list_store_gen
   ml_loadable_icon_gen
   ml_memory_input_stream_gen
   ml_memory_monitor_gen
   ml_memory_output_stream_gen
   ml_menu_attribute_iter_gen
   ml_menu_gen
   ml_menu_item_gen
   ml_menu_link_iter_gen
   ml_menu_model_gen
   ml_mount_gen
   ml_mount_operation_gen
   ml_native_socket_address_gen
   ml_native_volume_monitor_gen
   ml_network_address_gen
   ml_network_monitor_gen
   ml_network_service_gen
   ml_notification_gen
   ml_output_message_gen
   ml_output_stream_gen
   ml_output_vector_gen
   ml_permission_gen
   ml_pollable_input_stream_gen
   ml_pollable_output_stream_gen
   ml_power_profile_monitor_gen
   ml_property_action_gen
   ml_proxy_address_enumerator_gen
   ml_proxy_address_gen
   ml_proxy_gen
   ml_proxy_resolver_gen
   ml_remote_action_group_gen
   ml_resolver_gen
   ml_resource_gen
   ml_seekable_gen
   ml_settings_gen
   ml_settings_schema_gen
   ml_settings_schema_key_gen
   ml_settings_schema_source_gen
   ml_simple_action_gen
   ml_simple_action_group_gen
   ml_simple_async_result_gen
   ml_simple_io_stream_gen
   ml_simple_permission_gen
   ml_simple_proxy_resolver_gen
   ml_socket_address_enumerator_gen
   ml_socket_address_gen
   ml_socket_client_gen
   ml_socket_connectable_gen
   ml_socket_connection_gen
   ml_socket_control_message_gen
   ml_socket_gen
   ml_socket_listener_gen
   ml_socket_service_gen
   ml_srv_target_gen
   ml_static_resource_gen
   ml_subprocess_gen
   ml_subprocess_launcher_gen
   ml_task_gen
   ml_tcp_connection_gen
   ml_tcp_wrapper_connection_gen
   ml_test_d_bus_gen
   ml_themed_icon_gen
   ml_threaded_resolver_gen
   ml_threaded_socket_service_gen
   ml_tls_backend_gen
   ml_tls_certificate_gen
   ml_tls_client_connection_gen
   ml_tls_connection_gen
   ml_tls_database_gen
   ml_tls_file_database_gen
   ml_tls_interaction_gen
   ml_tls_password_gen
  )
  (flags -fPIC -Igenerated -Icore -I../common (:include cflag-gio.sexp) -Wno-deprecated-declarations -Wno-incompatible-pointer-types -Wno-int-conversion))
 (c_library_flags (:include clink-gio.sexp)))

(library
 (name ocgtk_gio_generated_stubs_batch_2)
 (public_name ocgtk.gio.generated_stubs_batch_2)
 (wrapped false)
 (modules)  ; No OCaml modules, only C stubs
 (libraries ocgtk_common)  ; Depend on common for header files
 (foreign_stubs
  (language c)
  (names
   ml_tls_server_connection_gen
   ml_unix_connection_gen
   ml_unix_credentials_message_gen
   ml_unix_fd_list_gen
   ml_unix_socket_address_gen
   ml_vfs_gen
   ml_volume_gen
   ml_volume_monitor_gen
   ml_zlib_compressor_gen
   ml_zlib_decompressor_gen
  )
  (flags -fPIC -Igenerated -Icore -I../common (:include cflag-gio.sexp) -Wno-deprecated-declarations -Wno-incompatible-pointer-types -Wno-int-conversion))
 (c_library_flags (:include clink-gio.sexp)))

(library
 (name ocgtk_gio_generated_stubs)
 (public_name ocgtk.gio.generated_stubs)
 (wrapped false)
 (modules)  ; No OCaml modules, only C stubs
 (libraries ocgtk_gio_generated_stubs_batch_0 ocgtk_gio_generated_stubs_batch_1 ocgtk_gio_generated_stubs_batch_2))
