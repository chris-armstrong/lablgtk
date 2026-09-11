(* GENERATED CODE - DO NOT EDIT *)
(* FrameTimings: FrameTimings *)

type t = [ `frame_timings ] Gobject.obj
(** Holds timing information for a single frame of the application’s displays.

    To retrieve `GdkFrameTimings` objects, use
    [method@Gdk.FrameClock.get_timings] or
    [method@Gdk.FrameClock.get_current_timings]. The information in
    `GdkFrameTimings` is useful for precise synchronization of video with the
    event or audio streams, and for measuring quality metrics for the
    application’s display, such as latency and jitter. *)

external gtype : unit -> Gobject.Type.t = "ml_gdk_frame_timings_get_type"

(* Methods *)

external ref : t -> t = "ml_gdk_frame_timings_ref"
(** Increases the reference count of @timings. *)

external get_refresh_interval : t -> int64
  = "ml_gdk_frame_timings_get_refresh_interval"
(** Gets the natural interval between presentation times for the display that
    this frame was displayed on.

    Frame presentation usually happens during the “vertical blanking interval”.
*)

external get_presentation_time : t -> int64
  = "ml_gdk_frame_timings_get_presentation_time"
(** Reurns the presentation time.

    This is the time at which the frame became visible to the user. *)

external get_predicted_presentation_time : t -> int64
  = "ml_gdk_frame_timings_get_predicted_presentation_time"
(** Gets the predicted time at which this frame will be displayed.

    Although no predicted time may be available, if one is available, it will be
    available while the frame is being generated, in contrast to
    [method@Gdk.FrameTimings.get_presentation_time], which is only available
    after the frame has been presented.

    In general, if you are simply animating, you should use
    [method@Gdk.FrameClock.get_frame_time] rather than this function, but this
    function is useful for applications that want exact control over latency.
    For example, a movie player may want this information for Audio/Video
    synchronization. *)

external get_frame_time : t -> int64 = "ml_gdk_frame_timings_get_frame_time"
(** Returns the frame time for the frame.

    This is the time value that is typically used to time animations for the
    frame. See [method@Gdk.FrameClock.get_frame_time]. *)

external get_frame_counter : t -> int64
  = "ml_gdk_frame_timings_get_frame_counter"
(** Gets the frame counter value of the `GdkFrameClock` when this frame was
    drawn. *)

external get_complete : t -> bool = "ml_gdk_frame_timings_get_complete"
(** Returns whether @timings are complete.

The timing information in a `GdkFrameTimings` is filled in
incrementally as the frame as drawn and passed off to the
window system for processing and display to the user. The
accessor functions for `GdkFrameTimings` can return 0 to
indicate an unavailable value for two reasons: either because
the information is not yet available, or because it isn't
available at all.

Once this function returns %TRUE for a frame, you can be
certain that no further values will become available and be
stored in the `GdkFrameTimings`. *)
