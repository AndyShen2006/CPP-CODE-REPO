#include <bits/stdc++.h>

using namespace std;

bool nPrime[100001];

int main()
{
    nPrime[1] = true;
    for (int i = 2; i <= 100000; i++) {
        if (!nPrime[i]) {
            for (int j = i + i; j <= 100000; j += i) {
                nPrime[j] = true;
            }
        }
    }
    int n;
    cin >> n;
    int tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        if (!nPrime[tmp]) {
            cout << tmp << ' ';
        }
    }
    cout << endl;
    return 0;
}