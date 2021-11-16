#include <iostream>
using namespace std;

// Global scope
// For variables that hold the fibonacci numbers set type as unsigned long int in case large fibonacci numbers are to be generated.
uint64_t 
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
    int i = 0;
    do {
        //Don't print duplicate terms
        if (prev_val != current_val) {
            cout << ++i << ": " << prev_val << endl;
        };

        calc_next_term();
    } while (i < count);
}

int get_length() {
    cout << "Note: This program can not compute the negative terms of a fibonacci sequence!\n";

    int count = 0;
    cout << "Enter length of the fibonacci series: ";
    cin >> count;

    if (count > 0) {
        return count;
    }

    cout << "Enter at least 1 term!\n\n";
    return get_length();
}
int main() {
    int count = get_length();
    print_terms(count);

    return 0;
}