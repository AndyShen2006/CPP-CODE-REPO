#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;
using namespace cdg;

int main()
{
    int len = randint(3e3, 6e3);
    for (int i = 1; i <= len; i++) {
        int op = randint(1, 3);
        switch (op) {
        case 1:
            cout << char(randint('0', '9'));
            break;
        case 2:
            cout << char(randint('a', 'z'));
            break;
        case 3:
            cout << char(randint('A', 'Z'));
            break;
        default:
            break;
        }
    }
    cout << endl;
    return 0;
}