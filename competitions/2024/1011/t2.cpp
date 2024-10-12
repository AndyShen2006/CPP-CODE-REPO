#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N=1e5+10;
typedef long long ll;
int a[MAX_N],b[MAX_N];

int main()
{
	freopen("t2.in","r",stdin);
	freopen("t2.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for(int i=1; i<=m; i++) {
        cin >> b[i];
    }
//    cerr << n <<' ' << m << endl;
    sort(a+1,a+n+1,greater<int>());
    sort(b+1,b+m+1,greater<int>());
//    for(int i=1; i<=n; i++) {
//        cerr << a[i] << ' ' << b[i] << endl;
//    }
    ll ans=0;
    for(int i=1; i<=n; i++) {
        ans+=a[i]*b[i];
    }
    cout << ans << endl;
    return 0;
}
