#include <bits/stdc++.h>

using namespace std;

struct Edge {
    /* data */
    int Vert1, Vert2, EdgeLen;
};

struct {
    bool operator()(Edge a, Edge b)
    {
        return a.EdgeLen > b.EdgeLen;
    }
} EdgeLessFunctor;

map<int, map<int, int>> G;
priority_queue<Edge, vector<Edge>, EdgeLessFunctor> EdgeList;

int main()
{
    int n, m, tempFrom, tempTo, tempLen;
    for (size_t i = 0; i < m; i++) {
        cin >> tempFrom >> tempTo >> tempLen;
        pair<int, int> tempPair;
        tempPair.make_pair(tempTo, tempLen);
        G.insert(tempPair);
    }
    return 0;
}
