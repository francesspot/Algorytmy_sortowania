#ifndef TABLES_GENERATOR_HPP
#define TABLES_GENERATOR_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

std::mt19937 gen(std::random_device{}());  // Generator liczb losowych

// Generowanie losowej tablicy
template <typename T>
std::vector<T> generateRandomArray(int n, T minValue = 0, T maxValue = 1000000) {
  std::vector<T> arr(n); // Tworzenie wektora o rozmiarze n
  std::uniform_int_distribution<T> dis(minValue, maxValue); // Rozkład równomierny

  for (int i = 0; i < n; i++) { 
    arr[i] = dis(gen); 
  }
  return arr;
}

// Tablica częściowo posortowana
template <typename T>
std::vector<T> generatePartiallySortedArray(int n, T minValue = 0, T maxValue = 1000000, double sortedPercentage = 0.5) {
  std::vector<T> arr = generateRandomArray<T>(n, minValue, maxValue);
 
  int sortedElements = static_cast<int>(n * sortedPercentage);   // Obliczanie liczby posortowanych elementów
  sortedElements = std::min(sortedElements, n); // Zapewnienie, że nie przekroczy rozmiaru tablicy

  std::sort(arr.begin(), arr.begin() + sortedElements);  // Posortowanie pierwszej części tablicy
  return arr; // Zwrócenie częściowo posortowanej tablicy
}

// Tablica odwrotnie posortowana
template <typename T>
std::vector<T> generateReverseSortedArray(int n, T minValue = 0, T maxValue = 1000000) {
  std::vector<T> arr = generateRandomArray<T>(n, minValue, maxValue);
  std::sort(arr.rbegin(), arr.rend()); // Posortowanie tablicy w odwrotnej kolejności, rbegin() - iterator od końca, rend() - iterator do początku
  return arr;
}

// Generowanie testowej tablicy
template <typename T>
std::vector<T> generateCaseArray(int n, double sortedPercentage = 0.0, bool reverse = false) {

  // Zakres wartości
  const T minValue = 0; 
  const T maxValue = 1000000;
  
  // Generowanie tablicy w zależności od parametrów
  if (reverse) {
    return generateReverseSortedArray<T>(n, minValue, maxValue);
  }

  if (sortedPercentage > 0.0) {
    return generatePartiallySortedArray<T>(n, minValue, maxValue, sortedPercentage);
  }

  return generateRandomArray<T>(n, minValue, maxValue);
}

#endif