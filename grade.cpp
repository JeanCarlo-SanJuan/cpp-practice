#include <iostream>

using namespace std;

int main() {

    float grade;

    cout << "Enter a grade: ";
    cin >> grade;    

    //Error handling first
    if (grade < 0 || grade > 100) {
        cout << "Invalid grade";
    } else if (grade < 50) {
        cout << "Failed";
    } else {
        cout << "Passed";
    }

    return 0;
}

// cout << ((grade < 50) ? "Failed":"Passed");