#include <bits/stdc++.h>

using namespace std;

map<char,int> mp;

int main()
{
	freopen("t1.in","r",stdin);
	freopen("t1.out","w",stdout);
    string str;
    getline(cin,str);
    int mx=0;
    for(auto it:str) {
        if(islower(it)) {
            mp[it]++;
            mx=max(mx,mp[it]);
        }
    }
    for(auto it:mp) {
        if(it.second==mx) {
            cout << it.first;
        }
    }
    cout << endl;
    return 0;
}
