#include<bits/stdc++.h>

using namespace std;

int main()
{
	//int d[7];
	int ans=8,ta,tb,pos;
	for(int i=0; i<7; i++) {
		cin >> ta >> tb;
		if(ta+tb>ans) {
			ans=ta+tb;
			pos=i+1;
		}
	}
	cout << pos;
	return 0;
}

