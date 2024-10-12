#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 1010;
vector<int> G[MAX_N];
bool stops[MAX_N];
int deg[MAX_N];
int level[MAX_N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        memset(stops, 0, sizeof(stops));
        int s;
        cin >> s;
        for (int j = 1; j <= s; j++) {
            int v;
            cin >> v;
            stops[v] = true;
        }
        for (int j = 1; j <= n; j++) {
            if (stops[j]) {
                for (int k = j + 1; k <= n; k++) {
                    if (!stops[k]) {
                        G[j].push_back(k);
                        deg[k]++;
                    }
                }
            }
        }
    }
    queue<int> Q;
    for (int i = 1; i <= n; i++) {
        if (!deg[i]) {
            Q.push(i);
            level[i] = 1;
        }
    }
    int ans = 1;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto it : G[u]) {
            deg[it]--;
            if (!deg[it]) {
                Q.push(it);
                level[it] = level[u] + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        // cout << i << ' ' << level[i] << endl;
        ans = max(ans, level[i]);
    }
    cout << ans << endl;
    return 0;
}