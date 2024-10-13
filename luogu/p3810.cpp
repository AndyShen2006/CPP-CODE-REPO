#include <bits/stdc++.h>

using namespace std;

// Structs
constexpr int MAX_N = 200010;
struct Element {
    int a, b, c;
    int cnt, res;
    bool operator<(const Element& rhs) const
    {
        return this->a == rhs.a ? this->b == rhs.b ? this->c < rhs.c : this->b < rhs.b : this->a < rhs.a;
    }
    bool operator==(const Element& rhs) const
    {
        return this->a == rhs.a && this->b == rhs.b && this->c && rhs.c;
    }
} elems[MAX_N];

map<Element, int> melem;

// Global variables
int n, k, res[MAX_N];

// Binary Indexed Tree
int BIT[MAX_N << 1];

inline int lowbit(int x)
{
    return x & (-x);
}

void add(int x, int v)
{
    while (x <= k) {
        BIT[x] += v;
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

// cdq divide and conquer

void cdq(int l, int r)
{
    if (l >= r) {
        return;
    }
    int mid = (l + r) >> 1;
    cdq(l, mid);
    cdq(mid + 1, r);
    sort(elems + l, elems + mid + 1, [](const Element& lhs, const Element& rhs) -> bool { return lhs.b == rhs.b ? lhs.c < rhs.c : lhs.b < rhs.b; });
    sort(elems + mid + 1, elems + r + 1, [](const Element& lhs, const Element& rhs) -> bool { return lhs.b == rhs.b ? lhs.c < rhs.c : lhs.b < rhs.b; });
    int posL = l, posR = mid + 1;
    while (posR <= r) {
        while (posL <= mid && elems[posL].b <= elems[posR].b) {
            add(elems[posL].c, elems[posL].cnt);
            posL++;
        }
        elems[posR].res += sum(elems[posR].c);
        posR++;
    }
    for (int i = l; i < posL; i++) {
        add(elems[i].c, -elems[i].cnt);
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        Element tmp = {};
        cin >> tmp.a >> tmp.b >> tmp.c;
        melem[tmp]++;
    }
    // for (auto it : melem) {
    //     cerr << it.first.a << ' ' << it.first.b << ' ' << it.first.c << ' ' << it.second << endl;
    // }
    int m = 0;
    for (auto it : melem) {
        elems[++m] = { it.first.a, it.first.b, it.first.c, it.second, 0 };
    }
    // cout << m << endl;
    // for (int i = 1; i <= m; i++) {
    //     cerr << elems[i].a << ' ' << elems[i].b << ' ' << elems[i].c << ' ' << elems[i].cnt << endl;
    // }
    cdq(1, m);

    for (int i = 1; i <= m; i++) {
        res[elems[i].res + elems[i].cnt - 1] += elems[i].cnt;
        // cout << elems[i].res << endl;
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << endl;
    }
    return 0;
}