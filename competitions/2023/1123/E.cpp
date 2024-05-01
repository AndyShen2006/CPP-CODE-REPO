#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, a, b, c;
    cin >> n >> k >> a >> b >> c;
    cout << ceil((n - 1) * 2.0 / k) * a << endl;
    return 0;
}