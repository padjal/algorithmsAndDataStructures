#include <iostream>
#include <vector>

void countSort(std::vector<int> *numbers) {
    int max_element = numbers->at(0);

    // Find max element
    for (int number : *numbers) {
        if (number > max_element) {
            max_element = number;
        }
    }

    // Create a new array which keeps frequency of elements
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

    int *resulting_array = new int[numbers->size()];

    for (int i = numbers->size() - 1; i >= 0; --i) {
        resulting_array[count[numbers->at(i)] - 1] = numbers->at(i);
        count[numbers->at(i)]--;
    }

    for (int i = 0; i < numbers->size(); ++i) {
        numbers->at(i) = resulting_array[i];
    }

    // Free memory
    delete[] count;
    delete[] resulting_array;
}

void printVector(std::vector<int> *numbers) {
    for (int number : *numbers) {
        std::cout << number << " ";
    }
}

int main() {
    int n;

    std::cin >> n;

    std::vector<int> numbers;

    int next_number;
    for (int i = 0; i < n; ++i) {
        std::cin >> next_number;
        numbers.push_back(next_number);
    }

    countSort(&numbers);

    printVector(&numbers);

    return 0;
}
