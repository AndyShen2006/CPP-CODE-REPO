#include <bits/stdc++.h>

using namespace std;

int matrix[1001][1001];
int prem[1001][1001];
int subMatrix[1001];
int lastsub;

int main()
{
    //Input
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> matrix[i][j];
        }
    }
    //Compute prefix of matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            prem[i][j] = prem[i][j - 1] + matrix[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            for (int k = 1; k <= n; k++) {
                subMatrix[k] = prem[k][i] - prem[k][j];
            }
            // Compute max subsequence
            lastsub = max(subMatrix[1], 0);
            for (int k = 2; k <= n; k++) {
                lastsub = max(lastsub + subMatrix[k], subMatrix[k]);
                ans = max(ans, lastsub);
            }
        }
    }
    cout << ans << endl;
    return 0;
}