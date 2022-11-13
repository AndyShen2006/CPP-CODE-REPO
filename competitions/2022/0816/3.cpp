#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 ell;

inline ell mul(ell n)
{
    ell ans = 1;
    for (ell i = 1; i <= n; i++) {
        ans *= i;
    }
    return ans;
}

inline ell c(ell up, ell down)
{
    return ell(mul(down) / mul(up) / mul(down - up));
}
ell a[30];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    ll tmp;
    for (ll i = 0; i <= n; i++) {
        cin >> tmp;
        a[i] = tmp;
    }
    ll cur = 0; //代表现在0次项的位置
    ell ans = 0;
    for (ll i = n; i >= 0; i--) {
        ans += c(i, n) * a[cur];
        cur++; //计算完当前0次后，原来一次项作为新的零次项
        for (ll j = cur; j <= n; j++) { //开始逐级乘
            a[j] *= j - cur + 1;
        }
    }
    string sans;
    while (ans > 0) {
        sans.push_back(char('0' + ans % 10));
        ans /= 10;
    }
    reverse(sans.begin(), sans.end());
    cout << sans << endl;
    return 0;
}