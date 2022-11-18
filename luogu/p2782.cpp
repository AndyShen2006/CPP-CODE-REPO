#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
vector<P> a;
vector<int> dp;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        P tp;
        cin >> tp.first >> tp.second;
        a.emplace_back(tp);
    }
    sort(a.begin(), a.end());
    for (auto it : a) {
        int u = it.second;
        if (dp.empty()) {
            dp.emplace_back(u);
        } else {
            if (u > dp.back()) {
                dp.emplace_back(u);
            } else {
                *lower_bound(dp.begin(), dp.end(), u) = u;
            }
        }
    }
    cout << dp.size() << endl;
    return 0;
}