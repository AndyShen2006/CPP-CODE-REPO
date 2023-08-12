#include<bits/stdc++.h>

using namespace std;

int judge(int a, int b)    //did on a have b
{
	if(b>a)  return 0;
	if(a%10 == b){
		return 1+judge(a/10, b);
	}else{
		return judge(a/10, b);
	}
}
int main()
{
	int start,finish,ans=0;
	cin >> start >> finish;
	for(int i=start; i<=finish; i++) {
		ans+=judge(i,2);
		//cout << judge(i,2) << ' ' << ans << endl;
	}
	cout << ans;
	//cout << judge(10,2);
	return 0;
}

