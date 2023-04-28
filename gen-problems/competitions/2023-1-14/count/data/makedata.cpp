#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;

int main()
{
    int n = randint(100000, 1000000);
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        cout << randint(100, 500) << ' ';
    }
    cout << endl;
    return 0;
}