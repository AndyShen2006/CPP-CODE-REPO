#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline void read(ll& a)
{
    a = 0;
    char c;
    while ((c = getchar()) < 48) // NOLINT
        ;
    do {
        a = a * 10 + (c ^ 48);
    } while ((c = getchar()) > 47); // NOLINT
}

inline void write(ll x)
{
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

ll dfs(ll st, ll r)
{
    if (r == 0)
        return 0;
    if (st <= r) {
        return 0 * r + dfs(st - 0 * r, r / 4);
    } else if (st <= 2 * r) {
        return 2 * r + dfs(st - 1 * r, r / 4);
    } else if (st <= 3 * r) {
        return 3 * r + dfs(st - 2 * r, r / 4);
    } else {
        return 1 * r + dfs(st - 3 * r, r / 4);
    }
}

int main()
{
    ll t;
    read(t);
    while (t--) {
        ll m;
        read(m);
        ll x = ((m - 1) / 3 + 1);
        ll pos = 1, ans = 1;
        while (pos + ans <= x) {
            pos += ans;
            ans <<= 2;
        }
        ll ans1 = ans + x - pos, ans2 = dfs(x - pos + 1, ans >> 2) + (ans << 1);
        if (m % 3 == 1) {
            write(ans1);
            putchar('\n');
        } else if (m % 3 == 2) {
            write(ans2);
            putchar('\n');
        } else {
            write(ans1 ^ ans2);
            putchar('\n');
        }
    }
    return 0;
}