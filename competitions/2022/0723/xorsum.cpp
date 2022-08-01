#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e5 + 3;
int s[N];
int xorpre[N], sumpre[N];

int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    int crt;
    ans = n;
    for (int i = n; i >= 1; i--) {
        crt = s[i];
        for (int j = 1; i - j >= 1; j++) {
            if ((crt ^ s[i - j]) != crt + s[i - j]) {
                break;
            }
            crt ^= s[i - j];
            ans++;
            // cout << i << ' ' << i - j << endl;
        }
    }
    cout << ans << endl;
    return 0;
}