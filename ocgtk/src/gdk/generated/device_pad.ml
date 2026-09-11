(* GENERATED CODE - DO NOT EDIT *)
(* DevicePad: DevicePad *)

type t = [ `device_pad ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gdk_device_pad_get_type"
external from_gobject : 'a Gobject.obj -> t = "ml_gdk_device_pad_from_gobject"

(* Methods *)

external get_n_groups : t -> int = "ml_gdk_device_pad_get_n_groups"
(** Returns the number of groups this pad device has.

    Pads have at least one group. A pad group is a subcollection of
    buttons/strip/rings that is affected collectively by a same current mode. *)

external get_n_features : t -> Gdk_enums.devicepadfeature -> int
  = "ml_gdk_device_pad_get_n_features"
(** Returns the number of features a tablet pad has. *)

external get_group_n_modes : t -> int -> int
  = "ml_gdk_device_pad_get_group_n_modes"
(** Returns the number of modes that @group may have. *)

external get_feature_group : t -> Gdk_enums.devicepadfeature -> int -> int
  = "ml_gdk_device_pad_get_feature_group"
(** Returns the group the given @feature and @idx belong to.

f the feature or index do not exist in @pad, -1 is returned. *)
