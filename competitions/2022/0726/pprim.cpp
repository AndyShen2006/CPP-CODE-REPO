#include <bits/stdc++.h>

using namespace std;

int isPrime[100001];
vector<int> primes;
int n;

void dfs(int crt)
{
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    int crt = 2;
    for (int i = 2; i <= n; i++) {
        if (!isPrime[i]) {
            crt = i;
            primes.emplace_back(i);
            for (int j = i + i; j <= n; j += i) {
                isPrime[j] = true;
            }
        } else {
            isPrime[i] = crt;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << isPrime[i] << ' ';
    }
    return 0;
}