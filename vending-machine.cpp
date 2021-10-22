#include <iostream>
#include <vector>
#include <map>

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
using namespace std;

void show_menu(int state);
void prompt(int state);
void handle_payment(int category, int item_id);

int denominations[] = {
    1,5,10, 20,50,100,200,500,1000
};

map<string, map<string, int>> menu = {
    {"Drinks", 
        {
            {"Juice", 5},
            {"Soda", 10},
            {"Coffee", 15}
        }
    },
    {"Snacks", 
        {
            {"Biscuits", 20},
            {"Chips", 35},
            {"Chocolate", 70}
        }
    }
};

void show_option(int i, string text) {
    cout << "(" << i << ") " << text << endl;
}

int main() {
    system("title Vending Machine");

    show_menu(0);

    return 0;
}

void show_menu(int state) {
    system("cls");

    int j = 0;
    int i = 0;

    switch (state) {
        case 0: // Main menu
            for(auto kv:menu) {
                show_option(++i, kv.first);
            }

            show_option(++i, "Quit");

            break;
        case 1: case 2: // Drinks, Snacks, ...
            for(auto kv:menu) {
                i++;

                if (state == i) {
                    cout << kv.first + ":" << endl;

                    for(auto item: kv.second) {
                        show_option(++j, item.first + " >> Php " + to_string(item.second));
                    }

                    break;
                }

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

    cout << "Enter action: ";
    cin >> action;

    switch (state) {
        case 0:
            if (action != 3) {
                show_menu(action);
            }

            break;
        case 1: case 2:

            if (action != 4) {
                handle_payment(state, action);
            }
            break;
        default:
            show_menu(0);
    }
}

void handle_payment(int category, int item_id) {
    int i = 0;
    int j = 0;

    int price = 0;
    int paid = 0;
    int current = 0;
    bool valid = false;

    string product;

    for(auto kv:menu) {
        i++;

        if (category == i) {

            for(auto item: kv.second) {
                j++;
                if (j == item_id) {
                    product = item.first;
                    price = item.second;

                    break;
                }
            }

            break;
        }

    }

    if (price > 0) {
        cout << "Please pay the amount: " << price << endl;
        while (paid < price) {

            cout << "Balance left: " << price - paid << "\nInsert amount: ";
            cin >> current;
        
            for (int denom: denominations) {
                if (denom == current) {
                    paid += current;
                    valid = true;
                    break;
                }
            }
            
            if (valid) {
                current = 0;
            } else {
                cout << "Invalid denomination!\n";
            }

            valid = false;
        }

        cout << "You bought " << product;
        cout << "\nYour change is Php " << paid - price;

    }
}