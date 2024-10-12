#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 2010;
typedef pair<int,int> P;
vector<P> G[2010];
// Minimum longest edge & Maximum shortest edge
int dpl[MAX_N],dps[MAX_N];

int main()
{
	freopen("t3.in","r",stdin);
	freopen("t3.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        G[a].emplace_back(b,c);
        G[b].emplace_back(a,c);
    }
    queue<int> q;
    q.push(1);
    memset(dpl,0x3f,sizeof(dpl));
    dpl[1]=0;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(auto it:G[u]) {
            int v=it.first,w=it.second;
            int tmp;
            if(dpl[u]>=0x3f3f3f3f) {
                tmp=w;
            }else{
                tmp=max(dpl[u],w);
            }
            if(tmp<dpl[v]) {
                dpl[v]=tmp;
                q.push(v);
            }
        }
    }
    //cerr << dpl[n] << endl;
    q.push(1);
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(auto it:G[u]) {
            int v=it.first,w=it.second;
            int tmp;
            if(dps[u]<=0) {
                tmp=w;
            }else{
                tmp=min(dps[u],w);
            }
            if(tmp>dps[v]) {
                dps[v]=tmp;
                q.push(v);
            }
        }
    }
    //cerr << dps[n] << endl;
    cout << dpl[n]-dps[n] << endl;
    return 0;
}
