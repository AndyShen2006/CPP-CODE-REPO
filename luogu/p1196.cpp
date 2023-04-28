#include <bits/stdc++.h>

using namespace std;

int par[30010], val[30010], num[30010];

int findpar(int x)
{
    if (par[x] == x) {
        return x;
    } else {
        int tmp = par[x];
        par[x] = findpar(par[x]);
        val[x] += val[tmp];
        num[x] = num[par[x]];
        return par[x];
    }
}

void unite(int x, int y)
{
    x = findpar(x);
    y = findpar(y);
    if (x != y) {
        par[x] = y;
        val[x] = val[y] + num[y];
        num[y] += num[x];
        num[x] = num[y];
    }
}

int main()
{
    // Initialization
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 1; i <= 30000; i++) {
        par[i] = i;
        val[i] = 0;
        num[i] = 1;
    }
    int T, x, y;
    // Input and Compute
    cin >> T;
    for (int i = 1; i <= T; i++) {
        char op;
        cin >> op;
        switch (op) {
        case 'M':
            cin >> x >> y;
            unite(x, y);
            break;
        case 'C':
            cin >> x >> y;
            if (findpar(x) == findpar(y)) {
                cout << abs(val[x] - val[y]) - 1 << endl;
            } else {
                cout << -1 << endl;
            }
            break;
        default:
            break;
        }
    }
    // for (int i = 1; i <= 5; i++) {
    //     cout << i << ' ' << par[i] << ' ' << val[i] << endl;
    // }
    return 0;
}