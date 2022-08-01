#include <stdio.h>

int arr[10001];
char templine[10001];
int pos = 0;

int main()
{
    freopen("data/matrix.in", "r", stdin);
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int i, j, num;
    for (i = 1; i <= n; i++) {
        if (i == k) {
            for (j = 1; j <= m; j++) {
                scanf("%d", &num);
                arr[pos++] = num;
            }
        }
        getline(NULL, 0, stdin);
    }
    int crt = 0, ans = 0;
    for (i = 0; i <= pos; i++) {
        if (arr[i] == 0) {
            ans = ans > crt ? ans : crt;
            crt = 0;
            continue;
        } else {
            crt++;
        }
    }
    printf("%d\n", ans);
    return 0;
}