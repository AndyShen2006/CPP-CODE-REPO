#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;
using namespace cdg;

int main()
{
    int n = randint(2, 3), q = randint(1, 10);
    cout << n << ' ' << q << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << randint(1, 1e9) << ' ';
        }
        cout << endl;
    }
    for (int i = 1; i <= q; i++) {
        cout << randint(1, 1e9) << endl;
    }
    return 0;
}