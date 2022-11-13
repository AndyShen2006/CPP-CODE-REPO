#include <bits/stdc++.h>

using namespace std;

bool isPrime[250];
int g[201][201];
vector<int> primes;

void show() {
  for (int i = 2; i <= 30; i++) {
    for (int j = 2; j <= 30; j++) {
      cout << g[i][j];
    }
    cout << endl;
  }
}

int main() {
  // Preinitialization
  // freopen("data/p2563a.in", "r", stdin);
  fill(isPrime + 2, isPrime + 250, true);
  for (int i = 2; i <= 200; i++) {
    if (isPrime[i]) {
      for (int j = 2; i * j <= 200; j++) {
        isPrime[i * j] = false;
      }
    }
  }
  for (int i = 2; i <= 200; i++) {
    if (isPrime[i]) {
      g[i][i] = 1;
      primes.push_back(i);
    }
  }
  vector<int>::iterator it1, it2;
  for (int i = 2; i <= 200; i++) {
    for (it1 = primes.begin(); *it1 < i; it1++) {
      for (it2 = it1; *it2 < i; it2++) {
        g[i][*it1] += g[i - *it1][*it2];
      }
    }
  }
  // Main
  int n, ans;
  while (scanf("%d", &n) != EOF) {
    ans = 0;
    for (int i = 2; i <= 200; i++) {
      ans += g[n][i];
    }
    cout << ans << endl;
  }
  return 0;
}