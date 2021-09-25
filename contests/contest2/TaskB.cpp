//A program which guesses how many questions are needed to guess a number between 1 and n.

#include <iostream>

using namespace std;

void guessNumber(int n){
    //Number is between 1 and n;
    //Is number positive or negative or 0?
    //Is number odd or even?

    if(n >= 1){
        int questions = 0;
        while (n != 1){
            if(n % 2 == 1) n+=1;
            n /= 2;
            questions++;
        }
        cout<<questions;
    }

    //Check for negative numbers

}

int main() {
    int n;
    std::cin >> n;

    guessNumber(n);
}
