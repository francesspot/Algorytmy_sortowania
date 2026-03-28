#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


template <typename T>
void printArray(vector<T>& arr) {
  for (int i = 0; i < arr.size() - 1; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

template <typename T>
bool isSortedLarge(vector<T>& arr, bool ascending = true) {
  for (int i = 0; i < arr.size() - 1; i++) {
    if ((ascending && arr[i] > arr[i + 1]) || (!ascending && arr[i] < arr[i + 1])) {
      return false;
    }
  }
  return true;
}
