#include <bits/stdc++.h>

using namespace std;

// Global variables and constants
constexpr int MAX_N = 200010;
int a[MAX_N], ans[MAX_N];
int n, m;

// Structs
struct Query {
    int id, type;
    int l, r, k;
    int data;
    Query() = default;
    Query(int L, int R, int K, int ID)
    {
        l = L;
        r = R;
        k = K;
        id = ID;
        type = 2;
        data = -1;
    }
    Query(int D, int ID)
    {
        data = D;
        id = ID;
        l = -1;
        r = -1;
        k = -1;
        type = 1;
    }
} qs[MAX_N << 1], qsl[MAX_N << 1], qsr[MAX_N << 1];
int tot;

// Binary Indexed Tree
int BIT[MAX_N];
inline int lowbit(int x)
{
    return x & (-x);
}
void update(int x, int val)
{
    while (x <= n) {
        BIT[x] += val;
        x += lowbit(x);
    }
}
int sum(int x)
{
    int ans = 0;
    while (x) {
        ans += BIT[x];
        x -= lowbit(x);
    }
    return ans;
}

void solve(int vl, int vr, int ql, int qr)
{
    if (ql > qr) {
        return;
    }
    if (vl == vr) {
        for (int i = ql; i <= qr; i++) {
            if (qs[i].type == 2) {
                ans[qs[i].id] = vl;
            }
        }
        return;
    }
    int vmid = (vl + vr) >> 1;
    int cntL = 0, cntR = 0;
    for (int i = ql; i <= qr; i++) {
        if (qs[i].type == 1) {
            if (qs[i].l <= vmid) {
                update(qs[i].id, 1);
                qsl[++cntL] = qs[i];
            } else {
                qsr[++cntR] = qs[i];
            }
        } else {
            int x = sum(qs[i].r) - sum(qs[i].l - 1);
            if (qs[i].k <= x) {
                qsl[++cntL] = qs[i];
            } else {
                qs[i].k -= x;
                qsr[++cntR] = qs[i];
            }
        }
    }
    for (int i = 1; i <= cntL; i++) {
        if (qsl[i].type == 1) {
            update(qsl[i].id, -1);
        }
    }
    for (int i = 1; i <= cntL; i++) {
        qs[i + ql - 1] = qsl[i];
    }
    for (int i = 1; i <= cntR; i++) {
        qs[i + cntL + ql - 1] = qsr[i];
    }
    solve(vl, vmid, ql, cntL + ql - 1);
    solve(vmid + 1, vr, cntR + ql, qr);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        qs[++tot] = Query(a[i], i);
    }

    for (int i = 1; i <= m; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        qs[++tot] = Query(l, r, k, i);
    }
    return 0;
}