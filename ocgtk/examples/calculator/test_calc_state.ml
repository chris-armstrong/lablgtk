open Calc_core

let pp_state fmt state =
  Format.fprintf fmt "{ expression = %S; result = %S; error = %b }"
    (Calc_state.get_expression state)
    (Calc_state.get_result state)
    (Calc_state.is_error state)

let state_equal a b =
  String.equal (Calc_state.get_expression a) (Calc_state.get_expression b)
  && String.equal (Calc_state.get_result a) (Calc_state.get_result b)
  && Bool.equal (Calc_state.is_error a) (Calc_state.is_error b)

let state = Alcotest.testable pp_state state_equal

let test_create () =
  let s = Calc_state.create () in
  Alcotest.(check string) "expression is empty" "" (Calc_state.get_expression s);
  Alcotest.(check string) "result is 0" "0" (Calc_state.get_result s);
  Alcotest.(check bool) "no error" false (Calc_state.is_error s)

let test_append_digit () =
  let s = Calc_state.create () in
  let s = Calc_state.append_char s '1' in
  let s = Calc_state.append_char s '2' in
  let s = Calc_state.append_char s '3' in
  Alcotest.(check string)
    "expression is 123" "123"
    (Calc_state.get_expression s)

let test_backspace () =
  let s = Calc_state.create () in
  let s = Calc_state.append_char s '1' in
  let s = Calc_state.append_char s '2' in
  let s = Calc_state.backspace s in
  Alcotest.(check string) "expression is 1" "1" (Calc_state.get_expression s);
  let s = Calc_state.backspace s in
  Alcotest.(check bool) "expression is empty" true (Calc_state.is_empty s)

let test_clear () =
  let s = Calc_state.create () in
  let s = Calc_state.append_char s '1' in
  let _s2 = Calc_state.append_char s '2' in
  let s3 = Calc_state.clear () in
  Alcotest.(check bool) "expression is empty" true (Calc_state.is_empty s3);
  Alcotest.(check string) "result is 0" "0" (Calc_state.get_result s3)

let test_evaluate_basic () =
  let s = Calc_state.create () in
  let s = Calc_state.append_char s '2' in
  let s = Calc_state.append_char s '+' in
  let s = Calc_state.append_char s '3' in
  let s = Calc_state.evaluate s in
  Alcotest.(check string) "result is 5" "5" (Calc_state.get_result s);
  Alcotest.(check bool) "no error" false (Calc_state.is_error s)

let test_evaluate_incomplete () =
  let s = Calc_state.create () in
  let s = Calc_state.append_char s '2' in
  let s = Calc_state.append_char s '+' in
  let s_before = s in
  let s = Calc_state.evaluate s in
  Alcotest.(check state) "state unchanged" s_before s

let test_error_blocks_append () =
  (* Create an error state by dividing by zero. *)
  let s = Calc_state.create () in
  let s = Calc_state.append_char s '1' in
  let s = Calc_state.append_char s '/' in
  let s = Calc_state.append_char s '0' in
  let s = Calc_state.evaluate s in
  Alcotest.(check bool) "in error state" true (Calc_state.is_error s);
  (* Try to append more characters - should be blocked. *)
  let s2 = Calc_state.append_char s '5' in
  Alcotest.(check state) "append blocked in error" s s2

let test_consecutive_operators () =
  let s = Calc_state.create () in
  let s = Calc_state.append_char s '2' in
  let s = Calc_state.append_char s '+' in
  let s = Calc_state.append_char s '*' in
  Alcotest.(check string) "operator replaced" "2*" (Calc_state.get_expression s)

let test_leading_minus_allowed () =
  let s = Calc_state.create () in
  let s = Calc_state.append_char s '-' in
  let s = Calc_state.append_char s '5' in
  Alcotest.(check string) "expression is -5" "-5" (Calc_state.get_expression s);
  let s = Calc_state.evaluate s in
  Alcotest.(check string) "result is -5" "-5" (Calc_state.get_result s)

let test_backspace_in_error () =
  (* Create an error state. *)
  let s = Calc_state.create () in
  let s = Calc_state.append_char s '1' in
  let s = Calc_state.append_char s '/' in
  let s = Calc_state.append_char s '0' in
  let s = Calc_state.evaluate s in
  Alcotest.(check bool) "in error state" true (Calc_state.is_error s);
  (* Backspace should clear error state. *)
  let s = Calc_state.backspace s in
  Alcotest.(check bool) "error cleared" false (Calc_state.is_error s);
  Alcotest.(check bool) "expression empty" true (Calc_state.is_empty s)

let test_evaluate_operator_precedence () =
  let s = Calc_state.create () in
  let s = Calc_state.append_char s '2' in
  let s = Calc_state.append_char s '+' in
  let s = Calc_state.append_char s '3' in
  let s = Calc_state.append_char s '*' in
  let s = Calc_state.append_char s '4' in
  let s = Calc_state.evaluate s in
  Alcotest.(check string) "result is 14" "14" (Calc_state.get_result s)

