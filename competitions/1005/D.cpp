#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P; //Interval[end,begin]

vector<P> intervals;

int main()
{
    int B;
    int start, end;
    cin >> B;
    for (int i = 1; i <= B; i++) {
        cin >> start >> end;
        intervals.push_back(P(end, start));
    }
    sort(intervals.begin(), intervals.end());
    /*
    for (int i = 0; i < intervals.size(); i++) {
        cout << intervals[i].first << intervals[i].second << endl;
    }
    */
    int ans = 0, last = 0;
    for (int i = 0; i < B; i++) {
        if (last >= intervals[i].second) {
            continue;
        }
        ans += intervals[i].first - intervals[i].second + 1;
        last = intervals[i].first;
    }
    cout << ans << endl;
    return 0;
}