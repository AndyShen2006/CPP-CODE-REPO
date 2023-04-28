#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;
using namespace cdg;

int main()
{
    int x = randint(100000, 1000000);
    int leng = randint(100, 1000000);
    cout << x << endl;
    for (int i = 1; i <= leng; i++) {
        cout << randint(0, 1);
    }
    cout << endl;
    return 0;
}