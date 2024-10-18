#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;

constexpr int MAX_N = 510;
int par[MAX_N];

void init()
{
    for (int i = 0; i < MAX_N; i++) {
        par[i] = i;
    }
}

int findpar(int x)
{
    return par[x] == x ? x : par[x] = findpar(par[x]);
}

int main()
{
    init();
    int n = randint(400, 500), m = n - 1;
    cout << n << ' ' << m << endl;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            cout << 0 << ' ';
        } else {
            cout << randint(1, 1e9) << ' ';
        }
    }
    cout << endl;
    for (int i = 1; i <= m; i++) {
        int u = randint(1, n), v = randint(1, n);
        if (u != v && findpar(u) != findpar(v)) {
            par[u] = v;
            cout << u << ' ' << v << ' ' << randint(1, 1e9) << endl;
        }
    }
    return 0;
}