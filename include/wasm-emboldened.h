// WebAssembly C "emboldened" API. These functions abort in debug builds
// (when NDEBUG is not defined), and have undefined behavior in release
// builds (when NDEBUG is defined), if attempts are made to violate wasm
// invariants.

#ifndef WASM_EMBOLDENED_H
#define WASM_EMBOLDENED_H

#include "wasm-unchecked.h"

#ifdef __cplusplus
extern "C" {
#endif

// See the comments in "wasm.h".
#define own

///////////////////////////////////////////////////////////////////////////////

static inline own wasm_trap_t* wasm_func_call_emboldened(
  wasm_store_t* store,
  const wasm_func_t* func,
  wasm_val_vec_t args,
  wasm_val_vec_t results)
{
#ifndef NDEBUG
  return wasm_func_call(store, func, args, results);
#else
  return wasm_func_call_unchecked(func, args.data, results.data);
#endif
}

static inline own wasm_global_t* wasm_global_new_emboldened(
  wasm_store_t* store,
  const wasm_globaltype_t* type,
  const wasm_val_t* val)
{
#ifndef NDEBUG
  own wasm_trap_t* trap;
  own wasm_global_t* global = wasm_global_new(store, type, val, &trap);
  assert(global || !trap || !wasm_trap_is_compile_error(trap));
  return global;
#else
  return wasm_global_new_unchecked(store, type, val);
#endif
}

static inline void wasm_global_set_emboldened(
  wasm_store_t* store,
  wasm_global_t* global,
  const wasm_val_t* val)
{
#ifndef NDEBUG
  assert(!wasm_global_set(store, global, val));
#else
  wasm_global_set_unchecked(global, val);
#endif
}

static inline own wasm_table_t* wasm_table_new_emboldened(
  wasm_store_t* store,
  const wasm_tabletype_t* type,
  const wasm_val_t* init)
{
#ifndef NDEBUG
  own wasm_trap_t* trap;
  own wasm_table_t* table = wasm_table_new(store, type, init, &trap);
  assert(table || !trap || !wasm_trap_is_compile_error(trap));
  return table;
#else
  return wasm_table_new_unchecked(store, type, init);
#endif
}

static inline own wasm_table_t* wasm_table_new_anyref_emboldened(
  wasm_store_t* store,
  const wasm_tabletype_t* type,
  wasm_ref_t* init)
{
#ifndef NDEBUG
  own wasm_trap_t* trap;
  own wasm_table_t* table = wasm_table_new_anyref(store, type, init, &trap);
  assert(table || !trap || !wasm_trap_is_compile_error(trap));
  return table;
#else
  return wasm_table_new_anyref_unchecked(store, type, init);
#endif
}

static inline own wasm_table_t* wasm_table_new_funcref_emboldened(
  wasm_store_t* store,
  const wasm_tabletype_t* type,
  wasm_ref_t* init)
{
#ifndef NDEBUG
  own wasm_trap_t* trap;
  own wasm_table_t* table = wasm_table_new_funcref(store, type, init, &trap);
  assert(table || !trap || !wasm_trap_is_compile_error(trap));
  return table;
#else
  return wasm_table_new_funcref_unchecked(store, type, init);
#endif
}

static inline own wasm_ref_t* wasm_table_get_anyref_emboldened(
  wasm_store_t* store,
  const wasm_table_t* table,
  wasm_table_size_t index,
  own wasm_trap_t** trap)
{
#ifndef NDEBUG
  return wasm_table_get_anyref(store, table, index, trap);
#else
  return wasm_table_get_anyref_unchecked(store, table, index, trap);
#endif
}

static inline own wasm_ref_t* wasm_table_get_funcref_emboldened(
  wasm_store_t* store,
  const wasm_table_t* table,
  wasm_table_size_t index,
  own wasm_trap_t** trap)
{
#ifndef NDEBUG
  return wasm_table_get_funcref(store, table, index, trap);
#else
  return wasm_table_get_funcref_unchecked(store, table, index, trap);
#endif
}

static inline own wasm_trap_t* wasm_table_set_emboldened(
  wasm_store_t* store,
  wasm_table_t* table,
  wasm_table_size_t index,
  const wasm_val_t* val)
{
#ifndef NDEBUG
  return wasm_table_set(store, table, index, val);
#else
  return wasm_table_set_unchecked(store, table, index, val);
#endif
}

static inline own wasm_trap_t* wasm_table_set_anyref_emboldened(
  wasm_store_t* store,
  wasm_table_t* table,
  wasm_table_size_t index,
  wasm_ref_t* ref)
{
#ifndef NDEBUG
  return wasm_table_set_anyref(store, table, index, ref);
#else
  return wasm_table_set_anyref_unchecked(store, table, index, ref);
#endif
}

static inline own wasm_trap_t* wasm_table_set_funcref_emboldened(
  wasm_store_t* store,
  wasm_table_t* table,
  wasm_table_size_t index,
  wasm_ref_t* ref)
{
#ifndef NDEBUG
  return wasm_table_set_funcref(store, table, index, ref);
#else
  return wasm_table_set_funcref_unchecked(store, table, index, ref);
#endif
}

static inline bool wasm_table_grow_emboldened(
  wasm_store_t* store,
  wasm_table_t* table,
  wasm_table_size_t delta,
  const wasm_val_t* init)
{
#ifndef NDEBUG
  bool success;
  own wasm_trap_t* trap = wasm_table_grow(store, table, delta, init, &success);
  assert(!trap);
  return success;
#else
  (void) store;
  return wasm_table_grow_unchecked(table, delta, init);
#endif
}

static inline bool wasm_table_grow_anyref_emboldened(
  wasm_store_t* store,
  wasm_table_t* table,
  wasm_table_size_t delta,
  wasm_ref_t* init)
{
#ifndef NDEBUG
  bool success;
  own wasm_trap_t* trap =
    wasm_table_grow_anyref(store, table, delta, init, &success);
  assert(!trap);
  return success;
#else
  (void) store;
  return wasm_table_grow_anyref_unchecked(table, delta, init);
#endif
}

static inline bool wasm_table_grow_funcref_emboldened(
  wasm_store_t* store,
  wasm_table_t* table,
  wasm_table_size_t delta,
  wasm_ref_t* init)
{
#ifndef NDEBUG
  bool success;
  own wasm_trap_t* trap =
    wasm_table_grow_funcref(store, table, delta, init, &success);
  assert(!trap);
  return success;
#else
  (void) store;
  return wasm_table_grow_funcref_unchecked(table, delta, init);
#endif
}

static inline own wasm_instance_t* wasm_instance_new_emboldened(
  wasm_store_t* store,
  const wasm_module_t* module,
  wasm_extern_vec_t imports,
  own wasm_trap_t** trap)
{
#ifndef NDEBUG
  return wasm_instance_new(store, module, imports, trap);
#else
  return wasm_instance_new_unchecked(store, module, imports.data, trap);
#endif
}

///////////////////////////////////////////////////////////////////////////////

#undef own

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // #ifdef WASM_EMBOLDENED_H
