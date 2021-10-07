#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define INF 10000000
struct Interval {
    //[start,end]
    int start, end;
} ins[200001];
ll w[200001], v[200001];
ll n, m, S, ans = INF;
bool check(int n)
{
    ll sum = 0;
    for (int i = 1; i <= m; i++) {
        int cnt = 0, sv = 0;
        for (int j = ins[i].start; j <= ins[i].end; j++) {
            if (w[j] >= n) {
                cnt++;
                sv += v[j];
            }
        }
        sum += cnt * sv;
    }
    if (abs(sum - S) < ans) {
        ans = abs(sum - S);
        return true;
    } else {
        return false;
    }
}
int main()
{
    freopen("xinao.in", "r", stdin);
    freopen("xinao.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> S;
    ll maxw = 0;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
        maxw = max(maxw, w[i]);
    }
    for (int i = 1; i <= m; i++) {
        cin >> ins[i].start >> ins[i].end;
    }
    int l = 0, r = maxw, mid;
    while (r - l > 1) {
        mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << ans << endl;
    return 0;
}