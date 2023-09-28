#include<bits/stdc++.h>
using namespace std;

int n,m;
struct node{
	int lc,rc,val;
}a[20010];

void dfs(int x){
	if(x==1){
		if(a[x].lc)a[x].val=max(a[a[x].lc].val,a[x].val)-min(a[a[x].lc].val,a[x].val);
		else a[x].val=max(a[a[x].rc].val,a[x].val)-min(a[a[x].rc].val,a[x].val);
	}
	else a[x].val=max(a[a[x].lc].val,a[a[x].rc].val)-min(a[a[x].lc].val,a[a[x].rc].val);
	if(a[x].lc) dfs(a[x].lc);
	if(a[x].rc) dfs(a[x].rc);
	return ;
}
int main(){
	freopen("end.in", "r", stdin);
	freopen("end.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		a[i].lc=x;
		a[i].rc=y;
	}
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		a[x].val=y;
	}
	bool flg;
	while(1){
		flg=1;
		for(int i=2;i<=n;i++){
			if(a[i].val){
				flg=0;
				break;
			}
		}
		if(flg)break;
		dfs(1);
	}
	cout<<a[1].val;
	return 0;
}
