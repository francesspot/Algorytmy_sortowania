**Polski** | [English](README.en.md)

# Algorytmy sortowania — porównanie wydajności

Projekt w C++ porównujący wydajność trzech algorytmów sortowania — **Merge Sort**, **Quick Sort** i **IntroSort** — na tablicach różnej wielkości i o różnym stopniu wstępnego uporządkowania.

## Algorytmy

| Plik | Algorytm | Uwagi |
|------|----------|-------|
| `merge_sort.hpp` | Merge Sort | Rekurencyjny, top-down |
| `quicksort.hpp` | Quick Sort | Podział w stylu Hoare'a, pivot — element środkowy |
| `heap_sort.hpp` | Heap Sort | Używany jako zapasowy algorytm w IntroSorcie |
| `introsort.hpp` | IntroSort | Quick Sort, który przechodzi na Heap Sort po przekroczeniu głębokości rekurencji `2·log₂(n)` |

Wszystkie algorytmy są szablonami (`std::vector<T>`) i obsługują sortowanie rosnące oraz malejące.

## Scenariusze testowe

- **Rozmiary tablic:** 10 000, 50 000, 100 000, 500 000, 1 000 000 elementów
- **Dane wejściowe:**
  - wartości losowe (0–1 000 000),
  - częściowo posortowane — pierwsze 25%, 50%, 75%, 95%, 99% i 99,7% tablicy już posortowane,
  - posortowane odwrotnie.
- Każdy przypadek jest uruchamiany **100 razy**; zapisywany jest czas średni, minimalny i maksymalny.

Po każdym sortowaniu sprawdzana jest poprawność wyniku (`verify_sorting.hpp`); tablice do 100 elementów są zamiast tego wypisywane.

## Struktura projektu

```
main.cpp              – program testujący, zapisuje wyniki do results.csv
tables_generator.hpp  – generowanie tablic losowych / częściowo posortowanych / odwróconych
test_sorting.hpp      – pomiar czasu (std::chrono)
verify_sorting.hpp    – sprawdzenie poprawności sortowania
results.csv           – surowe wyniki (algorithm;size;case;avg;min;max, w ms)
results_obrobka.*     – opracowane wyniki i wykresy (Excel)
```

## Kompilacja i uruchomienie

Wymagany kompilator C++17 (użyte są structured bindings).

```bash
g++ -std=c++17 -O2 main.cpp -o main
./main
```

Program wypisuje czasy dla każdego przypadku w terminalu i zapisuje je do `results.csv` (separator `;`, przecinek dziesiętny — gotowe do otwarcia w polskim Excelu).
