#include <iostream>
#include <vector>

using namespace std;

vector<string> msgs = {
    "Hello",
    "Happy",
    "World"
};

int main() {

    string current;

    for(;;) {
        getline(cin, current);
        if (current.length() > 0) 
        {
            msgs.push_back(current);
        } else break;
    }

    for (string &msg: msgs) {
        cout << msg << endl;
    }

    return 0;
}