#include <string.h>
#include "rlang.h"

SEXP r_chr_get(SEXP chr, size_t i) {
  return STRING_ELT(chr, i);
}

bool chr_has(SEXP chr, const char* c_string) {
  SEXP nm;
  for (int i = 0; i != vec_length(chr); ++i) {
    nm = STRING_ELT(chr, i);
    if (!strcmp(CHAR(nm), c_string))
      return true;
  }

  return false;
}

void mut_chr_at(SEXP chr, R_len_t i, SEXP elt) {
  SET_STRING_ELT(chr, i, elt);
}

SEXP r_new_scalar_string(const char* c_string) {
  return Rf_mkChar(c_string);
}
bool is_r_scalar_string(SEXP x) {
  return TYPEOF(x) == CHARSXP;
}

SEXP string(const char* c_string) {
  return Rf_mkString(c_string);
}
bool is_string(SEXP x) {
  return TYPEOF(x) == STRSXP && r_length(x) == 1;
}

const char* r_c_string(SEXP scalar_chr) {
  return CHAR(r_chr_get(scalar_chr, 0));
}

void validate_chr_setter(SEXP chr, SEXP scalar_string) {
  if (!is_character(chr))
    r_abort("`chr` must be a character vector");
  if (!is_r_scalar_string(scalar_string))
    r_abort("`scalar_string` must be an internal R string");
}
SEXP chr_prepend(SEXP chr, SEXP scalar_string) {
  if (is_null(chr))
    return Rf_ScalarString(scalar_string);
  else
    validate_chr_setter(chr, scalar_string);

  int n = r_length(chr);
  SEXP out = KEEP(Rf_allocVector(STRSXP, n + 1));

  vec_copy_n(chr, n, out, 1, 0);
  mut_chr_at(out, 0, scalar_string);

  FREE(1);
  return out;
}
SEXP chr_append(SEXP chr, SEXP r_new_scalar_string) {
  if (is_null(chr))
    return Rf_ScalarString(r_new_scalar_string);
  else
    validate_chr_setter(chr, r_new_scalar_string);

  int n = r_length(chr);
  SEXP out = KEEP(Rf_allocVector(STRSXP, n + 1));

  vec_copy_n(chr, n, out, 0, 0);
  mut_chr_at(out, n, r_new_scalar_string);

  FREE(1);
  return out;
}
