#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;

int main()
{
    int n = randint(400, 500), m = randint(5e4, 1e5);
    cout << n << ' ' << m << endl;
    for (int i = 1; i <= n; i++) {
        cout << 0 << ' ';
    }
    cout << endl;
    for (int i = 1; i <= m; i++) {
        cout << randint(1, n) << ' ' << randint(1, n) << ' ' << randint(1, 1e9) << endl;
    }
    return 0;
}