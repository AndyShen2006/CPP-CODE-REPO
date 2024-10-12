#include <bits/stdc++.h>

using namespace std;
#define DEBUG 0

constexpr int MAX_N = 50010;
/*
Sum = 0: 0====0
Sum = 1: 0====1;1====0
Sum = 2: 1====1
*/
vector<pair<int, int>> cows; // S->true;NS->False

int main()
{
    freopen("learning.in", "r", stdin);
    freopen("learning.out", "w", stdout);
    int n, a, b;
    int cnt = 0;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        string s;
        int w;
        cin >> s >> w;
        if (a <= w && w <= b) {
            cows.emplace_back(w, s == "S");
            cnt += (s == "S");
        }
    }
    sort(cows.begin(), cows.end());
#if DEBUG
    for (auto it : cows) {
        cerr << it.first << ' ' << it.second << endl;
    }
#endif
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int stat = cows[i - 1].second + cows[i].second, mid;
        switch (stat) {
        case 0:
            continue;
            break;
        case 1:
            mid = (cows[i - 1].first + cows[i].first) >> 1;
            ans += mid - cows[i - 1].first;
#if DEBUG
            cerr << cows[i - 1].first << ' ' << mid << endl;
#endif
            break;
        case 2:
            ans += cows[i].first - cows[i - 1].first - 1;
#if DEBUG
            cerr << cows[i - 1].first << ' ' << cows[i].first << endl;
#endif
            break;
        default:
            break;
        }
    }
    if (cows.front().second) {
        ans += cows.front().first - a;
    }
    if (cows.back().second) {
        ans += b - cows.back().first;
    }
    cout << ans + cnt << endl;
    return 0;
}