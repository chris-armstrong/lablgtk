open Ocgtk_gtk.Gtk

(* ── Types ────────────────────────────────────────────────────────────────── *)

type form_fields = {
  name_entry : Entry.entry_t;
  email_entry : Entry.entry_t;
  age_spin : Spin_button.spin_button_t;
  reason_view : Text_view.text_view_t;
  terms_check : Check_button.check_button_t;
}

(* ── Pure helpers ─────────────────────────────────────────────────────────── *)

let validate_form ~name ~email ~age ~reason ~terms_ok =
  let errors = ref [] in
  let add e = errors := e :: !errors in
  if String.equal name "" then add "Name is required";
  (if String.equal email "" then add "Email is required"
   else
     match String.index_opt email '@' with
     | None -> add "Email must contain '@'"
     | Some at_pos ->
         if String.length email <= at_pos + 1 then
           add "Email must have a domain after '@'");
  if age <= 0 then add "Age must be greater than 0";
  if String.equal reason "" then add "Reason to join is required";
  if not terms_ok then add "You must accept the Terms of Service";
  List.rev !errors

let get_reason_text (view : Text_view.text_view_t) =
  let buf = view#get_buffer () in
  let raw = buf#as_text_buffer in
  buf#get_text
    (Wrappers.Text_buffer.get_start_iter raw)
    (Wrappers.Text_buffer.get_end_iter raw)
    false

(* ── UI actions ───────────────────────────────────────────────────────────── *)

