//
// Created by padjal on 23.09.21 г..
//
#include <iostream>

using std::cin, std::cout, std::endl;

int main() {
    int m, n;

    cin >> n >> m;

    if (n < 1 || m > 1000)
        return 0;

    int** arr = new int*[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[m];
    }

    /*int** turnedArr = new int*[m];
    for (int i = 0; i < m; ++i) {
        turnedArr[i] = new int[n];
    }*/

    // Read array.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }

    // Rotate matrix.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << arr[n - i][i] << " ";
        }
        cout << endl;
    }

    // Display rotated matrix.
    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << turnedArr[i][j] << " ";
        }
        cout << endl;
    }*/

    for (int i = 0; i < n; ++i) {
        delete arr[i];
    }

    delete[] arr;
    return 0;
}