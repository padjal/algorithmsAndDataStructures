//
// Created by padjal on 12.09.21 г..
//

//Greatest common divisor

#include <iostream>
#include <cmath>

using namespace std;

int findGCD(int a, int b, int* count){
    *count = *count + 1;
    if(b == 0){
        return a;
    }
    else{

        findGCD(b, a%b, count);
    }
}

int main() {
    int n;
    cin>>n;
    int counter = 0;

    int first, second;
    for (int i = 0; i < n; ++i) {
        double input;
        cin >> input;

        if((int)input != input){
            cout << "Sequence has float values!";
            return 0;
        }

        //If it's the first number.
        if(i == 0){
            first = input;
            continue;
        }else{
            second = input;
            first = findGCD(second, first, &counter);
        }

    }

    cout << abs(first) << " "<<counter;

    return 0;
}
