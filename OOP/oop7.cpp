#include <iostream>
#include <map>
#include <utility>
#include <cstring>

using namespace std;

// Write a program in C++ to use map associative container. The
// keys will be the names of states and the values will be the
// populations of the states. When the program runs, the user is
// prompted to type the name of a state. The program then looks
// in the map, using the state name as an index and returns the
// population of the state

int main () {
    typedef map <string, int > maptype;
    maptype state;

    state.insert(pair <string,int> ("Maharahstra", 1124886355));
    state.insert(pair <string,int> ("Rajasthan", 48451243545));
    state.insert(pair <string,int> ("Uttarakhand", 4651354654));
    state.insert(pair <string,int> ("Tamilnadu", 23893698));
    state.insert(pair <string,int> ("Kerala", 90907345));
    state.insert(pair <string,int> ("Hariyana", 98736344));
    state.insert(pair <string,int> ("Punjab", 9879555));

    maptype :: iterator iter ;//= --  state.end();

    for (iter = state.begin(); iter != state.end(); iter ++) {
        cout << iter -> first << ": " << iter -> second << "$" << endl;
    }

    cout << "The number of state entries are: " << state.size() << endl;
    string name;
    cout << "Enter the name of state: ";
    cin >> name;

    iter = state.find(name);

    if (iter != state.end()) {
        cout << endl;
        cout << name << ": " << iter -> second << "$" << endl;
    } else {
        cout << "Entry not found! Try again." << endl;
    }

    state.clear();

    return 0;
}



  








