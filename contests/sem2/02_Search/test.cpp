/*
 * Copyright (c) 2022-2022.
 *
 * This program
 *
 * Author: Pavel Dzhalev
 */

#include <iostream>
#include <vector>

int binarySearch(int key, std::vector<int> numbers, int left, int right) {
    if (left > right) {
        return left;
    }

    int mid = left + (right - left) / 2;

    if (numbers.at(mid) > key) {
        return binarySearch(key, numbers, left, mid - 1);
    } else {
        return binarySearch(key, numbers, mid + 1, right);
    }
}

int main() {
    int n;  // Limits: >= 1
    int m;  // Limits: <- 40 000

    std::cin >> n >> m;

    if (n < 1 || m > 40000) {
        return 0;
    }

    std::vector<int> first_list = std::vector<int>();
    std::vector<int> second_list = std::vector<int>();

    for (int i = 0; i < n; ++i) {
        int next_number;
        std::cin >> next_number;
        first_list.push_back(next_number);
    }

    for (int i = 0; i < m; ++i) {
        int next_number;
        std::cin >> next_number;
        second_list.push_back(next_number);
    }

    std::cout << binarySearch(3, first_list, 0, first_list.size() - 1);
    return 0;
}