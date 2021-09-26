//
// Created by padjal on 23.09.21 г..
// Find min value for an interval.
//
#include <iostream>
#include <cmath>

using std::cin, std::cout;

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

    int rootArraySize = ceil(static_cast<double>(n) / k);
    int* rootArray = new int[rootArraySize];
    int count = 0;
    int min = INT32_MAX;
    for (int i = 0; i < n; ++i) {
        count++;
        if(arr[i] < min)
            min = arr[i];
        if(count % k == 0 || count == n){
            rootArray[count] = min;
            min = INT32_MAX;
        }
    }

    for (int i = 0; i < rootArraySize; ++i) {
        cout << rootArray[i];
    }

    /*int min = INT32_MAX;
    for (int i = 0; i <= n - k; ++i) {
        for (int j = 0; j < k; ++j) {
            if (arr[i+j] < min)
                min = arr[i+j];
        }
        std::cout << min << " ";
        min = INT32_MAX;
    }*/

    delete[] arr;
    return 0;
}
