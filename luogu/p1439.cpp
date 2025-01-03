#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

vector<int> a;
int mapping[100010];
vector<int> dp;

int main()
{
    int n;
    cin >> n;
    int tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        mapping[tmp] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        a.emplace_back(mapping[tmp]);
    }
    for (auto it : a) {
        if (dp.empty()) {
            dp.emplace_back(it);
        } else {
            if (it > dp.back()) {
                dp.emplace_back(it);
            } else {
                *lower_bound(dp.begin(), dp.end(), it) = it;
            }
        }
    }
    cout << dp.size() << endl;
    return 0;
}
