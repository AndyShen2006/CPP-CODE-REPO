#include<bits/stdc++.h>

using namespace std;

int main()
{
	string a;
	bool flag=true;
	cin >> a;
	int alen=a.size();
	int end=0;
	if(a[0] == '-')  cout << '-',end=1;
	for(int i=alen-1; i>=end; i--) {
		if(a[i]=='0' && flag)  continue;
		else{
			flag=false;
			cout << a[i];
		}
	}
	return 0;
}

