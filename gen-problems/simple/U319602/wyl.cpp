#include <bits/stdc++.h>

using namespace std;

unsigned N, n;
double a, ans;
array<double, 114515> f1, f2, f3;

int main()
{
    cin >> N;
    n = N + 1u;
    for (unsigned i(1u); i != n; ++i) {
        cin >> a;
        f1[i] = a * (f1[i - 1] + 1.0);
        f2[i] = a * (f2[i - 1] + 2.0 * f1[i - 1] + 1.0);
        f3[i] = a * (f3[i - 1] + 3.0 * f2[i - 1] + 3.0 * f1[i - 1] + 1.0);
        ans += a * (4.0 * f3[i - 1] + 6.0 * f2[i - 1] + 4.0 * f1[i - 1] + 1.0);
    }
    cout << fixed << setprecision(1) << ans << endl;
    return 0;
}