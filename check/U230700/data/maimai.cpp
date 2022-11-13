#include<bits/stdc++.h>
using namespace std;

struct edge{
	int num,to;
};

vector<edge>g[100005];
vector<int>ans;
int n,m;
int myroad[100005];
bool been[200005];

void dfs(int x){
	for(int i=0;i<g[x].size();i++){
		int c=abs(g[x][i].num);
		if(been[c]) continue;
		been[c]=1;
		dfs(g[x][i].to);
		ans.push_back(g[x][i].num);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(edge{i,y});
		g[y].push_back(edge{-i,x});
		myroad[x]++,myroad[y]++;
	}
	for(int i=1;i<=n;i++){
		if(myroad[i]%2){
			cout<<"NO";
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		if(myroad[i]){
			dfs(i);
			break;
		}
	}
	
	if(ans.size()!=m){
		cout<<"NO";
		return 0;
	}
	cout<<"YES"<<endl;
	for(int i=m-1;i>=0;i--)cout<<ans[i]<<' ';
	return 0;
}
