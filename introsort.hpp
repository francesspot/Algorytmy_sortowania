#ifndef INTROSORT_HPP
#define INTROSORT_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "heap_sort.hpp"

template <typename T>
void introSort(std::vector<T>& arr, int left, int right, bool ascending = true, int depthlimit = -1) {
  if (left >= right) {
    return;
  }

  if (depthlimit < 0) {
    int n = right - left + 1;
    depthlimit = 2 * static_cast<int>(std::log2(n));
  }

  if (depthlimit == 0) {
    heapSort(arr, left, right, ascending);
    return;
  }

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
    introSort(arr, left, j, ascending, depthlimit - 1);
  }
  if (i < right) {
    introSort(arr, i, right, ascending, depthlimit - 1);
  }
}

#endif