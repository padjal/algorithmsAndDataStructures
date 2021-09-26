//
// Created by padjal on 23.09.21 г..
// Rotate array by 90 degrees.
//
#include <iostream>

using std::cin, std::cout, std::endl;

int main() {
    int m, n;

    cin >> n >> m;

    if (n < 1 || m > 1000)
        return 0;

    int **arr = new int *[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[m];
    }

    // Read array.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }

    cout << m << " " << n << endl;

    // Display rotated matrix.
    for (int i = 0; i < m; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; ++i) {
        delete arr[i];
    }

    delete[] arr;
    arr = nullptr;
    return 0;
}
