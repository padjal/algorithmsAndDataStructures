/*
 * Copyright (c) 2022-2022.
 *
 * This program searches for all occurrences of numbers in a given list
 * using left and right binary search and prints out the left-most and right-most
 * position of each number in the second list.
 *
 * The first list is ordered.
 *
 * Author: Pavel Dzhalev
 */

#include <iostream>
#include <vector>

int leftBinarySearch(int key, std::vector<int> list, int left, int right) {
    if (left > right) {
        return -1;
    }
    if (right - left < 1) {
        // Only one element remaining
        return left;
    }

    int mid = left + (right - left) / 2;

    if (list.at(mid) <= key) {
        return leftBinarySearch(key, list, mid + 1, right);
    } else {
        return leftBinarySearch(key, list, left, mid);
    }
}

int rightBinarySearch(int key, std::vector<int> list, int left, int right) {
    if (left > right) {
        return -1;
    }
    if (right - left < 1) {
        // Only one element remaining
        return right;
    }

    int mid = left + (right - left) / 2;

    if (list.at(mid) <= key) {
        if (right - left < 2) {
            // Only one element remaining
            return right;
        }
        return rightBinarySearch(key, list, mid, right);
    } else {
        return rightBinarySearch(key, list, left, mid - 1);
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

    for (int i: second_list) {
        int left = leftBinarySearch(i, first_list, 0, first_list.size() - 1);
        int right = rightBinarySearch(i, first_list, 0, first_list.size() - 1);

        if (left == -1 || right == -1) {
            std::cout << 0 << std::endl;
            continue;
        }

        std::cout << ++left << " ";
        std::cout << ++right << std::endl;
    }
    return 0;
}
