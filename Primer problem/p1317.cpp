#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,count=0;
	cin >> n;
	int h[10001]={0};
	for(int i=0; i<n; i++) {
		cin >> h[i];
	}
	bool left;
	for(int i=1; i<n; i++) {
		if(h[i]-h[i-1]<0) left=true;
		if(h[i]-h[i-1]>0&&left){
			count++;
			left=false;
		}
	}
	cout << count;
	return 0;
}

