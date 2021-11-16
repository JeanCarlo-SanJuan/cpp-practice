#include <iostream>
using namespace std;

template <typename T>
T input(T ret, string msg) {
    T ret;
    cout << msg;
    cin >> re;
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        input (ret, msg);
        } else break;
}
int main() {
    int n;

    cout << n;
    return 0;
}