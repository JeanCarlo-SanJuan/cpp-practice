#include <iostream>
using namespace std;
float getInput(void);
float computeSpeed(float, float);

main()
{
    float x, y;
    x = getInput();
    y = getInput();
    cout << "The speed of the car is " << computeSpeed(x, y) << " kph." << endl;
}

float computeSpeed(float T, float D)
{
    return D / T;
}

float getInput(void)
{
    cout << "Please enter value here: ";
    float input;
    cin >> input;
    return input;
}