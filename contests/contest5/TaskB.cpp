//
// Custom deck (double-sided queue) implementation.
//

#include <iostream>
#include <string>

class Deck {
 private:
    const int kInitialArraySize = 10;
    int *array;
    int arrSize;
    int currentIndex = -1;

 public:
    Deck() {
        array = new int[kInitialArraySize];
        arrSize = kInitialArraySize;
    }

    std::string pushBack(int n) {
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

    std::string pushFront(int n) {
        currentIndex++;

        // Allocate memory
        arrSize += 1;
        int *newArray = new int[arrSize];

        newArray[0] = n;

        // Copy elements
        for (int i = 1 ; i < currentIndex + 1 ; ++i) {
            newArray[i] = array[i - 1];
        }

        // Deleted old array and pass new
        delete[] array;
        array = newArray;

        return "ok";
    }

    std::string popBack() {
        if (currentIndex == -1) {
            return "error";
        }

        int result = array[currentIndex];
        currentIndex--;
        return std::to_string(result);
    }

    std::string popFront() {
        if (currentIndex == -1) {
            return "error";
        }

        int result = array[0];

        // Allocate memory
        arrSize -= 1;
        int *newArray = new int[arrSize];

        // Copy elements
        for (int i = 0 ; i < currentIndex + 1 ; ++i) {
            newArray[i] = array[i + 1];
        }

        // Deleted old array and pass new
        delete[] array;
        array = newArray;

        currentIndex--;
        return std::to_string(result);
    }

    std::string back() {
        if (currentIndex == -1) {
            return "error";
        }

        return std::to_string(array[currentIndex]);
    }

    std::string front() {
        if (currentIndex == -1) {
            return "error";
        }

        return std::to_string(array[0]);
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
    Deck deck;

    do {
        std::cin >> input;

        if (input == "push_back") {
            std::cin >> input;
            std::cout << deck.pushBack(std::stoi(input)) << std::endl;
        } else if (input == "push_front") {
            std::cin >> input;
            std::cout << deck.pushFront(std::stoi(input)) << std::endl;
        } else if (input == "pop_front") {
            std::cout << deck.popFront() << std::endl;
        } else if (input == "pop_back") {
            std::cout << deck.popBack() << std::endl;
        } else if (input == "back") {
            std::cout << deck.back() << std::endl;
        } else if (input == "front") {
            std::cout << deck.front() << std::endl;
        } else if (input == "size") {
            std::cout << deck.size() << std::endl;
        } else if (input == "clear") {
            std::cout << deck.clear() << std::endl;
        }
    } while (input != "exit");

    std::cout << "bye";

    return 0;
}
