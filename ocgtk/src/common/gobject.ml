(**************************************************************************)
(*                ocgtk - OCaml bindings for GTK4                         *)
(*                                                                        *)
(*    This program is free software; you can redistribute it              *)
(*    and/or modify it under the terms of the GNU Library General         *)
(*    Public License version 2, as published by the                       *)
(*    Free Software Foundation with the exception described in file       *)
(*    COPYING which comes with the library.                               *)
(*                                                                        *)
(*    Based on lablgtk3 (https://github.com/garrigue/lablgtk)             *)
(*                                                                        *)
(**************************************************************************)

(** GObject module for GTK4 type system, properties, and signals *)

let () = Callback.register "Printexc.to_string" Printexc.to_string

(** {2 Core Types} *)

type -'a obj
(** GObject instance - abstract pointer type *)

type g_type = int
(** GType identifier *)

type g_value
(** Abstract type for GValue *)

type g_closure
(** Abstract type for GClosure *)

(** {2 Object Operations} *)

external get_type : 'a obj -> g_type = "ml_g_object_get_type"
external unsafe_cast : 'a obj -> 'b obj = "%identity"
external coerce : 'a obj -> unit obj = "%identity"
external same : 'a obj -> 'b obj -> bool = "ml_gobject_same"
external get_ref_count : 'a obj -> int = "ml_g_object_get_ref_count"

(** {2 Type System} *)

module Type = struct
  type t = g_type

  let equal (a : t) (b : t) = Int.equal a b
  let to_int (t : t) = t

  external name : t -> string = "ml_g_type_name"
  external from_name : string -> t = "ml_g_type_from_name"
  external parent : t -> t = "ml_g_type_parent"
  external is_a : t -> t -> bool = "ml_g_type_is_a"
  external of_fundamental_int : int -> t = "ml_g_type_of_fundamental"

  let invalid = of_fundamental_int 0
  let none = of_fundamental_int 1
  let interface = of_fundamental_int 2
  let char_ = of_fundamental_int 3
  let uchar = of_fundamental_int 4
  let boolean = of_fundamental_int 5
  let int_ = of_fundamental_int 6
  let uint = of_fundamental_int 7
  let long = of_fundamental_int 8
  let ulong = of_fundamental_int 9
  let int64 = of_fundamental_int 10
  let uint64 = of_fundamental_int 11
  let enum = of_fundamental_int 12
  let flags = of_fundamental_int 13
  let float_ = of_fundamental_int 14
  let double = of_fundamental_int 15
  let string = of_fundamental_int 16
  let pointer = of_fundamental_int 17
  let boxed = of_fundamental_int 18
  let param = of_fundamental_int 19
  let object_ = of_fundamental_int 20
end

(** {2 GValue Operations} *)

module Value = struct
  type t = g_value

  external create_empty : unit -> t = "ml_g_value_new"
  external init : t -> g_type -> unit = "ml_g_value_init_gtype"
  external reset : t -> unit = "ml_g_value_reset"
  external get_type : t -> g_type = "ml_g_value_get_gtype"

  let create gtype =
    let v = create_empty () in
    init v gtype;
    v

  external get_int : t -> int = "ml_g_value_get_int"
  external set_int : t -> int -> unit = "ml_g_value_set_int"
  external get_uint : t -> int = "ml_g_value_get_uint"
  external set_uint : t -> int -> unit = "ml_g_value_set_uint"
  external get_boolean : t -> bool = "ml_g_value_get_boolean"
  external set_boolean : t -> bool -> unit = "ml_g_value_set_boolean"
  external get_string : t -> string = "ml_g_value_get_string"
  external set_string : t -> string -> unit = "ml_g_value_set_string"
  external get_float : t -> float = "ml_g_value_get_float"
  external set_float : t -> float -> unit = "ml_g_value_set_float"
  external get_double : t -> float = "ml_g_value_get_double"
  external set_double : t -> float -> unit = "ml_g_value_set_double"
  external get_int64 : t -> int64 = "ml_g_value_get_int64"
  external set_int64 : t -> int64 -> unit = "ml_g_value_set_int64"
  external get_variant : t -> Gvariant.t = "ml_g_value_get_variant"
  external set_variant : t -> Gvariant.t -> unit = "ml_g_value_set_variant"
  external get_enum_int : t -> int = "ml_g_value_get_enum_int"
  external set_enum_int : t -> int -> unit = "ml_g_value_set_enum_int"
  external get_flags_int : t -> int = "ml_g_value_get_flags_int"
  external set_flags_int : t -> int -> unit = "ml_g_value_set_flags_int"
  external get_boxed : t -> 'a obj = "ml_g_value_get_boxed"
  external set_boxed : t -> 'a obj -> unit = "ml_g_value_set_boxed"
  external get_object_internal : t -> g_type -> 'a obj = "ml_g_value_get_object"

  external set_object_internal : t -> 'a obj -> g_type -> unit
    = "ml_g_value_set_object"

  external set_object_null : t -> g_type -> unit = "ml_g_value_set_object_null"

  (* [None] means the stored pointer is NULL ([Failure]); a wrong-typed value
     or a type mismatch raises [Invalid_argument] instead of being masked as
     [None]. *)
  let get_object v expected_type =
    match get_object_internal v expected_type with
    | x -> Some x
    | exception Failure _ -> None

  let set_object v expected_type = function
    | Some obj -> set_object_internal v obj expected_type
    | None -> set_object_null v expected_type

  let get_object_exn v expected_type = get_object_internal v expected_type

  let set_object_exn v expected_type obj =
    set_object_internal v obj expected_type
end

(** {2 Properties} *)

module Property = struct
  external get_value : 'a obj -> name:string -> g_value -> unit
    = "ml_g_object_get_property"

  external set_value : 'a obj -> name:string -> g_value -> unit
    = "ml_g_object_set_property"

  external get_type : 'a obj -> name:string -> g_type
    = "ml_g_object_get_property_type"

  external freeze_notify : 'a obj -> unit = "ml_g_object_freeze_notify"
  external thaw_notify : 'a obj -> unit = "ml_g_object_thaw_notify"
  external notify : 'a obj -> name:string -> unit = "ml_g_object_notify"
end

(** {2 Closures} *)

module Closure = struct
  type t = g_closure
  type args
  type argv = { result : g_value; nargs : int; args : args }

  external create : (argv -> unit) -> t = "ml_g_closure_new"
  external nth : argv -> pos:int -> g_value = "ml_g_closure_get_arg"
  external result : argv -> g_value = "ml_g_closure_get_result"
  external get_result_type : argv -> g_type = "ml_g_closure_get_result_type"
  external get_type : argv -> pos:int -> g_type = "ml_g_closure_get_arg_type"
  external set_result : argv -> g_value -> unit = "ml_g_closure_set_result"
end

(** {2 Signals} *)

module Signal = struct
  type handler_id = int

  external connect :
    'a obj -> name:string -> callback:g_closure -> after:bool -> handler_id
    = "ml_g_signal_connect_closure"

  let connect_simple obj ~name ~callback ~after =
    let closure = Closure.create (fun _argv -> callback ()) in
    connect obj ~name ~callback:closure ~after

  external disconnect : 'a obj -> handler_id -> unit
    = "ml_g_signal_handler_disconnect"

  external handler_block : 'a obj -> handler_id -> unit
    = "ml_g_signal_handler_block"

  external handler_unblock : 'a obj -> handler_id -> unit
    = "ml_g_signal_handler_unblock"

  external handler_is_connected : 'a obj -> handler_id -> bool
    = "ml_g_signal_handler_is_connected"

  external emit_by_name : 'a obj -> name:string -> unit
    = "ml_g_signal_emit_by_name"
end
