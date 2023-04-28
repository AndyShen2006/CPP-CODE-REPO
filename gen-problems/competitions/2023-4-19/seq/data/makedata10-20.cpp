#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;
using namespace cdg;

int main()
{
    int n = randint(100000, 1000000);
    int k = randint(1, n - 10);
    cout << n << ' ' << k << endl;
    for (int i = 1; i <= n; i++) {
        cout << randint(-1000000, 1000000) << ' ';
    }
    cout << endl;
}