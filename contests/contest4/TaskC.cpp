//
// Created by padjal on 30.09.21 г..
// Count people.
//

#include <iostream>
#include <sstream>
#include <string>

int main() {
    // Take user input
    std::string phrase, names;
    std::getline(std::cin, phrase);
    std::getline(std::cin, names);

    // Count how many words.
    int words = 1;
    for (char i : phrase) {
        if (i == ' ') {
            words++;
        }
    }

    // Count how many people.
    int people = 1;
    for (char i : names) {
        if (i == ' ') {
            people++;
        }
    }

    int count = words % people;

    if (count == 0) {
        count = people;
    }
    std::string name;
    int whiteSpaceCount = 1;
    for (char i : names) {
        if (i == ' ') {
            whiteSpaceCount++;
            continue;
        }
        if (whiteSpaceCount == count) {
            name += i;
        }
    }

    std::cout << name;
    return 0;
}
