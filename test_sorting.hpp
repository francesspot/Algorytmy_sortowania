#ifndef TEST_SORTING_HPP
#define TEST_SORTING_HPP

#include <iostream>
#include <vector>
#include <chrono>
#include "verify_sorting.hpp"

// Testowanie algorytmu sortowania i mierzenie czasu
template <typename T, typename SortFunction>
double testSortingAlgorithm(const std::vector<T>& arr, SortFunction sortFunction, bool ascending = true) {
  if (arr.empty()) {
    return 0.0;
  }
  
  std::vector<T> testArr = arr; // Kopiowanie tablicy, aby nie modyfikować oryginału

  auto start = std::chrono::high_resolution_clock::now(); // Start pomiaru czasu
  sortFunction(testArr, 0, testArr.size() - 1, ascending); // Wywołanie funkcji sortującej
  auto end = std::chrono::high_resolution_clock::now(); // Koniec pomiaru czasu
  double duration = std::chrono::duration<double, std::milli>(end - start).count(); // Obliczenie czasu w milisekundach

  if (testArr.size() <= 100) {
    std::cout << "Posortowana tablica: "; // Wypisanie posortowanej tablicy dla małych rozmiarów
    printArray(testArr);
  } else if (!isSorted(testArr, ascending)) { // Sprawdzenie poprawności sortowania dla dużych tablic
    std::cout << "Błąd: Tablica nie jest poprawnie posortowana." << std::endl;
  }
  
  return duration;
}

#endif