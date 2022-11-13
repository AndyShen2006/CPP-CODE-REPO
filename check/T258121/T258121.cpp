#include <bits/stdc++.h>

using namespace std;

typedef pair<double, int> decimal; // base*(10^power)

decimal mem[5000010]; // i!

inline decimal dec_multi(decimal a, int b)
{
    double base;
    int power;
    power = a.second;
    base = a.first * b;
    while (base >= 10) {
        power++;
        base /= 10;
    }
    return make_pair(base, power);
}

inline decimal dec_minus(decimal a, decimal b)
{
    double base = a.first / b.first;
    int power = a.second - b.second;
    while (base < 1) {
        power--;
        base *= 10;
    }
    return make_pair(base, power);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    mem[1] = make_pair(1.0, 0);
    for (int i = 2; i <= 5e6; i++) {
        mem[i] = dec_multi(mem[i - 1], i);
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
            cout << dec_minus(dec_minus(mem[n], mem[k]), mem[n - k]).second + 1 << endl;
        }
    }
    return 0;
}