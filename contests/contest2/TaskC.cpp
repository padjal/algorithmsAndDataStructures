//A program which checks whether a password is strong.

#include <iostream>

using namespace std;

bool isPasswordStrong(string password){

     if(password.size() < 8){
         return false;
     }

    bool hasSmallLetter = false, hasBigLetter = false, hasDigit = false;
    for (int i = 0; i < password.size(); ++i) {
        if(islower(password[i])){
            hasSmallLetter = true;
        }
        if(isupper(password[i])){
            hasBigLetter = true;
        }
        if(isdigit(password[i])){
            hasDigit = true;
        }
    }

    return hasDigit && hasSmallLetter && hasBigLetter;
}

int main() {
    string password;

    cin >> password;

    isPasswordStrong(password) ? cout << "YES" : cout << "NO";
}
