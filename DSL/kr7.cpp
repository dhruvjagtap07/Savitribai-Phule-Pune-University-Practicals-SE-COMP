// KR Assignment 7

// In any language program mostly syntax error occurs due to unbalancing delimiter such as
// (),{},[]. Write C++ program using stack to check whether given expression is well
// parenthesized or not.

#include <iostream>
#include <stack>
#include <string.h> 

using namespace std;

bool isValid (string str) {
    stack <char> S;
    for (int i = 0 ; i < str.size(); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            S.push(str[i]);
        } else {
            if ((str[i] == ')' || str[i] == '}' || str[i] == ']') &&  S.size() == 0) {
                return false;
            }

            if (str[i] == ')' && S.top() == '('  ) {
                S.pop();
            } else if (str[i] == '}' && S.top() == '{') {
                S.pop();
            } else if (str[i] == ']' && S.top() == '[') {
                S.pop();
            } else {
                return false;
            }
        }
    }
    return S.empty();
} 

int main () {
    string s ;
    cout << "Enter string to be checked: ";
    cin >> s;

    if (isValid(s)) {
        cout << "Valid." << endl;
    } else {
        cout << "Invalid" << endl;
    }
    return 0;
}
