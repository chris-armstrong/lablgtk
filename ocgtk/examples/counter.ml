open Ocgtk_gtk.Gtk
(* Simple Counter Application
   Demonstrates: GtkApplication lifecycle, Button, Label, event handling *)

let activate app =
  (* Create main window *)
  let window = Window.new_ () in
  window#set_title (Some "Counter App");
  window#set_default_size 300 100;
  (app :> Application.application_t)#add_window window;

  (* Create vertical box for layout *)
  let vbox = new Box.box (Wrappers.Box.new_ `VERTICAL 10) in
  window#set_child (Some (vbox :> Widget.widget_t));

  (* Counter state *)
  let count = ref 0 in

  (* Create label to display count *)
  let label =
    new Label.label
      (Wrappers.Label.new_ (Some ("Count: " ^ string_of_int !count)))
  in
  vbox#append (label :> Widget.widget_t);

  (* Create button to increment *)
  let button = new Button.button (Wrappers.Button.new_with_label "Click Me!") in
  vbox#append (button :> Widget.widget_t);
  ignore
    (button#on_clicked
       ~callback:(fun () ->
         count := !count + 1;
         label#set_label ("Count: " ^ string_of_int !count))
       ());

  (* Create reset button *)
  let reset_btn = new Button.button (Wrappers.Button.new_with_label "Reset") in
  vbox#append (reset_btn :> Widget.widget_t);
  ignore
    (reset_btn#on_clicked
       ~callback:(fun () ->
         count := 0;
         label#set_label ("Count: " ^ string_of_int !count))
       ());

  (* Show window *)
  window#present ()

let () =
  let app = Application.new_ (Some "org.ocgtk.Counter") [ `DEFAULT_FLAGS ] in
  ignore (app#on_activate ~callback:(fun () -> activate app) ());
  let status = app#run 0 None in
  exit status