let test_parentheses () =
  let s = Calc_state.create () in
  let s = Calc_state.append_char s '(' in
  let s = Calc_state.append_char s '2' in
  let s = Calc_state.append_char s '+' in
  let s = Calc_state.append_char s '3' in
  let s = Calc_state.append_char s ')' in
  let s = Calc_state.append_char s '*' in
  let s = Calc_state.append_char s '4' in
  let s = Calc_state.evaluate s in
  Alcotest.(check string) "result is 20" "20" (Calc_state.get_result s)

let test_get_expression_display () =
  let s = Calc_state.create () in
  Alcotest.(check string)
    "empty shows 0" "0"
    (Calc_state.get_expression_display s);
  let s = Calc_state.append_char s '1' in
  Alcotest.(check string)
    "shows expression" "1"
    (Calc_state.get_expression_display s)

let test_get_result_display () =
  let s = Calc_state.create () in
  Alcotest.(check string)
    "no eval shows 0" "0"
    (Calc_state.get_result_display s);
  (* Create error state. *)
  let s = Calc_state.append_char s '1' in
  let s = Calc_state.append_char s '/' in
  let s = Calc_state.append_char s '0' in
  let s = Calc_state.evaluate s in
  Alcotest.(check string)
    "error shows Error" "Error"
    (Calc_state.get_result_display s)

let test_decimal_point () =
  let s = Calc_state.create () in
  let s = Calc_state.append_char s '3' in
  let s = Calc_state.append_char s '.' in
  let s = Calc_state.append_char s '1' in
  let s = Calc_state.append_char s '4' in
  Alcotest.(check string)
    "expression is 3.14" "3.14"
    (Calc_state.get_expression s)

let test_leading_plus_rejected () =
  let s = Calc_state.create () in
  let s = Calc_state.append_char s '+' in
  Alcotest.(check bool)
    "plus rejected as first char" true (Calc_state.is_empty s)

let test_multiple_consecutive_operators () =
  let s = Calc_state.create () in
  let s = Calc_state.append_char s '2' in
  let s = Calc_state.append_char s '+' in
  let s = Calc_state.append_char s '-' in
  let s = Calc_state.append_char s '*' in
  Alcotest.(check string)
    "last operator wins" "2*"
    (Calc_state.get_expression s)

let test_double_decimal_rejected () =
  let s = Calc_state.create () in
  let s = Calc_state.append_char s '1' in
  let s = Calc_state.append_char s '.' in
  let s = Calc_state.append_char s '5' in
  let s_before = s in
  let s = Calc_state.append_char s '.' in
  Alcotest.(check state) "second decimal rejected" s_before s

let test_decimal_allowed_in_second_operand () =
  (* After an operator, decimal should be allowed in the new number. *)
  let s = Calc_state.create () in
  let s = Calc_state.append_char s '1' in
  let s = Calc_state.append_char s '.' in
  let s = Calc_state.append_char s '5' in
  let s = Calc_state.append_char s '+' in
  let s = Calc_state.append_char s '2' in
  let s = Calc_state.append_char s '.' in
  let s = Calc_state.append_char s '5' in
  Alcotest.(check string)
    "expression is 1.5+2.5" "1.5+2.5"
    (Calc_state.get_expression s)

let () =
  Alcotest.run "Calc_state"
    [
      ("creation", [ Alcotest.test_case "create" `Quick test_create ]);
      ( "append",
        [
          Alcotest.test_case "digits" `Quick test_append_digit;
          Alcotest.test_case "decimal" `Quick test_decimal_point;
          Alcotest.test_case "double decimal rejected" `Quick
            test_double_decimal_rejected;
          Alcotest.test_case "decimal in second operand" `Quick
            test_decimal_allowed_in_second_operand;
          Alcotest.test_case "consecutive operators" `Quick
            test_consecutive_operators;
          Alcotest.test_case "leading minus" `Quick test_leading_minus_allowed;
          Alcotest.test_case "leading plus rejected" `Quick
            test_leading_plus_rejected;
          Alcotest.test_case "multiple operators" `Quick
            test_multiple_consecutive_operators;
        ] );
      ( "backspace",
        [
          Alcotest.test_case "basic" `Quick test_backspace;
          Alcotest.test_case "in error" `Quick test_backspace_in_error;
        ] );
      ("clear", [ Alcotest.test_case "clear" `Quick test_clear ]);
      ( "evaluate",
        [
          Alcotest.test_case "basic" `Quick test_evaluate_basic;
          Alcotest.test_case "incomplete" `Quick test_evaluate_incomplete;
          Alcotest.test_case "error blocks append" `Quick
            test_error_blocks_append;
          Alcotest.test_case "precedence" `Quick
            test_evaluate_operator_precedence;
          Alcotest.test_case "parentheses" `Quick test_parentheses;
        ] );
      ( "display",
        [
          Alcotest.test_case "expression display" `Quick
            test_get_expression_display;
          Alcotest.test_case "result display" `Quick test_get_result_display;
        ] );
    ]
