#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int MAX_N = 1e5 + 10;
int n;
ll a[MAX_N], b[MAX_N], c[MAX_N], t[MAX_N];
int mapping[MAX_N];
bool vis[MAX_N];
vector<int> G[MAX_N];

// Tree x, Height on [l,r]
ll calc(int x, int l, int r)
{
    if (c[x] >= 0) {
        return b[x] * (r - l + 1) + c[x] * (l + r) * (r - l + 1) / 2;
    }
    ll T = (1 - b[x]) / c[x];
    if (T < l) {
        return r - l + 1;
    }
    if (T > r) {
        return b[x] * (r - l + 1) + c[x] * (l + r) * (r - l + 1) / 2;
    }
    return b[x] * (T - l + 1) + c[x] * (l + T) * (T - l + 1) / 2 + r - T;
}

int par[MAX_N];
void dfs(int x)
{
    for (auto it : G[x]) {
        if (it == par[x]) {
            continue;
        }
        par[it] = x;
        dfs(it);
    }
}

bool check(int m)
{
    for (int i = 1; i <= n; i++) {
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (calc(i, mid, m) >= a[i]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        t[i] = l;
        mapping[i] = i;
        vis[i] = false;
    }
    sort(mapping + 1, mapping + n + 1, [](int lhs, int rhs) -> bool { return t[lhs] < t[rhs]; });
    int days = 0;
    for (int i = 1; i <= n; i++) {
        vector<int> chain;
        int cur = mapping[i];
        while (cur != -1) {
            chain.push_back(cur);
            vis[cur] = true;
            cur = par[cur];
        }
        while (!chain.empty()) {
            days++;
            if (t[chain.back()] < days) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    freopen("data/p9755a.in", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    par[1] = -1;
    dfs(1);
    int l = n, r = 1e9;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}