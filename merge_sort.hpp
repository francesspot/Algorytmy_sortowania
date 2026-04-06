#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <iostream>
#include <cstdlib>
#include <vector>

// Łączenie dwóch posortowanych części tablicy
template <typename T>
void merge(std::vector<T>& arr, int left, int mid, int right, bool ascending = true) {
    int i = left; // Początek lewej części
    int j = mid + 1; // Początek prawej części

    std::vector<T> tempArr(right - left + 1); // Tymczasowa tablica do przechowywania połączonych elementów
    int k = 0; // Indeks dla tempArr
    while (i <= mid && j <= right) { // Porównanie elementów z obu części i dodanie mniejszego do tempArr
        if ((ascending && arr[i] <= arr[j]) || (!ascending && arr[i] >= arr[j])) {
            tempArr[k++] = arr[i++]; // Dodanie elementu z lewej części
        } else {
            tempArr[k++] = arr[j++]; // Dodanie elementu z prawej części
        }
    }

    while (i <= mid) { // Dodanie pozostałych elementów z lewej części, jeśli są
        tempArr[k++] = arr[i++];
    }

    while (j <= right) { // Dodanie pozostałych elementów z prawej części, jeśli są
        tempArr[k++] = arr[j++];
    }

    for (int p = left; p <= right; p++) { // Skopiowanie połączonych elementów z tempArr z powrotem do arr
        arr[p] = tempArr[p - left];
    }
}

// Merge Sort - dziel i łącz
template <typename T>
void mergeSort(std::vector<T>& arr, int left, int right, bool ascending = true) {
    if (left >= right)  // Koniec, jeśli jest jeden lub brak elementów
        return;
    
    int mid = left + (right - left) / 2; // Znalezienie środka tablicy
    mergeSort(arr, left, mid, ascending); // Rekurencyjne sortowanie lewej części
    mergeSort(arr, mid + 1, right, ascending); // Rekurencyjne sortowanie prawej części
      
    merge(arr, left, mid, right, ascending); // Połączenie posortowanych części
}

#endif