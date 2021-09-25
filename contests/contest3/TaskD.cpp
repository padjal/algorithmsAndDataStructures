//
// Created by padjal on 23.09.21 г..
// Find min value for an interval.
//
#include <iostream>

using std::cin;

int main() {
    int n, k;

    cin >> n >> k;

    if (n < 1 || n > 150000 || k < 1 || k > 10000 || k > n)
        return 0;

    auto *arr = new int[n];

    int number;
    for (int i = 0; i < n; ++i) {
        cin >> number;
        arr[i] = number;
    }

    /*int counter = 0;
    int min = INT32_MAX;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < min)
            min = arr[i];
        counter++;
        if (counter == k || i == n - 1) {
            counter = 0;
            std::cout << min << std::endl;
            min = INT32_MAX;
        }
    }*/

    int min = INT32_MAX;
    for (int i = 0; i < n + 1 - k; i++) {
        for (int j = i; j < k + i; ++j) {
            if (arr[i] < min)
                min = arr[i];
        }
        std::cout << min << std::endl;
        min = INT32_MAX;
    }

    delete[] arr;
    return 0;
}
