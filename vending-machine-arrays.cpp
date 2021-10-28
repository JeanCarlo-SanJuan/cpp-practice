#include <iostream>
#include <map>
#include <vector>
using namespace std;

/*  Vending Machine Project
States:
    menu -> products -> payment -> change

Show the following when...
in the menu state:
    Product categories(via for each loop)
    Quit

in the products state:
    Items with price (via for each loop)
    Go back option

in the payment state:
    Make user enter money at fixed amounts
    Coins:
    1,5,10

    Bills:
    20,50,100,200,500,1000
*/

void show_menu(int state);
void prompt(int state);
void handle_payment(int category, int item_id);

int denominations[] = {
    1,5,10, 20,50,100,200,500,1000
};

string invalid_msg = "Invalid denomination!\n Valid denominations are: \n 1, 5, 10, 20, 50, 100, 200, 500, and 1000\n\n";

string categories[] = {
    "Snacks",
    "Drinks",
};

string drinks[] = {
    "Juice",
    "Soda",
    "Coffee"
};

string snacks[] = {
    "Biscuits",
    "Chips",
    "Chocolate"
};

int prices[2][3] = {
    {20,44,70},
    {10,15,28},
};

int menu_items = 3;
bool reset_state = false;

void show_option(int i, string text) {
    cout << " (" << i << ") " << text << endl;
}

int main() {
    // Todo: add return option in payment state.
    system("title Vending Machine V1 by Jean Carlo San Juan");
    show_menu(0);
    return 0;
}

void show_menu(int state) {
    system("cls");

    int j = 0;
    int i = 0;

    switch (state) {
        case 0: // Main menu
            cout << "Main menu: \n";

            for(string cat:categories) {
                show_option(++i, cat);
            }

            show_option(++i, "Quit");
            break;
        case 1: case 2: // Drinks

            cout << categories[state - 1] + ":\n" ;

            switch(state) {
                case 1:
                    for (string snack:snacks) {
                        show_option(++j, snack + " >> Php " + to_string(prices[state - 1][j]));
                    }
                    break;
                case 2:
                    for (string drink:drinks) {
                        show_option(++j, drink + " >> Php " + to_string(prices[state - 1][j]));
                    }
                    break;
            }

            show_option(++j, "Return");
            break;

        case 3:
            break;
    }

    prompt(state);
}

void prompt(int state) {
    
    int action;

    cout << "\n> Enter action: ";
    cin >> action;

    switch (state) {
        case 0:
            // Quit the program
            if (action == 3) {
                return;
            }
            else if (action > 0 && action <= menu_items) {
                show_menu(action);
            }

            break;
        case 1: case 2:
            // Categories must have the same number of items otherwise refactor this.
            if (action == menu_items + 1) {
                show_menu(0);
            } 
            else if (action > 0 && action < menu_items + 1) {
                handle_payment(state, action);
            }
            break;
    }

    show_menu((reset_state) ? 0:state);
}

void handle_payment(int cat_id, int item_id) {
    system("cls");

    item_id -= 1; // Index starts at zero

    int i = 0;
    int j = 0;
    int price = 0;
    int paid = 0;
    int current = 0;
    bool valid = false;

    string product;

    switch (cat_id) {
        case 1:
            product = drinks[item_id];
            break;
        case 2:
            product = snacks[item_id];
            break;
    }

    price = prices[cat_id][item_id];

    if (price > 0) {

        // Make user pay at arbitrary denominations until desired price
        while (paid < price) {
            cout << " You have selected: " << product << endl;
            cout << " Please pay the amount: " << price << endl;
            cout << " Balance left: " << price - paid << "\nInsert amount: ";
            cin >> current;

            // Checks if the user enters a valid denomination
            for (int denom: denominations) {
                if (denom == current) {
                    paid += current;
                    valid = true;
                    break;
                }
            }
            
            system("cls");

            if (valid) {
                current = 0;
            } else {
                cout << invalid_msg;
            }

            valid = false;
        }

        cout << " You bought " + product + ".";
        cout << "\n Your change is Php " << paid - price << ".\n";
        reset_state = true;
        system("pause");
    }
}