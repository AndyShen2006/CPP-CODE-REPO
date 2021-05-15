#include<bits/stdc++.h>

using namespace std;
string a,b;
int main()
{
    int cnt,pos,add,ans;
    cin >> cnt;
    while(cnt--) {  //Input
        cin >> a >> b;
        pos=0;
        ans=0;
        while(pos<b.size()) {
            add=0;
            if(a.find(b[pos]))
            ans++;
            pos++;
        }
        cout << ans << endl;
    }
    return 0;
}