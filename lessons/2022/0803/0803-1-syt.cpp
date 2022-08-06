#include <bits/stdc++.h>

using namespace std;

deque<pair<int, int>> maxQ; // value,pos
deque<pair<int, int>> Q;
int a[5000001];

int main()
{
    freopen("data/1a.in", "r", stdin);
    int k, n;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (!maxQ.empty() && i - maxQ.front().second >= k) {
            maxQ.pop_front();
        }
        if (!Q.empty() && i - Q.front().second >= k) {
            Q.pop_front();
        }
        while (!maxQ.empty() && a[i] > maxQ.back().first) {
            maxQ.pop_back();
        }
        while (!Q.empty() && a[i] < Q.back().first) {
            Q.pop_back();
        }
        maxQ.push_back(make_pair(a[i], i));
        Q.push_back(make_pair(a[i], i));
        if (i >= k) {
            cout << maxQ.front().first << ' ' << Q.front().first << endl;
        }
    }
    return 0;
}