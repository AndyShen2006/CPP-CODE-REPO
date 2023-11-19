#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 100010;
typedef long long ll;

template <typename T>
inline void read(T& a)
{
    a = 0;
    char c;
    while ((c = getchar()) < 48) // NOLINT
        ;
    do {
        a = a * 10 + (c ^ 48);
    } while ((c = getchar()) > 47); // NOLINT
}

template <typename T>
inline void write(T x)
{
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

struct Item {
    ll a, b;
    bool operator<(const Item& rhs) const
    {
        return a < rhs.a;
    }
    Item() = default;
    Item(ll ia, ll ib)
    {
        a = ia, b = ib;
    }
} items[MAX_N];
ll preA[MAX_N];

int main()
{
    int t;
    read(t);
    while (t--) {
        int n, m;
        memset(items, 0, sizeof(items));
        memset(preA, 0, sizeof(preA));
        read(n);
        read(m);
        for (int i = 1; i <= m; i++) {
            read(items[i].a);
            read(items[i].b);
        }
        ll ans = 0, score;
        sort(items + 1, items + m + 1);
        for (int i = 1; i <= m; i++) {
            preA[i] = preA[i - 1] + items[i].a;
        }
        for (int i = 1; i <= m; i++) {
            ll curb = items[i].b;
            ll tn = n;
            score = 0;
            int pos = lower_bound(items + 1, items + m + 1, Item(curb, 0)) - items;
            // cout << curb << ' ' << pos << endl;
            // for (int i = pos; i <= m; i++) {
            //     tn--;
            //     score += items[i].a;
            // }
            if (m - tn >= pos) {
                score += preA[m] - preA[m - tn];
                tn = 0;
            } else {
                score += preA[m] - preA[pos - 1];
                tn = tn - (m - pos + 1);
            }
            if (tn == 1) {
                if (i < pos) {
                    score += items[pos - 1].a;
                } else {
                    score += items[i].b;
                }
            } else if (tn > 1) {
                if (i < pos) {
                    score += items[i].a;
                    tn--;
                }
                // while (tn > 0) {
                //     score += items[i].b;
                //     tn--;
                // }
                score += tn * items[i].b;
            }
            ans = max(score, ans);
        }
        write(ans);
        putchar('\n');
    }
    return 0;
}