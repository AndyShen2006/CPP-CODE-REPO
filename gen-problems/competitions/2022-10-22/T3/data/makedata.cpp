#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;

int main()
{
    int n = randint(5000, 10000);
    int m = randint(3, 6);
    cout << n << ' ' << m << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << randint(1, 20000) << ' ';
        }
        cout << endl;
    }
    return 0;
}