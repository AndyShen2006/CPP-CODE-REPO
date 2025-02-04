#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 5e6 + 10;
int fc[MAX_N];
int f(int n)
{
    if (fc[n]) {
        return fc[n];
    } else {
        int ans = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                ans ^= i;
                if (i * i != n) {
                    ans ^= (n / i);
                }
            }
        }
        fc[n] = ans;
        return ans;
    }
}

int gc[MAX_N];

int main()
{
    // for (int i = 1; i < 1000; i++) {
    //     gc[i] = gc[i - 1] ^ f(i);
    // }
    // for (int i = 1; i < 120; i++) {
    //     cerr << i << ' ' << gc[i] << ' ' << ((i) ^ (i - 1)) << endl;
    // }
    freopen("data/B1.in", "r", stdin);
    for (int i = 1; i <= 5e6; i++) {
        gc[i] = gc[i - 1] ^ f(i);
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << gc[n] << endl;
    }
    return 0;
}