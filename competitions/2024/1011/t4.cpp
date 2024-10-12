#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
constexpr int MAX_N = 1e5 + 10;
P a[MAX_N];

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        stable_sort(a + 1, a + n + 1);
        int t = 0;
        for (int i = 1; i <= n; i++) {
            t = max(t, abs(i - a[i].second));
        }
        cerr << t << endl;
        // cout << ceil(double(t) / double(k - 1)) << endl;
    }
    return 0;
}
