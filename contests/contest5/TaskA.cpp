//
// Custom stack implementation.
//

#include <iostream>
#include <string>

class Stack {
 private:
    const int kInitialArraySize = 10;
    int *array;
    int arrSize;
    int currentIndex = -1;

 public:
    Stack() {
        array = new int[kInitialArraySize];
        arrSize = kInitialArraySize;
    }

    std::string push(int n) {
        currentIndex++;
        if (currentIndex + 1 > arrSize) {
            // Allocate memory
            arrSize *= 2;
            int *newArray = new int[arrSize];

            // Copy elements
            for (int i = 0 ; i < currentIndex + 1 ; ++i) {
                newArray[i] = array[i];
            }

            // Deleted old array and pass new
            delete[] array;
            array = newArray;
        }

        array[currentIndex] = n;
        return "ok";
    }

    std::string pop() {
        if (currentIndex == -1) {
            return "error";
        }

        int result = array[currentIndex];
        currentIndex--;
        return std::to_string(result);
    }

    std::string back() {
        if (currentIndex == -1) {
            return "error";
        }

        return std::to_string(array[currentIndex]);
    }

    int size() {
        return currentIndex + 1;
    }

    std::string clear() {
        currentIndex = -1;
        delete[] array;
        arrSize = kInitialArraySize;
        array = new int[kInitialArraySize];
        return "ok";
    }
};

int main() {
    std::string input;
    Stack stack;

    do {
        std::cin >> input;

        if (input == "push") {
            std::cin >> input;
            std::cout << stack.push(std::stoi(input)) << std::endl;
        } else if (input == "pop") {
            std::cout << stack.pop() << std::endl;
        } else if (input == "back") {
            std::cout << stack.back() << std::endl;
        } else if (input == "size") {
            std::cout << stack.size() << std::endl;
        } else if (input == "clear") {
            std::cout << stack.clear() << std::endl;
        }
    } while (input != "exit");

    std::cout << "bye";

    return 0;
}
