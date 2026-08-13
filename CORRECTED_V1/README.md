*This project has been created as part of the 42 curriculum by dmaurici, yakumar.*

# Push_swap

---

## Description

Push_swap is a sorting project from the 42 curriculum.  
The goal of the project is to sort a stack of integers using only a limited set of stack operations, while printing the sequence of operations needed to sort the stack.

The program receives integers as command-line arguments, validates the input, stores the numbers in stack `a`, and uses stack `b` as an auxiliary stack.  
The final output is a list of valid push_swap instructions that, when executed in order, sort stack `a` in ascending order.

This project focuses on:

- input parsing and validation
- linked list manipulation
- stack operations
- memory management
- algorithm design
- complexity analysis
- operation-count optimization

---

## Instructions

### Compilation

To compile the project, run:

```bash
make
```

This creates the executable:

```bash
./push_swap
```

To remove object files:

```bash
make clean
```

To remove object files and the executable:

```bash
make fclean
```

To rebuild the project from scratch:

```bash
make re
```

---

### Execution

Run the program with a list of integers:

```bash
./push_swap 3 2 1
```

Example output:

```text
sa
rra
```

The program also supports quoted input:

```bash
./push_swap "3 2 1"
```

Mixed quoted and non-quoted input is also supported:

```bash
./push_swap "5 4" 3 "2 1"
```

If the input is already sorted, the program prints nothing:

```bash
./push_swap 1 2 3
```

---

### Available Flags

This implementation includes several optional flags:

```bash
--simple
--medium
--complex
--adaptive
--bench
```

Examples:

```bash
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
./push_swap --bench 5 4 3 2 1
```

The default strategy is:

```text
adaptive
```

The `--bench` flag prints benchmark information to standard error, such as disorder percentage, selected strategy, total operation count, and per-operation counters.

---

### Checker Usage

If a checker executable is available, the result can be tested like this:

```bash
ARG="3 2 1"
./push_swap $ARG | ./checker_linux $ARG
```

Expected result:

```text
OK
```

---

## Input Validation

The parser rejects invalid input.

Invalid input includes:

- non-numeric arguments
- empty strings
- strings containing only spaces
- duplicate numbers
- numbers greater than `INT_MAX`
- numbers smaller than `INT_MIN`
- invalid flags

Examples:

```bash
./push_swap 1 2 a
./push_swap ""
./push_swap "   "
./push_swap 1 2 2
./push_swap 2147483648
./push_swap -2147483649
./push_swap --unknown 3 2 1
```

Expected output:

```text
Error
```

The error message is printed to standard error.

---

## Project Structure

The project is organized by responsibility:

| File | Purpose |
|---|---|
| `main.c` | Program entry point and strategy dispatch |
| `push_swap.h` | Main header, structs, enums, and prototypes |
| `parse.c` | Argument parsing and parser flow |
| `parse_utils.c` | Parser validation helpers |
| `error.c` | Centralized error handling |
| `stack_alloc.c` | Allocation and freeing of stacks and nodes |
| `stack_core.c` | Core stack operations such as push, pop, sorted check, and min search |
| `rank_values.c` | Normalization of input values into indexes |
| `measure_disorder.c` | Disorder/inversion-ratio calculation |
| `op_swap.c` | Swap operations |
| `op_push.c` | Push operations |
| `op_rotate.c` | Rotate operations |
| `op_reverse.c` | Reverse-rotate operations |
| `op_print.c` | Operation output and total operation printing |
| `sort_simple.c` | Simple sorting strategy |
| `sort_helpers.c` | Sorting helper functions |
| `sort_small.c` | Sorting logic for 4 and 5 elements |
| `sort_medium.c` | Chunk-based sorting strategy |
| `sort_complex.c` | Binary radix sorting strategy |
| `sort_adaptive.c` | Automatic strategy selection |
| `bench_print.c` | Benchmark/debug output |

---

## Technical Choices

### Stack Representation

The stacks are implemented using doubly linked lists.

Each node stores:

- the original integer value
- the normalized index
- a pointer to the next node
- a pointer to the previous node

Each stack stores:

- a pointer to the top node
- a pointer to the bottom node
- the current size

