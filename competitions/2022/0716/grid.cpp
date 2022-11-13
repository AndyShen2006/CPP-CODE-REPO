#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
// constexpr int M = 64000000;

vector<string> G;
queue<P> q;
int dis[8001][8001];

inline int d(int r1, int c1, int r2, int c2)
{
    if (G[r1 - 1][c1 - 1] == G[r2 - 1][c2 - 1]) {
        return 0;
    } else {
        return 1;
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    string ts;
    G.reserve(8000);
    for (int i = 1; i <= n; i++) {
        cin >> ts;
        G.emplace_back(ts);
    }
    memset(dis, 0x3f, sizeof(dis));
    q.push(P(1, 1));
    dis[1][1] = 0;
    while (!q.empty()) {
        P u = q.front();
        q.pop();
        // cout << u.first << ' ' << u.second << ' ' << endl;
        if (u.first + 1 <= n && dis[u.first][u.second] + d(u.first, u.second, u.first + 1, u.second) < dis[u.first + 1][u.second]) {
            dis[u.first + 1][u.second] = dis[u.first][u.second] + d(u.first, u.second, u.first + 1, u.second);
            q.push(P(u.first + 1, u.second));
        }
        if (u.first - 1 >= 1 && dis[u.first][u.second] + d(u.first, u.second, u.first - 1, u.second) < dis[u.first - 1][u.second]) {
            dis[u.first - 1][u.second] = dis[u.first][u.second] + d(u.first, u.second, u.first - 1, u.second);
            q.push(P(u.first - 1, u.second));
        }
        if (u.second + 1 <= m && dis[u.first][u.second] + d(u.first, u.second, u.first, u.second + 1) < dis[u.first][u.second + 1]) {
            dis[u.first][u.second + 1] = dis[u.first][u.second] + d(u.first, u.second, u.first, u.second + 1);
            q.push(P(u.first, u.second + 1));
        }
        if (u.second - 1 >= 1 && dis[u.first][u.second] + d(u.first, u.second, u.first, u.second - 1) < dis[u.first][u.second - 1]) {
            dis[u.first][u.second - 1] = dis[u.first][u.second] + d(u.first, u.second, u.first, u.second - 1);
            q.push(P(u.first, u.second - 1));
        }
    }
    cout << dis[n][m] << endl;
    return 0;
}