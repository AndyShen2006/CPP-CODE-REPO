#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int MAX_N = 500010;
set<int> G[MAX_N];
map<set<int>, ll> mp;
ll c[MAX_N];

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

int main()
{
    int T;
    read(T);
    while (T--) {
        mp.clear();
        int n, m;
        read(n);
        read(m);
        for (int i = 1; i <= n; i++) {
            G[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            read(c[i]);
        }
        for (int i = 1; i <= m; i++) {
            int l, r;
            read(l);
            read(r);
            G[r].insert(l);
        }
        for (int i = 1; i <= n; i++) {
            if (G[i].empty()) {
                continue;
            }
            mp[G[i]] += c[i];
        }
        ll ans = 0;
        for (const auto& it : mp) {
            if (!ans) {
                ans = it.second;
            } else {
                ans = __gcd(ans, it.second);
            }
        }
        write(ans);
        putchar('\n');
    }
    return 0;
}