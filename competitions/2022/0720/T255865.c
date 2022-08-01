#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    float a, b;
    scanf("%f%f", &a, &b);
    char ans[1000000];
    memset(ans, 0, sizeof(ans));
    sprintf(ans, "%.3f", a / b);
    int i;
    for (i = 999999; i >= 0; i--) {
        if (ans[i] == '.') {
            i--;
            break;
        }
        if (ans[i] != 0 && ans[i] != '0') {
            break;
        }
    }
    for (int j = 0; j <= i; j++) {
        putchar(ans[j]);
    }
    return 0;
}