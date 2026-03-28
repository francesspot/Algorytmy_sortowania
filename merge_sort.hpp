#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <iostream>
#include <cstdlib>
#include <vector>

template <typename T>
void merge(std::vector<T>& arr, int left, int mid, int right, bool ascending = true) {
    int i = left;
    int j = mid + 1;

    std::vector<T> tempArr(right - left + 1);
    int k = 0;
    while (i <= mid && j <= right) {
        if ((ascending && arr[i] <= arr[j]) || (!ascending && arr[i] >= arr[j])) {
            tempArr[k++] = arr[i++];
        } else {
            tempArr[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        tempArr[k++] = arr[i++];
    }

    while (j <= right) {
        tempArr[k++] = arr[j++];
    }

    for (int p = left; p <= right; p++) {
        arr[p] = tempArr[p - left];
    }
}

template <typename T>
void mergeSort(std::vector<T>& arr, int left, int right, bool ascending = true) {
    if (left >= right)
        return;
    
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, ascending);
    mergeSort(arr, mid + 1, right, ascending);
      
    merge(arr, left, mid, right, ascending);
}

#endif