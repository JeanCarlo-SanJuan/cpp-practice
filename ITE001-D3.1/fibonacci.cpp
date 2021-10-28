#include <iostream>

using namespace std;

int main() {
    // Set the variable types as long int in case more fibonacci numbers are tested.
    int64_t i = 0,
        current_val = 0,
        prev_val = 0,
        next_val = 1,
        count = 30;

    cout << "First " << count << " Fibonacci numbers are...\n";
    for (i = 0; i < count;)
    {   
        if (prev_val != current_val) {
            cout << i + 1 << ": " << prev_val << endl;
            i++;
        }
        prev_val = current_val;
        current_val += next_val;
        next_val = prev_val;
    }
    

    return 0;
}