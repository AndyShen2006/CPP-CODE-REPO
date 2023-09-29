#include <bits/stdc++.h>

using namespace std;

pair<int, int> pw[200010];
int n, m, c;

bool check(int pos)
{
    int tm = m >> 1, sum = 0;
    priority_queue<int> lv, rv;
    for (int i = 1; i < pos; i++) {
        lv.push(pw[i].second);
    }
    for (int i = 1; i <= tm; i++) {
        sum += lv.top();
        lv.pop();
    }
    for (int i = pos + 1; i <= n; i++) {
        rv.push(pw[i].second);
    }
    for (int i = 1; i <= tm; i++) {
        sum += rv.top();
        rv.pop();
    }
    return sum <= c;
}

int main()
{
    freopen("wing.in", "r", stdin);
    freopen("wing.out", "w", stdout);
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) {
        cin >> pw[i].first;
    }
    for (int i = 1; i <= n; i++) {
        cin >> pw[i].second;
    }
    sort(pw + 1, pw + n + 1);
    // int l = (m >> 1) + 1, r = n - (m >> 1), mid = (1 + n) >> 1;
    // while (l < r) {
    //     mid = (l + r) >> 1;
    //     if (check(mid)) {
    //         l = mid + 1;
    //     } else {
    //         r = mid;
    //     }
    // }
    int ans = -1;
    for (int i = (m >> 1) + 1; i <= n - (m >> 1); i++) {
        if (check(i)) {
            ans = max(ans, pw[i].first);
        }
    }
    cout << ans << endl;
    return 0;
}
/*
8 5 32
45 42 49 55 51 38 52 47
6 8 6 6 7 6 5 8
*/