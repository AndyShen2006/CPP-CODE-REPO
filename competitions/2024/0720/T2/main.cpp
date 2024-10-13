#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 1000010;
int pre[MAX_N];

int main()
{
    int n, k, tmp;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        pre[i] = pre[i - 1] ^ tmp;
    }
    int ans = 0;
    for (int i = k; i <= n; i++) {
        ans = max(ans, pre[i] ^ pre[i - k]);
    }
    cout << ans << endl;
    return 0;
}