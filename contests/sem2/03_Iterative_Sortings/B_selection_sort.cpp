/*
 * This program sorts an array of elements using the selection sort algorithm
 * and displays the number of swaps completed by the program.
 *
 * Author: Pavel Dzhalev
 * Copyright 2022
 */

#include <iostream>
#include <utility>

int selectionSort(int *arr, int elements) {
    int swaps = 0;

    for (int i = 0; i < elements - 1; ++i) {
        int min_element_index = i;
        for (int j = i + 1; j < elements; ++j) {
            if (arr[j] < arr[min_element_index]) {
                min_element_index = j;
            }
        }
        if (i != min_element_index) {
            std::swap(arr[i], arr[min_element_index]);
            swaps++;
        }
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
    int swaps = selectionSort(arr, number_of_elements);

    for (int i = 0; i < number_of_elements; ++i) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    std::cout << swaps;

    // Free memory
    delete[] arr;

    return 0;
}
