#include <bits/stdc++.h>

using namespace std;

typedef __int128 ll;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        pq.emplace(1);
    }
    while (pq.size() > 1) {
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();
        pq.emplace(a * b + 1);
    }
    ll ans = pq.top();
    string str;
    while (ans > 0) {
        str.push_back(char('0' + ans % 10));
        ans /= 10;
    }
    reverse(str.begin(), str.end());
    cout << str << endl;
    return 0;
}