#include <bits/stdc++.h>
#include <ext_random.h>

using namespace std;

int main()
{
    int n = randint(300, 3000);
    int m = randint(1.5 * n, 1e5);
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
        // v = 1;
        cout << f << ' ' << t << ' ' << v << endl;
    }
    int T = randint(1, 1e6);
    cout << T << endl;
    for (int i = 1; i <= T; i++) {
        do {
            f = randint(1, n);
            t = randint(1, n);
        } while (f == t);
        cout << f << ' ' << t << endl;
    }
    return 0;
}