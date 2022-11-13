#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll x, y;
    cin >> x >> y;
    ll sum1 = 0, sum2 = 0;
    for (ll i = 1; i <= x - 1; i++) {
        printf("i=%lld,Sum1 Add:%lld*%lld=%lld\n", i, (x - 1) / i, i, ((x - 1) / i) * i);
        sum1 += (ll)((x - 1) / i) * i;
    }
    for (ll i = 1; i <= y; i++) {
        printf("i=%lld,Sum2 Add:%lld*%lld=%lld\n", i, (y / i), i, (y / i) * i);
        sum2 += (ll)(y / i) * i;
    }
    cout << sum2 - sum1 << endl;
}
/*

*/