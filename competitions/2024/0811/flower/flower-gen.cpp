#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;

int main()
{
    freopen("data/flowerN1.in", "w", stdout);
    int n;
    cin >> n;
    cout << n << ' ' << randint(1, n * (n - 1) / 2) << endl;
    for (int i = 1; i <= n; i++) {
        cout << randint(1, n) << ' ';
    }
    cout << endl;
    return 0;
}