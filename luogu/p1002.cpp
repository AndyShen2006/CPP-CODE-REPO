#include <bits/stdc++.h>

using namespace std;

long long dp[25][25];

bool antiPos[25][25] = { 0 };

void show(long long n, long long m)
{
    for (long long i = 0; i <= n; i++) {
        for (long long j = 0; j <= m; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    long long n, m, r, c;
    cin >> n >> m >> c >> r;
    // Set anti Pos
    antiPos[r][c] = true;
    if (r - 2 >= 1 && c - 1 >= 1) {
        antiPos[r - 2][c - 1] = true;
    }
    if (r - 1 >= 1 && c - 2 >= 1) {
        antiPos[r - 1][c - 2] = true;
    }
    if (r - 2 >= 1 && c + 1 <= m) {
        antiPos[r - 2][c + 1] = true;
    }
    if (r - 1 >= 1 && c + 2 <= m) {
        antiPos[r - 1][c + 2] = true;
    }
    if (r + 2 <= n && c - 1 >= 1) {
        antiPos[r + 2][c - 1] = true;
    }
    if (r + 1 <= n && c - 2 >= 1) {
        antiPos[r + 1][c - 2] = true;
    }
    if (r + 2 <= n && c + 1 <= m) {
        antiPos[r + 2][c + 1] = true;
    }
    if (r + 1 <= n && c + 2 <= m) {
        antiPos[r + 1][c + 2] = true;
    }
    dp[0][0] = 1;
    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= m; j++) {
            if (antiPos[i][j]) {
                continue;
            }
            cout << i << ' ' << j << endl;
            if (i - 1 < 0) {
                dp[i][j] = dp[i][j - 1];
            } else if (j - 1 < 0) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    show(n, m);
    cout << dp[n][m];
    return 0;
}