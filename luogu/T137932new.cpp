#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;

map<ull, ull> maxFactor;

int main()
{
	int n;
	cin >> n;
	ull ta,tb;
	for(int i=1; i<=n; i++) {
		cin >> ta >> tb;
		if(tb > maxFactor[ta])  maxFactor[ta] = tb; 
	}
	ull ans=1;
	for(auto it : maxFactor) {
		ans *= it.second+1;
	}
	cout << "1/" << ans;
	return 0;
}
