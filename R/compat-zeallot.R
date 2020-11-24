# nocov start --- compat-zeallot --- 2020-11-24

# This drop-in file implements a simple version of zeallot::`%<-%`.
# Please find the most recent version in rlang's repository.


`%<-%` <- function(lhs, value) {
  lhs <- substitute(lhs)
  env <- caller_env()

  if (!is_call(lhs, "c")) {
    abort("The left-hand side of `%<-%` must be a call to `c()`.")
  }

  vars <- as.list(lhs[-1])
  nms <- names(vars)

  as_var_name <- function(i, var) {
    if (!is_symbol(var)) {
      abort(paste0("Element ", i, " of the left-hand side of `%<-%` must be a symbol."))
    }
    as_string(var)
  }
  vars_seq <- seq_along(vars)
  vars <- Map(as_var_name, vars_seq, vars)

  if (is_null(nms)) {
    locs <- vars_seq
    if (length(value) != length(vars)) {
      abort("The left- and right-hand sides of `%<-%` must be the same length.")
    }
  } else {
    vars <- ifelse(vars == "", nms, vars)
    locs <- match(vars, names(value))
    vars <- nms
    if (anyNA(locs)) {
      abort("The names of the left- and right-hand sides of `%<-%` must match.")
    }
  }

  for (i in seq_along(vars)) {
    var <- vars[[i]]

    env[[as_string(var)]] <- value[[locs[[i]]]]
  }

  invisible(value)
}


# nocov end
