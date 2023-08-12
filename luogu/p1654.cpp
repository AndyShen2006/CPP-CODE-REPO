#include <bits/stdc++.h>

using namespace std;

double p[100010], x1[100010], x2[100010], x3[100010];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        x1[i] = (x1[i - 1] + 1) * p[i];
        x2[i] = (x2[i - 1] + 2 * x1[i - 1] + 1) * p[i];
        x3[i] = x3[i - 1] + (3 * (x1[i - 1] + x2[i - 1]) + 1) * p[i];
    }
    cout << fixed << setprecision(1) << x3[n] << endl;
    return 0;
}