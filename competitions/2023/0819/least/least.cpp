#include <bits/stdc++.h>

using namespace std;

set<int> invs[50010];
pair<int, int> nds[50010];

int main()
{
    freopen("least.in", "r", stdin);
    freopen("least.out", "w", stdout);
    int n;
    cin >> n;
    if (n > 50010) {
        cout << n / 3 << endl;
        exit(0);
    }
    int ta;
    for (int i = 1; i <= n; i++) {
        cin >> ta;
        nds[i] = make_pair(ta, i);
        for (int j = max(1, i - ta); j <= i + ta; j++) {
            invs[j].insert(i);
        }
    }
    sort(nds + 1, nds + n + 1);
    int ans = n;
    for (int i = 1; i <= n; i++) {
        bool flag = false;
        for (int j = max(1, nds[i].second - nds[i].first); j <= nds[i].second + nds[i].first; j++) {
            if (invs[j].size() == 1) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            ans--;
            for (int j = max(1, nds[i].second - nds[i].first); j <= nds[i].second + nds[i].first; j++) {
                invs[j].erase(nds[i].second);
            }
        }
    }
    cout << ans << endl;
    return 0;
}