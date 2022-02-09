#include <iostream>
#include <vector>

void countSort(int arr[], int n, int exp) {
    int *final_array = new int[n];
    int i, count[10] = {0};

    for (i = 0; i < n; ++i) {
        count[(arr[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; --i) {
        final_array[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; ++i) {
        arr[i] = final_array[i];
    }

    delete[] final_array;
}

int getBiggestNumber(const int arr[], int n) {
    int max_number = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max_number) {
            max_number = arr[i];
        }
    }

    return max_number;
}

void radixSort(int arr[], int n) {
    // Find the biggest number in the array
    int m = getBiggestNumber(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}

void lsd(int arr[], int n){

}

int main() {
    int n;

    std::cin >> n;

    int *array = new int[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    radixSort(array, n);

    for (int i = 0; i < n; ++i) {
        std::cout << array[i] << " ";
    }

    delete[] array;

    return 0;
}
