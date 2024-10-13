#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool check(ll x)
{
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    // for (ll x = 1e18; x >= 0; x--) {
    //     if (check(x)) {
    //         cout << x << endl;
    //         break;
    //     }
    // }
    // int cnt = 0;
    // for (ll x = 1e17; x >= 0; x--) {
    //     if (check(x)) {
    //         cout << x << endl;
    //         cnt++;
    //     }
    //     if (cnt >= 2) {
    //         break;
    //     }
    // }
    // cnt = 0;
    // for (ll x = 1e17; x <= ll(1e18); x++) {
    //     if (check(x)) {
    //         cout << x << endl;
    //         cnt++;
    //     }
    //     if (cnt >= 2) {
    //         break;
    //     }
    // }
    for (ll x = 1e17; x >= 0; x--) {
        if (check(x) && check(x + 2)) {
            cout << x << ' ' << x + 2 << endl;
            break;
        }
    }
    return 0;
}