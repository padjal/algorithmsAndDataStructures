/*
 * This program sorts an array of elements using the bubble sort algorithm
 * and displays the number of swaps completed by the program.
 *
 * Author: Pavel Dzhalev
 * Copyright 2022
 */

#include <iostream>

void swapValues(int *array, int index_one, int index_two) {
    int temp = array[index_one];
    array[index_one] = array[index_two];
    array[index_two] = temp;
}

int bubbleSort(int *array, int array_size) {
    bool array_sorted = false;
    int swaps = 0;

    for (int index = 0; index < array_size - 1 && !array_sorted; ++index) {
        int swaps_per_iteration = 0;
        for (int j = 0; j < array_size - index - 1; ++j) {
            if (array[j] > array[j + 1]) {
                swapValues(array, j, j + 1);
                swaps++;
                swaps_per_iteration++;
            }
        }
        if (swaps_per_iteration == 0) {
            array_sorted = true;
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
    int swaps = bubbleSort(arr, number_of_elements);

    for (int i = 0; i < number_of_elements; ++i) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    std::cout << swaps;

    // Free memory
    delete[] arr;

    return 0;
}
