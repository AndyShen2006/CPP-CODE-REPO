#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 1e5 + 10;
int n;
struct Node {
    int x, y, z;
    bool operator<(const Node& rhs) const
    {
        return this->x == rhs.x ? this->y == rhs.y ? this->z < rhs.z : this->y < rhs.y : this->x < rhs.x;
    }
};

inline Node make_node(int x, int y, int z)
{
    Node tmp {};
    tmp.x = x;
    tmp.y = y;
    tmp.z = z;
    return tmp;
}

set<Node> ns;
int color[MAX_N];

int par[MAX_N];
void init()
{
    for (int i = 0; i < MAX_N; i++) {
        par[i] = i;
    }
}

int findpar(int x)
{
    return par[x] == x ? x : par[x] = findpar(par[x]);
}

int main()
{
    cin >> n;
    Node fst {};
    for (int i = 1; i <= n; i++) {
        int xi, yi, zi;
        cin >> xi >> yi >> zi;
        fst = make_node(xi, yi, zi);
        ns.insert(fst);
    }
    int cnt = 0;
    while (cnt != n) {
        for (int i = 1; i <= n; i++) {
        }
    }
    return 0;
}