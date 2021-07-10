#include<bits/stdc++.h>

using namespace std;

map<int, set<int> > G;
const int MAXV = 1000;
bool isFind[MAXV]={0};


void dfs(int start)
{
    cout << start;
    for(auto it : G[start]) {
        if(!isFind[it]){
            dfs(it);
        }
    }
}

int main()
{
    freopen("scc.in","r",stdin);
    int n,m;  //n->vertex,m->edge
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    int tempa,tempb;
    for(int i=0; i<m; i++) {
        cin >> tempa >> tempb;
        G[tempa].insert(tempb);
        G[tempb].insert(tempa);
    }
    dfs(3);
    return 0;
}