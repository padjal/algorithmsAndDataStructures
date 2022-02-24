/*
 * Iterative implementation of the merge sort algorithm.
 */

#include <iostream>
#include <vector>

/*
 * Can be replaced by std::min().
 */
int findMin(int a, int b) {
    return a >= b ? b : a;
}

/*
 * This function merges the two arrays
 */
void merge(std::vector<int> *v, int left, int middle, int right, std::vector<int> *result) {
    // std::vector<int> result;

    // Merge left and right side
    int i = left, j = middle + 1;
    while (i <= middle && j <= right) {
        if (v->at(i) <= v->at(j)) {
            result->push_back(v->at(i++));
        } else {
            result->push_back(v->at(j++));
        }
    }

    // Copy remaining elements of left sub-array
    while (i <= middle) {
        result->push_back(v->at(i++));
    }

    // Copy remaining elements of right sub-array
    while (j <= right) {
        result->push_back(v->at(j++));
    }

    // Replace sorted values in the original list
    for (int l = 0; l < result->size(); ++l) {
        v->at(left + l) = result->at(l);
    }
}

void mergeSort(std::vector<int> *v) {
    int group_size = 1;
    std::vector<int> result;
    while (group_size < v->size()) {
        for (int left = 0; left < v->size(); left += 2 * group_size) {
            int middle = findMin(left + group_size - 1, v->size() - 1);

            int right = findMin(left + 2 * group_size - 1, v->size() - 1);

            merge(v, left, middle, right, &result);

            result.clear();
        }
        group_size *= 2;
    }
}

void printVector(std::vector<int> *v) {
    for (int i = 0; i < v->size(); ++i) {
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

    mergeSort(&numbers);

    printVector(&numbers);

    return 0;
}
