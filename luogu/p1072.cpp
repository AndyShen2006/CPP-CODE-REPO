#include <bits/stdc++.h>

using namespace std;

constexpr int N = 50000;
bool isPrime[N]; // is Prime->false;isn't prime->true
vector<int> primes;

bool check(int a, int b) //(a,b)==1->true
{
    for (auto it : primes) {
        if (a % it == 0 && b % it == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    // freopen("data/p1072a.in", "r", stdin);
    //  Sieve of Eratosthenes
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            continue;
        }
        for (int j = i + i; j < N; j += i) {
            isPrime[j] = true;
        }
    }
    for (int i = 2; i <= N; i++) {
        if (!isPrime[i]) {
            primes.push_back(i);
        }
    }
    int a, u, m, v, n, cnt;
    cin >> a;
    for (int i = 1; i <= a; i++) {
        cnt = 0;
        cin >> u >> m >> v >> n;
        for (int x = m; x <= n; x += m) {
            if (n % x == 0 && check(u / m, x / m) && check(n / v, n / x)) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}