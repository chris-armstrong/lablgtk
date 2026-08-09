(* Override Extractor: Version extraction from GIR doc strings *)

val extract_since_version : string -> string option
(** Extract a "Since X.Y[.Z]" version string from a doc comment. Matches
    patterns where the literal word "Since" (capital S) is followed by an
    optional colon and a version number: "Since 2.26", "Since: 2.74", "(Since:
    1.16)." Does NOT match lowercase "since" or "available since".

    @param doc_text the documentation string to search
    @return
      the version string (e.g. "2.26"), or [None] if no matching pattern is
      found *)
