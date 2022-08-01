#include <bits/stdc++.h>

using namespace std;

char G[401][5];

int main()
{
    // freopen("data/malody.in", "r", stdin);
    // freopen("data/malody.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a, k;
    for (int i = 1; i <= m; i++) {
        fill(G[i], G[i] + 5, ' ');
    }
    for (int i = 1; i <= n; i++) {
        cin >> a >> k;
        G[a][k] = '_';
    }
    for (int i = m; i >= 1; i--) {
        for (int j = 1; j <= 4; j++) {
            cout << G[i][j];
        }
        cout << endl;
    }
    return 0;
}