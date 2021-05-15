#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,ta,tb,ts,sum=0;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> ta >> tb;
		ts=ts+ta+tb-8;
		sum+=ts;
	}
	cout << sum;
	return 0;
}

