#include "rlang.h"

bool r_is_shared(SEXP x) {
  return MAYBE_SHARED(x);
}

const char* r_sxp_address(SEXP x) {
  static char str[1000];
  snprintf(str, 1000, "%p", (void*) x);
  return str;
}
SEXP rlang_sxp_address(SEXP x) {
  return Rf_mkString(r_sxp_address(x));
}

SEXP rlang_is_reference(SEXP x, SEXP y) {
  return r_scalar_lgl(x == y);
}

SEXPTYPE r_kind(SEXP x) {
  return TYPEOF(x);
}
const char* r_type(SEXP x) {
  return r_as_c_string(Rf_type2str(TYPEOF(x)));
}
SEXP r_friendly_type(const char* type) {
  SEXP fn = rlang_obj("friendly_type_of");
  SEXP args = r_new_pairlist(r_new_scalar_string(type));
  SEXP lang = KEEP(r_new_language(fn, args));

  SEXP friendly_type = r_eval(lang, r_empty_env);

  FREE(1);
  return friendly_type;
}

SEXP r_mut_kind(SEXP x, SEXPTYPE kind) {
  SET_TYPEOF(x, kind);
  return x;
}
SEXP rlang_mut_type(SEXP x, SEXP type) {
  SET_TYPEOF(x, Rf_str2type(r_as_c_string(type)));
  return x;
}

bool r_inherits(SEXP x, const char* class_) {
  return Rf_inherits(x, class_);
}

SEXP r_get_attr(SEXP x, SEXP sym) {
  return Rf_getAttrib(x, sym);
}

void mut_attr(SEXP x, SEXP sym, SEXP attr) {
  Rf_setAttrib(x, sym, attr);
}
void mut_class(SEXP x, SEXP classes) {
  Rf_setAttrib(x, R_ClassSymbol, classes);
}

SEXP set_attr(SEXP x, SEXP sym, SEXP attr) {
  x = KEEP(Rf_shallow_duplicate(x));
  mut_attr(x, sym, attr);

  FREE(1);
  return x;
}
SEXP set_class(SEXP x, SEXP classes) {
  return set_attr(x, R_ClassSymbol, classes);
}

SEXP sxp_class(SEXP x) {
  return Rf_getAttrib(x, R_ClassSymbol);
}
SEXP sxp_names(SEXP x) {
  return Rf_getAttrib(x, R_NamesSymbol);
}

void mut_names(SEXP x, SEXP nms) {
  Rf_setAttrib(x, R_NamesSymbol, nms);
}

bool is_named(SEXP x) {
  SEXP nms = sxp_names(x);

  if (TYPEOF(nms) != STRSXP)
    return false;

  if (chr_has(nms, ""))
    return false;

  return true;
}


SEXP r_missing_arg() {
  return R_MissingArg;
}
bool r_is_missing(SEXP x) {
  return x == R_MissingArg;
}


SEXP rlang_is_null(SEXP x) {
  return r_scalar_lgl(r_is_null(x));
}
bool r_is_null(SEXP x) {
  return x == R_NilValue;
}

SEXP r_duplicate(SEXP x, bool shallow) {
  if (shallow)
    return Rf_shallow_duplicate(x);
  else
    return Rf_duplicate(x);
}
SEXP rlang_duplicate(SEXP x, SEXP shallow) {
  return r_duplicate(x, r_as_bool(shallow));
}

int r_maybe_duplicate(SEXP* addr, bool shallow) {
  SEXP x = *addr;
  if (r_is_shared(x)) {
    *addr = KEEP(r_duplicate(x, shallow));
    return 1;
  } else {
    return 0;
  }
}
