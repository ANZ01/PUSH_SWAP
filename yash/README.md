*This project has been created as part of the 42 curriculum by dmaurici, yakumar.*

## Description

Push_swap is a sorting algorithm project where two stacks (a and b) and a limited
set of operations are used to sort a list of integers in ascending order with the
fewest possible moves. The program outputs the sequence of operations needed to sort
stack a.

The available operations are: sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr.

## Instructions

### Compilation

```bash
# Build push_swap
make

# Clean objects
make clean

# Full clean
make fclean

# Rebuild
make re
```

Drop your libft (source files + its own Makefile, producing `libft.a`) into
the `libft/` folder before building; the project Makefile calls it automatically.

### Usage

```bash
# Basic sort
./push_swap 5 3 1 4 2

# Force a specific algorithm
./push_swap --simple   5 3 1 4 2
./push_swap --medium   5 3 1 4 2
./push_swap --complex  5 3 1 4 2
./push_swap --adaptive 5 3 1 4 2

# Benchmark mode (metrics printed to stderr)
./push_swap --bench 5 3 1 4 2

# Hide ops, show only metrics
./push_swap --bench 5 3 1 4 2 2>&1 1>/dev/null

# Count operations
./push_swap 5 3 1 4 2 | wc -l

# Large input test
shuf -i 0-9999 -n 500 > args.txt
./push_swap $(cat args.txt) | wc -l
```

### Error cases

```bash
./push_swap 1 2 abc     # Error — not an integer
./push_swap 1 2 2       # Error — duplicate
./push_swap 1 99999999999  # Error — out of range
```

## Algorithms

### 1. Simple — O(n²) — Selection Sort

Repeatedly finds the current minimum of a, rotates it to the top the
cheap way, and pushes it to b. Because each extraction takes the
current minimum, b fills up in descending order top-to-bottom, so
unwinding it with plain `pa`'s rebuilds a in ascending order with no
extra bookkeeping needed on the way back in. Each of the n selections
costs up to O(n) rotations, giving O(n²) total.
Used when: `--simple` flag or disorder < 0.2 in adaptive mode.

Sizes 4 and 5 use a cheaper dedicated path (`sort_small.c`): push the
current minimum out to b once (n=4) or twice (n=5), solve the
remaining 3 with `sort_three`, then pull the pushed element(s) back —
this closes most of the gap with a hand-optimized solution for these
very common small sizes without adding real complexity.

### 2. Medium — O(n√n) — Chunk Sort

Divides the index range into √n chunks. Pushes each chunk from a to b in order.
Then pulls back from b always taking the maximum, rebuilding a in sorted order.
With √n chunks each of size √n, total operations are O(n√n).
Used when: `--medium` flag or 0.2 ≤ disorder < 0.5 in adaptive mode.

### 3. Complex — O(n log n) — LSD Radix Sort

Works on normalized indices (0 to n-1) in binary. For each bit position from
LSB to MSB: elements with bit=0 are pushed to b, elements with bit=1 stay in a
via rotate, then all of b is pushed back. After log2(n) passes the stack is sorted.
This generates O(n log n) operations and hits the excellent performance benchmarks.
Used when: `--complex` flag or disorder ≥ 0.5 in adaptive mode.

### 4. Adaptive — Disorder-Based Selection

Measures disorder before sorting (0.0 = sorted, 1.0 = fully reversed):
- size ≤ 3         → sort_three (trivial, 0-2 ops)
- size ≤ 5         → Simple / sort_small (dedicated small-n path)
- size ≤ 100       → Medium O(n√n)
- disorder < 0.2   → Medium O(n√n)     — nearly sorted, chunking wins
- disorder ≥ 0.2   → Complex O(n log n) — highly disordered

Threshold rationale: at low disorder or small size, O(n²)/O(n√n) beats
radix sort in practice because the constant factor is smaller and fewer
elements need moving. At high disorder, radix sort's logarithmic growth
is essential to stay within operation limits.

## Resources

- [Sorting algorithm visualizer](https://visualgo.net/en/sorting)
- [Radix sort explanation](https://en.wikipedia.org/wiki/Radix_sort)
- [Push_swap algorithm guide](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Big-O complexity cheat sheet](https://www.bigocheatsheet.com)

### AI Usage

Claude (claude.ai) was used to:
- Help structure the file layout and session plan
- Review Norminette compliance of individual functions, and fix real
  violations (a CRLF-encoded file with inline comments in an invalid
  scope, functions over the 25-line limit, files with too many
  functions) confirmed against the actual `norminette` tool, not just
  a manual read-through
- Explain radix sort adaptation for the push_swap operation model
- Independently verify correctness: every operation sequence produced
  by the program was replayed in a separate simulator (not trusting
  the C code's own success/failure reporting) across 1260+ randomized
  test cases spanning all 4 strategies and a wide range of sizes, plus
  a further 300 cases cross-checked against the official 42 reference
  `checker_linux` binary. This caught two real algorithmic bugs that
  compiled cleanly but produced wrong output on specific inputs:
  - `sort_three` had `ra`/`rra` swapped in two of its six branches
    (confirmed by hand-simulating each permutation)
  - `sort_medium`'s cost-optimized insertion path could rotate an
    already-correctly-placed element out of position while computing
    the insertion point for a later element (traced to a concrete
    6-element failing case); replaced with the simpler chunk-based
    approach that was already proven correct for larger inputs
- Optimize `sort_simple` for n=4/5 with a dedicated path
- Verify memory safety with AddressSanitizer and valgrind, including
  the error-exit paths, confirming zero leaks
- Debug linking errors during development

All generated code was reviewed, understood, and tested by both team members
before inclusion in the project.

## Contributors

| Login   | Contributions                                          |
|---------|---------------------------------------------------------|
| login1  | Stack structure, operations, sort_simple, sort_small     |
| login2  | sort_medium, sort_complex, adaptive, bench, README       |
