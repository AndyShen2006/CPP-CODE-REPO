#include <bits/stdc++.h>

using namespace std;

int par[1010], ans = 0;
bool isFind[1010];
map<int, map<int, char>> T;

void init(int n)
{
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
}

int findroot(int n)
{
    if (par[n] == n)
        return n;
    else {
        return findroot(par[n]);
    }
}

void unite(int a, int b, char type)
{
    a = findroot(a);
    b = findroot(b);
    if (a == b) {
        return;
    }
    // printf("Unite %d %d\n", a, b);
    par[b] = a;
}

int dfs(int n)
{
    int type;
    for (auto it : T[n]) {
        if (it.second == 'E') {
            type = 1;
        } else if (!isFind[it.first]) {
            isFind[it.first] = 1;
            type = max(type, dfs(it.first));
        }
    }
    return type;
}

int main()
{
    freopen("data/p1862a.in", "r", stdin);
    int n, m, p, q;
    char opt;
    cin >> n >> m;
    init(n);
    for (int i = 1; i <= n; i++) {
        T[i].insert(make_pair(i, 'F'));
    }
    for (int i = 1; i <= m; i++) {
        cin >> opt >> p >> q;
        T[p].insert(make_pair(q, opt));
        T[q].insert(make_pair(p, opt));
        unite(p, q, opt);
    }
    for (int i = 1; i <= n; i++) {
        if (i == par[i]) {
            ans += 1 + dfs(i);
        }
    }
    cout << ans << endl;
    return 0;
}