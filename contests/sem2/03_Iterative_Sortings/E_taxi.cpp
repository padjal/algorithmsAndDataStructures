#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <utility>

void bubbleSort(std::vector<int> *vec) {
    for (size_t i = 0; i < vec->size() - 1; ++i) {
        for (size_t j = 0; j < vec->size() - i - 1; ++j) {
            if (vec->at(j) > vec->at(j + 1)) {
                std::swap(vec->at(j), vec->at(j + 1));
            }
        }
    }
}

int main() {
    std::vector<int> distances;
    std::vector<int> prices;

    std::string line;
    std::string line_two;
    std::getline(std::cin, line);

    std::stringstream stream(line);

    int value;
    while (stream >> value) {
        distances.push_back(value);
    }

    std::getline(std::cin, line_two);
    std::stringstream stream2(line_two);

    while (stream2 >> value) {
        prices.push_back(value);
    }

    bubbleSort(&distances);
    bubbleSort(&prices);

    int64_t sum = 0;
    for (int i = 0; i < distances.size(); ++i) {
        sum += distances.at(i) * prices.at(prices.size() - i - 1);
    }

    std::cout << sum;
    return 0;
}
