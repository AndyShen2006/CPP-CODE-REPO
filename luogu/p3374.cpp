#include <bits/stdc++.h>

using namespace std;

inline int lowbit(int x)
{
    return x & (-x);
}

int n;
int tree[1000000];

void add(int x, int d)
{
    while (x <= n) {
        tree[x] += d;
        x += lowbit(x);
    }
}

int sum(int x)
{
    int sum = 0;
    while (x > 0) {
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
}

int main()
{
    // freopen("data/p3374.in", "r", stdin);
    int m, temp;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        add(i, temp);
    }
    int op, x, y;
    for (int i = 1; i <= m; i++) {
        cin >> op >> x >> y;
        if (op == 1) {
            add(x, y);
        } else {
            cout << sum(y) - sum(x - 1) << endl;
        }
    }
    return 0;
}