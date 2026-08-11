(* C Validation Helpers - High-level validation functions for C code testing *)

(** {1 Header Guard Types} *)

type header_guard = {
  guard_name : string;  (** The name of the guard (e.g., "_gtk_decls_h_") *)
  has_ifndef : bool;  (** Whether the #ifndef directive is present *)
  has_define : bool;  (** Whether the #define directive is present *)
  has_endif : bool;  (** Whether the #endif directive is present *)
}

(** {1 Include Directive Types} *)

type include_directive = {
  include_path : string;  (** The path in the include (e.g., "gdk_decls.h") *)
  is_system : bool;  (** true for <path>, false for "path" *)
}

(** {1 Include Directive Validation} *)

val assert_local_include_exists : string -> string -> unit
(** Assert that a local include directive exists in the header.

    [assert_local_include_exists header_content expected_path] checks for an
    include directive like [#include "path"].

    @raise Alcotest.Test_error if the include is not found *)

val assert_local_include_not_exists : string -> string -> unit
(** Assert that a local include directive does NOT exist in the header.

    [assert_local_include_not_exists header_content unexpected_path] checks that
    an include directive like [#include "path"] is NOT present.

    @raise Alcotest.Test_error if the include is found *)

(** {1 Header Guard Parsing} *)

val parse_header_guards : string -> header_guard list
(** Parse header content and extract all header guards. Returns a list of
    [header_guard] records representing each guard found. *)

(** {1 Forward Declaration Validation} *)

val extract_forward_decls : string -> string list
(** Extract all forward declaration macro names from header content. Returns a
    list of macro names matching patterns like [Val_<Type>] or [<Type>_val]. *)

val assert_forward_decl_exists : string -> string -> string -> unit
(** Assert that a forward declaration exists in the header.

    [assert_forward_decl_exists header_content c_type prefix] checks for macro
    declarations like [prefix<c_type>] (e.g., [Val_GtkWrapMode] when
    prefix="Val_" and c_type="GtkWrapMode").

    @raise Alcotest.Test_error if the declaration is not found *)

val assert_forward_decl_not_exists : string -> string -> string -> unit
(** Assert that a forward declaration does NOT exist in the header.

    [assert_forward_decl_not_exists header_content c_type prefix] ensures that
    macro declarations like [prefix<c_type>] are NOT present in the header.

    @raise Alcotest.Test_error if the declaration is found *)

val assert_header_guard_format : string -> string -> unit
(** Assert that a header guard exists with the expected pattern.

    [assert_header_guard_format header_content expected_pattern] validates that
    the header contains a complete guard (ifndef/define/endif) where the guard
    name ends with [expected_pattern].

    @raise Alcotest.Test_error
      if no matching guard is found or if it's incomplete *)

(** {1 Copy Function Declarations} *)

val assert_copy_func_decl_exists : string -> string -> unit
(** Assert that a copy function declaration exists for the given C type.

    [assert_copy_func_decl_exists header_content c_type] checks for a
    [value copy_<c_type>(] declaration line in the header, which is the
    prototype for a value-like record's copy helper.

    @raise Alcotest.Test_error if the declaration is not found *)

(** {1 Conditional Compilation Guards} *)

val assert_conditional_guard_exists : string -> string -> unit
(** Assert that a conditional compilation guard exists with the given name.

    [assert_conditional_guard_exists header_content guard_name] checks for a
    [#ifndef GUARD_NAME] directive. Unlike include guards, the [#define] inside
    the conditional block may protect something other than [guard_name], so only
    the presence of [#ifndef] is required.

    @raise Alcotest.Test_error if the guard is not found *)

val assert_conditional_guard_not_exists : string -> string -> unit
(** Assert that a conditional compilation guard does NOT exist.

    [assert_conditional_guard_not_exists header_content guard_name] checks that
    no [#ifndef GUARD_NAME] directive is present in the header.

    @raise Alcotest.Test_error if [#ifndef GUARD_NAME] is present *)

val extract_conditional_guard_content : string -> string -> string
(** Extract the content between a conditional compilation guard's [#ifndef] and
    its matching [#endif].

    [extract_conditional_guard_content header_content guard_name] returns the
    extracted lines joined with newlines; returns an empty string if the guard
    is not found. *)

(** {1 Function Validation} *)

val uses_macro : C_ast.c_function -> string -> bool
(** Check if any statement in the function body uses a specific macro.

    [uses_macro f macro_name] returns [true] if [macro_name] appears anywhere in
    the function body as a [Call] or [Macro] AST node. Useful for verifying that
    type-converter macros (e.g. [GdkPixbufColorspace_val]) are generated with
    the correct capitalisation. *)

val uses_correct_return_macro : C_ast.c_function -> string -> bool
(** Check if a function uses the correct return conversion macro *)

val validates_gtk_constructor : C_ast.c_function -> string -> bool
(** Validate that a GTK type constructor properly converts the result *)

val calls_c_function : C_ast.c_function -> string -> bool
(** Check if function properly calls the underlying C function *)

val param_converted_with_val_macro :
  C_ast.c_function -> string -> string -> bool
(** Validate parameter is properly converted using _val macro *)

val has_out_param_decl : C_ast.c_function -> string -> string -> bool
(** Validate that out parameters are declared with correct type *)

val out_param_passed_by_ref : C_ast.c_function -> string -> string -> bool
(** Check if out parameter is passed by reference (&param) to C function *)

val has_error_handling : C_ast.c_function -> bool
(** Validate that error handling is present (for throws=true) *)

val returns_result_type : C_ast.c_function -> bool
(** Validate that a function returns error type when throws=true *)

val has_caml_param_macro : C_ast.c_function -> bool
(** Validate CAMLparam macros are used correctly *)

val has_caml_return : C_ast.c_function -> bool
(** Validate CAMLreturn is used *)

val handles_nullable_param : C_ast.c_function -> string -> bool
(** Check if function properly handles nullable parameters *)

val validates_bytecode_native_pair : C_ast.c_function list -> string -> bool
(** Validate bytecode/native pair is correctly structured *)

val c_code_has_camlxparam_n_or_higher : string -> int -> bool
(** Check if raw C code string contains CAMLxparamN or higher.

    Simpler version that works directly with C code strings instead of parsed
    AST.

    @param c_code The C code string to check
    @param n The minimum CAMLxparam number to look for
    @return true if any CAMLxparam macro with number >= n is found *)

val c_code_has_caml_param : string -> string -> bool
(** Check if raw C code string contains a specific CAMLparam macro.

    @param c_code The C code string to check
    @param param_name The macro name to look for (e.g., "CAMLparam5")
    @return true if the macro is found with an opening parenthesis *)

(** {1 Array Validation Functions} *)

val counts_to_null : C_ast.c_function -> string -> bool
(** Check if function counts to NULL *)

val calls_caml_alloc : C_ast.c_function -> bool
(** Check if function calls caml_alloc *)

val has_conversion_loop : C_ast.c_function -> bool
(** Check if function has Store_field calls (indicates array conversion) *)

val calls_g_free : C_ast.c_function -> string -> bool
(** Check if function calls g_free *)
