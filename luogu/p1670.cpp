#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 10010;
vector<int> T[MAX_N];
int siz[MAX_N]; // Nodes in subtree.
int msiz[MAX_N];
int n;

void dfs(int x, int par)
{
    siz[x] = 1;
    for (auto it : T[x]) {
        if (it == par) {
            continue;
        }
        dfs(it, x);
        siz[x] += siz[it];
        msiz[x] = max(msiz[x], siz[it]);
    }
    msiz[x] = max(msiz[x], n - siz[x]);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    dfs(1, -1);
    bool noAns = true;
    for (int i = 1; i <= n; i++) {
        if (msiz[i] <= n / 2) {
            noAns = false;
            cout << i << endl;
        }
    }
    if (noAns) {
        cout << "NONE" << endl;
    }
}