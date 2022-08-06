#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 5e5 + 5;
vector<pair<int, bool>> G[MAX_N];

int dfn[MAX_N], low[MAX_N], dfc;
int root, ans;
vector<int> bcc[MAX_N];
int bcccnt;

void tarjan(int x, int par)
{
    int cntTree = 0;
    dfn[x] = low[x] = ++dfc;
    for (auto& it : G[x]) {
        if (it.first == par) {
            continue;
        }
        if (!dfn[it.first]) {
            cntTree++;
            tarjan(it.first, x);
            low[x] = min(low[it.first], low[x]);
            if (low[it.first] > dfn[x]) {
                // delete x->it.first
                it.second = false;
                // delete it.first->x
                for (auto& del : G[it.first]) {
                    if (del.first == x) {
                        del.second = false;
                    }
                }
            }
        } else {
            low[x] = min(dfn[it.first], low[x]);
        }
    }
}

bool vis[MAX_N];
void dfs(int x)
{
    if (vis[x]) {
        return;
    }
    vis[x] = true;
    bcc[bcccnt].emplace_back(x);
    for (auto it : G[x]) {
        // This edge isn't cut edge, search it
        if (it.second) {
            dfs(it.first);
        }
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    // freopen("data/p8435.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        G[x].push_back(make_pair(y, true));
        G[y].push_back(make_pair(x, true));
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            root = i;
            tarjan(root, -1);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            bcccnt++;
            dfs(i);
        }
    }
    cout << bcccnt << endl;
    for (int i = 1; i <= bcccnt; i++) {
        cout << bcc[i].size() << ' ';
        for (auto it : bcc[i]) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}