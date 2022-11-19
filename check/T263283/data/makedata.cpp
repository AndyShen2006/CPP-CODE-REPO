#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;

typedef long long ll;

char type[2] = { 'M', 'W' };

ll f[500001];
void func(int x)
{
    for (int i = 1; i <= x + 1; i++) {
        f[i] = 1;
    }
    for (int i = x + 2; i <= 500000; i++) {
        f[i] = f[i - x] + f[i - x - 1];
    }
}

vector<int> cur;

int main()
{
    int n = randint(7000, 50000);
    int T = randint(10000, 50000);
    int x = randint(1, 10);
    // func(x);
    // exit(0);
    ll m = randll(3, 1e15);
    cout << n << ' ' << x << ' ' << T << ' ' << m << endl;
    cur.emplace_back(0);
    for (int i = 1; i <= n; i++) {
        cur.emplace_back(randint(1, 100));
    }
    int pos = 0;
    pos = randint(1, 3);
    for (int i = 1; i <= n; i++) {
        cout << cur[i] << ' ';
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        pos = randint(1, 20);
        cout << cur[i] - 3 << ' ';
    }
    cout << endl;
    for (int i = 1; i <= pos; i++) {
        cout << 2 << endl;
    }
    for (int i = pos + 1; i <= T; i++) {
        int opt = randint(1, 2);
        int l, r;
        if (opt == 1) {
            do {
                l = randint(1, n);
                r = randint(1, n);
            } while (l > r);
            cout << 1 << ' ' << type[randint(0, 1)] << ' ' << l << ' ' << r << endl;
        } else {
            cout << 2 << endl;
        }
    }
    return 0;
}