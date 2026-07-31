# gir_gen — GIR-to-OCaml Binding Generator

This package provides the code generator for [ocgtk](https://github.com/chris-armstrong/ocgtk),
an OCaml binding for GTK 4.

`gir_gen` parses GObject Introspection (GIR) XML files and generates:

- OCaml module interfaces (`.mli`) and implementations (`.ml`)
- C stub files for the OCaml/C FFI layer
- Enumeration and bitfield converters
- High-level wrapper classes

## Usage

```sh
gir_gen --gir-file <GIR.xml> --output-dir <output/>
```

See `gir_gen --help` for full options, including filter files, overrides, and
cross-namespace reference files.

## License

LGPL-2.1-or-later WITH OCaml-LGPL-linking-exception
