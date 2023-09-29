#include <bits/stdc++.h>

using namespace std;

int a[40010];
int indeg[40010];
int tid[40010], par[40010], ta[40010];
int n, m;
vector<int> G[40010];

bool check(int maxLen)
{
    queue<int> Q;
    memcpy(tid, indeg, sizeof(indeg));
    memset(par, 0, sizeof(par));
    // memset(ta, 0, sizeof(ta));
    set<int> rest;
    for (int i = 1; i <= n; i++) {
        rest.insert(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (tid[i] == 0) {
            Q.push(i);
        }
    }
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (*rest.begin() - ta[par[u]] <= maxLen) {
            ta[u] = *rest.begin();
            rest.erase(rest.begin());
        } else {
            return false;
        }
        for (auto it : G[u]) {
            tid[it]--;
            if (tid[it] == 0) {
                Q.push(it);
            }
        }
    }
    return true;
}

int dfs(int u, int curMax)
{
    if (u == n) {
        // cout << curMax << endl;
        return curMax;
    }
    int ans = INT_MAX;
    for (auto it : G[u]) {
        ans = min(ans, dfs(it, max(ta[it] - ta[u], curMax)));
    }
    return ans;
}

int main()
{
    freopen("arrange.in", "r", stdin);
    freopen("arrange.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        indeg[v]++;
    }
    int l = 1, r = INT_MAX - 1, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << ta[i] << ' ';
    // }
    // cout << endl;
    cout << dfs(1, 0) << endl;
    return 0;
}