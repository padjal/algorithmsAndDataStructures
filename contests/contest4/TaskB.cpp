//
// Created by padjal on 30.09.21 г..
// Display tables.
//

#include <iostream>
#include <string>

std::string checkPluses(std::string str1, std::string str2) {
    std::string result;
    if (str1.length() <= str2.length()) {
        for (int i = 0; i < str1.length(); ++i) {
            if (str1[i] == '+') {
                str2[i] = '+';
            }
        }
        return str2;
    } else {
        for (int i = 0; i < str2.length(); ++i) {
            if (str2[i] == '+') {
                str1[i] = '+';
            }
        }
        return str1;
    }
}

int main() {
    int n;  // number of rows
    std::cin >> n;

    // Validate input.
    if (n < 1 || n > 100) {
        return 0;
    }

    std::string firstRow, secondRow, thirdRow, previousRow;

    int m;  // number of columns
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

        if (i == 0) {
            std::cout << firstRow << std::endl;
            std::cout << secondRow << std::endl;
            previousRow = thirdRow;

            if (n == 1) {
                std::cout << thirdRow << std::endl;
            }

            firstRow = "";
            secondRow = "";
            thirdRow = "";
            continue;
        }

        std::cout << checkPluses(firstRow, previousRow) << std::endl;
        std::cout << secondRow << std::endl;
        previousRow = thirdRow;

        if (i == n - 1) {
            std::cout << thirdRow << std::endl;
        }

        firstRow = "";
        secondRow = "";
        thirdRow = "";
    }
    return 0;
}

