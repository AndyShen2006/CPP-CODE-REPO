#include <bits/stdc++.h>

using namespace std;

/*
Binary Answer + Binary Search
*/

constexpr int MAX_N = 100010;
int a[MAX_N];
int n, k;

bool check(int x)
{
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int pos = int(upper_bound(a + 1, a + n + 1, x - a[i]) - a);
        if (pos > i) {
            sum += pos - i - 1;
            // cout << pos << ',' << i << ':' << pos - i - 1 << endl;
        }
    }
    return sum >= k;
}

int main()
{
    freopen("flower.in", "r", stdin);
    freopen("flower.out", "w", stdout);
    // freopen("data/flowerN1.in", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int l = a[1] + a[2], r = a[n] + a[n - 1];
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;
    return 0;
}