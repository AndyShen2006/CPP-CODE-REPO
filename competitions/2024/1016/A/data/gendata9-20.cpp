#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;

int main()
{
    int n = randint(1e3, 5e3), m = int(1e6 / n);
    cout << n << ' ' << m << ' ' << randint(1, 1e9) << ' ' << randint(1, 1e9) << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << randint(0, 100) << ' ';
        }
        cout << endl;
    }
    return 0;
}