#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,temp,ans=0;
	cin >> n;
	for(int i=1; i<=n; i++) {
		scanf("%d",&temp);
		ans^=temp;
	}
	printf("%d",ans);
	return 0;
}
