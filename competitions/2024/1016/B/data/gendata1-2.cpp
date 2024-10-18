#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;

int main()
{
    int n = 10, m = 10;
    cout << n << ' ' << m << endl;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            cout << 0 << ' ';
        } else {
            cout << randint(1, 1e9) << ' ';
        }
    }
    cout << endl;
    for (int i = 1; i <= m; i++) {
        cout << randint(1, n) << ' ' << randint(1, n) << ' ' << randint(1, 1e9) << endl;
    }
    return 0;
}