//An app for counting votes.

#include <iostream>

using namespace std;

bool isValid(string input){
    int result = 0;
    for (int i = 0; i < input.size(); ++i) {
        if(input[i] == '+')
            result++;
    }

    return result == 1;
}

string countVotes(int n, int m){
    int *parties = new int [n];
    int validVotes = 0;
    string result = "";

    //Count votes
    string input;
    for (int i = 0; i < m; ++i) {
        cin >> input;
        if(!isValid(input))
            continue;
        validVotes++;
        for (int j = 0; j < n; ++j) {
            if(input[j] == '+')
                parties[j]++;
        }
    }

    //Check which parties enter the parliament.
    double minVotes = 7*validVotes;
    for (int i = 0; i < n; ++i) {
        if(parties[i]*100 >= minVotes){
            result += to_string(i + 1) + " ";
        }
    }

    return result;
}

int main() {

    int n, m;
    cin >> n >> m;

    cout << countVotes(n, m);

    return 0;
}
