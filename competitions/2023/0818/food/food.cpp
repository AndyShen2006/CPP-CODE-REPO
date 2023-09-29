#include <bits/stdc++.h>

using namespace std;

set<string> WalkingStick;
map<string, int> cnt;

int main()
{
    freopen("food.in", "r", stdin);
    freopen("food.out", "w", stdout);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m, t;
    cin >> n >> m >> t;
    string ts;
    for (int i = 1; i <= n; i++) {
        cin >> ts;
    }
    for (int i = 1; i <= m; i++) {
        cin >> ts;
        WalkingStick.insert(ts);
    }
    for (int i = 1; i <= t; i++) {
        int k;
        cin >> k;
        for (int i = 1; i <= k; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            WalkingStick.erase(s2);
            cnt[s1]++;
        }
        for (const auto& it : cnt) {
            cout << it.first << ' ' << it.second << endl;
        }
        for (const auto& it : WalkingStick) {
            cout << it << ' ';
        }
        cout << endl;
        cnt.clear();
    }
    return 0;
}