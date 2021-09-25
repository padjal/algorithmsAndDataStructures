//
// Created by padjal on 23.09.21 г..
// Pascal's triangle
//
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int n, m;

    cin >> n >> m;

    if (n < 1 || m > 150 || n*m > 1024)
        return 0;

    int64_t **array = new int64_t *[n];
    for (int i = 0; i < n; ++i) {
        array[i] = new int64_t[m];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 || j == 0) {
                array[i][j] = 1;
            } else {
                array[i][j] = array[i - 1][j] + array[i][j - 1];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; ++i) {
        delete[] array[i];
    }

    delete[] array;
    array = nullptr;

    return 0;
}
