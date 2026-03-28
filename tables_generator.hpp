#ifndef TABLES_GENERATOR_HPP
#define TABLES_GENERATOR_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

std::mt19937 gen(std::random_device{}());

template <typename T>
std::vector<T> generateRandomArray(int n, T minValue = 0, T maxValue = 1000000) {
  std::vector<T> arr(n);
  std::uniform_int_distribution<T> dis(minValue, maxValue);

  for (int i = 0; i < n; i++) {
    arr[i] = dis(gen);
  }
  return arr;
}

template <typename T>
std::vector<T> generatePartiallySortedArray(int n, T minValue = 0, T maxValue = 1000000, double sortedPercentage = 0.5) {
  std::vector<T> arr = generateRandomArray<T>(n, minValue, maxValue);

  int sortedElements = static_cast<int>(n * sortedPercentage);
  sortedElements = std::min(sortedElements, n);

  std::sort(arr.begin(), arr.begin() + sortedElements);
  return arr;
}

template <typename T>
std::vector<T> generateReverseSortedArray(int n, T minValue = 0, T maxValue = 1000000) {
  std::vector<T> arr = generateRandomArray<T>(n, minValue, maxValue);
  std::sort(arr.rbegin(), arr.rend());
  return arr;
}

#endif