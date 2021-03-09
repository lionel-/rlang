#' Create a formula
#'
#' @param lhs,rhs A call, name, or atomic vector.
#' @param env An environment.
#' @return A formula object.
#' @seealso [new_quosure()]
#' @export
#' @examples
#' new_formula(quote(a), quote(b))
#' new_formula(NULL, quote(b))
new_formula <- function(lhs, rhs, env = caller_env()) {
  .Call(rlang_new_formula, lhs, rhs, env)
}

#' Is object a formula?
#'
#' @description
#' `is_formula()` tests whether `x` is a call to `~`. `is_bare_formula()`
#' tests in addition that `x` does not inherit from anything else than
#' `"formula"`.
#'
#' At parse time, a formula is a simple call to `~` and it does not
#' have a class or an environment. Once evaluated, the `~` call
#' becomes a properly structured formula. Unevaluated formulas arise
#' by quotation, e.g. `~~foo` or `quote(~foo)`. Use the `scoped`
#' argument to check whether the formula carries an environment.
#'
#' @param x An object to test.
#' @param scoped A boolean indicating whether the quosure is scoped,
#'   that is, has a valid environment attribute. If `NULL`, the scope
#'   is not inspected.
#' @param lhs A boolean indicating whether the [formula][is_formula]
#'   or [definition][is_definition] has a left-hand side. If `NULL`,
#'   the LHS is not inspected.
#' @export
#' @examples
#' is_formula(~10)
#' is_formula(10)
#'
#' x <- disp ~ am
#' is_formula(x)
#'
#' # Note that unevaluated formulas are treated as bare formulas even
#' # though they don't inherit from "formula":
#' f <- quote(~foo)
#' is_bare_formula(f)
#'
#' # However you can specify `scoped` if you need the predicate to
#' # return FALSE for these unevaluated formulas:
#' is_bare_formula(f, scoped = TRUE)
#' is_bare_formula(eval(f), scoped = TRUE)
is_formula <- function(x, ..., lhs = NULL) {
  check_formula_args(..., env = caller_env())
  .Call(ffi_is_formula, x, lhs)
}
#' @rdname is_formula
#' @export
is_bare_formula <- function(x, ..., lhs = NULL) {
  check_formula_args(..., env = caller_env())
  is_formula(x, lhs = lhs) && identical(class, "formula")
}

check_formula_args <- function(..., scoped, env) {
  if (!missing(scoped)) {
    signal_soft_deprecated("The `scoped` argument is deprecated as of rlang 1.0.0.", env = env)
  }
}

#' Get or set formula components
#'
#' `f_rhs` extracts the righthand side, `f_lhs` extracts the lefthand
#' side, and `f_env` extracts the environment. All functions throw an
#' error if `f` is not a formula.
#'
#' @param f,x A formula
#' @param value The value to replace with.
#' @export
#' @return `f_rhs` and `f_lhs` return language objects (i.e.  atomic
#'   vectors of length 1, a name, or a call). `f_env` returns an
#'   environment.
#' @examples
#' f_rhs(~ 1 + 2 + 3)
#' f_rhs(~ x)
#' f_rhs(~ "A")
#' f_rhs(1 ~ 2)
#'
#' f_lhs(~ y)
#' f_lhs(x ~ y)
#'
#' f_env(~ x)
f_rhs <- function(f) {
  if (is_quosure(f)) {
    signal_formula_access()
    return(quo_get_expr(f))
  }
  .Call(r_f_rhs, f)
}

#' @export
#' @rdname f_rhs
`f_rhs<-` <- function(x, value) {
  if (is_quosure(x)) {
    signal_formula_access()
    return(quo_set_expr(x, value))
  }
  if (!is_formula(x)) {
    abort("`f` must be a formula")
  }
  x[[length(x)]] <- value
  x
}

#' @export
#' @rdname f_rhs
f_lhs <- function(f) {
  if (is_quosure(f)) {
    signal_formula_access()
    abort("Can't retrieve the LHS of a quosure")
  }
  .Call(r_f_lhs, f)
}

#' @export
#' @rdname f_rhs
`f_lhs<-` <- function(x, value) {
  if (is_quosure(x)) {
    signal_formula_access()
    abort("Can't set the LHS of a quosure")
  }
  if (!is_formula(x)) {
    abort("`f` must be a formula")
  }

  if (length(x) < 3) {
    x <- duplicate(x)
    node_poke_cdr(x, pairlist(value, x[[2]]))
  } else {
    x[[2]] <- value
  }

  x
}

#' @export
#' @rdname f_rhs
f_env <- function(f) {
  if (is_quosure(f)) {
    signal_formula_access()
    return(quo_get_env(f))
  }
  if (!is_formula(f)) {
    abort("`f` must be a formula")
  }
  attr(f, ".Environment")
}

#' @export
#' @rdname f_rhs
`f_env<-` <- function(x, value) {
  if (is_quosure(x)) {
    signal_formula_access()
    return(quo_set_env(x, value))
  }
  if (!is_formula(x)) {
    abort("`f` must be a formula")
  }
  structure(x, .Environment = value)
}

#' Turn RHS of formula into a string or label
#'
#' Equivalent of [expr_text()] and [expr_label()] for formulas.
#'
#' @param x A formula.
#' @inheritParams expr_text
#' @export
#' @examples
#' f <- ~ a + b + bc
#' f_text(f)
#' f_label(f)
#'
#' # Names a quoted with ``
#' f_label(~ x)
#' # Strings are encoded
#' f_label(~ "a\nb")
#' # Long expressions are collapsed
#' f_label(~ foo({
#'   1 + 2
#'   print(x)
#' }))
f_text <- function(x, width = 60L, nlines = Inf) {
  expr_text(f_rhs(x), width = width, nlines = nlines)
}
#' @rdname f_text
#' @export
f_name <- function(x) {
  expr_name(f_rhs(x))
}
#' @rdname f_text
#' @export
f_label <- function(x) {
  expr_label(f_rhs(x))
}


signal_formula_access <- function() {
  if (is_true(peek_option("rlang:::warn_quosure_access"))) {
    warn(
      "Using formula accessors with quosures is soft-deprecated"
    )
  }
}
