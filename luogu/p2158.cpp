#include <bits/stdc++.h>

using namespace std;

int phi[40010];
bool nPrime[40010];
vector<int> primes;

int main()
{
    int n;
    cin >> n;
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!nPrime[i]) {
            primes.push_back(i);
            phi[i] = i - 1;
        }
        for (int j = 0; j < primes.size(); j++) {
            if (i * primes[j] > n) {
                break;
            }
            nPrime[i * primes[j]] = true;
            if (i % primes[j] == 0) {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            } else {
                phi[i * primes[j]] = phi[i] * phi[primes[j]];
            }
        }
    }
    //	for(int i=1; i<=n*n; i++) {
    //		cout << i << ' ' << phi[i] << endl;
    //	}
    if (n == 1) {
        cout << 0 << endl;
        exit(0);
    }
    int ans = 2;
    for (int i = 2; i <= n - 1; i++) {
        ans += 2 * phi[i];
    }
    cout << ans + 1 << endl;
    return 0;
}