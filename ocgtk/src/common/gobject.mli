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

(** GObject type system and object model for GTK4 *)

(** {2 Core Types} *)

type -'a obj
(** Type for GObject instances. The type parameter provides type safety. *)

type g_type
(** GType identifier — opaque; use [Type.equal] to compare, [Type.to_int] for
    formatting *)

type g_value
(** GValue container for generic values *)

type g_closure
(** GClosure for signal callbacks *)

(** {2 Object Operations} *)

val get_type : 'a obj -> g_type
(** Get the GType of an object *)

external unsafe_cast : 'a obj -> 'b obj = "%identity"
(** Unsafe cast between object types *)

external coerce : 'a obj -> unit obj = "%identity"
(** Safe coercion to generic object *)

external same : 'a obj -> 'b obj -> bool = "ml_gobject_same"
(** [same a b] is [true] iff [a] and [b] wrap the same underlying GObject
    pointer. Two extractions of the same GObject (e.g. successive
    [Gobject.Value.get_object] calls in a signal callback) allocate distinct
    OCaml custom blocks, so [Stdlib.(==)] always returns [false]. Use [same]
    when the intent is identity comparison.

    [Stdlib.(=)], [Stdlib.compare], and [Hashtbl.hash] also operate on pointer
    identity for [obj] values (the custom block installs a pointer-compare /
    pointer-hash); [same] is the explicit form. *)

val get_ref_count : 'a obj -> int
(** Get reference count (for debugging) *)

(** {2 Type System} *)

module Type : sig
  type t = g_type

  val equal : t -> t -> bool
  (** Test two GTypes for identity *)

  val to_int : t -> int
  (** Expose the underlying integer (for logging/debugging only) *)

  val name : t -> string
  (** Get type name *)

  val from_name : string -> t
  (** Get type from name *)

  val parent : t -> t
  (** Get parent type *)

  val is_a : t -> t -> bool
  (** Check type hierarchy *)

  val invalid : t
  val none : t
  val interface : t
  val char_ : t
  val uchar : t
  val boolean : t
  val int_ : t
  val uint : t
  val long : t
  val ulong : t
  val int64 : t
  val uint64 : t
  val enum : t
  val flags : t
  val float_ : t
  val double : t
  val string : t
  val pointer : t
  val boxed : t
  val param : t
  val object_ : t
end

(** {2 GValue Operations} *)

