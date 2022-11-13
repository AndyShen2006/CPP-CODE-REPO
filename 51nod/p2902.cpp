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
    int c, n, m, tx, ty;
    bool isWaste;
    cin >> c;
    for (int i = 1; i <= c; i++) {
        cin >> n >> m;
        isWaste = false;
        init(n + 10);
        for (int j = 1; j <= m; j++) {
            cin >> tx >> ty;
            if (isSamePar(tx, ty)) {
                isWaste = true;
                break;
            }
            unite(tx, ty);
        }
        cout << (isWaste ? "Yes" : "No") << endl;
    }
    return 0;
}