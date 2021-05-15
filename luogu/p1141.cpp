#include <bits/stdc++.h>

using namespace std;

int puz[1001][1001];
bool isFind[1001][1001];
int n;

struct Node {
    int x, y;
    bool type;
    static Node makeNode(int a, int b, bool t)
    {
        Node n;
        n.x = a;
        n.y = b;
        n.type = t;
        return n;
    }
};

deque<Node> q;

void setZero(int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            isFind[i][j] = false;
        }
    }
}

int bfs()
{
    int ans = 0;
    int nx, ny;
    while (!q.empty()) {
        nx = q.front().x;
        ny = q.front().y;
        q.pop_front();
        // !!!Maybe Segmentation Fault!!!
        if (nx + 1 < n && !isFind[nx + 1][ny] && puz[nx][ny] ^ puz[nx + 1][ny]) {
            ans++;
            isFind[nx + 1][ny] = true;
            q.push_back(Node::makeNode(nx + 1, ny, puz[nx + 1][ny]));
        }
        if (nx - 1 >= 0 && !isFind[nx - 1][ny] && puz[nx][ny] ^ puz[nx - 1][ny]) {
            ans++;
            isFind[nx - 1][ny] = true;
            q.push_back(Node::makeNode(nx - 1, ny, puz[nx - 1][ny]));
        }
        if (ny + 1 < n && !isFind[nx][ny + 1] && puz[nx][ny] ^ puz[nx][ny + 1]) {
            ans++;
            isFind[nx][ny + 1] = true;
            q.push_back(Node::makeNode(nx, ny + 1, puz[nx][ny + 1]));
        }
        if (ny - 1 >= 0 && !isFind[nx][ny - 1] && puz[nx][ny] ^ puz[nx][ny + 1]) {
            ans++;
            isFind[nx][ny - 1] = true;
            q.push_back(Node::makeNode(nx, ny - 1, puz[nx][ny + 1]));
        }
    }
    return ans;
}

int main()
{
    //freopen("data/p1141a.in", "r", stdin);
    int m;
    cin >> n >> m;
    string tmpStr;
    for (int i = 0; i < n; i++) {
        cin >> tmpStr;
        for (int j = 0; j < n; j++) {
            puz[i][j] = tmpStr[j] - '0';
        }
    }
    int tx, ty;
    for (int i = 0; i < m; i++) {
        cin >> tx >> ty;
        q.push_back(Node::makeNode(tx - 1, ty - 1, puz[tx - 1][ty - 1]));
        setZero(n);
        cout << bfs() << endl;
    }
    return 0;
}