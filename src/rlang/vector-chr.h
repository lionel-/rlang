#ifndef RLANG_VECTOR_CHR_H
#define RLANG_VECTOR_CHR_H


SEXP r_chr_get(SEXP chr, size_t i);

bool chr_has(SEXP chr, const char* c_string);
void mut_chr_at(SEXP chr, R_len_t i, SEXP elt);

bool is_r_scalar_string(SEXP x);
SEXP r_new_scalar_string(const char* c_string);

bool is_string(SEXP x);
SEXP string(const char* c_string);

const char* r_c_string(SEXP scalar_chr);

SEXP chr_prepend(SEXP chr, SEXP r_new_scalar_string);
SEXP chr_append(SEXP chr, SEXP r_new_scalar_string);


#endif
