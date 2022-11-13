#include <bits/stdc++.h>
#include <ext_random.h>

using namespace std;

int main()
{
    srand(time(0));
    int n = randint(5, 10);
    int m = randint(2 * n, n * (n + 1));
    cout << n << ' ' << m << endl;
    int f, t, v;
    for (int i = 1; i <= m; i++) {
        do {
            f = randint(1, n);
            t = randint(1, n);
        } while (f == t);
        v = randint(1, 3000000);
        cout << f << ' ' << t << ' ' << v << endl;
    }
    return 0;
}