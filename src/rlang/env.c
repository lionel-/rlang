#include "rlang.h"


bool r_is_unbound_value(SEXP x) {
  return x == R_UnboundValue;
}

void r_mut_env_parent(SEXP env, SEXP new_parent) {
  SET_ENCLOS(env, new_parent);
}
SEXP rlang_mut_env_parent(SEXP env, SEXP new_parent) {
  SET_ENCLOS(env, new_parent);
  return env;
}

bool r_is_environment(SEXP x) {
  return r_kind(x) == ENVSXP;
}

SEXP r_env_get(SEXP env, SEXP sym) {
  return Rf_findVarInFrame3(env, sym, TRUE);
}
SEXP r_env_set(SEXP env, SEXP sym, SEXP value) {
  Rf_defineVar(sym, value, env);
  return env;
}

SEXP r_ns_env(const char* pkg) {
  SEXP ns = r_env_get(R_NamespaceRegistry, r_sym(pkg));
  if (r_is_unbound_value(ns))
    r_abort("Can't find namespace `%s`", pkg);
  return ns;
}

SEXP r_set_env(SEXP env, SEXP new_env) {
  if (r_is_environment(env)) {
    return new_env;
  }

  int n_kept = r_maybe_duplicate(&env, true);
  r_poke_env(env, new_env);

  FREE(n_kept);
  return env;
}
SEXP r_poke_env(SEXP env, SEXP new_env) {
  switch (r_kind(env)) {
  case CLOSXP: {
    SET_CLOENV(env, new_env);
    break;
  }
  case LANGSXP: {
    if (!r_inherits(env, "formula")) {
      goto abort;
    }
    r_poke_attr(env, r_sym(".Environment"), new_env);
    break;
  }
  abort:
  default: {
    r_abort("Can't set environment for %s", r_friendly_type(r_type(env)));
  }}

  return env;
}
