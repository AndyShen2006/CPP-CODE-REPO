#include <bits/stdc++.h>
#include <ext_random.hpp>
#include <string>

using namespace std;

int main()
{
    int n;
    n = randint(2000, 5000);
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        int m = randint(2, 5);
        cout << m << endl;
        for (int j = 1; j <= m; j++) {
            switch (randint(1, 4)) {
            case 1:
                cout << "biebie" << endl;
                break;
            case 2:
                cout << randstring(20, cdg::Rules("Lower Upper")) << endl;
                break;
            case 3:
                cout << randstring(20, cdg::Rules("Lower Upper")) << "bie" << endl;
                break;
            case 4:
                cout << randstring(10, cdg::Rules("Lower Upper")) << "bie" << randstring(10, cdg::Rules("Lower Upper")) << endl;
                break;
            }
        }
    }
    return 0;
}