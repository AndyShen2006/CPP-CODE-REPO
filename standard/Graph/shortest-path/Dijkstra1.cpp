#include <bits/stdc++.h>

using namespace std;

struct values {
    bool isFind = false;
    int value;
    int minValue = INT_MAX;
    static values make_values(int val)
    {
        values tempValue;
        tempValue.value = val;
        return tempValue;
    }
    int showValue()
    {
        return value;
    }
};

map<int, map<int, values>> g;

void show()
{
    for (auto it : g) {
        for (auto it2 : it.second) {
            printf("%d to %d, value is %d\n", it.first, it2.first, it2.second.showValue());
        }
    }
}

void dfs(int nodeFrom, int nodeTo)
{
    g[nodeFrom][nodeTo].isFind = true;
    g[nodeTo][nodeFrom].isFind = true;
    for (auto it : g[nodeFrom]) {
        g[it.first][nodeFrom].minValue = min(g[it.first][nodeFrom].minValue, g[nodeFrom][nodeTo].minValue + g[nodeFrom][it.first].value);
        dfs(it.first, nodeTo);
    }
}

int main()
{
    freopen("../data/Dijkstra1a.in", "r", stdin);
    int cn, ce;
    int tempFrom, tempTo, tempValue, from, to;
    pair<int, values> tempPair;
    cin >> cn >> ce;
    for (int i = 1; i <= ce; i++) {
        cin >> tempFrom >> tempTo >> tempValue;
        tempPair = make_pair(tempTo, values::make_values(tempValue));
        g[tempFrom].insert(tempPair);
        tempPair = make_pair(tempFrom, values::make_values(tempValue));
        g[tempTo].insert(tempPair);
    }
    cin >> from >> to;
    dfs(from, to);
    cout << g[from][to].minValue;
    return 0;
}