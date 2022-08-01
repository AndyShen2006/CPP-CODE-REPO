#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 5e5 + 7;
vector<int> G[MAX_N];
int root = 1;
int dfn[MAX_N], low[MAX_N], cnt;
map<int, set<int>> cc;

void tarjan(int x, int par)
{
    dfn[x] = low[x] = ++cnt;
    for (auto it : G[x]) {
        if (it == par) {
            continue;
        }
        if (!dfn[it]) {
            tarjan(it, x);
            low[x] = min(low[x], low[it]);
        } else {
            low[x] = min(low[x], dfn[it]);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i, -1);
        }
    }
    for (int i = 1; i <= n; i++) {
        cc[low[i]].insert(i);
    }
    cout << cc.size() << endl;
    for (const auto& c : cc) {
        cout << c.second.size() << ' ';
        for (auto it : c.second) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}