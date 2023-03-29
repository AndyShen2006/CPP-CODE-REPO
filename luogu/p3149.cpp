#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 300010;
#define DEBUG 0

inline int lowbit(const int& x)
{
    return x & (-x);
}

int b[MAX_N];
int a[MAX_N];
long long bt[MAX_N], suf[MAX_N];

inline void update(const int& n, int x)
{
    while (x <= n) {
        bt[x]++;
        x += lowbit(x);
    }
}

inline long long query(int x)
{
    long long ans = 0;
    while (x > 0) {
        ans += bt[x];
        x -= lowbit(x);
    }
    return ans;
}

signed main()
{
#if DEBUG
    freopen("data/p3179b.in", "r", stdin);
    freopen("data/p3149.out", "w", stdout);
    freopen("data/p3149.log", "w", stderr);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    // Discretize
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    long long ans = 0;
    sort(b + 1, b + n + 1);
    int cnt = static_cast<int>(unique(b + 1, b + n + 1) - b - 1);
    for (int i = n; i > 0; i--) {
        a[i] = static_cast<int>(lower_bound(b + 1, b + cnt + 1, a[i]) - b);
        int k = static_cast<int>(query(a[i] - 1));
        ans += k;
        suf[a[i]] += k;
        update(n, a[i]);
    }
    cout << ans << endl;
    int q, last = 0;
    for (int i = 1; i <= m; i++) {
        cin >> q;
        while (a[q] > last) {
            last++;
            ans -= suf[last];
        }
        cout << ans << endl;
    }
    return 0;
}