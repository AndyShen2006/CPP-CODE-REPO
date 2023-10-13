#include <bits/stdc++.h>

using namespace std;

#define int long long
constexpr int MAX_N = 5020;
vector<int> G[MAX_N];
bool ra[MAX_N][MAX_N];
vector<int> f[MAX_N];
int score[MAX_N];
int dis[MAX_N];

void bfs(int x, int k)
{
    memset(dis, 0x3f, sizeof(dis));
    queue<int> q;
    q.push(x);
    dis[x] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u != x) {
            ra[x][u] = true;
            if (x != 1 && ra[1][u]) {
                f[x].push_back(u);
                sort(f[x].begin(), f[x].end(), [](int u, int v) -> bool { return score[u] > score[v]; });
                if (f[x].size() > 3) {
                    f[x].pop_back();
                }
            }
        }
        if (dis[u] >= k + 1) {
            continue;
        }
        for (auto it : G[u]) {
            if (dis[it] == 0x3f3f3f3f3f3f3f3f) {
                dis[it] = dis[u] + 1;
                q.push(it);
            }
        }
    }
}

signed main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 2; i <= n; i++) {
        cin >> score[i];
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        bfs(i, k);
    }
    int ans = 0;
    for (int b = 2; b <= n; b++) {
        for (int c = 2; c <= n; c++) {
            if (ra[b][c]) {
                for (auto a : f[b]) {
                    for (auto d : f[c]) {
                        if (a != c && b != d && a != d) {
                            ans = max(ans, score[a] + score[b] + score[c] + score[d]);
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}