//
// Created by padjal on 30.09.21 г..
// Display tables.
//

#include <iostream>

int main() {
    int n; // number of rows
    std::cin >> n;

    // Validate input.
    if (n < 1 || n > 100) {
        return 0;
    }

    std::string firstRow, secondRow, thirdRow;

    int m; // number of columns
    for (int i = 0; i < n; ++i) {
        std::cin >> m;

        // Validate m
        if (m < 1 || m > 10) {
            return 0;
        }

        int width;
        for (int j = 0; j < m; ++j) {
            std::cin >> width;
            if (j == 0) {
                firstRow += "+";
                secondRow += "|";
                thirdRow += "+";
            }

            for (int k = 0; k < width; ++k) {
                firstRow += "-";
                secondRow += " ";
                thirdRow += "-";
            }

            firstRow += "+";
            secondRow += "|";
            thirdRow += "+";


        }

        std::cout << firstRow << std::endl;
        std::cout << secondRow << std::endl;

        firstRow = "";
        secondRow = "";
        thirdRow = "";


    }
    return 0;
}

