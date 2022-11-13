#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll f[1000000];
ll MOD = 1e9 + 7;

int main()
{
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= 114515; i++) {
        f[i] = (3 * f[i - 1] % MOD - 2 * f[i - 2] % MOD + 3) % MOD;
    }
    cout << f[114514] << endl;
    return 0;
}