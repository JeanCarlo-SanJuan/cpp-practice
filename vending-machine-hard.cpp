#include <iostream>
#include <vector>
#include <map>

/*  Vending Machine Project
States:
    menu
    products
    payment
    Instruction

Show the following when...
in the menu state:
    Product categories
    Quit
    Reset
    pay
    instruction 

in the products state:
    Items with price
    
    Go back option

in the payment state:


*/
using namespace std;

map<string, vector<string>> menu = {
    {"1. Drinks", {"Juice","Soda","Coffee"}},
    {"2. Snacks", {"Chips","Biscuits","Mixed"}},
};

void show_menu(int section) {
    int i = 0;

    if (section == 0) {
        for(auto kv:menu) {
            cout << kv.first << endl;
        }

        cout << "(0) Quit";
        cout << "Insert";
        cout << "(9) Reset transaction";
    } 
    else {
        for(auto kv:menu) {
            if (i + 1 == section) {
                cout << kv.first << endl;
                for(string item:kv.second) {
                    cout << item << endl;
                }
            }

            i++;
        }
    }

    //Default Items
    // (0) Go back

}

void navigate_to() {
    int section;

    cout << "Go to ";
    cin >> section;

    show_menu(section);
    navigate_to();
}

string state = "menu";

int prompt(string _state) {
    int action;

    if (_state == "menu") {
        show_menu(0);
    }

    cout << "Enter action: ";
    cin >> action;

    switch (action) {
        case 0:
            break;
    }
}

int main() {
    prompt(0);

    return 0;
}