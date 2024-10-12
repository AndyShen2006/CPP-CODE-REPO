#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;

int main()
{
    int n = randint(1, 60), m = randint(1, 60);
    int k = randint(0, 200000);
    cout << n << ' ' << m << endl;
    cout << k << endl;
    for (int i = 1; i <= k; i++) {
        cout << randint(1, n) << ' ' << randint(1, m) << endl;
    }
    return 0;
}