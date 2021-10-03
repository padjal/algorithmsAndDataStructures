//
// Created by padjal on 30.09.21 г..
// Find different letters.
//

#include <iostream>
#include <string>
#include <algorithm>

std::string findDifferent(std::string str1, std::string str2) {
    std::string result;
    for (char i : str1) {
        if (str2.find(i) == -1) {
            if (result.find(i) == -1) {
                if (i != ' ') {
                    result += i;
                }
            }
        }
    }

    return result;
}

int main() {
    std::string str1, str2;
    getline(std::cin, str1);
    getline(std::cin, str2);

    std::string result;
    result += findDifferent(str1, str2);
    result += findDifferent(str2, str1);

    std::sort(std::begin(result), std::end(result));

    std::string result2;
    for (char i : result) {
        result2 += i;
        result2 += " ";
    }

    if (result2.length() == 0) {
        result2 = "NONE";
    }

    std::cout << result2;

    return 0;
}

