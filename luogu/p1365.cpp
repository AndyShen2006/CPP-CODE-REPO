#include <bits/stdc++.h>

using namespace std;

long double f[300010];

int main()
{
    int n;
    string str;
    cin >> n;
    cin >> str;
    long double len = 0;
    for (int i = 1; i <= n; i++) {
        switch (str[i - 1]) {
        case 'o':
            f[i] = f[i - 1] + 2 * len + 1;
            len++;
            break;
        case 'x':
            f[i] = f[i - 1];
            len = 0;
            break;
        case '?':
            f[i] = f[i - 1] + len + 0.5;
            len = (len + 1) / 2;
            break;
        }
    }
    cout << fixed << setprecision(4) << f[n] << endl;
    return 0;
}