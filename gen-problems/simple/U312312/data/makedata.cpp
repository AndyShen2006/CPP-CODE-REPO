#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;

int par[10010];

vector<int> G[10010];

int findpar(int x)
{
    return par[x] == x ? x : par[x] = findpar(par[x]);
}

int main()
{
    for (int i = 0; i < 10005; i++) {
        par[i] = i;
    }
    int n = randint(5000, 10000);
    int m = randint(n, n + 2);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        while (true) {
            u = randint(1, n);
            v = randint(1, n);
            if (findpar(u) != findpar(v) && u < v) {
                break;
            }
        }
        G[u].push_back(v);
        par[v] = u;
    }
    for (int i = n; i <= m; i++) {
        int u, v;
        while (true) {
            u = randint(1, n);
            v = randint(1, n);
            if (u < v) {
                break;
            }
        }
        G[u].push_back(v);
        par[v] = u;
    }
    cout << n << ' ' << randint(20, 200) << endl;
    for (int i = 1; i <= n; i++) {
        cout << randint(10, 100) << ' ' << randint(-100000, 100000) << ' ' << G[i].size() << endl;
        for (auto it : G[i]) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
