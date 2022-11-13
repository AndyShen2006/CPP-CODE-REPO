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

int main()
{
    int a, b;
    cin >> a >> b;
    int x, y;
    extgcd(a, b, x, y);
    cout << x << ' ' << y << endl;
    return 0;
}