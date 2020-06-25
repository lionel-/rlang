#include <rlang.h>
#include "internal.h"


sexp* rlang_env_get(sexp* env, sexp* nm) {
  sexp* sym = r_str_as_symbol(r_chr_get(nm, 0));
  sexp* out = KEEP(r_env_find(env, sym));

  // Trigger `symbol not found` error if needed
  if (out == r_unbound_sym) {
    r_eval(sym, r_empty_env);
    r_abort("Internal error: `rlang_env_get()` should have failed earlier");
  }

  if (r_typeof(out) == r_type_promise) {
    out = r_eval(out, r_empty_env);
  }

  FREE(1);
  return out;
}

sexp* rlang_env_has(sexp* env, sexp* nms, sexp* inherit) {
  if (r_typeof(nms) != r_type_character) {
    r_abort("`nms` must be a character vector.");
  }
  if (r_typeof(inherit) != r_type_logical) {
    r_abort("`inherit` must be a logical value.");
  }

  r_ssize n = r_length(nms);
  sexp* out = KEEP(r_new_vector(r_type_logical, n));

  int* p_out = r_lgl_deref(out);
  sexp* const * p_nms = r_chr_deref(nms);

  if (r_lgl_get(inherit, 0)) {
    for (r_ssize i = 0; i < n; ++i) {
      sexp* sym = r_str_as_symbol(p_nms[i]);
      p_out[i] = r_env_has_anywhere(env, sym);
    }
  } else {
    for (r_ssize i = 0; i < n; ++i) {
      sexp* sym = r_str_as_symbol(p_nms[i]);
      p_out[i] = r_env_has(env, sym);
    }
  }

  r_poke_names(out, nms);
  FREE(1);
  return out;
}

static sexp* env_poke_or_zap(sexp* env, sexp* sym, sexp* value);

sexp* rlang_env_poke(sexp* env, sexp* nm, sexp* value, sexp* inherit, sexp* create) {
  if (!r_is_string(nm)) {
    r_abort("`nm` must be a string.")
  }
  if (!r_is_bool(inherit)) {
    r_abort("`inherit` must be a string.")
  }
  if (!r_is_bool(create)) {
    r_abort("`create` must be a string.")
  }

  bool c_inherit = r_lgl_get(inherit, 0);
  sexp* sym = r_str_as_symbol(r_chr_get(nm, 0));

  sexp* old;
  if (c_inherit) {
    old = r_env_find_anywhere(env, sym);
  } else {
    old = r_env_find(env, sym);
  }
  if (old == r_unbound_sym) {
    if (!c_create) {
      r_abort("Can't find existing binding in `env` for \"%s\".",
              r_sym_get_c_string(sym));
    }
    old = rlang_zap;
  }
  KEEP(old);

  if (c_inherit) {
    r_abort("todo");
  } else {
    env_poke_or_zap(env, sym, value);
  }

  ;

  FREE(1);
}

static
void env_poke_or_zap(sexp* env, sexp* sym, sexp* value) {
  if (value == rlang_zap) {
    r_env_unbind(env, sym);
  } else {
    r_env_poke(env, sym);
  }
}

static
void scope_poke(sexp* env) {
  ;
}

sexp* rlang_env_unbind(sexp* env, sexp* names, sexp* inherits) {
  if (r_typeof(env) != r_type_environment) {
    r_abort("`env` must be an environment");
  }
  if (r_typeof(names) != r_type_character) {
    r_abort("`names` must be a character vector");
  }
  if (!r_is_scalar_logical(inherits)) {
    r_abort("`inherits` must be a scalar logical vector");
  }

  if (*r_lgl_deref(inherits)) {
    r_env_unbind_anywhere_names(env, names);
  } else {
    r_env_unbind_names(env, names);
  }

  return r_null;
}
