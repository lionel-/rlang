.onLoad <- function(lib, pkg) {
  check_linked_version(pkg, with_rlang = FALSE)

  rlang_ns <- topenv(environment())
  .Call(ffi_init_r_library, rlang_ns)
  .Call(ffi_init_rlang, rlang_ns)

  run_on_load()
}
.onUnload <- function(lib) {
  .Call(ffi_fini_rlang)
}

#' Global options in rlang
#'
#' Full documentation.
#'
#' @export
rlang_options <- new_options()

on_load({
  opt_bind(
    message_verbosity = "default",
    name_repair_verbosity = "verbose"
  )

  # Complex defaults with active bindings?
  # Problem: These may be overridden by users.
  env_bind_active(
    rlang_options,
    fancy_opt = function() if (is_testing()) "foo" else "bar"
  )
})

# Internal options which are not exported
rlang_internal_options <- new_options()
