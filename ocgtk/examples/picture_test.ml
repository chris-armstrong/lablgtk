open Ocgtk_gtk.Gtk

let test_image_path = "/usr/share/pixmaps/ubuntu-logo-text.png"

let build_form_grid ~grid =
  let rows = [| "Name:"; "Email:"; "Age:"; "Reason to join:" |] in
  Array.iteri
    (fun i label ->
      let lbl = Label.new_ (Some label) in
      grid#attach (lbl :> Widget.widget_t) 0 i 1 1;
      if i < 3 then begin
        let entry = Entry.new_ () in
        grid#attach (entry :> Widget.widget_t) 1 i 1 1
      end
      else begin
        let tv = Text_view.new_ () in
        tv#set_wrap_mode `WORD;
        grid#attach (tv :> Widget.widget_t) 1 i 1 1
      end)
    rows;
  let terms =
    Check_button.new_with_label (Some "I agree to Terms of Service")
  in
  grid#attach (terms :> Widget.widget_t) 0 4 2 1

let measure_layout ~window ~grid ~sig_frame ~picture ~app () =
  let wh = (window :> Widget.widget_t)#get_allocated_height () in
  let gh = (grid :> Widget.widget_t)#get_allocated_height () in
  let fh = (sig_frame :> Widget.widget_t)#get_allocated_height () in
  let pw = (picture :> Widget.widget_t)#get_allocated_width () in
  let ph = (picture :> Widget.widget_t)#get_allocated_height () in
  Printf.printf "window allocated: %dx%d\n%!" pw wh;
  Printf.printf "grid height: %d\n%!" gh;
  Printf.printf "sig_frame allocated: %dx%d\n%!" pw fh;
  Printf.printf "picture allocated: %dx%d\n%!" pw ph;
  Printf.printf "before set_filename: paintable = %s\n%!"
    (match picture#get_paintable () with Some _ -> "Some" | None -> "None");
  picture#set_filename (Some test_image_path);
  Printf.printf "after set_filename: paintable = %s\n%!"
    (match picture#get_paintable () with Some _ -> "Some" | None -> "None");
  app#quit ();
  false

let activate app =
  let window = Window.new_ () in
  window#set_title (Some "Picture Layout Test");
  window#set_default_size 500 550;
  (app :> Application.application_t)#add_window window;

  let main_box = Box.new_ `VERTICAL 10 in
  window#set_child (Some (main_box :> Widget.widget_t));

  (* title *)
  let title_label = Label.new_ (Some "Contact Form") in
  main_box#append (title_label :> Widget.widget_t);

  (* grid with textview - the biggest item *)
  let grid = Grid.new_ () in
  grid#set_row_spacing 8;
  grid#set_column_spacing 8;
  main_box#append (grid :> Widget.widget_t);

  build_form_grid ~grid;

  (* tos link *)
  let tos = Link_button.new_ "https://example.com/tos" in
  main_box#append (tos :> Widget.widget_t);

  (* signature section - replicating form_example exactly *)
  let picture = Picture.new_ () in
  picture#set_content_fit `CONTAIN;
  picture#set_keep_aspect_ratio true;
  picture#set_vexpand true;
  picture#set_hexpand true;
  picture#set_size_request 200 150;

  let sig_label = Label.new_ (Some "No signature") in
  let sig_box = Box.new_ `VERTICAL 5 in
  sig_box#append (picture :> Widget.widget_t);
  sig_box#append (sig_label :> Widget.widget_t);
  let choose_btn = Button.new_with_label "Choose Image..." in
  sig_box#append (choose_btn :> Widget.widget_t);
  ignore choose_btn;

  let sig_frame = Frame.new_ (Some "Signature") in
  sig_frame#set_child (Some (sig_box :> Widget.widget_t));
  main_box#append (sig_frame :> Widget.widget_t);

  let status_label = Label.new_ None in
  main_box#append (status_label :> Widget.widget_t);

  let button_box = Box.new_ `HORIZONTAL 10 in
  let submit_btn = Button.new_with_label "Submit" in
  let cancel_btn = Button.new_with_label "Cancel" in
  button_box#append (submit_btn :> Widget.widget_t);
  button_box#append (cancel_btn :> Widget.widget_t);
  ignore (submit_btn, cancel_btn, status_label);
  main_box#append (button_box :> Widget.widget_t);

  let statusbar = Statusbar.new_ () in
  main_box#append (statusbar :> Widget.widget_t);
  ignore statusbar;

  let shortcut_label = Label.new_ (Some "Press Ctrl+Q to cancel and quit") in
  main_box#append (shortcut_label :> Widget.widget_t);
  ignore shortcut_label;

  (* Don't load image yet — test post-realize set_filename *)
  window#present ();
  ignore
    (window#on_close_request
       ~callback:(fun () ->
         app#quit ();
         false)
       ());

  ignore
    (Glib.Timeout.add ~ms:300
       ~callback:(measure_layout ~window ~grid ~sig_frame ~picture ~app)
       ())

let () =
  let app =
    Application.new_ (Some "com.example.PictureTest") [ `DEFAULT_FLAGS ]
  in
  ignore (app#on_activate ~callback:(fun () -> activate app) ());
  let status = app#run 0 None in
  exit status
