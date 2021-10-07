#include <bits/stdc++.h>

using namespace std;

int matrix[1001][1001];
int preMatrix[1001][1001];
int sum = 0;

int main()
{
    //Input
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> matrix[i][j];
            sum += matrix[i][j];
            preMatrix[i][j] = matrix[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            preMatrix[i][j] += preMatrix[i - 1][j] + preMatrix[i][j - 1] - preMatrix[i - 1][j - 1];
        }
    }
    /*
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << preMatrix[i][j] << ' ';
        }
        cout << endl;
    }
    */
    int ans = 0;
    for (int i = 1; i <= n - r + 1; i++) {
        for (int j = 1; j <= m - c + 1; j++) {
            //printf("from(%d,%d)to(%d,%d)sum is%d\n", i, j, i + r - 1, j + c - 1, preMatrix[i + r - 1][j + c - 1] - preMatrix[i + r - 1][j - 1] - preMatrix[i - 1][j + c - 1] + preMatrix[i - 1][j - 1]);
            ans = max(ans, preMatrix[i + r - 1][j + c - 1] - preMatrix[i + r - 1][j - 1] - preMatrix[i - 1][j + c - 1] + preMatrix[i - 1][j - 1]);
        }
    }
    cout << ans << endl;
    return 0;
}