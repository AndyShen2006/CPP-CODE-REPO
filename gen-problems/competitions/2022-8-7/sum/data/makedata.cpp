#include <bits/stdc++.h>
#include <ext_random.h>

using namespace std;

int main()
{
    int n = randint(50000, 1000000);
    int q = randint(50000, 1000000);
    cout << n << ' ' << q << endl;
    for (int i = 1; i <= n; i++) {
        cout << randint(114514, 1919810) << ' ';
    }
    cout << endl;
    int f, t;
    for (int i = 1; i <= q; i++) {
        do {
            f = randint(1, n);
            t = randint(1, n);
        } while (f > t);
        cout << f << ' ' << t << endl;
    }
    return 0;
}