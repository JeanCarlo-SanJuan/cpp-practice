/*PROBLEM 2: Using user defined function and appropriate conditional and looping statements, create a program that will: */
 #include <iostream>
 #include <iomanip>
 using namespace std;

float total_price; // Only global var
 
float ask_number(string msg) {
    float n;
    cout << "Enter " + msg + ": ";
    cin >> n;

    return n;
}

bool again(string msg) {
    char action;

    cout << endl << msg << " [Y/N]? ";
    cin >> action;

    return action == 'Y' || action == 'y';
}

void get_item_info() {
    float price =  ask_number("item price"); // a
    int quantity = ask_number("item quantity"); // b

    // d - partial computation
    if (price > 0 && quantity >= 1) {
        total_price += price * quantity;
    } else {
        cout << "Invalid price or quantity!\n";
    }
}

// e & f
int get_payment() {
    float payment;
    do {
        cout << "\nPlease pay exact amount of Php " << total_price << endl;
        payment = ask_number("payment");
    } while (payment < total_price);
    
    return payment;
}

// g
void calc_change(float payment) {
    cout << "\nYour change is Php " << payment - total_price << endl;
}

int main() {
    do {
        get_item_info(); // c - more items query
    }
    while (again("Are there any more items?"));

    // d - display total
    cout << "The cost of all the items is Php " << fixed << setprecision(2) << total_price << endl;

    float payment = get_payment();
    calc_change(payment);

    cout << "\nThank you for your patronage! (:\n";

    return 0;
}