#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

map<int, set<int>> T;
bool D[10000] = {0};
int SonTreeSize[10000] = {0};

int dfs(int root)
{
    D[root] = true;
    SonTreeSize[root] = 1;
    for (auto it : T[root]) {
        if (!D[it]) {
            SonTreeSize[root] += dfs(it);
        }
    }
    return SonTreeSize[root];
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
    dfs(0);
    for (int i = 0; i < n; i++) {
        cout << i << ' ' << SonTreeSize[i] << endl;
    }
    /*
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
    */
    return 0;
}