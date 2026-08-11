*This project has been created as part of the 42 curriculum by dmaurici , yakumar.*

# PUSH_SWAP

---

## Description

Push_swap is a sorting project developed as part of the 42 curriculum.  
The goal of this project is to sort a stack of integers using a limited set of stack operations and output the shortest reasonable sequence of instructions.

The program receives integers as arguments, validates the input, normalizes the values into indexes, chooses a sorting strategy, and prints the operations needed to sort stack `a` in ascending order.

This project reinforces fundamental concepts such as:
- argument parsing and input validation
- memory management
- doubly linked lists
- stack manipulation
- sorting algorithms
- algorithmic complexity
- operation counting and benchmarking

---

## Rules

The program works with two stacks:

- `a`: contains the input numbers at the beginning
- `b`: starts empty and is used as an auxiliary stack

The goal is to sort stack `a` in ascending order using only the allowed Push_swap operations.

### Allowed Operations

| Operation | Description |
|---|---|
| `sa` | Swap the first two elements of stack `a` |
| `sb` | Swap the first two elements of stack `b` |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push the top element of `b` to `a` |
| `pb` | Push the top element of `a` to `b` |
| `ra` | Rotate stack `a` upward |
| `rb` | Rotate stack `b` upward |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack `a` |
| `rrb` | Reverse rotate stack `b` |
| `rrr` | `rra` and `rrb` at the same time |

---

## Project Structure

The project is divided by responsibility:

### Core Program
- `main.c` — program entry point and strategy execution
- `push_swap.h` — shared structures, enums, and function prototypes
- `Makefile` — compilation rules

### Parsing and Errors
- `parse.c` — argument processing and stack creation
- `parse_utils.c` — validation helpers and flag handling
- `error.c` — centralized error handling

### Stack Management
- `stack_alloc.c` — allocation and cleanup of nodes, stacks, and program state
- `stack_core.c` — stack insertion, removal, sorted check, and minimum lookup

### Operations
- `op_swap.c`
- `op_push.c`
- `op_rotate.c`
- `op_reverse.c`
- `op_print.c`

Each operation updates the stack, prints the corresponding instruction, and updates the operation counters used for benchmarking.

### Sorting
- `rank_values.c` — normalizes raw values into indexes
- `measure_disorder.c` — calculates the disorder ratio of the input
- `sort_helpers.c` — shared helpers for small sorting
- `sort_simple.c` — simple selection-style sorting and 2/3 element cases
- `sort_small.c` — optimized sorting for 4 and 5 elements
- `sort_medium.c` — chunk-based sorting
- `sort_complex.c` — radix sorting
- `sort_adaptive.c` — automatic strategy selection

### Benchmarking
- `bench_print.c` — prints operation counts and strategy information to `stderr`

---

## Data Structures

The project uses a doubly linked list to represent each stack.

Each node stores:
```c
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;
```

- `value` is the original integer from the input.
- `index` is the normalized rank of that value.
- `next` and `prev` connect the node inside the stack.

Each stack stores:
```c
typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;
```

The full program state stores both stacks, the chosen strategy, benchmark mode, disorder value, and operation counters.

---

## Input Validation

The parser accepts integers passed either separately or inside quoted strings.

Examples:
```bash
./push_swap 3 2 1
./push_swap "3 2 1"
./push_swap "3 2" 1
```

The program rejects:
- non-numeric arguments
- empty strings
- arguments containing only spaces
- duplicate numbers
- numbers outside the `int` range
- unknown flags

On invalid input, the program prints:
```text
Error
```

to `stderr`.

If no arguments are provided, the program exits without output.

---

## Normalization

Before sorting, every value is converted into a normalized index.

Example:
```text
values:  40  -3  10
indexes:  2   0   1
```

This means:
```text
-3  -> 0
10  -> 1
40  -> 2
```

Normalization allows the algorithms to work with compact positive indexes from `0` to `n - 1`, instead of raw integers that may be negative or have large gaps.

---

## Disorder Measurement

The program measures disorder by counting inverted pairs.

An inverted pair is a pair `(i, j)` where `i` appears before `j`, but:
```text
index[i] > index[j]
```

The result is a ratio between `0.0` and `1.0`.

- `0.0` means the stack is already sorted
- `1.0` means the stack is fully reversed

This value is used by adaptive mode to decide which sorting strategy to use.

---

## Sorting Strategies

The program supports several strategies.

### Simple Strategy — `--simple`

The simple strategy handles small cases directly and uses a selection-sort style method for larger inputs.

For each step:
1. Find the minimum index in stack `a`
2. Rotate it to the top using the cheaper direction
3. Push it to stack `b`
4. Push all elements back to `a`

Complexity:
```text
O(n²)
```

