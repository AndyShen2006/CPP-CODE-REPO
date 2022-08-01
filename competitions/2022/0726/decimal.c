#include <stdio.h>
#include <string.h>

char str[10000];
int t1[10000], t2[10000];
int c1, c2;

int main()
{
    // freopen("data/decimal.in", "r", stdin);
    int n;
    scanf("%d", &n);
    scanf("%s", str);
    int i, len = strlen(str);
    int isdec = 0, iscyc = 0;
    for (i = 0; i < len; i++) {
        if (str[i] == '.') {
            isdec = 1;
            continue;
        }
        if (str[i] == '(') {
            iscyc = 1;
            continue;
        }
        if (str[i] == ')') {
            break;
        }
        if (isdec && !iscyc) {
            t1[c1++] = str[i] - '0';
        }
        if (isdec && iscyc) {
            t2[c2++] = str[i] - '0';
        }
    }
    if (n - 1 <= c1) {
        putchar('0' + t1[n - 1]);
    } else {
        n -= 1 + c1;
        putchar('0' + t2[n % c2]);
    }
    return 0;
}