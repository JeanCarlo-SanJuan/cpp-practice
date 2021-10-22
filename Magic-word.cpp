// Problem 2

#include <iostream>
using namespace std;

int main() 
{
    const string magicWord = "ComputerScience";    
    string input;
    cout << "Guess the magic word: ";
    cin >> input;

    // Please read comment (1) and (2) from problem 1.
    cout << ((input == magicWord) ? "You got it right...": "Try again later...");

    return 0;
}