*This activity has been created as part of the 42 curriculum by igomes-d, mdurte-s.*

# push_swap

Sort a stack of integers using **two stacks** and a **restricted set of operations**,
producing the **shortest possible** list of instructions.

---

## Description

`push_swap` receives a list of unique integers and must output a sequence of stack
operations that, when applied to stack **A**, leaves it sorted in ascending order.
There are only two stacks (**A** and **B**) and only eleven allowed operations, so the
challenge is **not** "can you sort?" — any sort works — but **"how few moves can you do it
in?"** The grade is a function of the number of operations emitted.

The mandatory program prints the operations and nothing else. The **bonus** program,
`checker`, does the opposite: it reads a list of integers **and** a sequence of operations
from the standard input, applies them, and answers `OK` if the stack ends up sorted or
`KO` if it does not — so it can validate any solver.

This implementation is built around a single idea: **no single sorting algorithm is optimal
for every input distribution.** A list that is already almost sorted, a list shuffled at
random, and a list reversed end-to-end each have a different "best" strategy. So instead of
committing to one algorithm, the program **measures how disordered the input is** and
**routes it to the cheapest strategy for that case** — this is the *Adaptive* engine and the
headline feature of the project.

### The allowed operations

| Op | Effect |
|----|--------|
| `sa` / `sb` / `ss` | swap the first two elements of A / B / both |
| `pa` / `pb` | push the top of B onto A / push the top of A onto B |
| `ra` / `rb` / `rr` | rotate A / B / both up (first element goes to the bottom) |
| `rra` / `rrb` / `rrr` | reverse-rotate A / B / both down (last element goes to the top) |

---

## Instructions

### Requirements
A C compiler (`cc`/`gcc`/`clang`) and `make`. No external libraries — a small in-house
`mini_libft` and `ft_printf` are bundled in `srcs/`.

### Compilation

```bash
make          # builds the mandatory program  ->  ./push_swap
make bonus    # builds the checker program     ->  ./checker
make clean    # removes object files
make fclean   # removes objects + binaries
make re       # fclean + all
```

The project compiles with `-Wall -Wextra -Werror`.

### Execution

Pass the integers as separate arguments **or** as a single quoted string:

```bash
./push_swap 3 2 1                 
./push_swap "4 67 3 87 23"        # quoted form also works
./push_swap $(shuf -i 1-100000 -n 500 | tr '\n' ' ')
```

Invalid input (non-numeric, duplicates, values outside `INT_MIN..INT_MAX`) prints
`Error\n` to **stderr** and exits. No arguments produces no output.

### Checking a solution (bonus)

`checker` takes the integers as arguments and the operations on stdin:

```bash
./push_swap 3 2 1 | ./checker 3 2 1      # -> OK
echo -e "sa\nra" | ./checker 3 2 1       # -> KO  (does not sort)
```

### Flags

These flags let you force a specific strategy or print a benchmark report:

```bash
./push_swap --simple   <nums>   # force the O(n^2) strategy
./push_swap --medium   <nums>   # force the O(n sqrt n) strategy
./push_swap --complex  <nums>   # force the O(n log n) strategy
./push_swap --adaptive <nums>   # explicit adaptive (this is also the default)
./push_swap --bench    <nums>   # print disorder %, chosen strategy and op counts to stderr
```

Example benchmark output (on stderr, stdout still carries the real operations):

```
[bench] disorder: 49.87%
[bench] strategy: Adaptive / O(n log n)
[bench] total_ops: 3897
[bench] sa: 0 sb: 0 ss: 0 pa: 498 pb: 500 ra: ... rrb: ... rrr: ...
```

---

## Algorithms

### Data structure — a circular buffer, not a linked list

Most `push_swap` solutions model each stack as a doubly-linked list. We use a
**ring buffer** instead: each stack is a flat array `t_node arr[]` plus three indices
`start`, `len` and `capacity` ([`includes/push_swap.h`](includes/push_swap.h)). A logical
index `i` maps to the physical slot `(start + i) mod capacity` through the helper
[`_i()`](srcs/stacks.c).

Why this matters for the cost we are graded on:

* **`rotate` / `reverse-rotate` become O(1).** Rotating is just moving `start` by one, one
  element is copied, no pointer is relinked. A linked-list rotation has to splice nodes.
* **`push` is O(1)** and touches contiguous memory, which is **cache-friendly** — a real
  speed win on the 500-element benchmarks.
* The array also makes **binary search over the stack** trivial (`_i()` gives random
  access), which the *Simple* and *Medium* strategies exploit to pick insertion points
  cheaply.

### The disorder metric — how the engine "sees" the input

Before sorting, [`mesure_disorder()`](srcs/algth_adaptive.c) counts **inversions**: the
number of pairs `(i, j)` with `i < j` but `a[i] > a[j]`, divided by the total number of
pairs. The result is a percentage:

