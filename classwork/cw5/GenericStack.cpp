//
// Created by padjal on 4.10.21 г..
//

#include <iostream>
#include <algorithm>

template <typename T>

class GenericStack {
    // Pop
    // Push
    // Peek
    // Pointer

private:
    T* array = new T[10];
    int topElementIndex = 0;
    int size = 10;

public:
    T pop(){
        if(topElementIndex == -1){
            throw new std::exception();
        }

        T result = array[topElementIndex];
        topElementIndex--;
        return result;
    }

    void push(T input){
        // Check if there is space
        if(topElementIndex + 1 >= size){
            T* tempArray[] = new T[size];

            for (int i = 0 ; i < size ; ++i) {
                tempArray[i] = array[i];
            }

            delete[] array;

            size*=2;
            array = new T[size];

            for (int i = 0 ; i < size ; ++i) {
                array[i] = tempArray[i];
            }

            delete[] tempArray;
        }

        topElementIndex++;

        array[topElementIndex] = input;
    }

    T peek(){
        T result = array[topElementIndex];
        return result;
    }
};

int main() {

    return 0;
}

