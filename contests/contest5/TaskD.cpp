//
// Custom stack implementation.
//

#include <iostream>
#include <string>

class CustomStack {
 private:
    const int kInitialArraySize = 10;
    char *array;
    int arrSize;
    int currentIndex = -1;

 public:
    CustomStack() {
        array = new char[kInitialArraySize];
        arrSize = kInitialArraySize;
    }

    void push(char n) {
        currentIndex++;
        if (currentIndex + 1 > arrSize) {
            // Allocate memory
            arrSize *= 2;
            char *newArray = new char[arrSize];

            // Copy elements
            for (int i = 0 ; i < currentIndex + 1 ; ++i) {
                newArray[i] = array[i];
            }

            // Deleted old array and pass new
            delete[] array;
            array = newArray;
        }

        array[currentIndex] = n;
    }

    char pop() {
        if (currentIndex == -1) {
            return ' ';
        }

        char result = array[currentIndex];
        currentIndex--;
        return result;
    }

    char back() {
        if (currentIndex == -1) {
            return ' ';
        }

        return array[currentIndex];
    }

    int size() {
        return currentIndex + 1;
    }

    void clear() {
        currentIndex = -1;
        delete[] array;
        arrSize = kInitialArraySize;
        array = new char[kInitialArraySize];
    }
};

int main() {
    std::string input;
    CustomStack customStack;

    getline(std::cin, input);

    for (char c : input) {
        if (customStack.back() == '(' && c == ')' ||
            customStack.back() == '[' && c == ']' ||
            customStack.back() == '{' && c == '}') {
            customStack.pop();
        } else {
            customStack.push(c);
        }
    }

    if (customStack.size() == 0) {
        std::cout << "yes";
    } else {
        std::cout << "no";
    }

    return 0;
}
