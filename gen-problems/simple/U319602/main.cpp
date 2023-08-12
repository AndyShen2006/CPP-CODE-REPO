#include <bits/stdc++.h>

using namespace std;

double x1[114520], x2[114520], x3[114520], ans[114520];

int main()
{
    int n;
    cin >> n;
    double p;
    for (int i = 1; i <= n; i++) {
        cin >> p;
        x1[i] = (x1[i - 1] + 1) * p;
        x2[i] = (x2[i - 1] + 2 * x1[i - 1] + 1) * p;
        x3[i] = (x3[i - 1] + 3 * x2[i - 1] + 3 * x1[i - 1] + 1) * p;
        ans[i] = (ans[i - 1] + 4 * x3[i - 1] + 6 * x2[i - 1] + 4 * x1[i - 1] + 1) * p + ans[i - 1] * (1 - p);
    }
    cout << fixed << setprecision(1) << ans[n] << endl;
    return 0;
}