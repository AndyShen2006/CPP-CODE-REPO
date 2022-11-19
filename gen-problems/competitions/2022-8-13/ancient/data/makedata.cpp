#include <bits/stdc++.h>
#include <ext_random.h>

using namespace std;

void print(initializer_list<int> L)
{
    for (auto it : L) {
        cout << it << ' ';
    }
    cout << endl;
}

map<int, set<int>> G;

int main()
{
    int n = randint(100, 200);
    int m = randint(3000, 6000);
    print({ n, m });
    for (int i = 1; i <= n; i++) {
        cout << randint(1, 300) << ' ';
    }
    cout << endl;
    int u, v;
    for (int i = 1; i <= m; i++) {
        do {
            u = randint(1, n);
            v = randint(1, n);
        } while (G[u].find(v) != G[u].end() || G[v].find(u) != G[v].end() || u == v);
        G[u].insert(v);
        G[v].insert(u);
        print({ u, v });
    }
    return 0;
}