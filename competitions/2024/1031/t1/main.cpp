#include <bits/stdc++.h>

using namespace std;

#define DEBUG 0
#define VER1 1
constexpr int MAX_N = 3e5+10;
typedef long long ll;
typedef pair<ll,int> P;
priority_queue<P,vector<P>,greater<P>> pq;
int t[MAX_N];
#if VER2
ll lstT[MAX_N];
#endif

int par[MAX_N];
void init()
{
    for(int i=0; i<MAX_N; i++) {
        par[i]=i;
    }
}
int findpar(int x)
{
    return par[x]==x?x:findpar(par[x]);
}
void unite(int u, int v)
{
    par[u]=v;
}

int main()
{
    freopen("t1d.in","r",stdin);
    //freopen("t1.out","w",stdout);
    init();
    int n,k;
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for(int i=1; i<=k; i++) {
        pq.emplace(t[i],i);
    }
    int pos=k+1;
    while(pos<=n) {
        vector<P> cache;
        P x=pq.top();
        pq.pop();
        cache.push_back(x);
        while(x.first==pq.top().first) {
            cache.push_back(pq.top());
            pq.pop();
        }
#if DEBUG
        cerr << "DEBUG: " << pq.size() << endl;
        cerr << "Cache(Time,No.): " << endl;
        for(auto it : cache) {
            cerr << it.first << ' ' << it.second << endl;
        }
        cerr << endl;
#endif
#if VER1
        for(size_t i=1; i<cache.size(); i++) {
            unite(cache[i-1].second,cache[i].second);
        }
#endif
        for(auto it : cache) {
            if(pos<=n) {
                pq.emplace(it.first+t[pos],it.second);
                pos++;
            }else{
                pq.push(it);
            }
        }
        cache.clear();
    }
    cout << pq.top().first << endl;
#if VER1
    vector<P> cache;
    P x=pq.top();
    pq.pop();
    cache.push_back(x);
    while(x.first==pq.top().first) {
        cache.push_back(pq.top());
        pq.pop();
    }
#if DEBUG
    cerr << "DEBUG: " << pq.size() << endl;
    cerr << "Cache(Time,No.): " << endl;
    for(auto it : cache) {
        cerr << it.first << ' ' << it.second << endl;
    }
    cerr << endl;
#endif
#if VER1
        for(size_t i=1; i<cache.size(); i++) {
            unite(cache[i-1].second,cache[i].second);
        }
#endif
    for(int i=1; i<=k; i++) {
        cerr << i << ' ' << par[i] << endl;
    }
    for(int i=1; i<=k; i++) {
        if(findpar(i)==findpar(x.second)) {
            cout << 1;
        }else{
            cout << 0;
        }
    }
    cout << endl;
#endif
    return 0;
}
