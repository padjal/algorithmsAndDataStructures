//
// Created by padjal on 30.09.21 г..
// Program for solving the
//

#include <iostream>
#include <string>

std::string countNSay(std::string firstNumber, int iteration) {
    // Base cases
    if (iteration == 1) {
        return firstNumber;
    }

    std::string previousNumber, number;
    int count;

    for (int i = 1; i <= iteration; ++i) {
        number = "";
        if (i == 1) {
            previousNumber = firstNumber;
            continue;
        }

        char currentChar = previousNumber[0];
        count = 1;


        // Check if previousNumber only has one character. Ex: 1, 2, 3 ...
        if (previousNumber.length() == 1) {
            number += "1";
            number += currentChar;
            previousNumber = number;
            continue;
        }
        for (int j = 1; j < previousNumber.length(); ++j) {
            if (previousNumber.at(j) == currentChar) {
                count++;

                if (j + 1 == previousNumber.length()) {
                    number += std::to_string(count);
                    number += currentChar;
                }
            } else {
                number += std::to_string(count) + currentChar;
                currentChar = previousNumber.at(j);
                count = 1;

                if (j + 1 == previousNumber.length()) {
                    number += std::to_string(count);
                    number += currentChar;
                }
            }
        }
        previousNumber = number;
    }

    return number;
}

int main() {
    int x1, n;
    std::cin >> x1 >> n;

    // Check input
    if (x1 < 0 || x1 > 100 || n < 1 || n > 25) {
        return 0;
    }

    std::string number = std::to_string(x1);

    std::cout << countNSay(number, n);

    return 0;
}
