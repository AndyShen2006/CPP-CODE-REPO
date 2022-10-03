#include <bits/stdc++.h>

using namespace std;

long double mem[5000010]; // i!

int mylg(double n)
{
    int cnt = 0;
    while (n >= 10) {
        n /= 10;
        cnt++;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    mem[1] = 1.0;
    for (int i = 2; i <= 5e6; i++) {
        mem[i] = mem[i - 1] * i;
    }
    int t;
    cin >> t;
    int n, k;
    for (int i = 1; i <= t; i++) {
        cin >> n >> k;
        k--;
        if (k == 0 || n == k) {
            cout << 1 << endl;
        } else {
            // cout << dec_minus(dec_minus(mem[n], mem[k]), mem[n - k]).second + 1 << endl;
            cout << (long long)(log10(mem[n]) - log10(mem[k]) - log10(mem[n - k])) + 1 << endl;
        }
    }
    return 0;
}