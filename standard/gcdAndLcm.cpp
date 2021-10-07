#include <bits/stdc++.h>

using namespace std;

int factorize(int x, int* p)
{
    int cnt = 0;
    for (int i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            p[cnt++] = i;
            x /= i;
        }
    }
    if (x > 1) {
        p[cnt++] = x;
    }
    return cnt;
}
int fa[10001], fb[10001];
int gcd[10001];
int lcm[10001];
int main()
{
    int a, b;
    cin >> a >> b;
    int sa = factorize(a, fa);
    int sb = factorize(b, fb);
    int* sg = set_intersection(fa, fa + sa, fb, fb + sb, gcd);
    int* sl = set_union(fa, fa + sa, fb, fb + sb, lcm);
    int ansGcd = 1, ansLcm = 1;
    for (int* i = gcd; i != sg; i++) {
        ansGcd *= *i;
    }
    for (int* i = lcm; i != sl; i++) {
        ansLcm *= *i;
    }
    cout << ansGcd << ' ' << ansLcm;
    return 0;
}