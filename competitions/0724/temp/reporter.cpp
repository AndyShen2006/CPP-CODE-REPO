#include <bits/stdc++.h>

using namespace std;

#define INF 0x7fffffff

int hMap[1001][1001];
int dis[1001][1001];
int n, m;
int sr, sc, er, ec;
void dfs(int nr, int nc, int d, int heal)
{

    if (heal <= 0 || (nr > n && nc > m) || nr <= 0 || nc <= 0 || d >= dis[nr][nc]) {
        return;
    }
    dis[nr][nc] = d;
    if (nr != n) {
        if (hMap[nr][nc] - hMap[nr + 1][nc] > 3) {
            dfs(nr + 1, nc, d + 1, heal - 1);
        }
        if (hMap[nr][nc] - hMap[nr - 1][nc] > 3) {
            dfs(nr - 1, nc, d + 1, heal - 1);
        }
        if (hMap[nr + 1][nc] - hMap[nr][nc] <= 2) {
            dfs(nr + 1, nc, d + 1, heal);
        }
        if (hMap[nr - 1][nc] - hMap[nr][nc] <= 2) {
            dfs(nr - 1, nc, d + 1, heal);
        }
    }
    if (nc != m) {
        if (hMap[nr][nc] - hMap[nr][nc + 1] > 3) {
            dfs(nr, nc + 1, d + 1, heal - 1);
        }
        if (hMap[nr][nc] - hMap[nr][nc - 1] > 3) {
            dfs(nr, nc - 1, d + 1, heal - 1);
        }
        if (hMap[nr][nc + 1] - hMap[nr][nc] <= 2) {
            dfs(nr, nc + 1, d + 1, heal);
        }
        if (hMap[nr][nc - 1] - hMap[nr][nc] <= 2) {
            dfs(nr, nc - 1, d - 1, heal);
        }
    }
}

int main()
{
    freopen("reporter.in", "r", stdin);
    freopen("reporter.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    cin >> sr >> sc >> er >> ec;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> hMap[i][j];
            dis[i][j] = INF;
        }
    }
    dfs(sr, sc, 0, 5);
    cout << dis[n][m] << endl;
    return 0;
}