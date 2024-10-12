#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 1010;
typedef pair<int, int> P;
P ivs[MAX_N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ivs[i].second >> ivs[i].first;
    }
    sort(ivs + 1, ivs + n + 1);
    int cur = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (ivs[i].second >= cur) {
            ans++;
            cur = ivs[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}