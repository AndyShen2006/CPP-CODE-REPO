#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int MAX_N = 500010;
ll a[MAX_N];
ll tMem[MAX_N];
ll cdq(ll mem[], int l, int r)
{
    if (l >= r) {
        return 0;
    }
    int mid = (l + r) >> 1;
    ll lAns = cdq(mem, l, mid);
    ll rAns = cdq(mem, mid + 1, r);
    ll ans = 0;
    int posL = l, posR = mid + 1;
    int pos = l;
    // printf("Merging [%d,%d]\n", l, r);
    // for (int i = l; i <= mid; i++) {
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    // for (int i = mid + 1; i <= r; i++) {
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    while (posL <= mid && posR <= r) {
        if (a[posL] <= a[posR]) {
            mem[pos++] = a[posL++];
        } else {
            mem[pos++] = a[posR++];
            ans += mid - posL + 1;
            // cout << "Add " << posL - l + 1 << endl;
        }
    }
    while (posL <= mid) {
        mem[pos++] = a[posL++];
    }
    while (posR <= r) {
        mem[pos++] = a[posR++];
    }
    // cout << "A: ";
    for (int i = l; i <= r; i++) {
        a[i] = mem[i];
        // cout << a[i] << ' ';
    }
    // cout << endl;
    // cout << "Current answer: " << lAns << ' ' << rAns << ' ' << ans << endl;
    return lAns + rAns + ans;
}

int main()
{
    // freopen("data/p1908a.out", "w", stdout);
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