#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr ll MOD = 998244353;
constexpr int MAX_N = 10010;
map<int, int> p[MAX_N];
vector<int> primes;
bool nPrime[MAX_N];

int main()
{
    for (int i = 2; i <= 10005; i++) {
        if (!nPrime[i]) {
            primes.push_back(i);
        }
        for (int j = i * i; j <= 10005; j += i) {
            nPrime[j] = true;
        }
    }
    for (auto it : primes) {
        cout << it << ' ';
    }
    cout << endl;
    int n, w;
    cin >> n >> w;
    int g, tp;
    cin >> tp;
    g = tp;
    for (int i = 2; i <= n; i++) {
        cin >> tp;
        g = __gcd(g, tp);
    }

    return 0;
}