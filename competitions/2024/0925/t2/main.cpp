#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define DEBUG 0

constexpr int MAX_N = 100010;
// "Leftest Right"
int lr[MAX_N];

void init()
{
    memset(lr,0,sizeof(lr));
}

int main()
{
#if !DEBUG
    freopen("t2.in","r",stdin);
    freopen("t2.out","w",stdout);
#endif
    int T;
    cin >> T;
    while(T--) {
        int n,a;
        ll v,mul;
        init();
        deque<pair<int,ll>> dq; // pos,data
        cin >> n >> v;
        for(int i=1; i<=n; i++) {
            cin >> a;
            mul*=a;
            dq.emplace_back(i,a);
            while(mul>=v) {
                lr[dq.front().first]=i;
                // cerr << dq.front().first << ' ' << i  << ' ' << mul << endl;
                mul/=dq.front().second;
                dq.pop_front();
            }
        }
#if DEBUG
        for(int i=1; i<=n; i++) {
            cerr << lr[i] << ' ';
        }
        cerr << endl;
#endif
        int ans=0;
        for(int i=1; i<=n; i++) {
            if(lr[i]) {
                ans+=n-lr[i]+1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
