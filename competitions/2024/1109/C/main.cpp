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
} nodes[MAX_N];

inline Node make_node(int x, int y, int z)
{
    Node tmp {};
    tmp.x = x;
    tmp.y = y;
    tmp.z = z;
    return tmp;
}

map<Node, int> ns;

vector<int> G[MAX_N];
constexpr int NOCOLOR = 0;
int RED = 1;
int BLUE = 2;
int color[MAX_N];
int cnt[MAX_N];

void dfs(int x, int curcolor)
{
    if (curcolor == RED) {
        color[x] = RED;
    } else if (curcolor == BLUE) {
        color[x] = BLUE;
    }
    for (auto it : G[x]) {
        if (!color[it]) {
            if (curcolor == RED) {
                dfs(it, BLUE);
            } else if (curcolor == BLUE) {
                dfs(it, RED);
            }
        }
    }
}

int main()
{
    freopen("data/C3.in", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nodes[i].x >> nodes[i].y >> nodes[i].z;
        ns[nodes[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        int dx[] = { 1, -1, 0, 0, 0, 0 };
        int dy[] = { 0, 0, 1, -1, 0, 0 };
        int dz[] = { 0, 0, 0, 0, 1, -1 };
        for (int j = 0; j < 6; j++) {
            int to = ns[make_node(nodes[i].x + dx[j], nodes[i].y + dy[j], nodes[i].z + dz[j])];
            if (to) {
                G[i].push_back(to);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!color[i]) {
            dfs(i, RED);
            RED += 2;
            BLUE += 2;
        }
    }
    for (int i = 1; i <= n; i++) {
        cnt[color[i]]++;
    }
    int mx = 0;
    for (int i = 1; i <= n; i += 2) {
        if (cnt[i] == 0 && cnt[i + 1] == 0) {
            break;
        }
        mx += max(cnt[i], cnt[i + 1]);
    }
    cout << mx << endl;
    return 0;
}