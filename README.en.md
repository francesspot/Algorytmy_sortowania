🇵🇱 [Polski](README.md) | 🇬🇧 **English**

# ⚡ Sorting Algorithms — Benchmark

![C++](https://img.shields.io/badge/C++-00599C?logo=cplusplus&logoColor=white) ![Excel](https://img.shields.io/badge/Excel-217346?logo=microsoftexcel&logoColor=white)

> 🎓 Project for the **Algorithm Design and Analysis** course (Wrocław University of Science and Technology)

I implemented three sorting algorithms from scratch and measured which one is the fastest — and when. 🏁

## ✨ What I did

- 🔀 **Merge Sort**, ⚡ **Quick Sort** and 🧠 **IntroSort** (Quick Sort that switches to 🏔️ **Heap Sort** when recursion gets too deep) — all as C++ templates, ascending and descending
- 🧪 Benchmarks on arrays from **10k to 1M** elements: random, partially sorted (25% → 99.7%) and reversed
- 🔁 Each case measured **100 times** (average, min, max), with an automatic check that the output is actually sorted
- 📊 Results saved to CSV and charted in Excel

## 🛠️ Tech

C++17 · `std::chrono` · `<random>` · Excel

## 🚀 Run it

```bash
g++ -std=c++17 -O2 main.cpp -o main
./main
```

Results are written to `results.csv`.
