#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> Interval;

vector<Interval> its;
set<int> poss;
int mapping[100010];

int main()
{
    int n;
    int cur = 0, ans = 0;
    poss.insert(0);
    for (int i = 1; i <= n; i++) {
        int dis;
        char op;
        cin >> dis >> op;
        if (op == 'L') {
            its.emplace_back(cur - dis, cur);
            poss.insert(cur - dis);
            cur -= dis;
        } else {
            its.emplace_back(cur, cur + dis);
            poss.insert(cur + dis);
            cur += dis;
        }
    }
    int tmp = 1;
    for (auto it : poss) {
    }
    return 0;
}