#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

int main()
{
    int n;
    long long ans = 0;
    freopen("fuck.out", "w", stdout);
    for (n = 2; n <= 10000000; n++) {
        for (int i = 2; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (gcd(i - 1, j - 1) == 1) {
                    ans++;
                }
            }
        }
        cout << ans * 2 + 3 << ',';
        ans = 0;
    }
    return 0;
}