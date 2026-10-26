🇵🇱 **Polski** | 🇬🇧 [English](README.en.md)

# ⚡ Algorytmy sortowania — benchmark

![C++](https://img.shields.io/badge/C++-00599C?logo=cplusplus&logoColor=white) ![Excel](https://img.shields.io/badge/Excel-217346?logo=microsoftexcel&logoColor=white)

> 🎓 Projekt na przedmiot **Projektowanie i Analiza Algorytmów** (Politechnika Wrocławska)

Implementacja trzech algorytmów sortowania od podstaw oraz porównanie ich wydajności dla różnych rozmiarów i rodzajów danych wejściowych.

## ✨ Co zrobiłem

- **Merge Sort**, **Quick Sort** i **IntroSort** (Quick Sort, który przy zbyt głębokiej rekurencji przełącza się na **Heap Sort**) — wszystko jako szablony C++, sortowanie rosnące i malejące
- Benchmark na tablicach od **10 tys. do 1 mln** elementów: losowych, częściowo posortowanych (25% 99,7%) i odwróconych
- Każdy przypadek mierzony **100 razy** (średnia, min, max) + automatyczne sprawdzanie, czy wynik jest poprawnie posortowany
- Wyniki w CSV i wykresy w Excelu

## 🛠️ Technologie

C++17 · `std::chrono` · `<random>` · Excel

## 🚀 Uruchomienie

```bash
g++ -std=c++17 -O2 main.cpp -o main
./main
```

Wyniki trafiają do `results.csv`.
