// Problem 1

#include <iostream>
#include <cmath>

using namespace std;

bool is_perfect_square(int n) 
{
    if (n < 0) return false; // negative roots numbers have no roots (imaginary)

    // Truncate the square root into an integer
    int root = int(sqrt(n));

    // Evaluate whether squaring the root would give the original number
    return n == root * root; 
}

int main() 
{
    int integer;

    cout << "Enter an integer: ";
    cin >> integer;

    // Add the substring " not" when n is not a perfect square otherwise just append an empty string.
    // (1) Since there are only two possible outputs, use a ternary operator to simplify the code.
    // (2) Note that the parenthesis enclosing the ternary expression is important otherwise the appended substring would be one of the integer values of a boolean (0 or 1)
    cout << integer << " is" << (is_perfect_square(integer) ? "": " not") << " a perfect square.";

    return 0;
}