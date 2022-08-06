#include <bits/stdc++.h>

using namespace std;

deque<pair<int, int>> maxQ; // value,pos
deque<pair<int, int>> minQ;
int a[5000001];
vector<int> minans;
vector<int> maxans;

int main()
{
    int k, n;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (!maxQ.empty() && i - maxQ.front().second >= k) {
            maxQ.pop_front();
        }
        if (!minQ.empty() && i - minQ.front().second >= k) {
            minQ.pop_front();
        }
        while (!maxQ.empty() && a[i] > maxQ.back().first) {
            maxQ.pop_back();
        }
        while (!minQ.empty() && a[i] < minQ.back().first) {
            minQ.pop_back();
        }
        maxQ.push_back(make_pair(a[i], i));
        minQ.push_back(make_pair(a[i], i));
        if (i >= k) {
            minans.push_back(minQ.front().first);
            maxans.push_back(maxQ.front().first);
        }
    }
    for (auto it : minans) {
        cout << it << ' ';
    }
    cout << endl;
    for (auto it : maxans) {
        cout << it << ' ';
    }
    cout << endl;
    return 0;
}