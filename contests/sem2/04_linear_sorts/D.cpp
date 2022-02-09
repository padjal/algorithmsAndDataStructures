#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>

void countSort(std::vector<int> *numbers) {
    int max_element = numbers->at(0);
    int array_size = numbers->size();

    // Find max element
    for (int number : *numbers) {
        if (number > max_element) {
            max_element = number;
        }
    }

    int *count = new int[max_element + 1];

    for (int i = 0; i <= max_element; ++i) {
        count[i] = 0;
    }

    for (int number : *numbers) {
        count[number]++;
    }

    for (int i = 1; i <= max_element; ++i) {
        count[i] += count[i - 1];
    }

    int *resulting_array = new int[array_size];

    for (int i = numbers->size() - 1; i >= 0; --i) {
        resulting_array[count[numbers->at(i)] - 1] = numbers->at(i);
        count[numbers->at(i)]--;
    }

    // Reverse sort
    for (int i = 0; i < array_size; ++i) {
        numbers->at(numbers->size() - i - 1) = resulting_array[i];
    }

    // Free memory
    delete[] count;
    delete[] resulting_array;
}

std::string longestPalindrome(const std::string &str) {
    int letters[26];

    for (int i = 0; i < 26; ++i) {
        letters[i] = 0;
    }

    for (char ch : str) {
        int index = ch - 'A';
        letters[index]++;
    }

    std::string mid_char;
    std::string left;

    for (int index = 0; index < 26; ++index) {
        char letter = 'A' + index;

        if (letters[index] == 0) {
            continue;
        } else if (letters[index] % 2 == 1 && mid_char.empty()) {
            mid_char = letter;
            letters[index]--;
            if (letters[index] > 0) {
                for (int j = 0; j < letters[index] / 2; ++j) {
                    left.push_back(letter);
                }
            }
        } else {
            for (int j = 0; j < letters[index] / 2; ++j) {
                left.push_back(letter);
            }
        }
    }

    std::string right(left.rbegin(), left.rend());

    return (left + mid_char + right);
}

int main() {
    std::string line;

    int n;
    std::cin >> n;

    std::vector<int> letters;

    char next_char;
    std::cin >> std::noskipws >> next_char;
    for (int i = 0; i < n; ++i) {
        std::cin >> std::noskipws >> next_char;
        letters.push_back(next_char);
    }

    countSort(&letters);

    for (int number : letters) {
        line += static_cast<char>(number);
    }

    std::cout << longestPalindrome(line);

    return 0;
}
