(* GENERATED CODE - DO NOT EDIT *)
(* TestDBus: TestDBus *)

type t = [ `test_d_bus | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_test_d_bus_get_type"

external new_ : Gio_enums.testdbusflags -> t = "ml_g_test_dbus_new"
(** Create a new TestDBus *)

(* Methods *)

external up : t -> unit = "ml_g_test_dbus_up"
(** Start a dbus-daemon instance and set DBUS_SESSION_BUS_ADDRESS. After this
    call, it is safe for unit tests to start sending messages on the session
    bus.

    If this function is called from setup callback of g_test_add(),
    g_test_dbus_down() must be called in its teardown callback.

    If this function is called from unit test's main(), then g_test_dbus_down()
    must be called after g_test_run(). *)

external stop : t -> unit = "ml_g_test_dbus_stop"
(** Stop the session bus started by g_test_dbus_up().

    Unlike g_test_dbus_down(), this won't verify the #GDBusConnection singleton
    returned by g_bus_get() or g_bus_get_sync() is destroyed. Unit tests wanting
    to verify behaviour after the session bus has been stopped can use this
    function but should still call g_test_dbus_down() when done. *)

external get_flags : t -> Gio_enums.testdbusflags = "ml_g_test_dbus_get_flags"
(** Get the flags of the #GTestDBus object. *)

external get_bus_address : t -> string option = "ml_g_test_dbus_get_bus_address"
(** Get the address on which dbus-daemon is running. If g_test_dbus_up() has not
    been called yet, %NULL is returned. This can be used with
    g_dbus_connection_new_for_address(). *)

external down : t -> unit = "ml_g_test_dbus_down"
(** Stop the session bus started by g_test_dbus_up().

    This will wait for the singleton returned by g_bus_get() or g_bus_get_sync()
    to be destroyed. This is done to ensure that the next unit test won't get a
    leaked singleton from this test. *)

external add_service_dir : t -> string -> unit
  = "ml_g_test_dbus_add_service_dir"
(** Add a path where dbus-daemon will look up .service files. This can't be
    called after g_test_dbus_up(). *)

(* Properties *)
