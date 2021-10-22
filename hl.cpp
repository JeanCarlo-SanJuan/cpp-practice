#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Game {
    private:
        int ans;
        int last;
        int attempts = 0;
        
    public:
        void start() {
            system("cls");
            ans = abs(rand() % 100); // Congruence Magic to get last 2 digits;
            guess();

            string response;

            cout << "Play again? [Y|N]";
			cin.ignore();
            getline(cin,response);

            if (response == "y" or response == "Y") {
                start();
            }
        }
        
        int guess() {
            int user_ans;
			
            cout << "My number is ";
            cin >> user_ans;

            if (ans == user_ans) {
                cout << "Correct!\n";
				cout << "Attempts: " << attempts << endl;
                return 0;
            }
            
            last = user_ans;

            string say = (ans > user_ans) ? "higher":"lower";

            cout << "Wrong! (Hint: It's " << say << " than " << last << ")\n";

            attempts++;
            guess();
        }
};

int main() {
    srand(time(0));
    
    system("title High-Low Game by JSCJ (C++)");
    cout << "I am thinking of a number between 0 and 99 (inclusive).\n";

    Game game; 
    game.start();

    return 0;
}