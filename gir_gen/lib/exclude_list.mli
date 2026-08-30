module Log : Logs.LOG

val should_skip_method :
  find_type_mapping:(Types.gir_type -> 'a option) ->
  enums:'b ->
  bitfields:'c ->
  Types.gir_method ->
  bool

val should_skip_constructor :
  find_type_mapping:(Types.gir_type -> 'a option) ->
  enums:'b ->
  bitfields:'c ->
  Types.gir_constructor ->
  bool
