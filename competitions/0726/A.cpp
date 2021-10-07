#include <bits/stdc++.h>

using namespace std;

bool vis[30];

int main()
{
    freopen("data/A-example.in", "r", stdin);
    int n;
    char c;
    cin >> n;
    getchar();
    for (int i = 1; i <= n; i++) {
        c = getchar();
        if (!vis[c - 'A']) {
            cout << c;
            vis[c - 'A'] = true;
        }
    }
    return 0;
}