(** Version guard nesting logic for generated C stubs.

    Guards are applied at two levels:

    1. Class-level: if a class/interface/record has a version, the entire .c
    file body is wrapped in one outer [#if]/[#endif]. All members inherit this
    implicitly. 2. Member-level: if a member's version exceeds the class version
    (or there is no class version), the member gets its own inner
    [#if]/[#endif].

    Call {!resolve_guard} per member to determine which case applies, then call
    {!emit_c_guard} to produce the C preprocessor strings. The class-level outer
    guard is also driven by {!resolve_guard} — call it with
    [member_version:None] to obtain the [Class_guard v] that names the outer
    guard's version. *)

type version = {
  major : int;  (** Major version component. *)
  minor : int;  (** Minor version component. *)
  micro : int;  (** Micro (patch) version component; [0] when absent. *)
}

(** Result of resolving the version guard needed for a specific member.

    - [No_guard]: neither class nor member has a version; emit no guard.
    - [Class_guard v]: the member is covered by an outer class-level guard at
      version [v]; no additional inner guard is needed for this member.
    - [Member_guard v]: this member needs its own inner guard at version [v],
      either because there is no class-level guard, or because this member's
      version exceeds the class version. *)
type guard_kind = No_guard | Class_guard of version | Member_guard of version

val parse_version : string -> (version, string) result
(** Parse a version string such as ["4.14"] or ["1.32.4"] into a {!version}.
    Two-component versions have [micro = 0]. Returns [Error] for other formats
    or non-integer components. *)

val compare_versions : version -> version -> int
(** Lexicographic comparison: negative if [v1 < v2], zero if equal, positive if
    [v1 > v2]. *)

val resolve_guard :
  class_version:string option ->
  member_version:string option ->
  (guard_kind, string) result
(** Determine the guard kind for a member given raw version strings from the
    GIR. Returns [Error] if either version string fails to parse. *)

val emit_c_guard :
  string -> version -> is_opening:bool -> (string, string) result
(** [emit_c_guard namespace version ~is_opening] produces a C preprocessor line.
    When [is_opening] is [true], returns the [#if MACRO(M,m,u)] line appropriate
    for [namespace]. When [is_opening] is [false], returns ["#endif"]. Returns
    [Error] if [namespace] is not recognised. *)

val c_guard_else : string
(** The string ["#else"]. *)

val normalize_namespace : string -> (string, string) result
(** [normalize_namespace s] maps a user-friendly, case-insensitive library name
    (e.g. ["pango"], ["gdk-pixbuf"]) to the canonical GIR namespace name
    accepted by {!emit_c_guard} (e.g. ["Pango"], ["GdkPixbuf"]). Returns [Error]
    if the name is not recognised. *)
