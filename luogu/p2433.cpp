#include <bits/stdc++.h>

using namespace std;

int main()
{
    int op;
    cin >> op;
    switch (op) {
    case 1:
        cout << "I love Luogu!" << endl;
        break;
    case 2:
        cout << 6 << ' ' << 4;
        break;
    case 3:
        cout << 3 << endl
             << 12 << endl
             << 2;
        break;
    case 4:
        printf("%.3f", 500.0 / 3);
        break;
    case 5:
        cout << 480 / 32 << endl;
        break;
    case 6:
        cout << 10.8167 << endl;
        break;
    case 7:
        cout << 110 << endl
             << 90 << endl
             << 0;
        break;
    case 8:
        cout << 3.141593 * 10 << endl
             << 3.141593 * 25 << endl
             << 4.0 / 3 * 3.141593 * 125 << endl;
        break;
    case 9:
        cout << 22 << endl;
        break;
    case 10:
        cout << 9 << endl;
        break;
    case 11:
        cout << 100.0 / 3 << endl;
        break;
    case 12:
        cout << 13 << endl
             << "R" << endl;
        break;
    case 13:
        cout << static_cast<int>(pow(3.141593 * (4 * 4 * 4 + 10 * 10 * 10) * 4 / 3, 1.0 / 3));
        break;
    case 14:
        cout << 50 << endl;
        break;
    default:
        break;
        ;
    }
    return 0;
}