#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;

int par[100001];

int findpar(int n)
{
    return par[n] == n ? n : par[n] = findpar(par[n]);
}

void unite(int a, int b)
{
    a = findpar(a);
    b = findpar(b);
    if (a == b) {
        return;
    }
    par[b] = a;
}

int main()
{
    for (int i = 1; i <= 100000; i++) {
        par[i] = i;
    }
    int n = randint(50000, 100000), q = randint(5000, 100000);
    cout << n << ' ' << q << endl;
    for (int i = 1; i <= n - 1; i++) {
        while (true) {
            int f = randint(1, n);
            int t = randint(1, n);
            if (f == t || findpar(f) == findpar(t)) {
                continue;
            }
            unite(f, t);
            cout << f << ' ' << t << endl;
            break;
        }
    }
    for (int i = 1; i <= q; i++) {
        cout << randint(1, n) << ' ' << randint(1, n) << ' ' << randint(1, n) << ' ' << randint(1, n) << endl;
    }
    return 0;
}