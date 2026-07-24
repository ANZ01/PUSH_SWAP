*This project has been created as part of the 42 curriculum by login1, login2.*

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

# Build checker (bonus)
make bonus

# Clean objects
make clean

# Full clean
make fclean

# Rebuild
make re
```

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

# Verify with checker
./push_swap 5 3 1 4 2 | ./checker 5 3 1 4 2

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
- disorder < 0.2  → Simple O(n²)      — nearly sorted, few fixes needed
- disorder < 0.5  → Medium O(n√n)     — partially sorted
- disorder ≥ 0.5  → Complex O(n log n) — highly disordered

Threshold rationale: at low disorder, O(n²) beats radix sort in practice because
the constant factor is smaller and fewer elements need moving. At high disorder,
radix sort's logarithmic growth is essential to stay within operation limits.

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
  scope, two functions over the 25-line limit, one file with too many
  functions) confirmed against the actual `norminette` tool, not just
  a manual read-through
- Explain radix sort adaptation for the push_swap operation model
- Independently verify correctness: every operation sequence produced
  by the program was replayed in a separate Python simulator (not
  trusting the C code's own success/failure reporting) across 1260
  randomized test cases spanning all 4 strategies and sizes 1-200.
  This caught two real algorithmic bugs that compiled cleanly but
  produced wrong output on specific inputs:
  - `sort_three` had `ra`/`rra` swapped in two of its six branches
    (confirmed by hand-simulating each permutation)
  - `sort_medium`'s cost-optimized insertion path could rotate an
    already-correctly-placed element out of position while computing
    the insertion point for a later element (traced to a concrete
    6-element failing case); replaced with the simpler chunk-based
    approach that was already proven correct for larger inputs
- Debug linking errors during development

All generated code was reviewed, understood, and tested by both team members
before inclusion in the project.

## Contributors

| Login   | Contributions                                      |
|---------|----------------------------------------------------|
| login1  | Stack structure, operations, sort_simple, checker  |
| login2  | sort_medium, sort_complex, adaptive, bench, README |
