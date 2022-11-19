#include <bits/stdc++.h>
#include <ext_random.h>

using namespace std;
using namespace cdg;

int main()
{
    int a = randint(1000, 10000);
    int n = randint(400, 1000);
    cout << a << ' ' << n << endl;
    for (int i = 1; i <= n; i++) {
        int sym = randint(1, 3);
        switch (sym) {
        case 1:
            cout << "+ ";
            break;
        case 2:
            cout << "- ";
            break;
        case 3:
            cout << "* ";
            break;
        default:
            break;
        }
    }
    cout << endl;
    return 0;
}