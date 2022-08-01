#include <stdio.h>
#include <string.h>

char str[1000];

int main()
{
    // freopen("data/num.in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    int i, j, len, type, ans = n;
    type = (m > 10) ? 0 : 1;
    for (i = 1; i <= n; i++) {
        scanf("%s", str);
        len = strlen(str);
        for (j = 0; j < len; j++) {
            if (type) {
                if (str[j] >= '0' + m) {
                    --ans;
                    break;
                }
            } else {
                if (str[j] >= 'A' + m - 10) {
                    --ans;
                    break;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}