//A program for finding special palindroms.

#include <iostream>
#include <regex>

using namespace std;

bool evaluateString(const string& input){
    string newString = input;
    int startIndex = 0;
    int endIndex = input.size()-1;
    char currentConsonant;

    //TODO:Find a better way to check if current char is a consonant. Maybe try using regular expressions.
    while (startIndex != endIndex){
        //auto variable = regex_match(to_string(newString[startIndex]), regex("[b-df-hj-np-tv-z]"));
        if(newString[startIndex] != 'a' && newString[startIndex] != 'e' && newString[startIndex] != 'o' &&
        newString[startIndex] != 'i' && newString[startIndex] != 'u' && newString[startIndex] != 'y'){
            currentConsonant = newString[startIndex];

            if(newString[endIndex] != 'a' && newString[endIndex] != 'e' && newString[endIndex] != 'o' &&
               newString[endIndex] != 'i' && newString[endIndex] != 'u' && newString[endIndex] != 'y'){

                //Change consonants
                newString[startIndex] = newString[endIndex];
                newString[endIndex] = currentConsonant;

                if(endIndex - startIndex < 3)
                    return true;

                startIndex++;
                endIndex--;
            }else{
                endIndex--;
            }
        }else{
            startIndex++;
        }
    }

    return input == newString;
}

int main() {
    string input;
    cin >> input;

    bool result = evaluateString(input);

    result ? cout << "YES" : cout << "NO";

    return 0;
}
