#include <bits/stdc++.h>

using namespace std;
#define DEBUG 0
constexpr int MAX_N = 100010;

vector<int> spds[2];

bool merge(bool cur)
{
    bool flag = false;
    spds[!cur].clear();
    for (auto it : spds[cur]) {
        if (!spds[!cur].empty() && it < spds[!cur].back()) {
            flag = true;
            spds[!cur].back() = it;
            continue;
        }
        spds[!cur].push_back(it);
    }
    return flag;
}

int main()
{
#if DEBUG
    freopen("data/cowjog1.in", "r", stdin);
#else
    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int tmp, spd;
        cin >> tmp >> spd;
        spds[0].push_back(spd);
    }
    bool flag = false;
    while (merge(flag)) {
        flag = !flag;
#if DEBUG
        for (auto it : spds[!flag]) {
            cout << it << ' ';
        }
        cout << endl;
#endif
    }
    cout << spds[flag].size() << endl;
    return 0;
}