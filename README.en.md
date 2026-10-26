[Polski](README.md) | **English**

# Sorting Algorithms — Benchmark

A C++ project comparing the performance of three sorting algorithms — **Merge Sort**, **Quick Sort** and **IntroSort** — on arrays of different sizes and different degrees of initial ordering.

## Algorithms

| File | Algorithm | Notes |
|------|-----------|-------|
| `merge_sort.hpp` | Merge Sort | Recursive, top-down |
| `quicksort.hpp` | Quick Sort | Hoare-style partitioning, middle element as pivot |
| `heap_sort.hpp` | Heap Sort | Used as the fallback inside IntroSort |
| `introsort.hpp` | IntroSort | Quick Sort that switches to Heap Sort once recursion depth exceeds `2·log₂(n)` |

All algorithms are templates (`std::vector<T>`) and support both ascending and descending order.

## Test scenarios

- **Array sizes:** 10 000, 50 000, 100 000, 500 000, 1 000 000 elements
- **Input data:**
  - random values (0–1 000 000),
  - partially sorted — the first 25%, 50%, 75%, 95%, 99% and 99.7% of the array already sorted,
  - sorted in reverse order.
- Each case is run **100 times**; the average, minimum and maximum time are recorded.

After every run the result is checked for correctness (`verify_sorting.hpp`); arrays of up to 100 elements are printed instead.

## Project structure

```
main.cpp              – test driver, writes results to results.csv
tables_generator.hpp  – generation of random / partially sorted / reversed arrays
test_sorting.hpp      – time measurement (std::chrono)
verify_sorting.hpp    – correctness check
results.csv           – raw results (algorithm;size;case;avg;min;max, in ms)
results_obrobka.*     – processed results and charts (Excel)
```

## Build and run

Requires a C++17 compiler (structured bindings are used).

```bash
g++ -std=c++17 -O2 main.cpp -o main
./main
```

The program prints the times for each case to the terminal and saves them to `results.csv` (`;`-separated, decimal comma — ready to open in Polish-locale Excel).
