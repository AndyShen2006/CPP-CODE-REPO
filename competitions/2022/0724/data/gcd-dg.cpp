#include <bits/stdc++.h>
#include <ext_random.h>

using namespace std;

int main()
{
    long long l, r, x, T = randll(1, 10);
    cout << T << endl;
    for (int i = 1; i <= T; i++) {
        do {
            l = randll(1, 1e18);
            r = randll(1, 1e18);
        } while (l > r);
        x = randll(1, l);
        cout << l << ' ' << r << ' ' << x << endl;
    }
    return 0;
}