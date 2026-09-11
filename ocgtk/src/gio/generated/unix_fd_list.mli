(* GENERATED CODE - DO NOT EDIT *)
(* UnixFDList: UnixFDList *)

type t = [ `unix_fd_list | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_unix_fd_list_get_type"

external new_ : unit -> t = "ml_g_unix_fd_list_new"
(** Create a new UnixFDList *)

external new_from_array : int array -> int -> t
  = "ml_g_unix_fd_list_new_from_array"
(** Create a new UnixFDList *)

(* Methods *)

external steal_fds : t -> int array * int = "ml_g_unix_fd_list_steal_fds"
(** Returns the array of file descriptors that is contained in this
object.

After this call, the descriptors are no longer contained in
@list. Further calls will return an empty list (unless more
descriptors have been added).

The return result of this function must be freed with g_free().
The caller is also responsible for closing all of the file
descriptors.  The file descriptors in the array are set to
close-on-exec.

If @length is non-%NULL then it is set to the number of file
descriptors in the returned array. The returned array is also
terminated with -1.

This function never returns %NULL. In case there are no file
descriptors contained in @list, an empty array is returned. *)

external peek_fds : t -> int array * int = "ml_g_unix_fd_list_peek_fds"
(** Returns the array of file descriptors that is contained in this
object.

After this call, the descriptors remain the property of @list.  The
caller must not close them and must not free the array.  The array is
valid only until @list is changed in any way.

If @length is non-%NULL then it is set to the number of file
descriptors in the returned array. The returned array is also
terminated with -1.

This function never returns %NULL. In case there are no file
descriptors contained in @list, an empty array is returned. *)

external get_length : t -> int = "ml_g_unix_fd_list_get_length"
(** Gets the length of @list (ie: the number of file descriptors
contained within). *)

external get : t -> int -> (int, GError.t) result = "ml_g_unix_fd_list_get"
(** Gets a file descriptor out of @list.

@index_ specifies the index of the file descriptor to get.  It is a
programmer error for @index_ to be out of range; see
g_unix_fd_list_get_length().

The file descriptor is duplicated using dup() and set as
close-on-exec before being returned.  You must call close() on it
when you are done.

A possible cause of failure is exceeding the per-process or
system-wide file descriptor limit. *)

external append : t -> int -> (int, GError.t) result
  = "ml_g_unix_fd_list_append"
(** Adds a file descriptor to @list.

The file descriptor is duplicated using dup(). You keep your copy
of the descriptor and the copy contained in @list will be closed
when @list is finalized.

A possible cause of failure is exceeding the per-process or
system-wide file descriptor limit.

The index of the file descriptor in the list is returned.  If you use
this index with g_unix_fd_list_get() then you will receive back a
duplicated copy of the same file descriptor. *)
