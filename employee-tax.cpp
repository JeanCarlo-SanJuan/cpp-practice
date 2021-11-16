#include <iostream>
using namespace std;
// Function Signature or Function Prototype
double getIncome(string);
double computeTaxes(double);
void printTaxes(double);

main()
{
    // Get the income;
    double income = getIncome("Please enter the employee income: ");
    // Compute Taxes
    double taxes = computeTaxes(income);
    // Print employee taxes
    printTaxes(taxes);
}

double computeTaxes(double income)
{
    if (income < 5000)
        return 0.0;

    return 0.07 * (income - 5000.0);
}

double getIncome(string prompt)
{
    cout << prompt;
    double income;
    cin >> income;
    return income;
}

void printTaxes(double taxes)
{
    cout << "The taxes is Php " << taxes << endl;
}