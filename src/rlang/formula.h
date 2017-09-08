#ifndef RLANG_FORMULA_H
#define RLANG_FORMULA_H


SEXP rlang_is_formulaish(SEXP x, SEXP scoped, SEXP lhs);
SEXP r_f_rhs(SEXP f);
SEXP r_f_lhs(SEXP f);
SEXP r_f_env(SEXP f);
bool r_f_has_env(SEXP f);

SEXP r_set_formula_env(SEXP f, SEXP new_env);
SEXP r_poke_formula_env(SEXP f, SEXP new_env);


#endif
