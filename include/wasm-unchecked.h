// WebAssembly C unchecked API. These functions exhibit undefined behavior
// if attempts are made to violate wasm invariants.

#ifndef WASM_UNCHECKED_H
#define WASM_UNCHECKED_H

#include "wasm.h"

#ifdef __cplusplus
extern "C" {
#endif

// See the comments in "wasm.h".
#define own

/// Similar to `wasm_func_call`, but with undefined behavior instead of
/// reporting errors.
///
/// # Safety
///
/// This function has undefined behavior in response to any errors.
WASM_API_EXTERN own wasm_trap_t* wasm_func_call_unchecked(
  const wasm_func_t*,
  const wasm_val_t args[],
  wasm_val_t results[]);

/// Similar to `wasm_global_new`, but with undefined behavior instead of
/// reporting errors.
///
/// # Safety
///
/// This function has undefined behavior in response to any errors.
WASM_API_EXTERN own wasm_global_t* wasm_global_new_unchecked(
  wasm_store_t*, const wasm_globaltype_t*, const wasm_val_t*);

/// Similar to `wasm_global_set`, but with undefined behavior instead of
/// reporting errors.
///
/// # Safety
///
/// This function has undefined behavior in response to any errors.
WASM_API_EXTERN void wasm_global_set_unchecked(wasm_global_t*, const wasm_val_t*);

/// Similar to `wasm_table_new`, but with undefined behavior instead of
/// reporting errors.
///
/// # Safety
///
/// This function has undefined behavior in response to any errors.
WASM_API_EXTERN own wasm_table_t* wasm_table_new_unchecked(
  wasm_store_t*, const wasm_tabletype_t*, const wasm_val_t* init);

/// Similar to `wasm_table_new_anyref`, but with undefined behavior instead of
/// reporting errors.
///
/// # Safety
///
/// This function has undefined behavior in response to any errors.
WASM_API_EXTERN own wasm_table_t* wasm_table_new_anyref_unchecked(
  wasm_store_t*, const wasm_tabletype_t*, wasm_ref_t* init);

/// Similar to `wasm_table_new_funcref`, but with undefined behavior instead of
/// reporting errors.
///
/// # Safety
///
/// This function has undefined behavior in response to any errors.
WASM_API_EXTERN own wasm_table_t* wasm_table_new_funcref_unchecked(
  wasm_store_t*, const wasm_tabletype_t*, wasm_ref_t* init);

/// Similar to `wasm_table_get_anyref`, but with undefined behavior instead of
/// reporting errors.
///
/// # Safety
///
/// This function has undefined behavior in response to any errors.
WASM_API_EXTERN own wasm_ref_t* wasm_table_get_anyref_unchecked(
  wasm_store_t*, const wasm_table_t*, wasm_table_size_t index, own wasm_trap_t** trap
);

/// Similar to `wasm_table_get_funcref`, but with undefined behavior instead of
/// reporting errors.
///
/// # Safety
///
/// This function has undefined behavior in response to any errors.
WASM_API_EXTERN own wasm_ref_t* wasm_table_get_funcref_unchecked(
  wasm_store_t*, const wasm_table_t*, wasm_table_size_t index, own wasm_trap_t** trap
);

/// Similar to `wasm_table_set`, but with undefined behavior instead of
/// reporting errors.
///
/// # Safety
///
/// This function has undefined behavior in response to any errors.
WASM_API_EXTERN own wasm_trap_t* wasm_table_set_unchecked(
  wasm_store_t*, wasm_table_t*, wasm_table_size_t index, const wasm_val_t*
);

/// Similar to `wasm_table_set_anyref`, but with undefined behavior instead of
/// reporting errors.
///
/// # Safety
///
/// This function has undefined behavior in response to any errors.
WASM_API_EXTERN own wasm_trap_t* wasm_table_set_anyref_unchecked(
  wasm_store_t*, wasm_table_t*, wasm_table_size_t index, wasm_ref_t*
);

/// Similar to `wasm_table_set_funcref`, but with undefined behavior instead of
/// reporting errors.
///
/// # Safety
///
/// This function has undefined behavior in response to any errors.
WASM_API_EXTERN own wasm_trap_t* wasm_table_set_funcref_unchecked(
  wasm_store_t*, wasm_table_t*, wasm_table_size_t index, wasm_ref_t*
);

/// Similar to `wasm_table_grow`, but with undefined behavior instead of
/// reporting errors.
///
/// # Safety
///
/// This function has undefined behavior in response to any errors.
WASM_API_EXTERN bool wasm_table_grow_unchecked(
  wasm_table_t*, wasm_table_size_t delta, const wasm_val_t* init
);

/// Similar to `wasm_table_grow_anyref`, but with undefined behavior instead of
/// reporting errors.
///
/// # Safety
///
/// This function has undefined behavior in response to any errors.
WASM_API_EXTERN bool wasm_table_grow_anyref_unchecked(
  wasm_table_t*, wasm_table_size_t delta, wasm_ref_t* init
);

/// Similar to `wasm_table_grow_funcref`, but with undefined behavior instead of
/// reporting errors.
///
/// # Safety
///
/// This function has undefined behavior in response to any errors.
WASM_API_EXTERN bool wasm_table_grow_funcref_unchecked(
  wasm_table_t*, wasm_table_size_t delta, wasm_ref_t* init
);

/// Similar to `wasm_instance_new`, but with undefined behavior instead of
/// reporting errors.
///
/// # Safety
///
/// This function has undefined behavior in response to any errors.
WASM_API_EXTERN own wasm_instance_t* wasm_instance_new_unchecked(
  wasm_store_t*, const wasm_module_t*,
  const wasm_extern_t* const imports[],
  own wasm_trap_t** trap
);

///////////////////////////////////////////////////////////////////////////////

#undef own

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // #ifdef WASM_UNCHECKED_H
