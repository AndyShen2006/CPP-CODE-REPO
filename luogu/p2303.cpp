#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long ans = n;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int b = 0;
            while (n % i == 0) {
                ++b;
                n /= i;
            }
            ans /= i;
            ans *= b * i - b + i;
        }
    }
    if (n > 1) {
        ans /= n;
        ans *= n + n - 1;
    }
    cout << ans;
    return 0;
}