#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;

int main()
{
    int n = randint(1, 1000);
    int q = randint(1, 1000);
    cout << n << ' ' << q << endl;
    for (int i = 1; i <= n; i++) {
        cout << randint(-1000000000, 1000000000) << ' ';
    }
    cout << endl;
    for (int i = 1; i <= q; i++) {
        int l = randint(1, n);
        int r = randint(l, n);
        int k = 1;
        cout << l << ' ' << r << ' ' << k << endl;
    }
    return 0;
}