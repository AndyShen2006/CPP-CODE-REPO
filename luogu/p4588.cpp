#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int MAX_Q = 100010;
ll M;

ll st[4 * MAX_Q];

void push_up(int x)
{
    st[x] = (st[x << 1] * st[(x << 1) + 1]) % M;
}

void build(int x, int l, int r)
{
    st[x] = 1;
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    build(x << 1, l, mid);
    build((x << 1) + 1, mid + 1, r);
    push_up(x);
}

void update(int pos, int x, int l, int r, int cur)
{
    if (l == r) {
        st[cur] = x;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) {
        update(pos, x, l, mid, cur << 1);
    } else {
        update(pos, x, mid + 1, r, cur << 1 | 1);
    }
    push_up(cur);
}

int main()
{
    // freopen("data/p4588.in", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int Q;
        cin >> Q >> M;
        build(1, 1, Q);
        for (int i = 1; i <= Q; i++) {
            int op;
            cin >> op;
            if (op == 1) {
                int m;
                cin >> m;
                update(i, m, 1, Q, 1);
                cout << st[1] << endl;
            } else {
                int pos;
                cin >> pos;
                update(pos, 1, 1, Q, 1);
                cout << st[1] << endl;
            }
            // for (int i = 1; i <= 4 * Q; i++) {
            //     cout << st[i] << ' ';
            // }
            // cout << endl;
        }
    }
    return 0;
}