This method is simple and correct, but not efficient for large inputs.

---

### Medium Strategy — `--medium`

The medium strategy uses chunk sorting.

It splits the normalized index range into chunks and pushes each chunk from `a` to `b`.  
Then it repeatedly brings the maximum index in `b` to the top and pushes it back to `a`.

Complexity target:
```text
O(n√n)
```

This method is useful for medium-sized inputs and often produces better move counts than simple selection sort.

---

### Complex Strategy — `--complex`

The complex strategy uses binary radix sort over normalized indexes.

For each bit:
1. Elements with bit `0` are pushed to `b`
2. Elements with bit `1` are rotated inside `a`
3. Elements in `b` are pushed back to `a`

Complexity:
```text
O(n log n)
```

Radix sort is predictable and reliable for large inputs, although it is not always the lowest possible move-count strategy.

---

### Adaptive Strategy — `--adaptive`

Adaptive strategy automatically chooses a sorting method.

The intended design is based on disorder:

| Disorder range | Strategy | Complexity target |
|---|---|---|
| `disorder < 0.2` | Simple / low-disorder method | `O(n²)` |
| `0.2 <= disorder < 0.5` | Medium chunk method | `O(n√n)` |
| `disorder >= 0.5` | Complex radix method | `O(n log n)` |

Tiny inputs are handled separately with optimized small-case logic.

This strategy exists to avoid using the same algorithm for every input. A nearly sorted stack should not necessarily be treated the same way as a highly disordered random stack.

---

## Flags

The program supports the following optional flags:

| Flag | Description |
|---|---|
| `--simple` | Forces the simple sorting strategy |
| `--medium` | Forces the medium chunk strategy |
| `--complex` | Forces the radix strategy |
| `--adaptive` | Uses adaptive strategy selection |
| `--bench` | Prints benchmark information to `stderr` |

Default behavior uses adaptive mode.

Examples:
```bash
./push_swap --simple 3 2 1
./push_swap --medium "5 1 4 2 3"
./push_swap --complex 100 42 -3 7
./push_swap --adaptive 3 2 1
./push_swap --bench 3 2 1
```

---

## Benchmark Mode

Benchmark mode prints extra information to `stderr`.

Example:
```bash
./push_swap --bench 3 2 1
```

The normal operations are still printed to `stdout`, while benchmark data is printed to `stderr`.

Benchmark output includes:
- disorder percentage
- chosen strategy
- total operation count
- count of each individual operation

This keeps benchmark information separate from the operation list expected by the checker.

---

## Compilation

To compile the project:

```bash
make
```

This builds the `push_swap` executable.

To remove object files:

```bash
make clean
```

To remove object files and the executable:

```bash
make fclean
```

To rebuild from scratch:

```bash
make re
```

---

## Usage

Run the program with a list of integers:

```bash
./push_swap 3 2 1
```

Example output:
```text
sa
rra
```

Use the checker:
```bash
ARG="3 2 1"; ./push_swap $ARG | ./checker_linux $ARG
```

Expected checker result:
```text
OK
```

---

## Testing

Basic tests:

```bash
./push_swap
./push_swap 1 2 3
./push_swap 3 2 1
./push_swap "3 2 1"
./push_swap "3 2" 1
```

Error tests:

```bash
./push_swap ""
./push_swap "     "
./push_swap 1 2 2
./push_swap 2147483648
./push_swap -2147483649
./push_swap 1 2 a
```

Memory test:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./push_swap "3 2 1"
```

---

## Complexity Summary

| Strategy | Main idea | Complexity |
|---|---|---|
| Simple | Selection-style sorting | `O(n²)` |
| Medium | Chunk sorting | `O(n√n)` target |
| Complex | Binary radix sort | `O(n log n)` |
| Adaptive | Chooses based on size/disorder | Depends on selected strategy |

---

## Notes

The current implementation focuses on correctness, clean structure, and explainable algorithm choices.

Radix sort gives predictable results for large inputs. Chunk sort can perform better for medium or partially ordered input. Simple sorting is useful for small cases and as a clear baseline.

The adaptive strategy should be kept aligned with the subject requirements: low disorder should use an `O(n²)` method, medium disorder an `O(n√n)` method, and high disorder an `O(n log n)` method.

---

## Resources

### References
- 42 Push_swap subject documentation
- The C Programming Language — Kernighan & Ritchie
- Linux manual pages
- Algorithm references for selection sort, chunk sorting, and radix sort

### AI Usage

AI (ChatGPT) was used as a support tool during the development of this project.

It was mainly used for:
- understanding stack operations and linked list behavior
- debugging parsing and memory ownership issues
- comparing sorting strategies
- improving explanation of algorithmic complexity
- preparing for evaluation questions
