#include <bits/stdc++.h>

using namespace std;

int par[10010];

void init(int n)
{
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
}

int findpar(int u)
{
    if (par[u] == u) {
        return u;
    } else {
        return par[u] = findpar(par[u]);
    }
}

void unite(int x, int y)
{
    x = findpar(x);
    y = findpar(y);
    if (x == y) {
        return;
    }
    par[y] = x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    init(n);
    int op, x, y;
    for (int i = 1; i <= m; i++) {
        cin >> op >> x >> y;
        switch (op) {
        case 1:
            unite(x, y);
            break;
        case 2:
            cout << (findpar(x) == findpar(y) ? "Y" : "N") << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}