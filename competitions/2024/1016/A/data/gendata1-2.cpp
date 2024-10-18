#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;

int main()
{
    int n = 2, m = 2;
    cout << n << ' ' << m << ' ' << randint(1, 1e9) << ' ' << randint(1, 1e9) << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << randint(0, 100) << ' ';
        }
        cout << endl;
    }
    return 0;
}