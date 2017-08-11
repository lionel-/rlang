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
  if (r_is_shared(x)) {
    x = r_duplicate(x, true);
  }
  return Rf_setAttrib(x, attr, value);
}
SEXP r_poke_attr(SEXP x, SEXP attr, SEXP value) {
  return Rf_setAttrib(x, attr, value);
}
