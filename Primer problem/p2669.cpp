#include<bits/stdc++.h>

using namespace std;

int main()
{
	double k;
	cin >> k; 
	int ans=0,max=floor((sqrt(1.0+8.0*k)-1.0)/2.0);
	ans+=max*(max+1)*(2*max+1)/6.0;
	ans+=(k-max*(max+1)/2)*(max+1.0);
	cout << ans;
	return 0;
}

