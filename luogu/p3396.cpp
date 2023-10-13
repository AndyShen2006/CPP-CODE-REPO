#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 150010;
constexpr int SMN = 400;

int val[MAX_N];
int ans[MAX_N][SMN];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int p = 1; p * p <= n; p++) {
            ans[p][i % p] += val[i];
        }
    }
    for (int i = 1; i <= m; i++) {
        char cmd;
        cin >> cmd;
        if (cmd == 'A') {
            int x, y;
            cin >> x >> y;
            if (x * x <= n) {
                cout << ans[x][y] << endl;
            } else {
                int sum = 0;
                for (int i = y; i <= n; i += x) {
                    sum += val[i];
                }
                cout << sum << endl;
            }
        } else {
            int x, y;
            cin >> x >> y;
            for (int p = 1; p * p <= n; p++) {
                ans[p][x % p] = ans[p][x % p] - val[x] + y;
            }
            val[x] = y;
        }
    }
    return 0;
}