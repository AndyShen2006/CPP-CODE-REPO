#include <stdio.h>

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int g[1005][1005];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 1001; i++) {
        for (int j = 1; j <= i; j++) {
            g[i][j] = gcd(i, j);
            g[j][i] = g[i][j];
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k <= j; k++) {
                //printf("%d %d %d: %d\n", i, j, k, g[g[i][j]][k]);
                if (i == j && j == k) {
                    sum += g[g[i][j]][k];
                } else if (i == j || i == k || j == k) {
                    sum += g[g[i][j]][k] * 3;
                } else {
                    sum += g[g[i][j]][k] * 6;
                }
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}