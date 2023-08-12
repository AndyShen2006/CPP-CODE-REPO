#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int w0, m;
unsigned long long int ans = 0;
int w[25];
void dfs(int count, int sum, int start)
{
    // cout << count << ',' << sum << ',' << start << endl;
    if (count == m) {
        if (isPrime(sum))
            ans++;
        return;
    }
    for (int i = start; i < w0; i++) {
        dfs(count + 1, sum + w[i], i + 1);
    }
}

int main()
{
    // freopen("p1036i1.in", "r", stdin);
    // Input
    cin >> w0 >> m;
    for (int i = 0; i < w0; i++) {
        cin >> w[i];
    }
    dfs(0, 0, 0);
    cout << ans;
    return 0;
}