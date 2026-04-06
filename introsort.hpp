#ifndef INTROSORT_HPP
#define INTROSORT_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "heap_sort.hpp"

// IntroSort - hybryda Quick Sort i Heap Sort
template <typename T>
void introSort(std::vector<T>& arr, int left, int right, bool ascending = true, int depthlimit = -1) { // depthlimit - limit głębokości, domyślnie ustawiony na -1, co oznacza, że zostanie obliczony na podstawie rozmiaru tablicy
  if (left >= right) {  // Koniec, jeśli jest jeden lub brak elementów
    return;
  }

  // Obliczanie limitu głębokości, jeśli nie został ustawiony lub jest mniejszy niż 0
  if (depthlimit < 0) { 
    int n = right - left + 1; // Rozmiar tablicy do posortowania
    depthlimit = 2 * static_cast<int>(std::log2(n)); // Ustawienie limitu głębokości na 2 * log2(n), gdzie n to rozmiar tablicy.
  }

  // Jeśli limit głębokości został osiągnięty, użyj Heap Sort
  if (depthlimit == 0) { 
    heapSort(arr, left, right, ascending); // Przejście do Heap Sort, gdy limit głębokości został osiągnięty
    return;
  }

  // Quick Sort - wybór pivota i partycjonowanie
  int i = left; // Indeks dla lewej części
  int j = right; // Indeks dla prawej części
  T pivot = arr[(left + right) / 2]; // Wybór pivota (środkowy element)

  while (i <= j) { // Porównanie elementów z pivotem i przesuwanie indeksów
    if (ascending) {
      while (arr[i] < pivot) i++; // Szukanie większego elementu po lewej stronie
      while (arr[j] > pivot) j--; // Szukanie mniejszego elementu po prawej stronie
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
    introSort(arr, left, j, ascending, depthlimit - 1);
  }
  // Sortowanie prawej części
  if (i < right) {
    introSort(arr, i, right, ascending, depthlimit - 1);
  }
}

#endif