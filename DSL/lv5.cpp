// A palindrome is a string of character that‘s the same forward and backward. Typically, punctuation,
// capitalization, and spaces are ignored. For example, “Poor Dan is in a droop” is a palindrome, as can
// be seen by examining the characters “poord a ni si nad roop” and observing that they are the same
// forward and backward. One way to check for a palindrome is to reverse the characters in the string
// and then compare with them the original-in a palindrome, the sequence will be identical. Write C++
// program with functions-

// a) To print original string followed by reversed string using stack

// b) To check whether given string is palindrome or not
#include <iostream>
#include <cstring>
#include <cctype>
#define max 50
using namespace std;

class Stack {
private:
    char s[max];
    int tos = -1;

public:
    // Push a character onto the stack
    void push(char c) {
        if (tos == max - 2) {
            cout << "Stack overflowed." << endl;
            return;
        } else {
            tos++;
            s[tos] = c;
            s[tos + 1] ='\0';
        }
    }

    // Pop a character from the stack
    void pop() {
        if (tos == -1) {
            cout << "Stack underflowed." << endl;
            return;
        } else {
            tos--;
        }
    }

    // Reverse the string using the stack
    string reverse(char str[]) {
        int length = strlen(str);
        char reversed[max];
        for (int i = 0; i < length; i++) {
            push(str[i]);  // Push characters onto stack
        }
        for (int i = 0; i < length; i++) {
            reversed[i] = s[tos];  // Pop characters and build reversed string
            pop();
        }
        reversed[length] = '\0';  // Null-terminate the reversed string
        return string(reversed);
    }

    // Convert the string to lowercase and remove non-alphabetic characters
    string convert(char str[]) {
        char converted[max];
        int j = 0;
        for (int i = 0; str[i]; i++) {
            if (isalpha(str[i])) {
                converted[j] = tolower(str[i]);  // Convert to lowercase
                j++;
            }
        }
        converted[j] = '\0';  // Null-terminate the converted string
        return string(converted);
    }

    // Check if the string is a palindrome
    // bool palindrome(char str[]) {
    //     string converted = convert(str);  // Convert the original string
    //     string reversed = reverse(&str[0]);
    //     string revconvert = convert(&reversed[0]);  // Reverse the original string

    //     return converted == revconvert;  // Check if they are the same
    // }

    // Print the original string stored in the stack
    void print() {
        if (tos == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Original string: ";
        for (int i = 0; i <= tos; i++) {
            cout << s[i];
        }
        cout << endl;
    }

    string rev(string str) {
        int len = str.length();
        char r[len];
        int j = 0;

        for (int i = len - 1; i >=0; i--) {
            r[j] = s[i];
            j++;
        }
        
        r[len] = '\0';
        return string(r);
    }

    string converting (string str) {
        string arr;
        int j, k = 0, len = str.length();

        for (j = 0; j < len; j++) {
            // Check if the character is alphabetic
            if ((str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'A' && str[j] <= 'Z')) {
                if (str[j] >= 'A' && str[j] <= 'Z') {
                    arr += char(str[j] + 32);  // Convert uppercase to lowercase
                } else {
                    arr += str[j];  // Keep lowercase as is
                }
            }
        }
        return arr;  // Return the converted string
    }

    bool palindrome(char str[]) {
        string converted = converting(str);  // Convert the original string
        string reversed = rev(str);
        string revconvert = converting(reversed);  // Reverse the original string

        return converted == revconvert;  // Check if they are the same
    }

};

int main() {
    Stack stack;
    char input[max];

    cout << "Enter a string: ";
    cin.getline(input, max);  // Read the input string

    // Push each character of the input string onto the stack
    for (int i = 0; input[i] != '\0'; i++) {
        stack.push(input[i]);
    }

    stack.print();  // Print the original string

    cout << "Reveresed string: ";
    cout << stack.rev(input) << endl;

    // Check if the string is a palindrome
    if (stack.palindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}


