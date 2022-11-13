#include <bits/stdc++.h>

using namespace std;

const int maxN = 250, MAX = 0x7fffffff / 2;
int Fmax[maxN][maxN], Fmin[maxN][maxN], sum[maxN]; // sum[i]->add from a[1] to a[i]
int a[maxN], n, tmp, ansMax = 0, ansMin = MAX;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i <= n * 2; i++) {
        sum[i] = sum[i - 1] + a[i];
        Fmax[i][i] = 0;
        Fmin[i][i] = 0;
    }
    int j;
    for (int L = 2; L <= n; L++) {
        for (int i = 1; i <= 2 * n - L + 1; i++) {
            j = i + L - 1;
            Fmax[i][j] = 0, Fmin[i][j] = MAX;
            for (int k = i; k < j; k++) {
                Fmin[i][j] = min(Fmin[i][j], Fmin[i][k] + Fmin[k + 1][j]);
                Fmax[i][j] = max(Fmax[i][j], Fmax[i][k] + Fmax[k + 1][j]);
            }
            Fmin[i][j] += sum[j] - sum[i - 1];
            Fmax[i][j] += sum[j] - sum[i - 1];
        }
    }
    for (int i = 1; i <= n; i++)
        ansMax = max(ansMax, Fmax[i][i + n - 1]);
    for (int i = 1; i <= n; i++)
        ansMin = min(ansMin, Fmin[i][i + n - 1]);
    cout << ansMin << endl
         << ansMax << endl;
    return 0;
}
