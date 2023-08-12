#include <bits/stdc++.h>

using namespace std;

pair<double, double> things[1010];

int main()
{
    int n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> things[i].first >> things[i].second;
    }
    sort(things + 1, things + n + 1, [](pair<double, double> a, pair<double, double> b) -> bool { return (a.second / a.first) > (b.second / b.first); });
    // for (int i = 1; i <= n; i++) {
    //     cout << things[i].first << ' ' << things[i].second << endl;
    // }
    double ans = 0, cur = 0;
    for (int i = 1; i <= n; i++) {
        if (t - cur >= things[i].first) {
            cur += things[i].first;
            ans += things[i].second;
        } else {
            ans += (t - cur) * (things[i].second / things[i].first);
            break;
        }
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}