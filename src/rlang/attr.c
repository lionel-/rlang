#include "rlang.h"

// These change attributes in-place.

SEXP rlang_zap_attrs(SEXP x) {
  SET_ATTRIB(x, R_NilValue);
  return x;
}

SEXP rlang_set_attrs(SEXP x, SEXP attrs) {
  SET_ATTRIB(x, attrs);
  return x;
}

SEXP rlang_get_attrs(SEXP x) {
  return ATTRIB(x);
}

SEXP r_set_attr(SEXP x, SEXP attr, SEXP value) {
  int n_kept = r_maybe_duplicate(&x, true);

  r_poke_attr(x, attr, value);

  FREE(n_kept);
  return x;
}
SEXP r_poke_attr(SEXP x, SEXP attr, SEXP value) {
  Rf_setAttrib(x, attr, value);
  return x;
}
