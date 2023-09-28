#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;
using namespace cdg;

pair<int, int> BT[20010];
int mapping[20010];

int main()
{
    int n, m;
    int bit = 14;
    n = (1 << bit) - 1;
    m = randint(2, n * 2 / 3);
    cout << n + 1 << ' ' << m << endl;
    for (int i = 1; i <= n >> 1; i++) {
        BT[i].first = i * 2;
        BT[i].second = i * 2 + 1;
    }
    BT[0].first = 1;
    for (int i = 0; i <= n; i++) {
        cout << (BT[i].first == 0 ? 0 : (BT[i].first + 1)) << ' ' << (BT[i].second == 0 ? 0 : (BT[i].second + 1)) << endl;
    }
    for (int i = 1; i <= n + 1; i++) {
        mapping[i] = i;
    }
    shuffle(mapping + 2, mapping + n + 2, rand_eng);
    for (int i = 1; i <= m; i++) {
        cout << mapping[i] << ' ' << randint(1000, 100000) << endl;
    }
    return 0;
}