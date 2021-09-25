//Fibonacci strings.

#include <iostream>

using namespace std;

int main() {

    string first, second;
    cin >> first >> second;
    int n, m;
    cin >> n >> m;

    for (int i = 3 ; i <= n; ++i) {
        string next = first + second;
        first = second;
        second = next;
    }

    cout << second[m-1];

    return 0;
}
