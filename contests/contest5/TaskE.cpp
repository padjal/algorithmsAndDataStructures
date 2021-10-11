//
// Created by padjal on 4.10.21 г..
// Unpack strings.
//

#include <iostream>
#include <string>

std::string unpack(std::string str) {
    int numberPos = str.find_first_of("123456789");

    if (numberPos == -1) {
        return str;
    }

    // There is definitely at least one number.
    int lastBracket = str.find_last_of(']');
    std::string inner = unpack(str.substr(numberPos + 2, lastBracket - numberPos - 2));

    int multiplier = std::stoi(std::to_string(str.at(numberPos) - 48));

    std::string result = "";
    for (int i = 0 ; i < multiplier ; ++i) {
        result += inner;
    }

    str.replace(numberPos, lastBracket + 1, result);

    return str;
}

void test(const std::string &str) {
    std::cout << "Testing for: " << str << std::endl;
    std::cout << "Result: " << unpack(str) << std::endl;
}

int main() {
    // test("1[aaaa]");
    // test("1[a3[bb]]");
    // test("1[1[1[1[1[e]d]c]b]a]");

    std::string input;
    std::cin >> input;
    std::cout << unpack(input);

    return 0;
}

