#include <rlang.h>

static
const char* quo_tags[2] = { "quosure", "formula" };

sexp* new_raw_formula(sexp* lhs, sexp* rhs, sexp* env);

sexp* rlang_new_quosure(sexp* expr, sexp* env) {
  if (r_typeof(env) != R_TYPE_environment) {
    r_abort("`env` must be an environment");
  }
  sexp* quo = KEEP(new_raw_formula(r_null, expr, env));
  r_attrib_push_classes(quo, quo_tags, R_ARR_SIZEOF(quo_tags));
  FREE(1);
  return quo;
}
bool rlang_is_quosure(sexp* x) {
  return r_typeof(x) == R_TYPE_call && Rf_inherits(x, "quosure");
}

inline void check_quosure(sexp* quo) {
  if (!rlang_is_quosure(quo)) {
    r_abort("`quo` must be a quosure");
  }
}
sexp* rlang_quo_get_expr(sexp* quo) {
  check_quosure(quo);
  return r_node_cadr(quo);
}
sexp* rlang_quo_set_expr(sexp* quo, sexp* expr) {
  check_quosure(quo);
  quo = r_clone(quo);
  r_node_poke_cadr(quo, expr);
  return quo;
}

sexp* rlang_quo_get_env(sexp* quo) {
  check_quosure(quo);
  return r_attrib_get(quo, r_syms.dot_environment);
}
sexp* rlang_quo_set_env(sexp* quo, sexp* env) {
  check_quosure(quo);
  if (r_typeof(env) != R_TYPE_environment) {
    r_abort("`env` must be an environment");
  }
  return r_attrib_set(quo, r_syms.dot_environment, env);
}

sexp* rlang_get_expression(sexp* x, sexp* alternate) {
  switch (r_typeof(x)) {
  case LANGSXP:
    if (r_is_formula(x, 0)) {
      return r_f_rhs(x);
    }
    break;
  // case CLOSXP:
  //   return r_fn_body(x);
  case VECSXP:
    if (r_inherits(x, "frame")) {
      return r_list_get(x, 2);
    }
    break;
  default:
    break;
  }

  if (alternate) {
    return alternate;
  } else {
    return x;
  }
}

bool quo_is_missing(sexp* quo) {
  return r_node_cadr(quo) == R_MissingArg;
}
bool quo_is_symbol(sexp* quo) {
  return r_typeof(r_node_cadr(quo)) == R_TYPE_symbol;
}
bool quo_is_call(sexp* quo) {
  return r_typeof(r_node_cadr(quo)) == R_TYPE_call;
}
bool quo_is_symbolic(sexp* quo) {
  return r_is_symbolic(r_node_cadr(quo));
}
bool quo_is_null(sexp* quo) {
  return r_node_cadr(quo) == r_null;
}
