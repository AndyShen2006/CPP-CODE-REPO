#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll readn()
{
    char c = getchar();
    ll ans = 0;
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
        ans = ans * 10 + c - '0', c = getchar();
    return ans;
}
inline char readc()
{
    char c = getchar();
    while (c != 'M' && c != 'W')
        c = getchar();
    return c;
}
ll n, x, t, m, l, r;
ll pr(ll x) { return (x % m + m) % m; }
ll a[500010], b[500010], f[500010];
ll c[500010], d[500010], z, p;
void zred(ll id)
{
    if (id > n)
        return;
    if (!d[id])
        z--;
}
void zadd(ll id)
{
    if (id > n)
        return;
    if (!d[id])
        z++;
}
char s;
int main()
{
    n = readn(), x = readn(), t = readn(), m = readn();
    for (int i = 1; i <= n; i++)
        a[i] = readn();
    for (int i = 1; i <= n; i++)
        b[i] = readn();
    for (int i = 1; i <= min(x, n); i++)
        f[i] = 1;
    for (int i = x + 1; i <= n; i++)
        f[i] = pr(f[i - x] + f[i - x - 1]);
    for (int i = 1; i <= n; i++)
        c[i] = a[i] - b[i];
    for (int i = 1; i <= min(x, n); i++) {
        d[i] = pr(c[i]);
        if (!d[i])
            z++;
    }
    for (int i = x + 1; i <= n; i++) {
        d[i] = pr(c[i] - c[i - x] - c[i - x - 1]);
        if (!d[i])
            z++;
    }
    while (t--) {
        if (readn() == 1) {
            s = readc(), l = readn(), r = readn(), p = -1;
            if (s == 'M')
                p = 1;
            if (l + x - 1 > r) {
                for (int i = l; i <= r; i++) {
                    if (!d[i])
                        z--;
                    d[i] = pr(d[i] + p);
                    if (!d[i])
                        z++;
                }
                zred(l + x);
                d[l + x] = pr(d[l + x] - p);
                zadd(l + x);
                for (int i = 1; i <= r - l; i++) {
                    zred(l + x + i);
                    d[l + x + i] = pr(d[l + x + i] - p * 2);
                    zadd(l + x + i);
                }
                zred(r + x + 1);
                d[r + x + 1] = pr(d[r + x + 1] - p);
                zadd(r + x + 1);
            } else {
                for (int i = 0; i < x; i++) {
                    zred(l + i);
                    d[l + i] = pr(d[l + i] + p);
                    zadd(l + i);
                }
                for (int i = 1; i <= x; i++) {
                    zred(r + i);
                    d[r + i] = pr(d[r + i] - p * f[r - l + i + 1]);
                    zadd(r + i);
                }
                zred(r + x + 1);
                d[r + x + 1] = pr(d[r + x + 1] - p * f[r - l + 1]);
                zadd(r + x + 1);
            }
        } else {
            if (z == n)
                printf("Sure\n");
            else
                printf("No way\n");
        }
    }
    return 0;
}
