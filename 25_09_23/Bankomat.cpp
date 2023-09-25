#include "Bankomat.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int Bankomat::count = 0;

Bankomat::Bankomat()
{
    id = count++;
    am100 = 0;
    am200 = 0;
    am500 = 0;
    am1000 = 0;
    min = 0;
    max = 0;
    total = 0;
}

Bankomat::Bankomat(int a100, int a200, int a500, int a1000, int mn, int mx)
{
    id = count++;
    am100 = a100;
    am200 = a200;
    am500 = a500;
    am1000 = a1000;
    min = mn;
    max = mx;
    total = am100 * 100 + am200 * 200 + am500 * 500 + am1000 * 1000;
}

void Bankomat::withdraw()
{
    int withdramount = 0;
    cout << "Select amount you wish to withdraw: ";
    cin >> withdramount;
    if(withdramount < min || withdramount > max || withdramount > total || withdramount < 100)
    {
        system("CLS");
        cout << "INCORRECT AMOUNT.\n";
        system("pause");
        system("CLS");
        return;
    }

    int w1000 = 0;
    int w500 = 0;
    int w200 = 0;
    int w100 = 0;

    withdramount -= withdramount % 100;
    bool first = true;

    cout << "You can withdraw " << withdramount;
    if (withdramount >= 1000 && am1000 > 0)
    {
        cout << "(" << (withdramount / 1000 <= am1000 ? withdramount / 1000 : am1000) << "x1000";
        w1000 = (withdramount / 1000 <= am1000 ? withdramount / 1000 : am1000);
        withdramount -= (withdramount / 1000 <= am1000 ? withdramount / 1000 : am1000) * 1000;
        first = false;
    }
    if (withdramount >= 500 && am500 > 0)
    {
        cout << (first == true ? "(" : " + ");
        cout << (withdramount / 500 <= am500 ? withdramount / 500 : am500) << "x500";
        w500 = (withdramount / 500 <= am500 ? withdramount / 500 : am500);
        withdramount -= (withdramount / 500 <= am500 ? withdramount / 500 : am500) * 500;
        first = false;
    }
    if (withdramount >= 200 && am200 > 0)
    {
        cout << (first == true ? "(" : " + ");
        cout << (withdramount / 200 <= am200 ? withdramount / 200 : am200) << "x200";
        w200 = (withdramount / 200 <= am200 ? withdramount / 200 : am200);
        withdramount -= (withdramount / 200 <= am200 ? withdramount / 200 : am200) * 200;
        first = false;
    }
    if (withdramount >= 100 && am100 > 0)
    {
        cout << (first == true ? "(" : " + ");
        cout << (withdramount / 100 <= am100 ? withdramount / 100 : am100) << "x100";
        w100 = (withdramount / 500 <= am100 ? withdramount / 100 : am100);
        withdramount -= (withdramount / 500 <= am100 ? withdramount / 100 : am100) * 100;
        first = false;
    }


    cout << ")" << endl;
    cout << "Do you wish to proceed? (y/n): ";

    char answer;
    cin >> answer;
    switch (answer)
    {
    case 'y':       
        am1000 -= w1000;
        am500 -= w500;
        am200 -= w200;
        am100 -= w100;
        total = am100 * 100 + am200 * 200 + am500 * 500 + am1000 * 1000;
        system("CLS");
        return;
    case'n':
        system("CLS");
        return;
    default:
        system("CLS");
        cout << "INCORRECT VALUE, AUTOMATICALLY SELECTED \"NO\"\n";
        system("pause");
        system("CLS");
        return;
    }
}

void Bankomat::deposit()
{
    int d1000 = 0;
    int d500 = 0;
    int d200 = 0;
    int d100 = 0;
    int deposited = 0;
    int answer = 0;
    while (true)
    {
        cout << "Please deposit: (1 -> 1000 / 2 -> 500 / 3 -> 200 / 4 -> 100 / 0 -> finish / -1 -> cancel) : ";
        cin >> answer;
        switch (answer)
        {
        case 1:
            d1000++;
            deposited += 1000;
            break;
        case 2:
            d500++;
            deposited += 500;
            break;
        case 3:
            d200++;
            deposited += 200;
            break;
        case 4:
            d100++;
            deposited += 100;
            break;
        case 0:
            am1000 += d1000;
            am500 += d500;
            am200 += d200;
            am100 += d100;
            total += deposited;
            return;
        case -1:
            return;
        default:
            system("CLS");
            cout << "INCORRECT VALUE" << endl;
            system("pause");
            system("CLS");
            break;
        }
        system("CLS");
        cout << "deposited: " << deposited << endl;
    }
}

string Bankomat::toString()
{
    string result;
    int num = total;

    if (num == 0) {
        result = "0";
    }
    while (num > 0) {
        char digit = '0' + (num % 10);
        result = digit + result;
        num /= 10;
    }
    return result;
}

void Bankomat::print()
{
    cout << "Available balance: " << toString() << endl;
    bool first = true;
    if (am1000 > 0)
    {
        cout << "(" << am1000 << "x1000";
        first = false;
    }
    if (am500 > 0)
    {
        cout << (first == true ? "(" : " + ");
        cout << am500 << "x500";
        first = false;
    }
    if (am200 > 0)
    {
        cout << (first == true ? "(" : " + ");
        cout << am200 << "x200";
        first = false;
    }
    if (am100 > 0)
    {
        cout << (first == true ? "(" : " + ");
        cout << am100 << "x100";
        first = false;
    }
    cout << ")" << endl;
    cout << "Minimum withdraw amount: " << min << endl;
    cout << "Maximum withdraw amount: " << max << endl;
    cout << "ID: " << id << endl;

}

void Bankomat::randomize()
{
    srand(time(NULL));
    am100 = rand() % 19 + 1;
    am200 = rand() % 19 + 1;
    am500 = rand() % 19 + 1;
    am1000 = rand() % 9 + 1;
    min = (rand() % 4 + 1) * 100;
    max = (rand() % 55 + 20) * 100;
    total = am100 * 100 + am200 * 200 + am500 * 500 + am1000 * 1000;
}

