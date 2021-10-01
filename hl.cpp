#include <iostream>
#include <random>
#include <stdlib.h>
#include <time.h>

using namespace std;

class game {
    public:
        int ans;
        int last;

        game(int _ans) {
            ans = _ans;
        }

        int guess() {
            int user_ans;
            cout << "My number is ";
            cin >> user_ans;

            if (ans == user_ans) {
                return -1;
            }

            last = user_ans;
            return ans > user_ans;
    }
};

int main() {
    int res;
    srand(time(0));
    game Game(abs(rand() % 100)); // Congruence Magic to get last 2 digits;
    
    system("title High-Low Game by JSCJ (C++)");
    printf("Note: The number is in the inclusive range of 0 to 99.\n");

    while (true) {
        res = Game.guess();
        if (res == -1) {
            cout << "Correct!\n";
            break;
        }

        cout << ((res > 0) ? "Higher!":"Lower!");
        cout << "\n";

    }
    system("\npause");
    return 0;
}