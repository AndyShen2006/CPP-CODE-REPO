#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 100010;
typedef pair<int, int> P;
P a[MAX_N], b[MAX_N];
int res1[MAX_N], res2[MAX_N];

int main()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= m1; i++) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 1; i <= m2; i++) {
        cin >> b[i].first >> b[i].second;
    }
    sort(a + 1, a + m1 + 1);
    sort(b + 1, b + m2 + 1);
    priority_queue<int, vector<int>, greater<int>> bg1;
    priority_queue<P, vector<P>, greater<P>> pl1;
    for (int i = 1; i <= n; i++) {
        bg1.push(i);
    }
    for (int i = 1; i <= m1; i++) {
        while (!pl1.empty() && a[i].first >= pl1.top().first) {
            bg1.push(pl1.top().second);
            pl1.pop();
        }
        if (bg1.empty()) {
            continue;
        }
        int cur = bg1.top();
        bg1.pop();
        res1[cur]++;
        pl1.emplace(a[i].second, cur);
    }
    priority_queue<int, vector<int>, greater<int>> bg2;
    priority_queue<P, vector<P>, greater<P>> pl2;
    for (int i = 1; i <= n; i++) {
        bg2.push(i);
    }
    for (int i = 1; i <= m2; i++) {
        while (!pl2.empty() && b[i].first >= pl2.top().first) {
            bg2.push(pl2.top().second);
            pl2.pop();
        }
        if (bg2.empty()) {
            continue;
        }
        int cur = bg2.top();
        bg2.pop();
        res2[cur]++;
        pl2.emplace(b[i].second, cur);
    }
    for (int i = 1; i <= n; i++) {
        res1[i] += res1[i - 1];
        res2[i] += res2[i - 1];
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, res1[i] + res2[n - i]);
    }
    cout << ans << endl;
    return 0;
}