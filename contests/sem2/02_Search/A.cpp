/*
 * Copyright (c) 2022-2022.
 *
 * This program finds the biggest and second biggest numbers
 * of a set of numbers between 100 and 150, without storing the
 * array.
 *
 * Author: Pavel Dzhalev
 */

#include <iostream>

int main() {
    int biggest_number = 100;
    int second_biggest_number;
    int input_number;

    do {
        std::cin >> input_number;

        if (input_number < 100 || input_number > 150) {
            continue;
        }
        if (input_number >= biggest_number) {
            second_biggest_number = biggest_number;
            biggest_number = input_number;
        } else if (input_number > second_biggest_number) {
            second_biggest_number = input_number;
        }
    } while (input_number != 0);

    std::cout << biggest_number << std::endl << second_biggest_number;
}
