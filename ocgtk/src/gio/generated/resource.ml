(* GENERATED CODE - DO NOT EDIT *)
(* Resource: Resource *)

type t = [ `resource ] Gobject.obj
(** Applications and libraries often contain binary or textual data that is
    really part of the application, rather than user data. For instance
    [`GtkBuilder`](https://docs.gtk.org/gtk4/class.Builder.html) `.ui` files,
    splashscreen images, [class@Gio.Menu] markup XML, CSS files, icons, etc.
    These are often shipped as files in `$datadir/appname`, or manually included
    as literal strings in the code.

    The `GResource` API and the
    [`glib-compile-resources`](glib-compile-resources.html) program provide a
    convenient and efficient alternative to this which has some nice properties.
    You maintain the files as normal files, so it’s easy to edit them, but
    during the build the files are combined into a binary bundle that is linked
    into the executable. This means that loading the resource files are
    efficient (as they are already in memory, shared with other instances) and
    simple (no need to check for things like I/O errors or locate the files in
    the filesystem). It also makes it easier to create relocatable applications.

    Resource files can also be marked as compressed. Such files will be included
    in the resource bundle in a compressed form, but will be automatically
    uncompressed when the resource is used. This is very useful e.g. for larger
    text files that are parsed once (or rarely) and then thrown away.

    Resource files can also be marked to be preprocessed, by setting the value
    of the `preprocess` attribute to a comma-separated list of preprocessing
    options. The only options currently supported are:

    - `xml-stripblanks` which will use the [`xmllint`](man:xmllint(1)) command
      to strip ignorable whitespace from the XML file. For this to work, the
      `XMLLINT` environment variable must be set to the full path to the xmllint
      executable, or xmllint must be in the `PATH`; otherwise the preprocessing
      step is skipped.

    - `to-pixdata` (deprecated since gdk-pixbuf 2.32) which will use the
      `gdk-pixbuf-pixdata` command to convert images to the
      [`GdkPixdata`](https://docs.gtk.org/gdk-pixbuf/class.Pixdata.html) format,
      which allows you to create pixbufs directly using the data inside the
      resource file, rather than an (uncompressed) copy of it. For this, the
      `gdk-pixbuf-pixdata` program must be in the `PATH`, or the
      `GDK_PIXBUF_PIXDATA` environment variable must be set to the full path to
      the `gdk-pixbuf-pixdata` executable; otherwise the resource compiler will
      abort. `to-pixdata` has been deprecated since gdk-pixbuf 2.32, as
      `GResource` supports embedding modern image formats just as well. Instead
      of using it, embed a PNG or SVG file in your `GResource`.

    - `json-stripblanks` which will use the
      [`json-glib-format`](man:json-glib-format(1)) command to strip ignorable
      whitespace from the JSON file. For this to work, the `JSON_GLIB_FORMAT`
      environment variable must be set to the full path to the
      `json-glib-format` executable, or it must be in the `PATH`; otherwise the
      preprocessing step is skipped. In addition, at least version 1.6 of
      `json-glib-format` is required.

    Resource files will be exported in the `GResource` namespace using the
    combination of the given `prefix` and the filename from the `file` element.
    The `alias` attribute can be used to alter the filename to expose them at a
    different location in the resource namespace. Typically, this is used to
    include files from a different source directory without exposing the source
    directory in the resource namespace, as in the example below.

    Resource bundles are created by the
    [`glib-compile-resources`](glib-compile-resources.html) program which takes
    an XML file that describes the bundle, and a set of files that the XML
    references. These are combined into a binary resource bundle.

    An example resource description: ```xml <?xml version="1.0"
    encoding="UTF-8"?> <gresources> <gresource prefix="/org/gtk/Example">
    <file>data/splashscreen.png</file> <file compressed="true">dialog.ui</file>
    <file preprocess="xml-stripblanks">menumarkup.xml</file> <file
    alias="example.css">data/example.css</file> </gresource> </gresources> ```

    This will create a resource bundle with the following files: ```
    /org/gtk/Example/data/splashscreen.png /org/gtk/Example/dialog.ui
    /org/gtk/Example/menumarkup.xml /org/gtk/Example/example.css ```

    Note that all resources in the process share the same namespace, so use
    Java-style path prefixes (like in the above example) to avoid conflicts.

    You can then use [`glib-compile-resources`](glib-compile-resources.html) to
    compile the XML to a binary bundle that you can load with
    [func@Gio.Resource.load]. However, it’s more common to use the
    `--generate-source` and `--generate-header` arguments to create a source
    file and header to link directly into your application. This will generate
    `get_resource()`, `register_resource()` and `unregister_resource()`
    functions, prefixed by the `--c-name` argument passed to
    [`glib-compile-resources`](glib-compile-resources.html). `get_resource()`
    returns the generated `GResource` object. The register and unregister
    functions register the resource so its files can be accessed using
    [func@Gio.resources_lookup_data].

    Once a `GResource` has been created and registered all the data in it can be
    accessed globally in the process by using API calls like
    [func@Gio.resources_open_stream] to stream the data or
    [func@Gio.resources_lookup_data] to get a direct pointer to the data. You
    can also use URIs like `resource:///org/gtk/Example/data/splashscreen.png`
    with [iface@Gio.File] to access the resource data.

    Some higher-level APIs, such as
    [`GtkApplication`](https://docs.gtk.org/gtk4/class.Application.html), will
    automatically load resources from certain well-known paths in the resource
    namespace as a convenience. See the documentation for those APIs for
    details.

    There are two forms of the generated source, the default version uses the
    compiler support for constructor and destructor functions (where available)
    to automatically create and register the `GResource` on startup or library
    load time. If you pass `--manual-register`, two functions to
    register/unregister the resource are created instead. This requires an
    explicit initialization call in your application/library, but it works on
    all platforms, even on the minor ones where constructors are not supported.
    (Constructor support is available for at least Win32, Mac OS and Linux.)

    Note that resource data can point directly into the data segment of e.g. a
    library, so if you are unloading libraries during runtime you need to be
    very careful with keeping around pointers to data from a resource, as this
    goes away when the library is unloaded. However, in practice this is not
    generally a problem, since most resource accesses are for your own
    resources, and resource data is often used once, during parsing, and then
    released.

    # Overlays

    When debugging a program or testing a change to an installed version, it is
    often useful to be able to replace resources in the program or library,
    without recompiling, for debugging or quick hacking and testing purposes.
    Since GLib 2.50, it is possible to use the `G_RESOURCE_OVERLAYS` environment
    variable to selectively overlay resources with replacements from the
    filesystem. It is a `G_SEARCHPATH_SEPARATOR`-separated list of substitutions
    to perform during resource lookups. It is ignored when running in a setuid
    process.

    A substitution has the form

    ``` /org/gtk/libgtk=/home/desrt/gtk-overlay ```

    The part before the `=` is the resource subpath for which the overlay
    applies. The part after is a filesystem path which contains files and
    subdirectories as you would like to be loaded as resources with the
    equivalent names.

    In the example above, if an application tried to load a resource with the
    resource path `/org/gtk/libgtk/ui/gtkdialog.ui` then `GResource` would check
    the filesystem path `/home/desrt/gtk-overlay/ui/gtkdialog.ui`. If a file was
    found there, it would be used instead. This is an overlay, not an outright
    replacement, which means that if a file is not found at that path, the
    built-in version will be used instead. Whiteouts are not currently
    supported.

    Substitutions must start with a slash, and must not contain a trailing slash
    before the `=`. The path after the slash should ideally be absolute, but
    this is not strictly required. It is possible to overlay the location of a
    single resource with an individual file. *)

external gtype : unit -> Gobject.Type.t = "ml_gio_resource_get_type"

external new_from_data : Glib_bytes.t -> (t, GError.t) result
  = "ml_g_resource_new_from_data"
(** Create a new Resource *)

(* Methods *)

external ref : t -> t = "ml_g_resource_ref"
(** Atomically increments the reference count of @resource by one.

This function is threadsafe and may be called from any thread. *)

external open_stream :
  t ->
  string ->
  Gio_enums.resourcelookupflags ->
  (Input_stream.t, GError.t) result = "ml_g_resource_open_stream"
(** Looks for a file at the specified @path in the resource and
returns a [class@Gio.InputStream] that lets you read the data.

@lookup_flags controls the behaviour of the lookup.

The only error this can return is %G_RESOURCE_ERROR_NOT_FOUND, if @path was
not found in @resource. *)

external lookup_data :
  t ->
  string ->
  Gio_enums.resourcelookupflags ->
  (Glib_bytes.t, GError.t) result = "ml_g_resource_lookup_data"
(** Looks for a file at the specified @path in the resource and
returns a [struct@GLib.Bytes] that lets you directly access the data in
memory.

The data is always followed by a zero byte, so you
can safely use the data as a C string. However, that byte
is not included in the size of the [struct@GLib.Bytes].

For uncompressed resource files this is a pointer directly into
the resource bundle, which is typically in some read-only data section
in the program binary. For compressed files, memory is allocated on
the heap and the data is automatically uncompressed.

@lookup_flags controls the behaviour of the lookup.

This can return error %G_RESOURCE_ERROR_NOT_FOUND if @path was not found in
@resource, or %G_RESOURCE_ERROR_INTERNAL if decompression of a compressed
resource failed. *)

external has_children : t -> string -> bool = "ml_g_resource_has_children"
(** Returns whether the specified @path in the resource
has children. *)

external get_info :
  t ->
  string ->
  Gio_enums.resourcelookupflags ->
  (bool * Gsize.t * UInt32.t, GError.t) result = "ml_g_resource_get_info"
(** Looks for a file at the specified @path in the resource and
if found returns information about it.

@lookup_flags controls the behaviour of the lookup.

The only error this can return is %G_RESOURCE_ERROR_NOT_FOUND, if @path was
not found in @resource. *)

external enumerate_children :
  t ->
  string ->
  Gio_enums.resourcelookupflags ->
  (string array, GError.t) result = "ml_g_resource_enumerate_children"
(** Returns all the names of children at the specified @path in the resource.

The return result is a `NULL` terminated list of strings which should
be released with [func@GLib.strfreev].

If @path is invalid or does not exist in the [struct@Gio.Resource],
%G_RESOURCE_ERROR_NOT_FOUND will be returned.

@lookup_flags controls the behaviour of the lookup. *)

external _unregister : t -> unit = "ml_g_resources_unregister"
(** Unregisters the resource from the process-global set of resources. *)

external _register : t -> unit = "ml_g_resources_register"
(** Registers the resource with the process-global set of resources.

    Once a resource is registered the files in it can be accessed with the
    global resource lookup functions like [func@Gio.resources_lookup_data]. *)
