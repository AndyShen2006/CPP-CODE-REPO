#include <bits/stdc++.h>

using namespace std;

int s[100001][20];
int t[100001][20];

int main()
{
    //    freopen("data/slide.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i][0];
        t[i][0] = s[i][0];
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += s[i][0] * t[i][0];
    }
    cout << sum << ' ';
    for (int j = 1; j <= log2(n); j++) {
        for (int i = 1; i <= n + 1 - (1 << j); i++) {
            s[i][j] = min(s[i][j - 1], s[i + (1 << (j - 1))][j - 1]);
            t[i][j] = max(t[i][j - 1], t[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int k = 2; k <= n; k++) {
        //printf("k:%d\n", k);
        sum = 0;
        for (int i = 1; i <= n + 1 - k; i++) {
            int j = log2(k);
            sum += min(s[i][j], s[i + k - (1 << j)][j]) * max(t[i][j], t[i + k - (1 << j)][j]);
        }
        cout << sum << ' ';
    }
    return 0;
}