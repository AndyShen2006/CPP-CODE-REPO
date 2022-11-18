#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 1e5 + 10;
typedef long long ll;
struct NodeA {
    int l, r;
    ll PosMin, NegMax, Min, Max;
} sta[4 * MAX_N];
struct NodeB {
    int l, r;
    ll Min, Max;
} stb[4 * MAX_N];

int a[MAX_N], b[MAX_N];

void buildA(int pos, int l, int r)
{
    sta[pos] = { l, r };
    if (l == r) {
        sta[pos].PosMin = sta[pos].NegMax = sta[pos].Min = sta[pos].Max = a[l];
        if (a[l] >= 0) {
            sta[pos].NegMax = LONG_LONG_MIN;
        } else {
            sta[pos].PosMin = LONG_LONG_MAX;
        }
        return;
    }
    int mid = (l + r) >> 1;
    buildA(pos << 1, l, mid);
    buildA(pos << 1 | 1, mid + 1, r);
    sta[pos].PosMin = min(sta[pos << 1].PosMin, sta[pos << 1 | 1].PosMin);
    sta[pos].NegMax = max(sta[pos << 1].NegMax, sta[pos << 1 | 1].NegMax);
    sta[pos].Min = min(sta[pos << 1].Min, sta[pos << 1 | 1].Min);
    sta[pos].Max = max(sta[pos << 1].Max, sta[pos << 1 | 1].Max);
}

void buildB(int pos, int l, int r)
{
    stb[pos] = { l, r };
    if (l == r) {
        stb[pos].Min = stb[pos].Max = b[l];
        return;
    }
    int mid = (l + r) >> 1;
    buildB(pos << 1, l, mid);
    buildB(pos << 1 | 1, mid + 1, r);
    stb[pos].Min = min(stb[pos << 1].Min, stb[pos << 1 | 1].Min);
    stb[pos].Max = max(stb[pos << 1].Max, stb[pos << 1 | 1].Max);
}

ll queryNegAMax(int pos, int x, int y)
{
    if (x <= sta[pos].l && sta[pos].r <= y) {
        return sta[pos].NegMax;
    }
    ll NegMax = LONG_LONG_MIN;
    int mid = (sta[pos].l + sta[pos].r) >> 1;
    if (x <= mid) {
        NegMax = max(NegMax, queryNegAMax(pos << 1, x, y));
    }
    if (y > mid) {
        NegMax = max(NegMax, queryNegAMax(pos << 1 | 1, x, y));
    }
    return NegMax;
}

ll queryPosAMin(int pos, int x, int y)
{
    if (x <= sta[pos].l && sta[pos].r <= y) {
        return sta[pos].PosMin;
    }
    ll PosMin = LONG_LONG_MAX;
    int mid = (sta[pos].l + sta[pos].r) >> 1;
    if (x <= mid) {
        PosMin = min(PosMin, queryPosAMin(pos << 1, x, y));
    }
    if (y > mid) {
        PosMin = min(PosMin, queryPosAMin(pos << 1 | 1, x, y));
    }
    return PosMin;
}

ll queryAMax(int pos, int x, int y)
{
    if (x <= sta[pos].l && sta[pos].r <= y) {
        return sta[pos].Max;
    }
    ll Max = LONG_LONG_MIN;
    int mid = (sta[pos].l + sta[pos].r) >> 1;
    if (x <= mid) {
        Max = max(Max, queryAMax(pos << 1, x, y));
    }
    if (y > mid) {
        Max = max(Max, queryAMax(pos << 1 | 1, x, y));
    }
    return Max;
}

ll queryAMin(int pos, int x, int y)
{
    if (x <= sta[pos].l && sta[pos].r <= y) {
        return sta[pos].Min;
    }
    ll Min = LONG_LONG_MAX;
    int mid = (sta[pos].l + sta[pos].r) >> 1;
    if (x <= mid) {
        Min = min(Min, queryAMin(pos << 1, x, y));
    }
    if (y > mid) {
        Min = min(Min, queryAMin(pos << 1 | 1, x, y));
    }
    return Min;
}

ll queryBMin(int pos, int x, int y)
{
    if (x <= stb[pos].l && stb[pos].r <= y) {
        return stb[pos].Min;
    }
    ll Min = LONG_LONG_MAX;
    int mid = (stb[pos].l + stb[pos].r) >> 1;
    if (x <= mid) {
        Min = min(Min, queryBMin(pos << 1, x, y));
    }
    if (y > mid) {
        Min = min(Min, queryBMin(pos << 1 | 1, x, y));
    }
    return Min;
}

ll queryBMax(int pos, int x, int y)
{
    if (x <= stb[pos].l && stb[pos].r <= y) {
        return stb[pos].Max;
    }
    ll Max = LONG_LONG_MIN;
    int mid = (stb[pos].l + stb[pos].r) >> 1;
    if (x <= mid) {
        Max = max(Max, queryBMax(pos << 1, x, y));
    }
    if (y > mid) {
        Max = max(Max, queryBMax(pos << 1 | 1, x, y));
    }
    return Max;
}

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    buildA(1, 1, n);
    buildB(1, 1, m);
    // for (int i = 1; i <= 5; i++) {
    //     printf("[%d,%d]:Max:%lld;Min:%lld\n", stb[i].l, stb[i].r, stb[i].Max, stb[i].Min);
    // }
    int l1, r1, l2, r2;
    for (int i = 1; i <= q; i++) {
        cin >> l1 >> r1 >> l2 >> r2;
        ll AMax = queryAMax(1, l1, r1);
        ll AMin = queryAMin(1, l1, r1);
        ll APosMin = queryPosAMin(1, l1, r1);
        ll ANegMax = queryNegAMax(1, l1, r1);
        ll BMin = queryBMin(1, l2, r2);
        ll BMax = queryBMax(1, l2, r2);
        // printf("AMax:%lld,AMin:%lld,APosMin:%lld,ANegMax:%lld\n", AMax, AMin, APosMin, ANegMax);
        // printf("BMin:%lld,BMax:%lld\n", BMin, BMax);
        ll ans = LONG_LONG_MIN;
        if (AMax >= 0 && BMin >= 0) {
            ans = max(ans, AMax * BMin);
        }
        if (APosMin != LONG_LONG_MAX && BMin < 0) {
            ans = max(ans, APosMin * BMin);
        }
        if (ANegMax != LONG_LONG_MIN && BMax >= 0) {
            ans = max(ans, ANegMax * BMax);
        }
        if (AMin < 0 && BMax < 0) {
            ans = max(ans, AMin * BMax);
        }
        cout << ans << endl;
    }
    return 0;
}