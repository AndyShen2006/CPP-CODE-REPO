#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 2e5 + 10;
vector<int> G[MAX_N];
int dfn[MAX_N], low[MAX_N], dfc;
int fat[MAX_N];
set<int> cut;
vector<int> chk;
int root;

void tarjan(int x, int par)
{
    int cntTree = 0;
    dfn[x] = low[x] = ++dfc;
    for (auto it : G[x]) {
        if (it == par) {
            continue;
        }
        if (!dfn[it]) {
            cntTree++;
            fat[it] = x;
            tarjan(it, x);
            low[x] = min(low[x], low[it]);
            if (low[it] >= dfn[x] && x != root) {
                cut.insert(x);
            }
        } else {
            low[x] = min(low[x], dfn[it]);
        }
    }
    if (x == root && cntTree >= 2) {
        cut.insert(x);
    }
}

int main()
{
    // freopen("data/p5058.in", "r", stdin);
    int n, u, v, s, t;
    cin >> n;
    do {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    } while (u != 0);
    cin >> s >> t;
    root = s;
    tarjan(root, -1);
    int crt = t;
    while (crt != s) {
        crt = fat[crt];
        if (cut.find(crt) != cut.end()) {
            chk.push_back(crt);
        }
    }
    int ans = INT_MAX;
    for (auto it : chk) {
        ans = min(it, ans);
    }
    if (ans == INT_MAX) {
        cout << "No solution" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}