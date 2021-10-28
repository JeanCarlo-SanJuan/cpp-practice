#include <iostream>
using namespace std;

int main() {
    // Determine all the prime numbers from 2 up to 100, 
    // apply the algorithm called sieve of erasthones which was taught during MATH-014 Number Theory.

    int n = 2, remainder; // Start value
    const int LIMIT = 100; // Last number to be tested.
    bool prime = true;

    cout << "Prime numbers from " << n << " up to " << LIMIT << endl;
    while(n <= LIMIT) {
        prime = true;

        int i = 2;

        // Determines when to stop the test.
        while (i < n) {
            remainder = n % i; 

            // When the remainder is zero the number is prime.
            if (remainder == 0) {
                prime = false;
                break; // Stop inner loop since we already know that n is not prime.
            }
            i++;
        }

        if (prime) cout << n << endl;

        n++;
    }
    return 0;
}