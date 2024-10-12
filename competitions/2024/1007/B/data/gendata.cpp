#include <bits/stdc++.h>
#include <ext_random.hpp>
#include <structure.hpp>

using namespace std;

int main()
{
    int T = 10;
    cout << T << ' ' << randint(0, 2) << endl;
    while (T--) {
        size_t len = randll(1e5, 5e5);
        size_t pre = randll(1, len), suf = len - pre;
        cerr << pre << ' ' << suf << endl;
        char preC = char('a' + randint(0, 25));
        for (size_t i = 1; i <= pre; i++) {
            cout << preC;
        }
        for (size_t i = pre + 1; i <= suf; i++) {
            cout << char('a' + randint(0, 25));
        }
        cout << endl;
    }
    return 0;
}