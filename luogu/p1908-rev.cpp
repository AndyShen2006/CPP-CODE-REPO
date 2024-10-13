#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int MAX_N = 500010;
ll a[MAX_N];
ll tMem[MAX_N];
ll cdq(ll mem[], int left, int right)
{
    if (left >= right) {
        return 0;
    }
    int mid = (left + right) >> 1;
    ll lAns = cdq(mem, left, mid);
    ll rAns = cdq(mem, mid + 1, right);
    ll ans = 0;
    int posL = mid, posR = right;
    int pos = right;
    while (posL >= left && posR >= mid + 1) {
        // printf("Compare %lld %lld\n", a[posL], a[posR]);
        if (a[posL] > a[posR]) {
            mem[pos--] = a[posR--];
            ans += posL - left + 1;
            // cout << "Add " << ans << endl;
        } else {
            mem[pos--] = a[posL--];
        }
    }
    while (posL >= left) {
        mem[pos--] = a[posL--];
    }
    while (posR >= mid + 1) {
        mem[pos--] = a[posR--];
    }
    for (int i = left; i <= right; i++) {
        a[i] = mem[i];
    }
    return lAns + rAns + ans;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << cdq(tMem, 1, n) << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    return 0;
}