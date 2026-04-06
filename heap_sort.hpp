#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

#include <iostream>
#include <cstdlib>
#include <vector>

// Heapify - budowanie kopca
template <typename T>
void heapify(std::vector<T>& arr, int n, int index, int offset = 0, bool ascending = true) {
  int root = index;  // Korzeń
  int leftChild = 2 * index + 1;  // Lewe dziecko
  int rightChild = 2 * index + 2;  // Prawe dziecko

  // Porównianie z lewym dzieckiem
  if (leftChild < n) { // Sprawdzenie, czy lewe dziecko istnieje
    if ((ascending && arr[leftChild + offset] > arr[root + offset]) || (!ascending && arr[leftChild + offset] < arr[root + offset])) { // Jeśli lewy jest większy (lub mniejszy dla malejącego), ustaw jako nowy korzeń
      root = leftChild; // Aktualizacja indeksu korzenia
    }
  }

  // Porównianie z prawym dzieckiem
  if (rightChild < n) { // Sprawdzenie, czy prawe dziecko istnieje
    if ((ascending && arr[rightChild + offset] > arr[root + offset]) || (!ascending && arr[rightChild + offset] < arr[root + offset])) { // Jeśli prawy jest większy (lub mniejszy dla malejącego), ustaw jako nowy korzeń
        root = rightChild; // Aktualizacja indeksu korzenia
      }
  }

  // Jeśli korzeń nie jest największy (lub najmniejszy dla malejącego), zamień i rekurencyjnie heapify
  if (root != index) {
    std::swap(arr[index + offset], arr[root + offset]); // Zamiana elementów w tablicy
    heapify(arr, n, root, offset, ascending); // Rekurencyjne wywołanie heapify dla poddrzewa, które zostało zmienione
  }
}

// HeapSort - sortowanie przez kopcowanie
template <typename T>
void heapSort(std::vector<T>& arr, int left, int right, bool ascending = true) {
  int n = right - left + 1; // Rozmiar tablicy do posortowania

  // Budowanie kopca
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i, left, ascending); // Budowanie kopca dla całej tablicy
  }
    
  // Wyciąganie elementów z kopca
  for (int i = n - 1; i > 0; i--) {
    std::swap(arr[left], arr[i + left]); // Zamiana pierwszego elementu (największego) z ostatnim elementem
    heapify(arr, i, 0, left, ascending); // Heapify dla pozostałej części kopca, aby przywrócić właściwości kopca
  }
}

#endif