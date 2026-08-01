(** Test-only helpers for invoking GObject closures directly.

    These functions exist solely for testing the closure-marshal path. They are
    NOT part of the public API and should only be used in tests. *)

external invoke_closure_void : Gobject.g_closure -> unit
  = "ml_test_invoke_closure_void"

external invoke_closure_int : Gobject.g_closure -> int -> unit
  = "ml_test_invoke_closure_int"

external invoke_closure_string : Gobject.g_closure -> string -> unit
  = "ml_test_invoke_closure_string"

external invoke_closure_two_ints : Gobject.g_closure -> int -> int -> unit
  = "ml_test_invoke_closure_two_ints"

external invoke_closure_boolean : Gobject.g_closure -> bool -> unit
  = "ml_test_invoke_closure_boolean"

external invoke_closure_double : Gobject.g_closure -> float -> unit
  = "ml_test_invoke_closure_double"

external invoke_closure_mixed_return_bool :
  Gobject.g_closure -> int -> string -> 'a Gobject.obj option -> bool
  = "ml_test_invoke_closure_mixed_return_bool"

external invoke_closure_flags_return_bool : Gobject.g_closure -> int -> bool
  = "ml_test_invoke_closure_flags_return_bool"

external invoke_closure_return_int : Gobject.g_closure -> int
  = "ml_test_invoke_closure_return_int"

external reset_closure_exception_flag : unit -> unit
  = "ml_test_reset_closure_exception_flag"

external check_closure_exception_flag : unit -> bool
  = "ml_test_check_closure_exception_flag"
