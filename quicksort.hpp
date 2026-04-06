#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <iostream>
#include <cstdlib>
#include <vector>

// Quick Sort - dziel i zwyciężaj 
template <typename T>
void quickSort(std::vector<T>& arr, int left, int right, bool ascending = true) {
  if (left >= right)  // Koniec, jeśli jest jeden lub brak elementów
    return;

  int i = left;  // Indeks dla lewej części
  int j = right; // Indeks dla prawej części
  T pivot = arr[(left + right) / 2]; // Wybór pivota (środkowy element)

  while (i <= j) {
    if (ascending) {
      while (arr[i] < pivot) i++;  // Szukanie większego elementu po lewej stronie
      while (arr[j] > pivot) j--;  // Szukanie mniejszego elementu po prawej stronie
    } else {
      while (arr[i] > pivot) i++; // Szukanie mniejszego elementu po lewej stronie
      while (arr[j] < pivot) j--; // Szukanie większego elementu po prawej stronie
    }

    // Zamiana elementów, jeśli są po złej stronie pivota
    if (i <= j) {
      std::swap(arr[i], arr[j]);
      i++; // Przesunięcie indeksów
      j--;
    }
  }
    
  // Sortowanie lewej części
  if (left < j) {
    quickSort(arr, left, j, ascending);
  }

  // Sortowanie prawej części
  if (i < right) {
    quickSort(arr, i, right, ascending);
  }
}

#endif