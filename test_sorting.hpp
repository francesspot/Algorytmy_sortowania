#ifndef TEST_SORTING_HPP
#define TEST_SORTING_HPP

#include <iostream>
#include <vector>
#include <chrono>
#include "verify_sorting.hpp"

template <typename T, typename SortFunction>
double testSortingAlgorithm(const std::vector<T>& arr, SortFunction sortFunction, bool ascending = true) {
  if (arr.empty()) {
    return 0.0;
  }
  
  std::vector<T> testArr = arr;

  auto start = std::chrono::high_resolution_clock::now();
  sortFunction(testArr, 0, testArr.size() - 1, ascending);
  auto end = std::chrono::high_resolution_clock::now();
  double duration = std::chrono::duration<double, std::milli>(end - start).count();

  if (testArr.size() <= 100) {
    std::cout << "Posortowana tablica: ";
    printArray(testArr);
  } else if (!isSorted(testArr, ascending)) {
    std::cout << "Błąd: Tablica nie jest poprawnie posortowana." << std::endl;
  }
  
  return duration;
}

#endif