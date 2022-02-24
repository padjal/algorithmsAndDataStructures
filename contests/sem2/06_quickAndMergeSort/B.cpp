#include <iostream>
#include <vector>
#include <utility>

int count = -1;

void printVector(std::vector<int> *v) {
    for (int i = 0; i < v->size(); ++i) {
        std::cout << v->at(i) << " ";
    }
}

void quickSort(std::vector<int> *v, int low, int high) {
    count++;
    int i = low, j = high;
    int pivot = v->at((low + high) / 2);

    do {
        while (v->at(i) < pivot) {
            i++;
        }
        while (v->at(j) > pivot) {
            j--;
        }

        if (i <= j) {
            if (v->at(i) > v->at(j)) {
                std::swap(v->at(i), v->at(j));
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < high) {
        quickSort(v, i, high);
    }
    if (low < j) {
        quickSort(v, low, j);
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

    std::cout << count << std::endl;

    printVector(&numbers);

    return 0;
}
