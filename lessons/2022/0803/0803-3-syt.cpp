#include <bits/stdc++.h>

using namespace std;

int h[400001];
deque<pair<int, int>> Q; // Height,pos
pair<int, int> interval[400001];

int main()
{
    // freopen("data/3a.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++) {
        while (!Q.empty() && h[i] < Q.back().first) {
            interval[Q.back().second].second = i;
            Q.pop_back();
        }
        Q.push_back(make_pair(h[i], i));
    }
    Q.clear();
    for (int i = n; i >= 1; i--) {
        while (!Q.empty() && h[i] < Q.back().first) {
            interval[Q.back().second].first = i;
            Q.pop_back();
        }
        Q.push_back(make_pair(h[i], i));
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        // ans = max(ans, h[i] * (interval[i].second - interval[i].first + 1));
        if (h[i] * (interval[i].second - interval[i].first + 1) > ans) {
            ans = max(ans, h[i] * (interval[i].second - interval[i].first + 1));
        }
    }
    cout << ans << endl;
    return 0;
}