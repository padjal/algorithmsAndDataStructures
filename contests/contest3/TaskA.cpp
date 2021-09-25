#include <iostream>

using namespace std;

int moveRight(int array[], int length){
    int lastElement = array[length-1];

    for (int i = 1; i < length; ++i) {
        array[i] = array[i-1];
    }

    array[0] = lastElement;
}

int countHemming(int array1[], int array2[], int length){
    int result;
    for (int i = 0; i < length; ++i) {
        if(array1[i] != array2[i] )
            result ++;
    }

    return result;
}

int main() {
    int n; //array size
    int* array; // program array

    cin >> n;

    array = new int[n];

    for (int i = 0; i < n; ++i){
        int number;
        cin >> number;
        array[i] = number;
    }

    // TODO:Find max Hemming

    int maxHemming;
    for (int i = 0; i < n; ++i) {
        int newArray[] = moveRight(array, n);
    }

    // TODO:

    delete array;
    array = nullptr;

    return 0;
}
