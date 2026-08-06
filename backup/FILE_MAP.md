# File Map — where to look for what

Grouped by responsibility. Alphabetical order within the file listing now
matches this grouping, so `ls *.c` roughly reads top-to-bottom in this order.

## Entry point & errors
| File | What's in it |
|---|---|
| `main.c` | `main()`, strategy dispatch, top-level flow |
| `error.c` | `error_exit()` — the one place `Error` ever gets printed |

## Stack foundation
| File | What's in it |
|---|---|
| `stack_alloc.c` | `node_new`, `stack_new`, `stack_free`, `ps_new`, `ps_free` — allocate/free lifecycle |
| `stack_core.c` | `stack_push_top`, `stack_push_bottom`, `stack_pop_top`, `stack_is_sorted`, `stack_min` — the primitives every operation is built from |

## Parsing (argv -> validated stack)
| File | What's in it |
|---|---|
| `parse.c` | `parse_args`, `apply_arg`, `parse_numbers`, `parse_token`, `finalize_parse` |
| `parse_utils.c` | `is_valid_int_str`, `in_int_range`, `has_duplicate`, `is_flag`, `flag_to_strategy` |

## Ranking & metrics (runs once, before any sort)
| File | What's in it |
|---|---|
| `rank_values.c` | `normalize()` — assigns rank 0..n-1 to every node |
| `measure_disorder.c` | `compute_disorder()` — the required disorder ratio |

## The 11 operations
| File | What's in it |
|---|---|
| `op_swap.c` | `op_sa`, `op_sb`, `op_ss` |
| `op_push.c` | `op_pa`, `op_pb` |
| `op_rotate.c` | `op_ra`, `op_rb`, `op_rr` |
| `op_reverse.c` | `op_rra`, `op_rrb`, `op_rrr` |
| `op_print.c` | `print_op()` — the single gate every operation prints through (currently just prints; this is where you'll add the --count check live) |

## Sorting strategies
| File | What's in it |
|---|---|
| `sort_simple.c` | `sort_two`, `sort_three`, `sort_simple` — O(n²) |
| `sort_helpers.c` | `find_min_pos`, `rotate_to_top` — shared by simple + small |
| `sort_small.c` | `sort_small` — dedicated n=4/5 path |
| `sort_medium.c` | `sort_medium` — O(n√n) chunk sort |
| `sort_complex.c` | `sort_complex` — O(n log n) radix sort |
| `sort_adaptive.c` | `sort_adaptive` — picks one of the above by size/disorder |

## Reporting
| File | What's in it |
|---|---|
| `bench_print.c` | `bench_print()` — the `--bench` report |

---

## Fast lookup by "I want to..."

- **...add a new flag** → `parse_utils.c` (`is_flag`) + `parse.c` (`apply_arg`) + `push_swap.h` (`t_ps` field)
- **...change what an operation prints or does** → the matching `op_*.c` file
- **...suppress/modify all operation output at once** → `op_print.c` only (this is the whole reason it's split out separately)
- **...change which algorithm handles which size/disorder** → `sort_adaptive.c`
- **...add a new sort strategy** → new `sort_*.c` file + `push_swap.h` + `main.c`'s `run_strategy` + `sort_adaptive.c` if it should be reachable adaptively
- **...change error behavior** → `error.c` (there's only one function, one place)
- **...change how numbers are validated** → `parse_utils.c`
- **...change memory allocation/cleanup** → `stack_alloc.c`
