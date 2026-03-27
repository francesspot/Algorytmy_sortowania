#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

template <typename T>
void quickSort(vector<T>& arr, int left, int right, bool ascending = true) {
    
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
      swap(arr[i], arr[j]);
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

