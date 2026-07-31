# ocgtk

OCaml bindings for GTK 4, generated from GObject-Introspection (GIR) data.

## Status

The bindings are under active development. Supported so far:

* Classes, interfaces, records, enumerations and bitfields
* Constructors, methods, properties and signals (primitive, enum, bitfield,
  and GObject class/interface parameters; boolean return values)
* GObject interface implementation in the type hierarchy (`:>` coercions work)
* Bindings for GTK and its dependencies (GLib, GObject, Pango, Gdk,
  GdkPixbuf, GIO)

Not yet supported: signals with boxed record parameters (e.g. `GtkTextIter`,
`GdkRGBA`) or callback parameters, standalone namespace-level functions (e.g.
`gtk_show_uri`), fields of non-opaque record types, and callbacks as method
parameters.

## Requirements

- OCaml >= 4.14
- Dune >= 3.13
- GTK 4 >= 4.0 (bindings are generated up to 4.14.5 — older versions will
  throw runtime errors on unavailable APIs)

## Install

```bash
opam install ocgtk
```

## Quick example

```ocaml
open Ocgtk_gtk.Gtk
module Button = Wrappers.Button

let () =
  ignore (GMain.init ());
  let btn = Button.new_with_label "Click Me!" in
  Button.set_label btn "Hello, GTK 4!"
```

## Source and documentation

This package is built from the [ocgtk monorepo](https://github.com/chris-armstrong/ocgtk),
which also hosts the GIR code generator, full architecture docs, and more
extensive examples. See that repository for contributing guidelines and
in-depth documentation.

## License

Distributed under the GNU Library General Public License v2.1, with the
special exception on linking described in [LICENSE](LICENSE). See [LGPL](LGPL)
for the full license text.

Copyright (C) 2025 Chris Armstrong, with some parts derived from lablgtk3
(see [LICENSE](LICENSE)).
