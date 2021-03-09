#include "rlang.h"


sexp* r_f_rhs(sexp* f) {
  if (r_typeof(f) != LANGSXP) {
    r_abort("`x` must be a formula");
  }

  switch (r_length(f)) {
  case 2: return r_node_cadr(f);
  case 3: return CADDR(f);
  default: r_abort("Invalid formula");
  }
}
sexp* r_f_lhs(sexp* f) {
  if (r_typeof(f) != LANGSXP) {
    r_abort("`x` must be a formula");
  }

  switch (r_length(f)) {
  case 2: return r_null;
  case 3: return r_node_cadr(f);
  default: r_abort("Invalid formula");
  }
}
sexp* r_f_env(sexp* f) {
  return r_attrib_get(f, r_sym(".Environment"));
}

bool r_f_has_env(sexp* f) {
  return r_is_environment(r_f_env(f));
}

bool r_is_formula(sexp* x, int lhs) {
  if (r_typeof(x) != LANGSXP) {
    return false;
  }

  if (r_node_car(x) != r_syms.tilde) {
    return false;
  }

  if (!r_inherits(x, "formula")) {
    return false;
  }

  if (lhs >= 0) {
    int has_lhs = r_length(x) > 2;
    if (lhs != has_lhs) {
      return false;
    }
  }

  return true;
}

sexp* new_raw_formula(sexp* lhs, sexp* rhs, sexp* env) {
  static sexp* tilde_sym = NULL;
  if (!tilde_sym) {
    tilde_sym = r_sym("~");
  }
  if (!r_is_environment(env) && env != r_null) {
    r_abort("`env` must be an environment");
  }

  sexp* f;
  sexp* args;
  if (lhs == r_null) {
    args = KEEP(r_pairlist(rhs));
  } else {
    args = KEEP(r_pairlist2(lhs, rhs));
  }
  f = KEEP(r_new_call(tilde_sym, args));

  sexp* attrs = KEEP(r_new_node(env, r_null));
  r_node_poke_tag(attrs, r_sym(".Environment"));
  r_poke_attrib(f, attrs);

  FREE(3);
  return f;
}
sexp* r_new_formula(sexp* lhs, sexp* rhs, sexp* env) {
  sexp* f = KEEP(new_raw_formula(lhs, rhs, env));
  r_attrib_push_class(f, "formula");

  FREE(1);
  return f;
}
