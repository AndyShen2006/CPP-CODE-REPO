#include <bits/stdc++.h>

using namespace std;
#define MAX_N 100001
#define lowbit(i) ((i) & -(i))

int bit[MAX_N + 1], n;

int sum(int i)
{
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i -= lowbit(i);
    }
    return s;
}

void add(int i, int x)
{
    while (i <= n) {
        bit[i] += x;
        i += lowbit(i);
    }
}

int main()
{
    int n, m, a;
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        add(i, a);
    }
    int opt, x, k;
    for (int i = 1; i <= m; i++) {
        cin >> opt;
        switch (opt) {
        case 1:
            cin >> x >> k;
            add(x, k);
            break;
        case 2:
            cin >> x >> k;
            cout << sum(k) - sum(x) << endl;
            break;
        default:;
        }
    }
    return 0;
}