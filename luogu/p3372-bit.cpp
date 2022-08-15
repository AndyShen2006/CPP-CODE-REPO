#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n, m;

inline int lowbit(int x)
{
    return ((x) & (-x));
}

struct BIT {
    ll sumc[1 << 10];
    void add(int x, ll y)
    {
        while (x <= n) {
            sumc[x] += y;
            x += lowbit(x);
        }
    }
    ll sum(int x)
    {
        ll res = 0;
        while (x > 0) {
            res += sumc[x];
            x -= lowbit(x);
        }
        return res;
    }
} T;

int main()
{
    cin >> n >> m;
    ll tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        T.add(i, tmp);
    }
    int op, x, y, k;
    for (int i = 1; i <= m; i++) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
        } else {
        }
    }
    return 0;
}