module Value : sig
  type t = g_value

  val create : g_type -> t
  (** Create and initialize a GValue with the given type *)

  val create_empty : unit -> t
  (** Create an uninitialized GValue *)

  val init : t -> g_type -> unit
  (** Initialize a GValue with a type *)

  val reset : t -> unit
  (** Reset a GValue (clear and reinitialize) *)

  val get_type : t -> g_type
  (** Get the type of a GValue *)

  (** {3 Type-specific getters/setters}

      Every typed setter raises [Invalid_argument] when the GValue does not hold
      the corresponding type — GLib would only log a critical and leave the
      GValue untouched, silently doing nothing from OCaml's perspective. *)

  val get_int : t -> int
  val set_int : t -> int -> unit
  val get_uint : t -> int
  val set_uint : t -> int -> unit
  val get_boolean : t -> bool
  val set_boolean : t -> bool -> unit
  val get_string : t -> string
  val set_string : t -> string -> unit
  val get_float : t -> float
  val set_float : t -> float -> unit
  val get_double : t -> float
  val set_double : t -> float -> unit

  val get_int64 : t -> int64
  (** Get a 64-bit integer from a GValue of G_TYPE_INT64. *)

  val set_int64 : t -> int64 -> unit
  (** Set a 64-bit integer on a GValue of G_TYPE_INT64. *)

  val get_variant : t -> Gvariant.t
  (** Get a GVariant from a GValue of G_TYPE_VARIANT. The returned value is a
      new reference (ref-counted); the caller may use it freely and the OCaml GC
      will unref it when the value is collected. *)

  val set_variant : t -> Gvariant.t -> unit
  (** Set a GVariant on a GValue of G_TYPE_VARIANT. Transfer-none: the GValue
      takes its own reference. *)

  val get_enum_int : t -> int
  (** Get the raw integer value of a GValue holding an enum type. Raises
      [Invalid_argument] if the GValue does not hold an enum type. *)

  val set_enum_int : t -> int -> unit
  (** Set the raw integer value of a GValue holding an enum type. Raises
      [Invalid_argument] if the GValue does not hold an enum type. *)

  val get_flags_int : t -> int
  (** Get the raw integer bitmask of a GValue holding a flags type. Raises
      [Invalid_argument] if the GValue does not hold a flags type. *)

  val set_flags_int : t -> int -> unit
  (** Set the raw integer bitmask of a GValue holding a flags type. Raises
      [Invalid_argument] if the GValue does not hold a flags type. *)

  val get_boxed : t -> 'a obj
  (** Get a boxed GIR record from a GValue holding a boxed GType. Returns a
      gir_record custom block (ocgtk_gir_record_ops) carrying the GType and an
      owned copy of the boxed data (g_boxed_copy was called). The existing
      gir_record finalizer calls g_boxed_free when the block is collected. The
      caller must ascribe the correct record type at the call site, e.g.
      [(Gobject.Value.get_boxed v : Gtk.Tree_iter.t)]. Raises [Invalid_argument]
      if the GValue does not hold a boxed type. *)

  val set_boxed : t -> 'a obj -> unit
  (** Set a boxed GIR record on a GValue holding a boxed GType. The argument
      must be a gir_record custom block created by the ocgtk GIR record
      infrastructure. [g_value_set_boxed] copies the data with the *GValue's*
      type, so the record's own GType must be a registered boxed subtype of the
      GValue's type. Raises [Invalid_argument] if the record's GType is missing,
      not boxed, or incompatible with the GValue's type, and [Failure] if the
      argument is not a gir_record custom block. Transfer-none: the GValue
      copies the data via [g_boxed_copy] internally. The caller must ascribe the
      correct record type at the call site. *)

  val get_object : t -> 'a obj option

  val set_object : t -> 'a obj option -> unit
  (** Set a GObject on a GValue of an object type. Raises [Invalid_argument] if
      the GValue does not hold an object type or if the object's concrete type
      is incompatible with the GValue's type. [None] stores NULL. *)

  val get_object_exn : t -> 'a obj
  (** Get a GObject from a GValue, raising [Failure] if the value is NULL. Use
      this when the GIR declares the parameter non-nullable. *)

  val set_object_exn : t -> 'a obj -> unit
  (** Set a non-nullable GObject on a GValue. *)
end

(** {2 Properties} *)

module Property : sig
  val get_value : 'a obj -> name:string -> g_value -> unit
  (** Get property value into a GValue. Raises [Invalid_argument] if the
      object's type has no property of that name. *)

  val set_value : 'a obj -> name:string -> g_value -> unit
  (** Set property from a GValue. Raises [Invalid_argument] if the object's type
      has no property of that name. *)

  val get_type : 'a obj -> name:string -> g_type
  (** Get the type of a property *)

  val freeze_notify : 'a obj -> unit
  (** Freeze property change notifications *)

  val thaw_notify : 'a obj -> unit
  (** Thaw property change notifications *)

  val notify : 'a obj -> name:string -> unit
  (** Emit property change notification *)
end

(** {2 Closures} *)

module Closure : sig
  type t = g_closure

  type args
  (** Opaque type for closure arguments *)

  type argv = { result : g_value; nargs : int; args : args }
  (** Closure invocation context. Fully self-contained: every GValue it carries
      is an OCaml-owned deep copy of the invocation's parameters, so reading the
      fields is safe at any time — including after the callback has returned, if
      argv is retained. *)

  val create : (argv -> unit) -> t
  (** Create a closure from an OCaml callback. The callback receives an argv
      snapshot it may retain beyond the callback's own lifetime. *)

  val nth : argv -> pos:int -> g_value
  (** Get the nth argument. Raises [Invalid_argument] if [pos] is out of bounds.
  *)

  val result : argv -> g_value
  (** Get the result GValue *)

  val get_result_type : argv -> g_type
  (** Get the expected result type *)

  val get_type : argv -> pos:int -> g_type
  (** Get the type of an argument. Raises [Invalid_argument] if [pos] is out of
      bounds. *)

  val set_result : argv -> g_value -> unit
  (** Set the result value *)
end

(** {2 Signals} *)

module Signal : sig
  type handler_id = int
  (** Signal handler identifier *)

  val connect :
    'a obj -> name:string -> callback:g_closure -> after:bool -> handler_id
  (** Connect a closure to a signal *)

  val connect_simple :
    'a obj -> name:string -> callback:(unit -> unit) -> after:bool -> handler_id
  (** Connect a simple callback with no arguments *)

  val disconnect : 'a obj -> handler_id -> unit
  (** Disconnect a signal handler *)

  val handler_block : 'a obj -> handler_id -> unit
  (** Temporarily block a signal handler *)

  val handler_unblock : 'a obj -> handler_id -> unit
  (** Unblock a signal handler *)

  val handler_is_connected : 'a obj -> handler_id -> bool
  (** Check if a handler is connected *)

  val emit_by_name : 'a obj -> name:string -> unit
  (** Emit a signal by name *)
end
