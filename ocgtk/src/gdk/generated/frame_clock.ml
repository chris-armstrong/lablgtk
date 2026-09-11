(* GENERATED CODE - DO NOT EDIT *)
(* FrameClock: FrameClock *)

type t = [ `frame_clock | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gdk_frame_clock_get_type"

(* Methods *)

external request_phase : t -> Gdk_enums.frameclockphase -> unit
  = "ml_gdk_frame_clock_request_phase"
(** Asks the frame clock to run a particular phase.

    The signal corresponding the requested phase will be emitted the next time
    the frame clock processes. Multiple calls to gdk_frame_clock_request_phase()
    will be combined together and only one frame processed. If you are
    displaying animated content and want to continually request the
    %GDK_FRAME_CLOCK_PHASE_UPDATE phase for a period of time, you should use
    [method@Gdk.FrameClock.begin_updating] instead, since this allows GTK to
    adjust system parameters to get maximally smooth animations. *)

external get_timings : t -> int64 -> Frame_timings.t option
  = "ml_gdk_frame_clock_get_timings"
(** Retrieves a `GdkFrameTimings` object holding timing information for the
    current frame or a recent frame.

    The `GdkFrameTimings` object may not yet be complete: see
    [method@Gdk.FrameTimings.get_complete] and
    [method@Gdk.FrameClock.get_history_start]. *)

external get_refresh_info : t -> int64 -> int64 * int64
  = "ml_gdk_frame_clock_get_refresh_info"
(** Predicts a presentation time, based on history.

Using the frame history stored in the frame clock, finds the last
known presentation time and refresh interval, and assuming that
presentation times are separated by the refresh interval,
predicts a presentation time that is a multiple of the refresh
interval after the last presentation time, and later than @base_time. *)

external get_history_start : t -> int64 = "ml_gdk_frame_clock_get_history_start"
(** Returns the frame counter for the oldest frame available in history.

    `GdkFrameClock` internally keeps a history of `GdkFrameTimings` objects for
    recent frames that can be retrieved with
    [method@Gdk.FrameClock.get_timings]. The set of stored frames is the set
    from the counter values given by [method@Gdk.FrameClock.get_history_start]
    and [method@Gdk.FrameClock.get_frame_counter], inclusive. *)

external get_frame_time : t -> int64 = "ml_gdk_frame_clock_get_frame_time"
(** Gets the time that should currently be used for animations.

    Inside the processing of a frame, it’s the time used to compute the
    animation position of everything in a frame. Outside of a frame, it's the
    time of the conceptual “previous frame,” which may be either the actual
    previous frame time, or if that’s too old, an updated time. *)

external get_frame_counter : t -> int64 = "ml_gdk_frame_clock_get_frame_counter"
(** `GdkFrameClock` maintains a 64-bit counter that increments for each frame
    drawn. *)

external get_fps : t -> float = "ml_gdk_frame_clock_get_fps"
(** Calculates the current frames-per-second, based on the
frame timings of @frame_clock. *)

external get_current_timings : t -> Frame_timings.t option
  = "ml_gdk_frame_clock_get_current_timings"
(** Gets the frame timings for the current frame. *)

external end_updating : t -> unit = "ml_gdk_frame_clock_end_updating"
(** Stops updates for an animation.

    See the documentation for [method@Gdk.FrameClock.begin_updating]. *)

external begin_updating : t -> unit = "ml_gdk_frame_clock_begin_updating"
(** Starts updates for an animation.

    Until a matching call to [method@Gdk.FrameClock.end_updating] is made, the
    frame clock will continually request a new frame with the
    %GDK_FRAME_CLOCK_PHASE_UPDATE phase. This function may be called multiple
    times and frames will be requested until gdk_frame_clock_end_updating() is
    called the same number of times. *)

let on_after_paint ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"after-paint" ~callback
    ~after:(Option.value after ~default:false)

let on_before_paint ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"before-paint" ~callback
    ~after:(Option.value after ~default:false)

let on_flush_events ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"flush-events" ~callback
    ~after:(Option.value after ~default:false)

let on_layout ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"layout" ~callback
    ~after:(Option.value after ~default:false)

let on_paint ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"paint" ~callback
    ~after:(Option.value after ~default:false)

let on_resume_events ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"resume-events" ~callback
    ~after:(Option.value after ~default:false)

let on_update ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"update" ~callback
    ~after:(Option.value after ~default:false)
