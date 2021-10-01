//
// Created by padjal on 30.09.21 г..
// Sandwich program.
//

#include <string_view>
#include <iostream>
#include <string>

std::string decrypt(std::string input) {
    std::string result1, result2;
    std::string_view sv = input;
    sv.remove_suffix(1);
    bool front = true;
    while (sv.length() > 0) {
        if (front) {
            result1.push_back(sv.front());
            sv.remove_prefix(1);
            front = false;
        } else {
            result2.insert(0, 1, sv.front());
            sv.remove_prefix(1);
            front = true;
        }
    }

    result1.append(result2);
    return result1;
}

int main() {
    std::string input;
    getline(std::cin, input);
    std::cout << decrypt(input);
    return 0;
}

