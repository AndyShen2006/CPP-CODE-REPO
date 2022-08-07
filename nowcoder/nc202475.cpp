#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<int> T[100010];
ll val[100010];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    int u, v;
    for (int i = 1; i <= n - 1; i++) {
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    return 0;
}