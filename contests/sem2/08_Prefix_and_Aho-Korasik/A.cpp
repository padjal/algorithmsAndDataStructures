#include <iostream>
#include <string>
#include <vector>

/*
 * Code attribution to https://cp-algorithms.com/string/prefix-function.html
 */

std::vector<int> prefixFunction(std::string const s) {
    size_t n = s.length();
    std::vector<int> pi(n);
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k <= i; ++k) {
            if (s.substr(0, k) == s.substr(i - k + 1, k)) {
                pi.at(i) = k;
            }
        }
    }

    return pi;
}

std::vector<int> optimizedPrefixFunction(std::string s) {
    size_t n = s.length();
    std::vector<int> pi(n);
    for (size_t i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

template <typename T>
void printVector(std::vector<T> const &vector) {
    for (auto elem: vector) {
        std::cout << elem << " ";
    }
}

int main() {
    std::string input;

    std::getline(std::cin, input);

    auto res = optimizedPrefixFunction(input);

    printVector(res);

    return 0;
}
