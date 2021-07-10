#include <bits/stdc++.h>
using namespace std;
#define MAX_V 100001
#define MAX_E 2000001
#define INF 0x7fffffff

struct Edge {
    int from, to, weight;
};
int V, E;
int dist[MAX_V];
Edge edge[MAX_E];

void bellman_ford(int start)
{
    fill(dist + 1, dist + V + 1, INF);
    dist[start] = 0;
    for (int i = 1; i <= V; ++i) {
        bool update = false;
        for (int j = 1; j <= E; ++j) {
            Edge e = edge[j];
            //dist[e.to] = min(dist[e.to], dist[e.from] + e.weight);
            if (dist[e.to] > dist[e.from] + e.weight) {
                dist[e.to] = dist[e.from] + e.weight;
                update = true;
            }
        }
        if (!update) {
            break;
        }
    }
}

int main()
{
    freopen("../data/dijkstra3.in", "r", stdin);
    int S;
    cin >> V >> E >> S;
    for (int i = 1; i <= E; i++) {
        cin >> edge[i].from >> edge[i].to >> edge[i].weight;
    }
    bellman_ford(S);
    for (int i = 1; i <= V; i++) {
        printf("%d ", dist[i]);
    }
    cout << endl;
    return 0;
}