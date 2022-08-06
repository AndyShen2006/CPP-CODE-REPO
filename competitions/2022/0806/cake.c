#include <stdio.h>

int G[1010][1010];
int curadd[1010][1010];

void add(int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // cout << curadd[i][j] << ' ';
            G[i][j] += curadd[i][j];
            curadd[i][j]++;
        }
        // cout << endl;
    }
}

int main()
{
    int n, m, x, y;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    char method[1010];
    scanf("%s", method);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            curadd[i][j] = 1;
        }
    }
    int curr = n - y + 1, curc = x;
    for (int i = 0; i < m; i++) {
        switch (method[i]) {
        case 'N':
            curadd[curr][curc] = 0;
            add(n);
            curr--;
            break;
        case 'S':
            curadd[curr][curc] = 0;
            add(n);
            curr++;
            break;
        case 'W':
            curadd[curr][curc] = 0;
            add(n);
            curc--;
            break;
        case 'E':
            curadd[curr][curc] = 0;
            add(n);
            curc++;
            break;
        default:
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", G[i][j]);
        }
        if (i != n) {
            putchar('\n');
        }
    }
    return 0;
}