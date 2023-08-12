#include <bits/stdc++.h>

using namespace std;

pair<int, int> pts[100010];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> pts[i].second >> pts[i].first;
    }
    sort(pts + 1, pts + n + 1, greater<>());
    int right = INT_MIN;
    int ans = 0;
    for (int i = 1; i <= n; i++) { // 从上到下扫描
        if (pts[i].second > right) {
            ans++;
            right = pts[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}