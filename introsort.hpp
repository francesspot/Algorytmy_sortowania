#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "heap_sort.hpp"

using namespace std;

template <typename T>
void introSort(vector<T>& arr, int left, int right, bool ascending = true, int depthlimit = -1) {
  if (left >= right) {
    return;
  }

  if (depthlimit < 0) {
    depthlimit = 2 * (int)log2(right - left + 1);
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
      swap(arr[i], arr[j]);
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