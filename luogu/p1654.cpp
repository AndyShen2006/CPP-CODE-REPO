#include <bits/stdc++.h>

using namespace std;

double poss[100010], x1[100010], x2[100010], ans[100010];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> poss[i];
    }
    for (int i = 1; i <= n; i++) {
        x1[i] = (x1[i - 1] + 1) * poss[i];
        x2[i] = (x2[i - 1] + 2 * x1[i - 1] + 1) * poss[i];
        ans[i] = ans[i - 1] + (3 * (x1[i - 1] + x2[i - 1]) + 1) * poss[i];
    }
    cout << fixed << setprecision(1) << ans[n] << endl;
    return 0;
}