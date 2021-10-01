#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


class game {
    private:
        int ans;
        int last;
        
    public:
        void set_ans(int _ans) {
            ans = _ans;
        }

        void start() {
            ans = abs(rand() % 100); // Congruence Magic to get last 2 digits;
			int attempts = 0;
            guess(attempts);

            string response;

            cout << "Play again? [Y|N]";
			cin.ignore();
            getline(cin,response);

            if (response == "y" or response == "Y") {
                start();
            }
        }
        
        int guess(int &attempts) {
            int user_ans;

			
			
            cout << "My number is ";
            cin >> user_ans;

            if (ans == user_ans) {
                cout << "Correct!\n";
				cout << "Attempts: " << attempts << endl;
                return 0;
            } else {
				attempts++;
			}

            last = user_ans;

            string say = (ans > user_ans) ? "higher":"lower";

            cout << "Wrong! (Hint: It's " << say << " than " << last << ")\n";

            guess(attempts);
        }
};

int main() {
    srand(time(0));
    
    system("title High-Low Game by JSCJ (C++)");
    cout << "Note: The number is in the inclusive range of 0 to 99.\n";

    game Game; 
    Game.start();

    return 0;
}