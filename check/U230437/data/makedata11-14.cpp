#include <bits/stdc++.h>
#include <ext_random.h>

using namespace std;

int main()
{
    int n = randint(2, 3000);
    int m = randint(1.5 * n, 5 * n);
    cout << n << ' ' << m << endl;
    int f, t, v;
    int type;
    for (int i = 1; i <= m; i++) {
        type = randint(1, 6);
        do {
            if (type % 3 == 0) {
                if (type % 2 == 0) {
                    f = 1;
                    t = randint(1, n);
                } else {
                    f = randint(1, n);
                    t = 1;
                }
            } else {
                f = randint(1, n);
                t = randint(1, n);
            }
        } while (f == t);
        v = randint(1, 1e9);
        cout << f << ' ' << t << ' ' << v << endl;
    }
    cout << 1 << endl;
    cout << randint(1, n) << ' ' << randint(1, n) << endl;
    return 0;
}