#include<bits/stdc++.h>

using namespace std;

int main()
{
	string a;
	int ans=0;
	getline(cin, a);
	for(int i=0; i<a.size(); i++) {
		if(isalnum(a[i]))  ans++;
	}
	cout << ans;
	return 0;
}

