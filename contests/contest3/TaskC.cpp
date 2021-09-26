//
// Created by padjal on 23.09.21 г..
// Find how many zeros in an array interval.
//
#include <iostream>
#include <cmath>
#include <string>

using std::cin, std::cout;

int main() {
    int n;  // number of elements in array
    cin >> n;

    // Enter numbers.
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Root decomposition
    int nRoot = ceil(sqrt(n));  // Number of elements of the root Array.
    int group = ceil(static_cast<double>(n) / nRoot);  // Number of elements in each group.
    int *rootArray = new int[nRoot];
    int counter = 0;
    int start = 0, end = group;
    for (int i = 0; i < nRoot; ++i) {
        for (int j = start; j < end; ++j) {
            if (arr[j] == 0)
                counter++;
        }
        start = end;
        end = end + group > n ? n : end + group;
        rootArray[i] = counter;
        counter = 0;
    }

    int k;  // Number of queries.
    cin >> k;

    int lowBound, upBound, zeros = 0;
    std::string result;
    for (int i = 0; i < k; ++i) {
        cin >> lowBound >> upBound;
        lowBound--;
        upBound--;
        if (upBound - lowBound > 2 * nRoot) {
            // Use root array.
            // Reach group
            while (lowBound % group != 0) {
                if (arr[lowBound] == 0)
                    zeros++;
                lowBound++;
            }
            // Groups
            while (lowBound < upBound) {
                if (lowBound + group >= upBound) {
                    break;
                }
                zeros += rootArray[lowBound / group];

                lowBound += group;
            }
            // Finish
            while (lowBound <= upBound) {
                if (arr[lowBound] == 0)
                    zeros++;
                lowBound++;
            }
        } else {
            for (int j = lowBound; j <= upBound; ++j) {
                if (arr[j] == 0)
                    zeros++;
            }
        }

        result += std::to_string(zeros) + " ";
        zeros = 0;
    }

    std::cout << result;
    return 0;
}
