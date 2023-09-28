#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;
using namespace cdg;

bool vis[20010];
bool used[20010];
pair<int, int> BT[20010];
int par[20010];
int mapping[20010];

int main()
{
    int n, m;
    n = randint(10, 20);
    m = randint(2, n * 2 / 3);
    cout << n << ' ' << m << endl;
    // Make Mappings
    for (int i = 1; i <= n; i++) {
        mapping[i] = i;
    }
    // Make a chain
    for (int i = 1; i <= n - 1; i++) {
        BT[i].first = i + 1;
        par[i + 1] = i;
    }
    BT[n].first = 0;
    int k = randint(2, n / 3);
    // Let k chains become the right tree
    for (int i = 1; i <= k; i++) {
        int u, v;
        do {
            v = randint(2, n / 2);
            u = randint(v + 1, n);
        } while (vis[v] || vis[u]); // Par[u] = v u>v
        vis[v] = true;
        vis[u] = true;
        BT[par[u]].first = 0;
        par[u] = v;
        BT[v].second = u;
    }
    for (int i = 1; i <= n; i++) {
        cout << mapping[BT[i].first] << ' ' << mapping[BT[i].second] << endl;
    }
    shuffle(mapping + 2, mapping + n + 1, rand_eng);
    for (int i = 1; i <= m; i++) {
        cout << mapping[i] << ' ' << randint(1000, 100000) << endl;
    }
    return 0;
}