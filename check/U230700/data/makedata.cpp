#include <bits/stdc++.h>
#include <ext_random.h>

using namespace std;

int main()
{
    int n = randint(1e3, 1e4);
    int m = randint(0.6 * n, 1e4);
    cout << n << ' ' << 2 * m << endl;
    int f, t;
    for (int i = 1; i <= m; i++) {
        f = randint(1, n);
        t = randint(1, n);
        cout << f << ' ' << t << endl;
        cout << t << ' ' << f << endl;
    }
    return 0;
}