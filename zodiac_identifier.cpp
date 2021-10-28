#include <iostream>
#include <vector>
using namespace std;

vector<vector<string>> zodiac_data = {
    {"January", "19", "31", "Capricorn", "Aquarius"},
    {"Februrary", "18", "28", "Aquarius", "Pisces"},
    {"March", "18", "31", "Pisces", "Aries"},
    {"April", "18", "30" "Aries", "Taurus"},
    {"May", "18", "31", "Taurus", "Gemini"},
    {"June", "18", "30", "Gemini", "Cancer"},
    {"July", "22", "31", "Cancer", "Leo"},
    {"August", "22", "31", "Leo", "Virgo"},
    {"September", "22","30", "Virgo", "Libra"},
    {"October", "22", "31", "Libra", "Scorpio"},
    {"November", "21", "30", "Scorpio", "Sagittarius"},
    {"December", "21", "31", "Sagittarius", "Capricorn"}
};

void show_zodiac(int m, int day) {
    if (day < 1 || stoi(zodiac_data[m][2]) > 31) {
        cout << "Please type a valid day (1-31)\n";
    } else {
        cout << "Zodiac sign for " << zodiac_data[m][0] << " " << day << " is " << ((day <= stoi(zodiac_data[m][1])) ? zodiac_data[m][3]:zodiac_data[m][4]) << endl;
    }
}

int main()
{
    int m, d;
    char again;
    do
    {
        cout << "Enter month:";
        cin >> m;
        cout << "Enter day:";
        cin >> d;

        if (m > 0 && m < 13) {
            show_zodiac(m - 1, d);
        } else {
            cout << "Please type a valid Month\n";
        }

        cout << "Would you like to try again? (y/n):";
        cin >> again;
    }
    while (again == 'y'); //while loop
    cout << "Press any key to continue." << endl;
    cin.ignore(1);

    cout << "End of Program";
    return 0;
}