#include <bits/stdc++.h>

using namespace std;

void extgcd(int a, int b, int& x, int& y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    extgcd(b, a % b, x, y);
    int tmp = x;
    x = y;
    y = tmp - (a / b) * y;
}

int modrev(int a, int mod)
{
    int x, y;
    extgcd(a, mod, x, y);
    return (mod + x % mod) % mod; // Avoid x<0
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << modrev(a, b) << endl;
    return 0;
}