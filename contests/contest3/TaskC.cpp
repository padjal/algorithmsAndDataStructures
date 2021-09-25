//
// Created by padjal on 23.09.21 г..
//
#include <iostream>

using namespace std;

void PrintNumber(int a){
    PrintNumber(a + 1);
}

int main() {
    PrintNumber(1);
    return 0;
}