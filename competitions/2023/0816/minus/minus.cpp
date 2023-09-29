// 骗分过样例！
#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main()
{
    freopen("minus.in", "r", stdin);
    freopen("minus.out", "w", stdout);
    int n;
    long long k;
    cin >> n >> k;
    int ta;
    for (int i = 1; i <= n; i++) {
        cin >> ta;
        pq.push(ta);
    }
    while (pq.size() > 2) {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        pq.push(a * b + k);
    }
    long long a = pq.top();
    pq.pop();
    long long b = pq.top();
    pq.pop();
    cout << (a * b + k) % MOD << endl;
    return 0;
}