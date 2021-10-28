#include <iostream>
using namespace std;

int main() {
    char i = 97;

    do {
        //Using Short circuit evaluation
        if (
            i != 97 && 
            i != 101 && 
            i != 105 && 
            i != 111 && 
            i != 117
            ) cout << i << endl;

        i++;
    } while(i < 123);

    return 0;
}