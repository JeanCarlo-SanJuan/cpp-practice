#include <iostream>
using namespace std;
string USERNAME[20] = {"Rey", "Jasper", "Paula"};
string PASSWORD[20] = {"Castillo", "Agustin", "Mendoza"};
int balance[20] = {500000, 50000, 5000};
int usernumber;

int decreaseBalance()
{
    int x;
    cout << "\nHow much do you want to withdraw? ";
    cin >> x;
    cout << "\nPhp" << x << "has been reduced from your account";
    return x;
}

int increaseBalance()
{
    int x;
    cout << "\nHow much do you want to deposit? ";
    cin >> x;
    cout << "\nPhp" << x << "has been added to your account";
    return x;
}

void checkBalance(int x)
{
    cout << "\n\nYour balance is: "
         << "Php" << x;
}

bool login()
{
    system("cls");
    string username;
    string password;
    cout << "USERNAME: ";
    cin >> username;
    cout << "\nPASSWORD: ";
    cin >> password;

    for (int i = 0; i < 20; i++)
    {
        if ((username.compare(USERNAME[i]) == 0) && (password.compare(PASSWORD[i]) == 0))
        {
            usernumber = i;
            return true;
        }
    }

    return false;
}

main()
{
    bool exit = false;
    cout << "Welcome to BankO!\n";
    while (exit != true)
    {
        int choice;
        do
        {
            cout << "\n\n[0] LOG IN\n[1] exit\n";
            cin >> choice;
        } while (!(choice == 1 || choice == 0));
        if (choice == 0)
        {
            bool valid = login();
            if (valid)
            {
                cout << "Hello! " << USERNAME[usernumber];
                bool cancel = false;
                while (!(cancel))
                {
                    int option;
                    do
                    {
                        cout << "\n[0] Deposit\n[1] Widthraw"
                             << "\n[2] Check Balance\n[3] LOG OUT \n";
                        cin >> option;
                    } while (!(option >= 0 || option <= 3));
                    switch (option)
                    {
                    case 0:
                        balance[usernumber] += increaseBalance();
                        break;
                    case 1:
                        balance[usernumber] -= decreaseBalance();
                        break;
                    case 2:
                        checkBalance(balance[usernumber]);
                        break;
                    default:
                        cancel = true;
                        break;
                    }
                }
            }
            else
                cout << "INVALID ACCOUNT!";
        }
        else
            exit = true;
    }
}