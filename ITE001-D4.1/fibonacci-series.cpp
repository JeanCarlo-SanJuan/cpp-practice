/* PROBLEM 1: Create a program that will display the nth numbers in the Fibonacci series. The length of the series depends on the user's input.  Use user defined function and appropriate conditional and looping statements to solve the given problem.*/
#include <iostream>
using namespace std;

// Global scope
// For variables that hold the fibonacci numbers set type as long int in case large fibonacci numbers are to be generated.
int64_t 
    current_val = 0,
    prev_val = 0,
    next_val = 1;

void calc_next_term() {
    prev_val = current_val;
    current_val += next_val;
    next_val = prev_val;
}

void print_terms(int count) {
    cout << "First " << count << " Fibonacci numbers are...\n";

    for(int i = 0; i < count;) {
        //Don't print duplicate terms
        if (prev_val != current_val) {
            cout << ++i << ": " << prev_val << endl;
        };

        calc_next_term();
    }
}

int main() {
    int count;
    cout << "Enter length of the fibonacci series: ";
    cin >> count;
    print_terms(count);
    return 0;
}