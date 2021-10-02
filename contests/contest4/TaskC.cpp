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
    for (char i: phrase) {
        if (i == ' ') {
            words++;
        }
    }

    int count = 0, index = 0;
    std::string name;
    for (int i = 0; i < names.length(); ++i) {
        // if ()
            name += names[i];

        // Secure that the loop will not end
        if (i == names.length() - 1) {
            i = -1;
            if (count == words) {

            }
        }
    }
    return 0;
}
