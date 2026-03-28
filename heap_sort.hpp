#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

#include <iostream>
#include <cstdlib>
#include <vector>

template <typename T>
void heapify(std::vector<T>& arr, int n, int index, int offset = 0, bool ascending = true) {
  int root = index;
  int leftChild = 2 * index + 1;
  int rightChild = 2 * index + 2;

  if (leftChild < n) {
    if ((ascending && arr[leftChild + offset] > arr[root + offset]) || (!ascending && arr[leftChild + offset] < arr[root + offset])) {
      root = leftChild;
    }
  }

  if (rightChild < n) {
    if ((ascending && arr[rightChild + offset] > arr[root + offset]) || (!ascending && arr[rightChild + offset] < arr[root + offset])) {
        root = rightChild;
      }
  }

  if (root != index) {
    std::swap(arr[index + offset], arr[root + offset]);
    heapify(arr, n, root, offset, ascending);
  }
}

template <typename T>
void heapSort(std::vector<T>& arr, int left, int right, bool ascending = true) {
  int n = right - left + 1;

  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i, left, ascending);
  }

  for (int i = n - 1; i > 0; i--) {
    std::swap(arr[left], arr[i + left]);
    heapify(arr, i, 0, left, ascending);
  }
}

#endif