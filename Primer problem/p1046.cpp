#include<bits/stdc++.h>

using namespace std;

int main()
{
	int hmax,ans=0;
	int h[10];
	for(int i=0; i<10; i++)
		cin >> h[i];
	cin >> hmax;
	hmax+=30;
	for(int i=0; i<10; i++)
		if(hmax>=h[i])  ans++;
	cout << ans;
	return 0;
}

