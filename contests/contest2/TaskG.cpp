//
// Created by padjal on 12.09.21 г..
//

//Least common multiple

#include <iostream>
#include <cmath>

using namespace std;

int findGCD(int a, int b){
    if (b == 0)
        return a;
    return findGCD(b, a % b);
}

// Function to return LCM of two numbers
int lcm(int a, int b)
{
    return (a / findGCD(a, b)) * b;
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
            first = lcm(first, second);
        }

    }

    cout << abs(first);

    return 0;
}
