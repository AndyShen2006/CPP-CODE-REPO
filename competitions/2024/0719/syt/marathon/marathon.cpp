#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> Point;
constexpr int MAX_N = 100010;
Point pts[MAX_N];
int d[MAX_N]; // Distance from i-1 to i

inline int dis(Point p1, Point p2)
{
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main()
{
    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> pts[i].first >> pts[i].second;
    }
    int sum = 0;
    for (int i = 2; i <= n; i++) {
        d[i] = dis(pts[i - 1], pts[i]);
        sum += d[i];
    }
    int ans = sum;
    for (int i = 2; i < n; i++) {
        ans = min(ans, sum - d[i] - d[i + 1] + dis(pts[i - 1], pts[i + 1])); // Continue i
    }
    cout << ans << endl;
    return 0;
}