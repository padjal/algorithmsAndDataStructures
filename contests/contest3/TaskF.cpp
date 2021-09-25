//
// Created by padjal on 23.09.21 г..
//
#include <iostream>

using namespace std;

int main() {
    int n, m;
    int* array;

    cin >> n >> m;

    array = new int[n, m];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(i == 1 || j == 0)
                array[i, j] = 1;
        }
    }

    delete array;
    array = nullptr;

    return 0;
}