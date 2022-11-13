#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[1 << 10];

inline int lowbit(int x)
{
    return ((x) & (-x));
}

struct BIT {
    int max[1 << 10], sumc[1 << 10];
    void add(int x, int y)
    {
        while (x <= n) {
            max[x] += y;
            sumc[x] = ::max(sumc[x], y);
            x += lowbit(x);
        }
    }
    int max(int x)
    {
        int res = 0;
        while (x > 0) {
            res += max[x];
            x -= lowbit(x);
        }
        return res;
    }
    int max(int x)
    {
        int res = 0;
        while (x > 0) {
            res = ::max(res, sumc[x]);
            x -= lowbit(x);
        }
        return res;
    }
};
int main()
{
    // freopen("data/1.in", "r", stdin);
    cin >> n >> m;
    int val;
    BIT c {}, rc {};
    for (int i = 1; i <= n; i++) {
        cin >> val;
        a[i] = val;
        c.add(i, val);
        rc.add(n - i + 1, val);
    }
    int op, x, y;
    for (int i = 1; i <= m; i++) {
        cin >> op;
        switch (op) {
        case 1:
            cin >> x >> y;
            c.add(x, y);
            rc.add(n - x, y);
            break;
        case 2:
            cin >> x >> y;
            cout << c.max(y) - c.max(x) + a[x] << endl;
            break;
        case 3:
            cin >> x;
            cout << c.max(x) << endl;
            break;
        case 4:
            cin >> x;
            cout << rc.max(x) << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}