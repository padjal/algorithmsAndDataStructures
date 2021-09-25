//Without arrays.

#include <iostream>
#include <vector>

using namespace std;

vector<int> AddNumbers(int iterations, vector<int> initialVector){
    if(iterations > 0) {
        int input;
        cin >> input;
        initialVector.push_back(input);
        initialVector = (iterations - 1, initialVector);
    }

        return initialVector;

}

void DisplayNumbers(vector<int> vec){

    if(vec.size() > 0){
        cout << *vec.rbegin();
        vec.pop_back();
        DisplayNumbers(vec);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> numbers;
    numbers = AddNumbers(n, numbers);

    DisplayNumbers(numbers);

    return 0;
}
