#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;
using namespace cdg;

int mapping[20010];

int main()
{
    int n, m;
    n = randint(18000, 20000);
    m = randint(2, n - 3);
    cout << n << ' ' << m << endl;
    for (int i = 1; i <= n - 1; i++) {
        cout << i + 1 << ' ' << 0 << endl;
    }
    return 0;
}