* **0 %** → already sorted,
* **~50 %** → randomly shuffled,
* **100 %** → reversed.

This single number is what the Adaptive engine uses to choose a strategy. (Computing it is
O(n²); for the input sizes that matter here this cost is dominated by the sort itself.)

### 1. Simple — O(n²) — insertion-based, for nearly-sorted input

[`low_disorder_optimized_insertion_sort()`](srcs/algth_simple.c)

Rotate the minimum to the right place, then sweep A pushing every element that breaks the
ascending run into B. Each element is then re-inserted into A at its correct position, found
with a **binary search** ([`binary_find_fit_distance()`](srcs/algth_simple.c)) and brought
in with the **cheapest combination of rotations** on A and B
([`choose_cheapest_distance_fit_to_a()`](srcs/algth_simple.c),
[`move_to_top_dual()`](srcs/algth_helpers.c)).

**Why / when:** when the list is **almost sorted** (disorder `< 20 %`), only a handful of
elements are out of place. Very few go to B, and each re-insertion is cheap, so in practice
the operation count is **near-linear** even though the worst case is O(n²). On a reversed
500-element list this strategy needs only **~2000 ops** — the cheapest of the three for
low-disorder structure.

### 2. Medium — O(n√n) — bucket distribution, for moderate disorder

[`bucket_sort()`](srcs/algth_medium.c)

Split the value range into **≈ √n buckets** (the divisor `div` is derived from
`ft_sqrt(n)` in [`sort()`](srcs/main.c)). Walk A and send each element to B, rotating B so
that elements of the same bucket stay grouped ([`move_to_top_bucket()`](srcs/algth_medium.c)).
Once everything is bucketed in B, [`binary_insertion_sort_a()`](srcs/algth_simple.c) pulls
the values back into A in order.

**Why / when:** for **moderate disorder** (`20 %–50 %`) a pure insertion sort does too much
work and a full divide-and-conquer does more than necessary. Distributing into √n buckets
and finishing with a binary insertion costs **O(n√n)** — the sweet spot in the middle. The
bucket count `√n` is the classic choice that balances "number of buckets" against
"elements per bucket."

### 3. Complex — O(n log n) — partial quicksort, for high disorder

[`intro_sort()`](srcs/algth_complex.c)

A recursive **partition sort**. Each pass picks a pivot — the **average** of the current
segment ([`get_avg()`](srcs/algth_complex_helpers.c)) — and partitions: elements above the
pivot rotate to stay in place, elements below are pushed to the other stack
([`partial_quick_sort_a_b()`](srcs/algth_complex.c) and
[`partial_quick_sort_b()`](srcs/algth_complex.c)). The recursion bottoms out at segments of
size ≤ 3, hard-coded by [`sort_three_a()` / `sort_three_b()`](srcs/algth_complex_helpers.c),
and a final [`low_disorder_optimized_insertion_sort()`](srcs/algth_simple.c) pass cleans up.

**Why / when:** for **high disorder** (`≥ 50 %`, i.e. essentially random or reversed input)
neither insertion nor bucketing is competitive. Mean-pivot partitioning halves the problem
each level, giving **O(n log n)** average behaviour, which is the right asymptotic class for
genuinely shuffled data.

> Implementation note: the pivot accumulator in `get_avg()` sums up to *n* values that can
> each reach `INT_MAX`, so the sum is accumulated in a **`long long`** to avoid signed
> overflow on inputs that use the full integer range.

### 4. Adaptive — the default engine

[`update_bench_strategy()` + `disorder_based_sort()`](srcs/algth_adaptive.c)

With no flag, the program measures disorder and dispatches:

| Measured disorder | Strategy chosen | Complexity |
|-------------------|-----------------|------------|
| `< 20 %`          | Simple          | O(n²) (near-linear in practice) |
| `20 % – 50 %`     | Medium          | O(n√n) |
| `≥ 50 %`          | Complex         | O(n log n) |

Lists of size ≤ 5 bypass all of this and use hand-tuned optimal sequences
([`sort_three()`, `sort_under_five()`](srcs/main.c)).

**Why this design:** the three strategies have **crossing cost curves** — each is the
cheapest in a different disorder band. Spending one O(n²) measurement pass to pick the right
one means the program is never far from the best achievable op-count for the *actual* input,
instead of being tuned for one assumed distribution.

### Measured performance

Average operation counts on random input (lower is better):

| n   | Simple | Medium | Complex | **Adaptive (default)** |
|-----|--------|--------|---------|------------------------|
| 100 | ~368   | ~546   | ~620    | **~528** |
| 500 | ~2773  | ~3815  | ~5013   | **~3932** |

The default Adaptive mode comfortably clears the 42 grading thresholds (100 numbers in
well under 700 operations, 500 numbers in well under 5500), and the bundled bonus `checker`
agrees with the official `checker_linux` on every run.

