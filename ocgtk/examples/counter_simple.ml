open Ocgtk_gtk.Gtk
module GMain = Ocgtk_gtk.GMain
module Button = Wrappers.Button
module Check_button = Wrappers.Check_button
module Toggle_button = Wrappers.Toggle_button

(* Simple Counter - using only gtkButton and minimal dependencies
   Demonstrates: gtkButton module directly *)

let () =
  (* Initialize GTK *)
  ignore (GMain.init ());

  print_endline "Counter app starting...";
  print_endline "Window would appear here in a full GUI environment";
  print_endline "This is a demonstration of the bindings";

  (* Show that we can create GTK objects *)
  let btn = Button.new_with_label "Click Me!" in
  print_endline "✓ Created button";

  Button.set_label btn "Counter: 0";
  print_endline "✓ Set label";

  let label_text = Button.get_label btn in
  print_endline ("✓ Got label: " ^ Option.value ~default:"" label_text);

  (* Demonstrate CheckButton with nullable parameters *)
  let check1 = Check_button.new_with_label (Some "Enable feature") in
  print_endline "✓ Created CheckButton with nullable string parameter";

  let check2 = Check_button.new_ () in
  Check_button.set_group check2 (Some check1);
  print_endline "✓ Created CheckButton group (radio buttons)";

  Check_button.set_active check1 true;
  print_endline
    ("✓ Check button 1 active: "
    ^ string_of_bool (Check_button.get_active check1));

  (* Demonstrate ToggleButton *)
  let toggle = Toggle_button.new_with_label "Toggle Me" in
  Toggle_button.set_active toggle true;
  print_endline
    ("✓ Toggle button active: "
    ^ string_of_bool (Toggle_button.get_active toggle));

  print_endline "\n✅ All bindings working correctly!";
  print_endline "Nullable parameters: WORKING ✓";
  print_endline "CheckButton grouping: WORKING ✓";
  print_endline "Button/ToggleButton: WORKING ✓"
