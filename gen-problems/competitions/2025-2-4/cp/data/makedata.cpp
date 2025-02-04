#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;
using namespace cdg;

vector<int> xs, ys;
vector<int> nxs, nys;
vector<pair<int, int>> pts;

int main()
{
    int n = randint(5e5, 1e6);
    cout << n << endl;
    int curx = 1, cury = 1;
    for (int i = 1; i <= 4 * n; i++) {
        xs.push_back(i);
        ys.push_back(i);
    }
    shuffle(xs.begin(), xs.end(), rand_eng);
    shuffle(ys.begin(), ys.end(), rand_eng);
    for (int i = 1; i <= n; i++) {
        nxs.push_back(xs[i]);
        nys.push_back(ys[i]);
    }
    sort(nxs.begin(), nxs.end());
    sort(nys.begin(), nys.end());
    for (int i = 0; i < n; i++) {
        pts.emplace_back(nxs[i], nys[i]);
    }
    shuffle(pts.begin(), pts.end(), rand_eng);
    for (auto it : pts) {
        cout << it.first << ' ' << it.second << endl;
    }
    return 0;
}