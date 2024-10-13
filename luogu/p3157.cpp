#include <bits/stdc++.h>

using namespace std;

// Global constants and variables.
constexpr int MAX_N = 100010;
int n, m;
int ms[50010];
int mapping[MAX_N]; // Value -> Position

// Structs
struct Element {
    int a, t, p;
    int res;
} elems[MAX_N];

// Binary Indexed Tree

int BIT[MAX_N << 2];

inline int lowbit(int x)
{
    return x & (-x);
}

void update(int pos, int val)
{
    while (pos <= n) {
        BIT[pos] += val;
        pos += lowbit(pos);
    }
}

int query(int pos)
{
    int ans = 0;
    while (pos) {
        ans += BIT[pos];
        pos -= lowbit(pos);
    }
    return ans;
}

// cdq divide and conquer

void cdq(int l, int r)
{
    if (l >= r) {
        return;
    }
    int mid = (l + r) >> 1;
    cdq(l, mid);
    cdq(mid + 1, r);
    sort(elems + l, elems + mid + 1, [](const Element& lhs, const Element& rhs) -> bool { return lhs.a < rhs.a; });
    sort(elems + mid + 1, elems + r + 1, [](const Element& lhs, const Element& rhs) -> bool { return lhs.a < rhs.a; });
    int posL = l, posR = mid + 1;
    while (posR <= r) {
        while (posL <= mid && elems[posL].a < elems[posR].a) {
            update(elems[posL].p, 1);
            posL++;
        }
        elems[posR].res += query(m + 1) - query(elems[posR].p);
        posR++;
    }
    for (int i = l; i < posL; i++) {
        update(elems[i].p, -1);
    }
    posL = mid, posR = r;
    while (posR >= mid + 1) {
        while (posL >= l && elems[posL].a > elems[posR].a) {
            update(elems[posL].p, 1);
            posL--;
        }
        elems[posR].res += query(m + 1) - query(elems[posR].p);
        posR--;
    }
    for (int i = mid; i > posL; i--) {
        update(elems[i].p, -1);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> elems[i].a;
        mapping[elems[i].a] = i;
        elems[i].p = i;
    }
    for (int i = 1; i <= m; i++) {
        int del;
        cin >> del;
        elems[mapping[del]].t = i;
    }
    int j = m;
    for (int i = 1; i <= n; i++) {
        if (!elems[i].t) {
            elems[i].t = ++j;
        }
    }
    sort(elems + 1, elems + n + 1, [](const Element& lhs, const Element& rhs) -> bool { return lhs.t < rhs.t; });
    for (int i = 1; i <= n; i++) {
        cerr << elems[i].p << ' ' << elems[i].a << ' ' << elems[i].t << endl;
    }
    cdq(1, n);
    for (int i = 1; i <= n; i++) {
        cerr << elems[i].res << endl;
    }
    return 0;
}