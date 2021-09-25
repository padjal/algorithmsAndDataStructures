//Find if two strings are the same.

#include <iostream>
#include <string>
using namespace std;


bool Compare(string s1, string s2) {
    int i = 0;
    while(s1[i] == s2[i]){
        if(s1[i] == '\0' || s2[i] == '\0')
            break;
        i++;
    }
    if(s1[i] == '\0' && s2[i] == '\0')
        return 0;
    else
        return 1;
}

int main()
{
    string s1, s2;

    cin >> s1;
    cin >> s2;

    int flag = Compare(s1, s2);
    if (flag == 0)
        cout << "yes";
    else
        cout << "no";
}
