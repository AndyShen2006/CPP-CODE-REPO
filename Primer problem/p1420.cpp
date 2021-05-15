#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,a,b=0xff,temp=0,ans=0;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a;
		if(a==b+1)  temp++;
		else temp=0;
		if(temp>ans)  ans=temp;
		b=a;
	}
	cout << ans+1;
	return 0;
}

