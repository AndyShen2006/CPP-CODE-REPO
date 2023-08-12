#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;

int main()
{
    int n = randint(10, 20);
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        cout << randdouble(0, 1) << ' ';
    }
    cout << endl;
    return 0;
}