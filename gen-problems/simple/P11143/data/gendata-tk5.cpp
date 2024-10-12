#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;

int main()
{
    long long n = randll(1, 1e18), m = randll(1, 1e18);
    int k = randint(1, 2e5);
    cout << n << ' ' << m << endl;
    cout << k << endl;
    for (int i = 1; i <= k; i++) {
        cout << randll(1, n) << ' ' << randll(1, m) << endl;
    }
    return 0;
}