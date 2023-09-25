#include "Bankomat.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Bankomat r1;
    r1.randomize();
    int action = 0;
    while (true)
    {
        r1.print();
        cout << endl;
        cout << "[1] -> Deposit money" << endl;
        cout << "[2] -> Withdraw money" << endl;
        cout << "Select option:";
        cin >> action;
        switch (action)
        {
        case 1:
            r1.deposit();
            system("CLS");
            break;
        case 2:
            r1.withdraw();
            system("CLS");
            break;
        default:
            system("CLS");
            cout << "\nERROR: INCORRECT VALUE\n\n";
            cin.clear();
            cin.ignore(100, '\n');
            system("pause");
            system("CLS");
            break;
        }
    }
}
