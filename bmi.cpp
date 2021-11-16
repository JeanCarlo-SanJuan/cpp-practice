#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <unistd.h>//for sleep
using namespace std;

string function_imperial(double imperial, string remark_imperial)
{
    if (imperial < 18.5)
    {
        remark_imperial = "Underweight";
    }
    else if (imperial >= 18.5 && imperial < 25)
    {
        remark_imperial = "Normal weight";
    }
    else if (imperial >= 25 && imperial < 30)
    {
        remark_imperial = "Overweight";
    }
    else if (imperial >= 30 && imperial < 35)
    {
        remark_imperial = "Class I obese";
    }
    else if (imperial >= 35 && imperial < 40)
    {
        remark_imperial = "Class II obese";
    }
    else if (imperial >= 40)
    {
        remark_imperial = "Class III obese";
    }
    return remark_imperial;
}

string function_metric(double metric, string remark_metric)
{
    if (metric < 18.5)
    {
        remark_metric = "Underweight";
    }
    else if (metric >= 18.5 && metric < 25)
    {
        remark_metric = "Normal weight";
    }
    else if (metric >= 25 && metric < 30)
    {
        remark_metric = "Overweight";
    }
    else if (metric >= 30 && metric < 35)
    {
        remark_metric = "Class I obese";
    }
    else if (metric >= 35 && metric < 40)
    {
        remark_metric = "Class II obese";
    }
    else if (metric >= 40)
    {
        remark_metric = "Class III obese";
    }
    return remark_metric;
}

char get_char(string msg) {
    char c;
    do {
        cout << msg;
        cin >> c;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();

            cout << "Invalid input!";
            sleep(1);
        } else return c;
    } while (true);
}

double get_double(string msg) {
    double c;
    do {
        cout << msg;
        cin >> c;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();

            cout << "Invalid input!\n";
            sleep(1);
        } else return c;
    } while (true);
}

int main()
{
    double pounds, feet, inches, kilograms, meters, imperial, metric;
    string remark_imperial, remark_metric;
    char sys, ask = 'Y';
    
    do{
        system("CLS");
        cout << "BMI Calculator" << endl;
        cout << "[I] Imperial" << endl;
        cout << "[M] Metric" << endl;
        sys = get_char("Choose system: ");
        
        switch (sys)
        {
            case 'I':
            case 'i':
                pounds = get_double("Enter weight in pounds: ");
                feet = get_double("Enter height in feet: ");
                inches = get_double("Enter inches in feet: ");
                imperial = (703 * pounds) / (pow(12*feet+inches, 2));
                cout << "BMI: " << fixed << setprecision(2) << imperial << endl;
                cout << "Remark: " << function_imperial(imperial, remark_imperial) << endl;
                ask = get_char("Do you want to calculate again [Y/N]? ");
                break;
            case 'M':
            case 'm':
                kilograms = get_double("Enter weight in kilograms: ");
                meters = get_double("Enter height in meters: ");
                metric = kilograms / (pow(meters, 2));
                cout << "BMI: " << fixed << setprecision(2) << metric << endl;
                cout << "Remark: " << function_metric(metric, remark_metric) << endl; 
                ask = get_char("Do you want to calculate again [Y/N]? ");
                break;
            default:
                cout << "Invalid input. Try again." << endl;
                sleep(1);
                break;
        }
        
      }while (ask == 'Y' || ask == 'y');
    return 0;
}