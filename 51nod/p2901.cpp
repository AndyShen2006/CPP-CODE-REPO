#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000000;

int par[MAX_N];

void init(int n)
{
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
}

int find(int n)
{
    if (par[n] == n)
        return n;
    else {
        return par[n] = find(par[n]);
    }
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    par[b] = a;
}

bool isSamePar(int a, int b)
{
    return find(a) == find(b);
}

int main()
{
    int n, m, ta, tb;
    cin >> n >> m;
    init(n + 10);
    for (int i = 1; i <= m; i++) {
        cin >> ta >> tb;
        unite(ta, tb);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (par[i] == i) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}