---

## Bonus — the checker

[`bonus/checker_bonus.c`](bonus/checker_bonus.c) re-implements the eleven operations on a
**doubly-linked list** (a deliberately different data structure from the mandatory part),
reads the operation stream from stdin, applies it, and prints `OK` / `KO`. Malformed input
or an unknown operation prints `Error\n` on stderr. It is the reference tool we used to
validate the solver during development.

---

## Project structure

```
includes/push_swap.h        types (t_ctx, t_stk, t_bench) and prototypes
srcs/
  main.c / main_helpers.c   entry point, small-N cases, strategy dispatch, context
  parser_argv*.c            argument parsing, validation, duplicate detection
  stacks.c                  the circular-buffer engine (_i, rotate, push backing)
  op_*.c                    the eleven operations (with op counting for --bench)
  algth_simple.c            Simple  O(n^2)
  algth_medium.c            Medium  O(n sqrt n)
  algth_complex*.c          Complex O(n log n)
  algth_adaptive.c          disorder measurement + strategy selection
  algth_helpers.c           shared move/cost helpers
  mini_libft.c / ft_split.c / ft_printf*.c   in-house utilities
bonus/                      the linked-list checker and its helpers
Makefile
```

---

## Contributions

This is a two-person project. The split below reflects the primary author of each area
(both members reviewed and iterated on the whole codebase):

**mdurte-s**
- Program skeleton and entry point (`main.c`), argument parser and input validation
  (`parser_argv*.c`).
- The eleven stack operations (`op_push`, `op_swap`, `op_rotate`, `op_rev_rotate`).
- The Complex / partial-quicksort core (`algth_complex.c`).
- The `ft_printf` utilities and the project header.
- The bonus **checker** core and its linked-list operations.

**igomes-d**
- The Adaptive engine and disorder metric (`algth_adaptive.c`), plus the Simple and Medium
  strategies (`algth_simple.c`, `algth_medium.c`) and their shared helpers
  (`algth_helpers.c`, `algth_complex_helpers.c`).
- The circular-buffer stack engine (`stacks.c`) and context/benchmark layer
  (`main_helpers.c`).
- `mini_libft`, `ft_split`, and the bonus init/utility files.
- Final integration, the `--bench`/strategy flag interface, and the round of fixes
  (e.g. the `long long` pivot accumulator and the checker memory cleanup).

---

## Resources

Classic references we studied for the topic:

- **42 `push_swap` subject** — the official project specification and constraints.
- **Sorting-algorithm complexity** — comparison of insertion sort, bucket/radix sort and
  quicksort, and the meaning of the O(n²), O(n√n) and O(n log n) classes
  - [`https://en.wikipedia.org/wiki/Sorting_algorithm`](https://en.wikipedia.org/wiki/Sorting_algorithm)
  - [`https://www.geeksforgeeks.org/dsa/insertion-sort-algorithm/`](https://www.geeksforgeeks.org/dsa/insertion-sort-algorithm/)
  - [`https://en.wikipedia.org/wiki/Greedy_algorithm`](https://en.wikipedia.org/wiki/Greedy_algorithm)
  - [`https://en.wikipedia.org/wiki/Bucket_sort`](https://en.wikipedia.org/wiki/Bucket_sort)
  - [`https://pt.wikipedia.org/wiki/Quicksort`](https://pt.wikipedia.org/wiki/Quicksort)
  - [`https://en.wikipedia.org/wiki/Introsort`](https://en.wikipedia.org/wiki/Introsort)
- **Inversions / Kendall-tau distance** — the basis for the "disorder %" measure used by the
  Adaptive engine.
  - [`https://en.wikipedia.org/wiki/Kendall_tau_distance`](https://en.wikipedia.org/wiki/Kendall_tau_distance)
- **Ring buffer (circular buffer)** — the data structure behind our O(1) rotations.
- Community write-ups and visualizers on `push_swap` strategies (chunk/radix sorts and the
  cost model for `rr`/`rrr` combined moves).
  - [`https://en.wikipedia.org/wiki/Circular_buffer`](https://en.wikipedia.org/wiki/Circular_buffer)

### Use of AI

We used an AI assistant as a study and review aid, specifically for:

- **Learning the complexity classes** — understanding the trade-offs between O(n²),
  O(n√n) and O(n log n), why each strategy wins in a different disorder band, and how to
  reason about the cost of combined operations (`rr`, `rrr`).
- **Clarifying doubts during development** — discussing the circular-buffer indexing,
  debugging edge cases (e.g. integer-overflow in the pivot accumulator and memory cleanup in
  the checker), and sanity-checking the strategy-selection thresholds.

All algorithm design decisions, the code itself, and the final implementation are our own;
AI was used for understanding and debugging discussion, not to generate the
solver.
