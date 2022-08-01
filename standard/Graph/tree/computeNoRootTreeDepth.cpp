#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

map<int, set<int>> T;
bool D[10000] = {0};
int HeadRoot;

void dfs(int root, int depth)
{
    if (D[root]) {
        return;
    }
    D[root] = true;
    for (auto it : T[root]) {
        if (!D[it]) {
            cout << HeadRoot << " to " << it << " has " << depth + 1 << endl;
            dfs(it, depth + 1);
        }
    }
}

int main()
{
    freopen("data1.in", "r", stdin);
    freopen("data1.out", "w", stdout);
    int n;
    cin >> n;
    int tempA, tempB;
    for (int i = 0; i < n; i++) {
        cin >> tempA >> tempB;
        T[tempA].insert(tempB);
        T[tempB].insert(tempA);
        //D.push_back(false);
    }
    HeadRoot = 0;
    dfs(0, 0);
    cout << endl;
    memset(D, 0, sizeof(D));
    HeadRoot = 2;
    dfs(2, 0);
    cout << endl;
    memset(D, 0, sizeof(D));
    HeadRoot = 3;
    dfs(3, 0);
    cout << endl;
    memset(D, 0, sizeof(D));
    HeadRoot = 5;
    dfs(5, 0);
}