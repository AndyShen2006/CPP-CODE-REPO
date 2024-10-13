#include <bits/stdc++.h>

using namespace std;

inline int read()
{
    int x = 0, f = 1;
    char ch = char(getchar());
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = char(getchar());
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - 48;
        ch = char(getchar());
    }
    return x * f;
}

constexpr int MAX_N = 1e5 + 10;
int Log2[MAX_N];
int st[32][MAX_N];

int main()
{
    int n, m;
    n = read(), m = read();
    Log2[1] = 0;
    for (int i = 2; i <= n; i++) {
        Log2[i] = Log2[i >> 1] + 1;
    }
    for (int i = 1; i <= n; i++) {
        st[0][i] = read();
    }
    for (int i = 1; i <= Log2[n]; i++) {
        for (int j = 1; j <= n - (1 << i) + 1; j++) {
            st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            // cout << i << ' ' << j << ' ' << st[i][j] << endl;
        }
    }
    for (int i = 1; i <= m; i++) {
        int l, r;
        l = read();
        r = read();
        printf("%d\n", max(st[Log2[r - l + 1]][l], st[Log2[r - l + 1]][r - (1 << Log2[r - l + 1]) + 1]));
    }
    return 0;
}
