#include <bits/stdc++.h>

using namespace std;

int par[1010];
int cnt[1010];

void init(int n)
{
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
}

int findroot(int n)
{
    if (par[n] == n)
        return n;
    else {
        return findroot(par[n]);
    }
}

void unite(int a, int b, char type)
{
    if (type == 'E') {
        cnt[a] = 1;
        cnt[b] = 1;
    }
    a = findroot(a);
    b = findroot(b);
    if (a == b) {
        return;
    }
    //printf("Unite %d %d\n", a, b);
    par[b] = a;
}

int main()
{
    freopen("data/p1862b.in", "r", stdin);
    int n, m, p, q, ans = 0;
    char opt;
    cin >> n >> m;
    init(n);
    for (int i = 1; i <= m; i++) {
        cin >> opt >> p >> q;
        unite(p, q, opt);
    }
    for (int i = 1; i <= n; i++) {
        //cout << i << ' ' << par[i] << endl;
        if (par[i] == i) {
            ans += 1 + cnt[i];
        }
    }
    cout << ans << endl;
    return 0;
}