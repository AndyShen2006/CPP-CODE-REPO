#include <bits/stdc++.h>

using namespace std;

vector<int> a;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        ans += tmp;
        a.emplace_back(tmp);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n / 2; i++) {
        ans += a[n - i - 1] - a[i];
    }
    cout << ans << endl;
    return 0;
}