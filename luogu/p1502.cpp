#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int MAX_N = 100010;

struct Line {
    int x;
    int yl, yr;
    int light;
    bool operator<(const Line& rhs) const
    {
        return x < rhs.x;
    }
} lines[MAX_N << 1];
int ys[MAX_N << 1];

// Segment Tree
struct Node {
    int l, r;
    ll mx;
    int lazy;
} st[MAX_N << 2];
void push_up(int cur)
{
    st[cur].mx = max(st[cur << 1].mx, st[cur << 1 | 1].mx);
}
void push_down(int cur)
{
    st[cur << 1].mx += st[cur].lazy;
    st[cur << 1 | 1].mx += st[cur].lazy;
    st[cur << 1].lazy += st[cur].lazy;
    st[cur << 1 | 1].lazy += st[cur].lazy;
    st[cur].lazy = 0;
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
void update(int cur, int ul, int ur, int light)
{
    int l = st[cur].l, r = st[cur].r;
    if (ys[r + 1] <= ul || ur <= ys[l]) {
        return;
    }
    if (ul <= ys[l] && ys[r] <= ur) {
        st[cur].mx += light;
        st[cur].lazy += light;
        return;
    }
    push_down(cur);
    update(cur << 1, ul, ur, light);
    update(cur << 1 | 1, ul, ur, light);
    push_up(cur);
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        memset(lines, 0, sizeof(lines));
        memset(ys, 0, sizeof(ys));
        memset(st, 0, sizeof(st));
        int n, w, h;
        cin >> n >> w >> h;
        for (int i = 1; i <= n; i++) {
            int x, y, l;
            cin >> x >> y >> l;
            ys[(i << 1) - 1] = y;
            ys[i << 1] = y + h - 1;
            lines[(i << 1) - 1] = { x, y, y + h - 1, l };
            lines[i << 1] = { x + w - 1, y, y + h - 1, -l };
        }
        n <<= 1;
        sort(ys + 1, ys + n + 1);
        sort(lines + 1, lines + n + 1);
        int tot = int(unique(ys + 1, ys + n + 1) - (ys + 1));
        build(1, 1, tot);
        ll ans = 0;
        for (int i = 1; i < n; i++) {
            update(1, lines[i].yl, lines[i].yr, lines[i].light);
            ans = max(ans, st[1].mx);
        }
        cout << ans << endl;
    }
    return 0;
}