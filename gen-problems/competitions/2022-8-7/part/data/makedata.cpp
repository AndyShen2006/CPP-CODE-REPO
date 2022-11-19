#include <bits/stdc++.h>
#include <ext_random.h>

using namespace std;
using namespace cdg;

map<int, set<int>> connected;

int main()
{
    int n = randint(5e4, 1e5);
    int m = randint(2e5, 6e5);
    cout << n << ' ' << m << endl;
    int l = randint(n / 4, n / 2);
    int r = n - l;
    int u, v;
    for (int i = 1; i <= m; i++) {
        while (true) {
            int u = randint(1, l);
            int v = randint(l + 1, n);
            if (connected[u].find(v) == connected[u].end()) {
                cout << u << ' ' << v << endl;
                connected[u].insert(v);
                break;
            }
        }
    }
    return 0;
}