A doubly linked list was chosen because several push_swap operations need efficient access to both ends of the stack.  
For example, rotate and reverse-rotate operations are easier and cleaner to implement when both `top` and `bottom` are directly available.

---

### Normalization

Before sorting, the input values are normalized into indexes.

Example:

```text
Input values:      40  -3  10
Sorted order:      -3  10  40
Normalized index:   2   0   1
```

The original values remain stored in the nodes, but the sorting algorithms mainly use the normalized indexes.

Normalization is useful because:

- negative numbers become easier to handle
- very large values do not affect sorting logic
- gaps between values do not matter
- radix sort becomes simple and reliable
- every value becomes part of the range `0` to `n - 1`

---

## Algorithm Explanation and Justification

This project uses several sorting strategies.  
The goal is to choose algorithms that are correct, understandable, and reasonably efficient for different input sizes and disorder levels.

---

### Simple Sort — `O(n²)`

The simple strategy is mainly used for small inputs.

For 2 elements, the program swaps the values if they are in the wrong order.  
For 3 elements, it uses direct case handling.  
For 4 and 5 elements, it pushes the smallest values to stack `b`, sorts the remaining 3 elements in stack `a`, and then pushes the saved values back to stack `a`.

For larger inputs, the simple strategy works like a selection sort:

1. Find the smallest index in stack `a`
2. Rotate it to the top using the cheapest direction
3. Push it to stack `b`
4. Repeat until all values are moved
5. Push everything back to stack `a`

Justification:

- very effective for tiny inputs
- simple and reliable
- easy to reason about
- useful as a baseline algorithm
- not ideal for large inputs because repeated scanning gives `O(n²)` behavior

---

### Small Sort

Small sort is used for 4 and 5 elements.

The idea is:

1. Move the smallest one or two elements to stack `b`
2. Sort the remaining three elements in stack `a`
3. Push the saved elements back from `b` to `a`

For 4 elements, one minimum value is pushed to `b`.  
For 5 elements, two minimum values are pushed to `b`.

Justification:

- avoids using a heavy algorithm for very small inputs
- produces fewer operations than a generic strategy
- keeps the logic simple and predictable

---

### Medium Sort — `O(n√n)`

The medium strategy is chunk-based.

The normalized index range is divided into chunks.  
The program pushes values from stack `a` to stack `b` chunk by chunk.  
After all chunks are pushed, it repeatedly brings the largest value in stack `b` to the top and pushes it back to stack `a`.

General process:

1. Calculate a chunk size based on `sqrt(n)`
2. Search stack `a` for values inside the current chunk range
3. Push matching values to stack `b`
4. Rotate stack `a` when the top value is not in the current chunk
5. Once all chunks are in `b`, find the maximum index in `b`
6. Rotate `b` in the cheapest direction
7. Push the maximum back to `a`
8. Repeat until `b` is empty

This works because pushing maximum values back first places larger values deeper in stack `a`, while smaller values are pushed later and end up closer to the top.

Justification:

- better than simple sort for medium-sized inputs
- suitable for around 100 numbers
- chunking reduces the cost compared with repeatedly selecting only one minimum
- move count depends on chunk size and input order, but it is generally practical for medium inputs

---

### Complex Sort — `O(n log n)`

The complex strategy uses binary radix sort on normalized indexes.

Because every value has been normalized into the range `0` to `n - 1`, each index can be sorted by examining its binary representation.

For each bit position:

1. Check the selected bit of the top index in stack `a`
2. If the bit is `0`, push the element to stack `b`
3. If the bit is `1`, rotate stack `a`
4. After one full pass, push all elements from `b` back to `a`
5. Repeat for all required bits

Example:

```text
index 5 = binary 101
```

The algorithm checks bit `0`, then bit `1`, then bit `2`, and continues until all necessary bits have been processed.

Justification:

- reliable for large inputs
- predictable operation count
- works well with normalized indexes
- avoids complicated value comparisons
- suitable for 500 numbers
- not always optimal for small or nearly sorted input, because it still performs all bit passes

---

### Adaptive Sort

The adaptive strategy selects a sorting algorithm automatically.

It first checks if the stack is already sorted.  
If so, it returns immediately and prints no operations.

