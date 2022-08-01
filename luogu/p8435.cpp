#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 5e5 + 7;
vector<int> G[MAX_N];

int dfn[MAX_N], low[MAX_N], dfc;
int st[MAX_N], top;
map<int, set<int>> ans;
void tarjan(int x, int par)
{
    int cntTree = 0;
    dfn[x] = low[x] = ++dfc;
    st[top++] = x;
    for (auto it : G[x]) {
        if (it == par) {
            continue;
        }
        if (!dfn[it]) {
            cntTree++;
            tarjan(it, x);
            low[x] = min(low[x], low[it]);
            if (low[it] == dfn[x]) {
                int u;
                while () {
                }
            }
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
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i, -1);
        }
    }
    return 0;
}