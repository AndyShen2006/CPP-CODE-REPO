#include <bits/stdc++.h>

using namespace std;

vector<int> G[100001];
int a[100001];

void dfs(int n, int k)
{
    if (a[n]) {
        return;
    }
    a[n] = k;
    for (auto it : G[n]) {
        dfs(it, k);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        G[v].push_back(u);
    }
    for (int i = n; i >= 1; i--) {
        dfs(i, i);
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}