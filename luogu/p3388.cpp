#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 2e4 + 5;
vector<int> G[MAX_N];

bool isCut[MAX_N];
int dfn[MAX_N], low[MAX_N], dfc;
int root, ans;

void tarjan(int i, int par)
{
    int cntTree = 0;
    dfn[i] = low[i] = ++dfc;
    for (auto it : G[i]) {
        if (it == par) {
            continue;
        }
        if (!dfn[it]) {
            cntTree++;
            tarjan(it, i);
            low[i] = min(low[it], low[i]);
            if (low[it] >= dfn[i] && i != root) {
                isCut[i] = true;
            }
        } else {
            low[i] = min(dfn[it], low[i]);
        }
    }
    if (i == root && cntTree >= 2) {
        isCut[i] = true;
    }
}

int main()
{
    freopen("data/p3388c.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        root = i;
        tarjan(root, -1);
    }
    for (int i = 1; i <= n; i++) {
        if (isCut[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
        if (isCut[i]) {
            cout << i << ' ';
        }
    }
    return 0;
}