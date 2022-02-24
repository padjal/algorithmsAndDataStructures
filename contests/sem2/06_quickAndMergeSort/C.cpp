/*
 * Realisation of quicksort using the Lomuto partitioning scheme.
 * Reference to
 * https://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/
 */

#include <iostream>
#include <vector>
#include <utility>

int count = -1;

int partition(std::vector<int> *v, int low, int high) {
    int pivot = v->at(high);
    int i = (low - 1);

    for (int j = low; j <= high - 1; ++j) {
        if (v->at(j) <= pivot) {
            ++i;
            std::swap(v->at(i), v->at(j));
        }
    }
    std::swap(v->at(i + 1), v->at(high));
    return (i + 1);
}

void quickSort(std::vector<int> *v, int low, int high) {
    if (low < high) {
        count++;
        int pivot = partition(v, low, high);

        quickSort(v, low, pivot - 1);
        quickSort(v, pivot + 1, high);
    }
}

void printVector(std::vector<int> *v) {
    for (int i = 0; i < static_cast<int>(v->size()); ++i) {
        std::cout << v->at(i) << " ";
    }
}

int main() {
    int n, next_number;

    std::cin >> n;

    std::vector<int> numbers;

    for (int i = 0; i < n; ++i) {
        std::cin >> next_number;
        numbers.push_back(next_number);
    }

    quickSort(&numbers, 0, numbers.size() - 1);

    if (count == -1) {
        count++;
    }

    std::cout << count << std::endl;

    printVector(&numbers);

    return 0;
}