For small inputs, it uses the specialized small sorting logic.  
For medium inputs, it uses the chunk-based strategy.  
For large and highly disordered inputs, it uses radix sort.

The project also calculates a disorder value based on inverted pairs:

```text
0.0 = already sorted
1.0 = fully reversed
```

The intended adaptive idea is:

```text
small input      -> small direct sorting
low disorder     -> simple or near-sorted strategy
medium disorder  -> chunk strategy
high disorder    -> radix strategy
```

Justification:

- small inputs should not use large-input algorithms
- nearly sorted input should avoid unnecessary radix passes
- medium-sized input benefits from chunk sorting
- large disordered input benefits from radix stability and predictability

---

## Benchmark Mode

Benchmark mode is enabled with:

```bash
--bench
```

Example:

```bash
./push_swap --bench 3 2 1
```

Benchmark mode prints:

- disorder percentage
- selected strategy
- total number of operations
- individual operation counters

Benchmark output is printed to standard error, not standard output.

This is important because standard output must contain only valid push_swap operations.  
If benchmark text were printed to standard output, the checker would treat it as an invalid instruction.

---

## Testing

### Basic Correctness

```bash
ARG="3 2 1"
./push_swap $ARG | ./checker_linux $ARG
```

Expected:

```text
OK
```

### Sorted Input

```bash
./push_swap 1 2 3
```

Expected: no output.

### Invalid Input

```bash
./push_swap 1 2 a
```

Expected:

```text
Error
```

### Integer Limits

Valid:

```bash
./push_swap 2147483647 -2147483648 0
```

Invalid:

```bash
./push_swap 2147483648
./push_swap -2147483649
```

### Memory Testing

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap "1 2 a"
```

Expected:

```text
All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors
```

### Random Testing

```bash
for i in {1..100}; do \
	ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' '); \
	./push_swap $ARG | ./checker_linux $ARG; \
done
```

Expected result for every run:

```text
OK
```

---


## Contributions

This project was developed collaboratively by `dmaurici` and `yakumar`.

### dmaurici

Main contributions:

- worked on argument parsing and input validation
- worked on stack allocation, memory management, and error handling
- worked on value normalization and disorder measurement
- contributed to the implementation and testing of the sorting strategies
- worked on benchmark mode, operation counting, and edge-case testing
- performed Valgrind testing and parser validation
- contributed to project documentation and README preparation

### yakumar

Main contributions:

- worked on stack operations and linked-list manipulation
- contributed to the implementation and optimization of the sorting algorithms
- worked on medium and complex sorting strategies
- contributed to adaptive strategy behavior and testing
- tested sorting correctness and operation counts
- contributed to debugging, code review, and project documentation

Both contributors reviewed and tested the final project together.

---

## Resources

### References

- The C Programming Language — Brian W. Kernighan and Dennis M. Ritchie
- Linux manual pages:
  - `man malloc`
  - `man free`
  - `man write`
  - `man exit`
- 42 Push_swap subject
- 42 Norm documentation
- Visualgo — Sorting algorithms
- Wikipedia — Stack data structure
- Wikipedia — Radix sort
- Wikipedia — Time complexity
- GeeksforGeeks — Linked list data structure
- GeeksforGeeks — Radix sort
- GeeksforGeeks — Time complexity analysis

---

### AI Usage

AI tools, including ChatGPT, were used as support during the development and documentation of this project.

AI was used for:

- explaining algorithmic concepts such as radix sort, chunk sorting, normalization, and inversion ratio
- reviewing algorithm choices and complexity tradeoffs
- identifying parser edge cases
- improving understanding of memory ownership during error handling
- suggesting Valgrind tests
- helping create test scripts for correctness, limits, and memory leaks
- improving README structure and wording

AI was not used as a replacement for understanding the project.  
All code was reviewed, tested, and adapted manually by the authors.

---

## Final Notes

Push_swap is not only a sorting project.  
It is also a project about constraints, correctness, and clean program behavior.

A correct implementation must:

- reject invalid input
- avoid memory leaks
- print only valid operations
- sort all valid inputs
- keep the operation count within acceptable limits
- explain and justify the selected algorithms
