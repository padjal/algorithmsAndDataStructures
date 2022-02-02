/*
 * This program sorts an array of elements using the insertion sort algorithm modified
 * with a binary search for finding the index for insertion of the next element
 * and displays the number of numbers which were originally in their right place.
 *
 * Author: Pavel Dzhalev
 * Copyright 2022
 */

#include <iostream>

int binarySearch(int *arr, int item, int low, int high) {
    if (high <= low) {
        return (item > arr[low]) ? (low + 1) : low;
    }
    int mid = (low + high) / 2;
    if (item == arr[mid]) {
        return mid + 1;
    }
    if (item > arr[mid]) {
        return binarySearch(arr, item, mid + 1, high);
    }
    return binarySearch(arr, item, low, mid - 1);
}

int insertionSort(int *array, int elements) {
    int key, j, swaps = 0;
    for (int index = 1; index < elements; ++index) {
        key = array[index];
        j = index - 1;
        int loc = binarySearch(array, key, 0, j);
        while (j >= loc) {
            array[j + 1] = array[j];
            if (array[j] != key) {
                swaps++;
            }
            j--;
        }
        array[j + 1] = key;
    }
    return swaps;
}

int main() {
    // User input.
    int number_of_elements;
    std::cin >> number_of_elements;

    auto arr = new int[number_of_elements];

    // Get numbers.
    for (int i = 0; i < number_of_elements; ++i) {
        std::cin >> arr[i];
    }

    // Sort array and print results
    int swaps = insertionSort(arr, number_of_elements);

    for (int i = 0; i < number_of_elements; ++i) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    std::cout << swaps;

    // Free memory
    delete[] arr;

    return 0;
}
