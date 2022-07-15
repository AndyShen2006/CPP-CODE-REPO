#include <bits/stdc++.h>

using namespace std;

constexpr int N = 500010;
vector<int> query[N];
vector<int> T[N];
vector<pair<int, int>> tasks;
unordered_map<int, unordered_map<int, int>> ans;

// Union Find Set
int par[N];
int findpar(int n)
{
    return par[n] == n ? n : par[n] = findpar(par[n]);
}
void unite(int a, int b)
{
    a = findpar(a);
    b = findpar(b);
    par[b] = a;
}

// Tarjan's LCA Algorithm
bool vis[N];
void tarjan(int n, int far)
{
    for (auto it : T[n]) {
        if (it == far) {
            continue;
        }
        tarjan(it, n);
    }
    vis[n] = true;
    for (auto it : query[n]) {
        if (vis[it]) {
            ans[n][it] = findpar(it);
            ans[it][n] = ans[n][it];
        }
    }
    unite(far, n);
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    // freopen("data/p3379.in", "r", stdin);
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    int x, y;
    for (int i = 1; i <= n - 1; i++) {
        cin >> x >> y;
        T[x].push_back(y);
        T[y].push_back(x);
    }
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        tasks.push_back(make_pair(x, y));
        query[x].push_back(y);
        query[y].push_back(x);
    }
    tarjan(s, s);
    for (auto it : tasks) {
        cout << ans[it.first][it.second] << endl;
    }
    return 0;
}