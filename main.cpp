#include <iostream>
#include <cstdlib>
#include <numeric>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <functional>
#include <algorithm>

#include "merge_sort.hpp"
#include "quicksort.hpp"
#include "heap_sort.hpp"
#include "introsort.hpp"

#include "tables_generator.hpp"
#include "test_sorting.hpp"

using namespace std;

const int numOfTest = 100;
ofstream file("results.csv");

using SortingAlgorithms = vector<pair<string, function<void(vector<int>&, int, int, bool)>>>;

SortingAlgorithms algorithms = {
    {"mergeSort", [](vector<int>& array, int left, int right, bool ascending){ mergeSort(array, left, right, ascending); }},
    {"quickSort", [](vector<int>& array, int left, int right, bool ascending){ quickSort(array, left, right, ascending); }},
    {"introSort", [](vector<int>& array, int left, int right, bool ascending){ introSort(array, left, right, ascending); }},
};

string toString(double value) {
    string str = to_string(value);
    replace(str.begin(), str.end(), '.', ',');
    return str;
}

string getCaseName(double sortedPercentage) {
    if (sortedPercentage > 0.0) {
        ostringstream oss;
        oss << "sorted_" << sortedPercentage * 100;
        return oss.str();
    }
    return "random";
}

void runTest(int n, const string& caseName, double sortedPercentage, bool reverse) {
    cout << "Przypadek: " << caseName << "\n";

    for (const auto& [name, func] : algorithms) {
        double sumTime = 0.0, minTime = 1000000, maxTime = 0.0;

        for (int run = 0; run < numOfTest; run++) {
            vector<int> arr = generateCaseArray<int>(n, sortedPercentage, reverse);
            double time = testSortingAlgorithm(arr, func);
            sumTime += time;
            minTime = min(minTime, time);
            maxTime = max(maxTime, time);
        }

        double avgTime = sumTime / numOfTest;
        file << name << ";" << n << ";" << caseName << ";" << toString(avgTime) << ";" << toString(minTime) << ";" << toString(maxTime) << "\n";
        cout << "  " << name << " | avg: " << avgTime << " | min: " << minTime << " | max: " << maxTime << "\n";
    }
}

int main() {
    vector<int> arrSizes = {10000, 50000, 100000, 500000, 1000000};
    vector<double> sortedPercentage = {0.25, 0.5, 0.75, 0.95, 0.99, 0.997};

    file << "algorithm;size;case;avg_time_ms;min_time_ms;max_time_ms\n";

    for (int n : arrSizes) {
        cout << "\n=== ROZMIAR: " << n << " ===\n";

        runTest(n, "random", 0.0, false);

        for (double p : sortedPercentage) {
            runTest(n, getCaseName(p), p, false);
        }

        runTest(n, "reverse", 0.0, true);
    }

    file.close();
    cout << "\nTesty zakończone. Wyniki zapisane do results.csv\n";
    return 0;
}