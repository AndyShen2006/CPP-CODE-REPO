#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 1000010;
typedef long long ll;

// Lines
int ys[MAX_N];
struct Line {
    int x, yl, yr, type;
    bool operator<(const Line& rhs) const
    {
        return x < rhs.x;
    }
} lines[MAX_N << 1];

// Segment Tree
struct Node {
    int l, r, mx;
    ll len;
} st[MAX_N << 2];
void push_up(int cur)
{
    int l = st[cur].l, r = st[cur].r;
    if (st[cur].mx) {
        st[cur].len = ys[r + 1] - ys[l];
    } else {
        st[cur].len = st[cur << 1].len + st[cur << 1 | 1].len;
    }
}
void build(int cur, int l, int r)
{
    st[cur] = { l, r, 0, 0 };
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    build(cur << 1, l, mid);
    build(cur << 1 | 1, mid + 1, r);
}
void update(int cur, ll ul, ll ur, int type)
{
    int l = st[cur].l;
    int r = st[cur].r;
    if (ys[r + 1] <= ul || ur <= ys[l]) {
        return;
    }
    if (ul <= ys[l] && ys[r + 1] <= ur) {
        st[cur].mx += type;
        push_up(cur);
        return;
    }
    update(cur << 1, ul, ur, type);
    update(cur << 1 | 1, ul, ur, type);
    push_up(cur);
}

int main()
{
    // freopen("data/p5490.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // Left Segment
        lines[(i << 1) - 1] = { x1, y1, y2, 1 };
        // Right Segment
        lines[i << 1] = { x2, y1, y2, -1 };
        ys[(i << 1) - 1] = y1;
        ys[i << 1] = y2;
    }
    n <<= 1;
    sort(lines + 1, lines + n + 1);
    sort(ys + 1, ys + n + 1);
    int tot = int(unique(ys + 1, ys + n + 1) - (ys + 1));
    build(1, 1, tot - 1);
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        update(1, lines[i].yl, lines[i].yr, lines[i].type);
        ans += st[1].len * (lines[i + 1].x - lines[i].x);
    }
    cout << ans << endl;
    return 0;
}