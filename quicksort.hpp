#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <iostream>
#include <cstdlib>
#include <vector>

template <typename T>
void quickSort(std::vector<T>& arr, int left, int right, bool ascending = true) {
    
  if (left >= right)
    return;

  int i = left;
  int j = right;
  T pivot = arr[(left + right) / 2];

  while (i <= j) {
    if (ascending) {
      while (arr[i] < pivot) i++;
      while (arr[j] > pivot) j--;
    } else {
      while (arr[i] > pivot) i++;
      while (arr[j] < pivot) j--;
    }


    if (i <= j) {
      std::swap(arr[i], arr[j]);
      i++;
      j--;
    }
  }
    
  if (left < j) {
    quickSort(arr, left, j, ascending);
  }

  if (i < right) {
    quickSort(arr, i, right, ascending);
  }
}

#endif