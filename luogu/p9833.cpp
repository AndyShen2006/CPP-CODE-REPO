#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
P cities[10010];

priority_queue<int> pq;

int main()
{
    int n, l, p;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cities[i].first >> cities[i].second;
    }
    cin >> l >> p;
    sort(cities + 1, cities + n + 1);
    int cur = 1;
    for (int pos = p; pos <= l;) {
        for (; cities[cur].first <= pos; cur++) {
            pq.push(cities[cur].second);
        }
        pos += pq.top();
        pq.pop();
    }
    return 0;
}