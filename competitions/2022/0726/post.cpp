#include <bits/stdc++.h>

using namespace std;

struct Interval {
    int l, r;
    inline bool operator<(const Interval& rhs) const
    {
        return l == rhs.l ? r > rhs.r : l < rhs.l;
    }
};

vector<Interval> inter;

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    // freopen("data/post.in", "r", stdin);
    int n;
    cin >> n;
    int s, w;
    Interval ti {};
    for (int i = 1; i <= n; i++) {
        cin >> s >> w;
        ti.l = max(0, s - w);
        ti.r = s + w;
        inter.emplace_back(ti);
    }
    sort(inter.begin(), inter.end());
    Interval crt = inter.front();
    int ans = 0;
    for (auto it : inter) {
        // cout << crt.l << ' ' << crt.r << endl;
        if (it.l > crt.r) {
            ans++;
            crt = it;
        } else {
            crt.l = max(crt.l, it.l);
            crt.r = min(crt.r, it.r);
        }
    }
    cout << ans + 1 << endl;
    return 0;
}