#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;

vector<int> cycles;
vector<int> G[50010];

int main()
{
    int n = 0, m = 0, q, cntc = randint(50, 250);
    int csize;
    for (int i = 1; i <= cntc; i++) {
        csize = randint(100, 150);
        cycles.emplace_back(csize);
        n += csize;
    }
    q = randint(1, 500);
    int cur = 1;
    for (auto it : cycles) {
        // for (int i = cur; i <= cur + it - 2; i++) {
        //     cout << i << " -> " << i + 1 << endl;
        // }
        // cout << cur + it - 1 << " -> " << cur << endl;
        // cout << cur + it - 1 << " -> " << cur + it << endl;
        // cur = cur + it;
        for (int i = cur; i <= cur + it - 2; i++) {
            G[i].emplace_back(i + 1);
            m++;
        }
        G[cur + it - 1].emplace_back(cur);
        G[cur + it - 1].emplace_back(cur + it);
        cur = cur + it;
        m += 2;
    }
    printf("%d %d %d\n", n + 1, m, q);
    for (int i = 1; i <= n; i++) {
        for (auto it : G[i]) {
            cout << i << " -> " << it << endl;
        }
    }
    for (int i = 1; i <= q; i++) {
        cout << randint(1, n) << ' ' << randint(1, n) << endl;
    }
    return 0;
}