#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
constexpr int M = 5005;

int cntEdges[6];
vector<P> G[M];
int dis[M];
priority_queue<P, vector<P>, greater<P>> pq;

int main()
{
    freopen("data/puzzle1.in", "r", stdin);
    freopen("data/puzzle1.out", "w", stdout);
    //    Input
    int x, m, start, end, val;
    cin >> x >> m;
    for (int i = 1; i <= x; i++) {
        cin >> cntEdges[i];
    }
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= cntEdges[i]; j++) {
            cin >> start >> end >> val;
            // For level x, Point P is p+1000*(x-1)
            // For example1:Level 1, point 2 is 2
            // Example2:Level 3, point 4 is 2004
            G[start + 1000 * (i - 1)].push_back(P(end + 1000 * (i - 1), val));
            G[end + 1000 * (i - 1)].push_back(P(start + 1000 * (i - 1), val));
        }
    }
    // Finish Generate Graph
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= x - 1; i++) {
            // Add edges between near levels
            // For example:Level 1,Point 1(1),Add edge to Level 2,Point1(1001)
            G[j].push_back(P(j + 1000 * i, 0));
            G[j + 1000 * i].push_back(P(j, 0));
        }
    }
    // Shortest Path:Dijkstra Algorithm
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    pq.push(P(0, 1));
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        if (dis[p.second] < p.first) {
            continue;
        }
        for (auto it : G[p.second]) {
            if (dis[p.second] + it.second < dis[it.first]) {
                dis[it.first] = dis[p.second] + it.second;
                pq.push(P(dis[it.first], it.first));
            }
        }
    }
    // Output
    cout << dis[m + 1000 * (x - 1)] << endl;
    return 0;
}