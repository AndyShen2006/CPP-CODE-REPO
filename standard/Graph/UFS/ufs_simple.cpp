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
        return find(par[n]);
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
    int n, m, p;
    cin >> n >> m >> p;
    init(n + 10);
    int mi, mj;
    for (int i = 0; i < m; i++) {
        cin >> mi >> mj;
        unite(mi, mj);
    }
    int pi, pj;
    for (int i = 0; i < p; i++) {
        cin >> pi >> pj;
        if (isSamePar(pi, pj))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}