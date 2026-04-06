#ifndef VERIFY_SORTING_HPP
#define VERIFY_SORTING_HPP

#include <iostream>
#include <cstdlib>
#include <vector>

// Wypisanie tablicy (sprawdzenie sortowania dla małych rozmiarów)
template <typename T>
void printArray(std::vector<T>& arr) {
  for (int i = 0; i < arr.size() - 1; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// Sprawdzenie, czy tablica jest posortowana dla dużych rozmiarów
template <typename T>
bool isSorted(std::vector<T>& arr, bool ascending = true) {
  for (int i = 0; i < arr.size() - 1; i++) {
    if ((ascending && arr[i] > arr[i + 1]) || (!ascending && arr[i] < arr[i + 1])) {
      return false;
    }
  }
  return true;
}

#endif
