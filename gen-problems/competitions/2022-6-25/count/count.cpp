#include <bits/stdc++.h>

using namespace std;

bool isPrime[1000001]; // true->not prime,false->is prime
vector<int> primes;
map<int, int> factor;

int main()
{
    // the Sieve of Eratosthenes
    for (int i = 2; i <= 1000000; i++) {
        if (isPrime[i]) {
            continue;
        } else {
            for (int j = i + i; j <= 1000000; j += i) {
                isPrime[j] = true;
            }
        }
    }
    for (int i = 2; i <= 1000000; i++) {
        if (!isPrime[i]) {
            primes.push_back(i);
        }
    }
    // Initalization and Input
    long long n;
    cin >> n;
    for (auto it : primes) {
        while (n % it == 0) {
            n /= it;
            factor[it]++;
        }
    }
    long long ans = 1;
    for (auto it : factor) {
        // printf("%d %d\n", it.first, it.second);
        ans *= it.second + 1;
    }
    cout << ans << endl;
    return 0;
}