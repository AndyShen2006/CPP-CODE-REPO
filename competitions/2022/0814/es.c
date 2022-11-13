#include <ctype.h>
#include <stdio.h>
int redn()
{
    int ret = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -f;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
char buf[1 << 21],
    a[20];
int p, P2 = -1;
void flush()
{
    fwrite(buf, 1, P2 + 1, stdout);
    P2 = -1;
}
void print(int x)
{
    if (P2 > 1 << 20)
        flush();
    if (x < 0)
        buf[++P2] = 45, x = -x;
    do {
        a[++p] = x % 10 + 48;
    } while (x /= 10);
    do {
        buf[++P2] = a[p];
    } while (--p);
    buf[++P2] = '\n';
}
int MOD = 1e9 + 7;
int main()
{
    int n;
    n = redn();
    long long ans = 1;
    int bi = 1;
    for (int i = 1; i <= n; i++) {
        bi = (bi << 1) % MOD;
        ans = ans * (bi - 1) % MOD;
    }
    print((int)ans);
    flush();
    return 0;
}
