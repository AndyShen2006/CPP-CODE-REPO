#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 1e5 + 10;
constexpr int lowbound = 10;
vector<pair<int, int>> G[MAX_N];
int update[MAX_N]; //记录被更新次数,用于bound来防止节点被多次重复更新
int dis[MAX_N]; //记录距离
deque<int> Q; // NOLINT，这个队列里面只放节点编号
bool inq[MAX_N];

bool bound(int x) //计算应该放入队列开头还是放入队列末尾，如果返回false则放在末尾，否则放在开头
{
    bool sign = true;
    if (dis[x] > dis[Q.front()]) { // SLF优化
        sign = false;
    }
    if (dis[Q.front()] + update[Q.front()] * lowbound < dis[x] + update[x] * lowbound) { // bound优化
        sign = false;
    }
    return sign;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m, s;
    cin >> n >> m >> s;
    int u, v, w;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        G[u].emplace_back(make_pair(v, w));
    }
    Q.push_back(s);
    inq[s] = true;
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    update[s]++;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop_front();
        inq[u] = false;
        for (auto it : G[u]) {
            if (dis[u] + it.second < dis[it.first]) {
                dis[it.first] = dis[u] + it.second;
                update[it.first]++;
                if (!inq[it.first]) {
                    inq[it.first] = true;
                    if (bound(it.first)) {
                        Q.push_front(it.first);
                    } else {
                        Q.push_back(it.first);
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << ' ';
    }
    cout << endl;
    return 0;
}