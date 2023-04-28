#include <bits/stdc++.h>

using namespace std;

vector<int> a;
vector<int> dp;

int main()
{
    int tmp;
    while (~scanf("%d", &tmp)) {
        a.emplace_back(tmp);
    }
    for (auto it : a) {
        if (dp.empty()) {
            dp.emplace_back(it);
        } else {
            if (it <= dp.back()) {
                dp.emplace_back(it);
            } else {
                *upper_bound(dp.begin(), dp.end(), it, [](int a, int b) -> bool { return a > b; }) = it;
            }
        }
    }
    cout << dp.size() << endl;
    dp.clear();
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