#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_P = 1e5;
bool nPrime[MAX_P];
vector<int> primes;

bool checkPrime(int x)
{
    if (x < MAX_P) {
        return !nPrime[x];
    }
    for (auto it : primes) { // NOLINT
        if (x % it == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    for (long long i = 2; i < MAX_P; i++) {
        if (!nPrime[i]) {
            for (long long j = i * i; j < MAX_P; j += i) {
                nPrime[j] = true;
            }
        }
    }
    for (int i = 2; i < MAX_P; i++) {
        if (!nPrime[i]) {
            primes.push_back(i);
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int x, k;
        cin >> x >> k;
        if (!k) {
            if (checkPrime(x)) {
                cout << 2 << endl;
            } else {
                for (auto it : primes) {
                    if (x % it == 0) {
                        cout << it << endl;
                        break;
                    }
                }
            }
        } else {
            cout << (x >> 1) + 1 << endl;
        }
    }
    return 0;
}
