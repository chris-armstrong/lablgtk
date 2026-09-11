(* GENERATED CODE - DO NOT EDIT *)
(* DeviceTool: DeviceTool *)

type t = [ `device_tool | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gdk_device_tool_get_type"

(* Methods *)

external get_tool_type : t -> Gdk_enums.devicetooltype
  = "ml_gdk_device_tool_get_tool_type"
(** Gets the `GdkDeviceToolType` of the tool. *)

external get_serial : t -> UInt64.t = "ml_gdk_device_tool_get_serial"
(** Gets the serial number of this tool.

    This value can be used to identify a physical tool (eg. a tablet pen) across
    program executions. *)

external get_hardware_id : t -> UInt64.t = "ml_gdk_device_tool_get_hardware_id"
(** Gets the hardware ID of this tool, or 0 if it's not known.

When non-zero, the identifier is unique for the given tool model,
meaning that two identical tools will share the same @hardware_id,
but will have different serial numbers (see
[method@Gdk.DeviceTool.get_serial]).

This is a more concrete (and device specific) method to identify
a `GdkDeviceTool` than [method@Gdk.DeviceTool.get_tool_type],
as a tablet may support multiple devices with the same
`GdkDeviceToolType`, but different hardware identifiers. *)

external get_axes : t -> Gdk_enums.axisflags = "ml_gdk_device_tool_get_axes"
(** Gets the axes of the tool. *)

(* Properties *)