let reset_form ~fields ~status_label ~dirty =
  fields.name_entry#set_text "";
  fields.email_entry#set_text "";
  fields.age_spin#set_value 25.0;
  (fields.reason_view#get_buffer ())#set_text "" 0;
  fields.terms_check#set_active false;
  status_label#set_label "";
  dirty := false

let load_signature ~path ~picture ~label ~dirty =
  Printf.printf "load_signature: loading %s\n%!" path;
  match Ocgtk_gdk.Gdk.Texture.new_from_filename path with
  | Error e ->
      Printf.printf "load_signature: ERROR %s\n%!" (GError.message e);
      label#set_markup
        (Printf.sprintf "<span foreground='red'>Failed to load image: %s</span>"
           (GError.message e))
  | Ok texture ->
      Printf.printf "load_signature: texture ok, calling set_paintable\n%!";
      picture#set_paintable
        (Some (texture :> Ocgtk_gdk.Gdk.Paintable.paintable_t));
      Printf.printf "load_signature: set_paintable done, paintable=%s\n%!"
        (match picture#get_paintable () with
        | Some _ -> "Some"
        | None -> "None");
      label#set_label (Printf.sprintf "Signature: %s" (Filename.basename path));
      dirty := true

(* ── Widget builders ─────────────────────────────────────────────────────── *)

let build_title_label () =
  let lbl = Label.new_ (Some "Contact Form") in
  lbl#set_markup "<big><b>Contact Form</b></big>";
  lbl

let build_contact_grid ~dirty =
  let grid = Grid.new_ () in
  grid#set_row_spacing 8;
  grid#set_column_spacing 8;

  let name_entry = Entry.new_ () in
  name_entry#set_placeholder_text (Some "Enter your name");
  grid#attach (Label.new_ (Some "Name:") :> Widget.widget_t) 0 0 1 1;
  grid#attach (name_entry :> Widget.widget_t) 1 0 1 1;
  ignore (name_entry#on_activate ~callback:(fun () -> dirty := true) ());

  let email_entry = Entry.new_ () in
  email_entry#set_placeholder_text (Some "Enter your email");
  grid#attach (Label.new_ (Some "Email:") :> Widget.widget_t) 0 1 1 1;
  grid#attach (email_entry :> Widget.widget_t) 1 1 1 1;
  ignore (email_entry#on_activate ~callback:(fun () -> dirty := true) ());

  let age_spin = Spin_button.new_with_range 0.0 120.0 1.0 in
  age_spin#set_value 25.0;
  grid#attach (Label.new_ (Some "Age:") :> Widget.widget_t) 0 2 1 1;
  grid#attach (age_spin :> Widget.widget_t) 1 2 1 1;
  ignore (age_spin#on_value_changed ~callback:(fun () -> dirty := true) ());

  let reason_view = Text_view.new_ () in
  reason_view#set_wrap_mode `WORD;
  reason_view#set_monospace false;
  reason_view#set_top_margin 4;
  reason_view#set_bottom_margin 4;
  reason_view#set_left_margin 4;
  reason_view#set_right_margin 4;
  grid#attach (Label.new_ (Some "Reason to join:") :> Widget.widget_t) 0 3 1 1;
  grid#attach (reason_view :> Widget.widget_t) 1 3 1 1;
  ignore
    (reason_view#on_insert_at_cursor
       ~callback:(fun ~string:_ -> dirty := true)
       ());
  ignore (reason_view#on_backspace ~callback:(fun () -> dirty := true) ());

  let terms_check =
    Check_button.new_with_label (Some "I agree to the Terms of Service")
  in
  grid#attach (terms_check :> Widget.widget_t) 0 4 2 1;
  ignore (terms_check#on_toggled ~callback:(fun () -> dirty := true) ());

  let fields =
    { name_entry; email_entry; age_spin; reason_view; terms_check }
  in
  (grid, fields)

let show_tos_window ~app () =
  let w = Window.new_ () in
  w#set_title (Some "Terms of Service");
  w#set_default_size 400 300;
  (app :> Application.application_t)#add_window w;
  let lbl =
    Label.new_
      (Some
         "Terms of Service\n\n\
          Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do \
          eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim \
          ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut \
          aliquip ex ea commodo consequat.")
  in
  lbl#set_wrap true;
  lbl#set_margin_top 12;
  lbl#set_margin_bottom 12;
  lbl#set_margin_start 12;
  lbl#set_margin_end 12;
  w#set_child (Some (lbl :> Widget.widget_t));
  ignore (w#on_close_request ~callback:(fun () -> false) ());
  w#present ();
  true

let pick_action offered =
  if List.exists (function `COPY -> true | _ -> false) offered then [ `COPY ]
  else if List.exists (function `MOVE -> true | _ -> false) offered then
    [ `MOVE ]
  else []

let build_signature_section ~window ~dirty =
  let picture = Picture.new_ () in
  picture#set_content_fit `CONTAIN;
  picture#set_keep_aspect_ratio true;
  picture#set_vexpand true;
  picture#set_hexpand true;
  picture#set_size_request 200 150;

  let label = Label.new_ (Some "No signature") in
  let box = Box.new_ `VERTICAL 5 in
  box#append (picture :> Widget.widget_t);
  box#append (label :> Widget.widget_t);

  let choose_btn = Button.new_with_label "Choose Image..." in
  box#append (choose_btn :> Widget.widget_t);
  ignore
    (choose_btn#on_clicked
       ~callback:(fun () ->
         let dialog =
           File_chooser_native.new_ (Some "Choose Signature Image")
             (Some window) `OPEN (Some "_Open") (Some "_Cancel")
         in
         let filter = File_filter.new_ () in
         filter#add_pixbuf_formats ();
         dialog#add_filter filter;
         ignore
           (dialog#on_response
              ~callback:(fun ~response_id ->
                (if response_id = -3 then
                   match dialog#get_file () with
                   | Some file -> (
                       match file#get_path () with
                       | Some path ->
                           load_signature ~path ~picture ~label ~dirty
                       | None -> ())
                   | None -> ());
                dialog#destroy ())
              ());
         dialog#show ())
       ());

  let fl_type = Ocgtk_gdk.Gdk.Wrappers.File_list.gtype () in

  let drop_target = Drop_target.new_ Gobject.Type.invalid [ `COPY ] in
  drop_target#set_gtypes (Some [| fl_type |]) (Gsize.of_int 1);
  (picture :> Widget.widget_t)#add_controller
    (drop_target :> Event_controller.event_controller_t);
  ignore (drop_target#on_accept ~callback:(fun ~drop:_ -> true) ());
  ignore
    (drop_target#on_enter
       ~callback:(fun ~x:_ ~y:_ ->
         let offered =
           match drop_target#get_current_drop () with
           | None -> []
           | Some drop -> drop#get_actions ()
         in
         pick_action offered)
       ());
  ignore
    (drop_target#on_motion
       ~callback:(fun ~x:_ ~y:_ ->
         let offered =
           match drop_target#get_current_drop () with
           | None -> []
           | Some drop -> drop#get_actions ()
         in
         pick_action offered)
       ());
  ignore
    (drop_target#on_leave
       ~callback:(fun () ->
         label#set_markup "<span foreground='gray'>Drop an image here</span>")
       ());
  ignore
    (drop_target#on_drop
       ~callback:(fun ~value:_ ~x:_ ~y:_ ->
         let path =
           match drop_target#get_value () with
           | None -> None
           | Some v ->
               if Gobject.Type.equal (Gobject.Value.get_type v) fl_type then
                 let raw : Ocgtk_gdk.Gdk.Wrappers.File_list.t =
                   Gobject.Value.get_boxed v
                 in
                 let fl = new Ocgtk_gdk.Gdk.File_list.file_list raw in
                 let ( let* ) = Option.bind in
                 let* file = List.nth_opt (fl#get_files ()) 0 in
                 file#get_path ()
               else None
         in
         match path with
         | None -> false
         | Some path ->
             load_signature ~path ~picture ~label ~dirty;
             true)
       ());

  let frame = Frame.new_ (Some "Signature") in
  frame#set_child (Some (box :> Widget.widget_t));
  (frame, picture, label)

let build_button_bar ~fields ~status_label ~dirty =
  let box = Box.new_ `HORIZONTAL 10 in

  let submit_btn = Button.new_with_label "Submit" in
  box#append (submit_btn :> Widget.widget_t);
  ignore
    (submit_btn#on_clicked
       ~callback:(fun () ->
         let name = fields.name_entry#get_text () in
         let email = fields.email_entry#get_text () in
         let age = fields.age_spin#get_value_as_int () in
         let terms_ok = fields.terms_check#get_active () in
         let reason = get_reason_text fields.reason_view in
         match validate_form ~name ~email ~age ~reason ~terms_ok with
         | [] ->
             status_label#set_markup
               "<span foreground='green'>Submitted!</span>";
             dirty := false
         | [ msg ] ->
             status_label#set_markup
               ("<span foreground='red'>" ^ msg ^ "</span>")
         | msgs ->
             status_label#set_markup
               ("<span foreground='red'>" ^ String.concat "; " msgs ^ "</span>"))
       ());

  let cancel_btn = Button.new_with_label "Cancel" in
  box#append (cancel_btn :> Widget.widget_t);
  ignore
    (cancel_btn#on_clicked
       ~callback:(fun () -> reset_form ~fields ~status_label ~dirty)
       ());

  box

let setup_key_controller ~window ~fields ~status_label ~dirty =
  let key_ctrl = Event_controller_key.new_ () in
  key_ctrl#set_propagation_phase `CAPTURE;
  (window :> Widget.widget_t)#add_controller
    (key_ctrl :> Event_controller.event_controller_t);
  ignore
    (key_ctrl#on_key_pressed
       ~callback:(fun ~keyval ~keycode:_ ~state ->
         let is_ctrl_q =
           keyval = Char.code 'q'
           && List.mem `CONTROL_MASK (state :> Ocgtk_gdk.Gdk_enums.modifiertype)
         in
         if is_ctrl_q then begin
           reset_form ~fields ~status_label ~dirty;
           true
         end
         else false)
       ())

let setup_window_count ~app ~statusbar ~statusbar_ctx ~window_count =
  ignore
    ((app :> Application.application_t)#on_window_added
       ~callback:(fun ~window:_ ->
         window_count := !window_count + 1;
         ignore
           (statusbar#push statusbar_ctx
              (Printf.sprintf "Windows: %d" !window_count)))
       ());
  ignore
    ((app :> Application.application_t)#on_window_removed
       ~callback:(fun ~window:_ ->
         window_count := !window_count - 1;
         ignore
           (statusbar#push statusbar_ctx
              (Printf.sprintf "Windows: %d" !window_count)))
       ())

(* ── Application entry point ─────────────────────────────────────────────── *)

let activate app =
  let window = Window.new_ () in
  window#set_title (Some "Contact Form");
  window#set_default_size 500 550;
  (app :> Application.application_t)#add_window window;

  let dirty = ref false in
  let window_count = ref 1 in

  let main_box = Box.new_ `VERTICAL 10 in
  window#set_child (Some (main_box :> Widget.widget_t));

  main_box#append (build_title_label () :> Widget.widget_t);

  let grid, fields = build_contact_grid ~dirty in
  main_box#append (grid :> Widget.widget_t);

  let tos_link = Link_button.new_ "https://example.com/tos" in
  main_box#append (tos_link :> Widget.widget_t);
  ignore (tos_link#on_activate_link ~callback:(show_tos_window ~app) ());

  let sig_frame, _picture, _sig_label =
    build_signature_section ~window ~dirty
  in
  main_box#append (sig_frame :> Widget.widget_t);

  let status_label = Label.new_ None in
  status_label#set_label "";
  main_box#append (status_label :> Widget.widget_t);

  main_box#append
    (build_button_bar ~fields ~status_label ~dirty :> Widget.widget_t);

  let statusbar = Statusbar.new_ () in
  main_box#append (statusbar :> Widget.widget_t);
  let statusbar_ctx = statusbar#get_context_id "form" in
  ignore (statusbar#push statusbar_ctx "Windows: 1");
  setup_window_count ~app ~statusbar ~statusbar_ctx ~window_count;

  setup_key_controller ~window ~fields ~status_label ~dirty;

  main_box#append
    (Label.new_ (Some "Press Ctrl+Q to cancel and quit") :> Widget.widget_t);

  ignore
    (window#on_close_request
       ~callback:(fun () ->
         if !dirty then begin
           status_label#set_label "Please submit or cancel before closing.";
           true
         end
         else false)
       ());

  window#present ()

let () =
  let app = Application.new_ (Some "com.example.FormApp") [ `DEFAULT_FLAGS ] in
  ignore (app#on_activate ~callback:(fun () -> activate app) ());
  let status = app#run 0 None in
  exit status
