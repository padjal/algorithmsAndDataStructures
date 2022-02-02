/*
 * This program sorts an array of elements using the simple insertion sort algorithm
 * and displays the number of numbers which were originally in their right place.
 *
 * Author: Pavel Dzhalev
 * Copyright 2022
 */

#include <iostream>

int insertionSort(int *array, int elements) {
    int key, j, elements_in_place = 0;
    for (int index = 1; index < elements; ++index) {
        key = array[index];  // keep so that we don't lose it
        j = index - 1;       // previous element's index

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
        if (j + 1 == index) {
            elements_in_place++;
        }
    }
    return elements_in_place;
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
