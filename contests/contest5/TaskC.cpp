//
// Solving traffic
//

#include <iostream>
#include <string>
#include <cmath>

class TrafficDeck {
 private:
    const int kInitialArraySize = 10;
    int *array;
    int arrSize;
    int currentIndex = -1;

 public:
    TrafficDeck() {
        array = new int[kInitialArraySize];
        arrSize = kInitialArraySize;
    }

    void pushBack(int n) {
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
    }

    void pushMiddle(int n) {
        currentIndex++;
        int mid = std::ceil(size() / 2.0);
        if (size() % 2 == 0) {
            mid++;
        }

        // Allocate memory
        arrSize += 1;
        int *newArray = new int[arrSize];

        // Copy elements
        for (int i = 0 ; i < mid - 1 ; ++i) {
            newArray[i] = array[i];
        }

        newArray[mid - 1] = n;

        // Copy elements
        for (int i = mid ; i < arrSize - 1 ; ++i) {
            newArray[i] = array[i - 1];
        }

        // Deleted old array and pass new
        delete[] array;
        array = newArray;
    }

    int popFront() {
        if (currentIndex == -1) {
            return -1;
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
        return result;
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
    TrafficDeck deck;

    int n;
    std::cin >> n;

    if (n < 1) {
        return 0;
    }

    for (int i = 0 ; i < n ; ++i) {
        std::cin >> input;

        if (input == "+") {
            std::cin >> input;
            deck.pushBack(std::stoi(input));
        } else if (input == "*") {
            std::cin >> input;
            deck.pushMiddle(std::stoi(input));
        } else if (input == "-") {
            std::cout << deck.popFront() << std::endl;
        }
    }

    return 0;
}
