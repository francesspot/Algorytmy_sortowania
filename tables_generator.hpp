#include <iostream>
#include <cstdlib>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

using namespace std;

mt19937 gen(random_device{}());

template <typename T>
vector<T> generateRandomArray(int n, T minValue = 0, T maxValue = 1000000) {
  vector<T> arr(n);
  uniform_int_distribution<T> dis(minValue, maxValue);

  for (int i = 0; i < n; i++) {
    arr[i] = dis(gen);
  }
  return arr;
}

template <typename T>
vector<T> generatePartiallySortedArray(int n, T minValue = 0, T maxValue = 1000000, double sortedPercentage = 0.5) {
  vector<T> arr = generateRandomArray<T>(n, minValue, maxValue);

  int sortedElements = static_cast<int>(n * sortedPercentage);
  sortedElements = min(sortedElements, n);

  sort(arr.begin(), arr.begin() + sortedElements);
  return arr;
}

template <typename T>
vector<T> generateReverseSortedArray(int n, T minValue = 0, T maxValue = 1000000) {
  vector<T> arr = generateRandomArray<T>(n, minValue, maxValue);
  sort(arr.rbegin(), arr.rend());
  return arr;
}