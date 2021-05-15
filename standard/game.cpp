#include<bits/stdc++.h>

using namespace std;

//map<int, pair<int, set<int> > > G;
vector<vector<int> > G;
bool sign[100000] = {0};

void dfs(int pos, int depth, int maxdepth)
{
	if(depth > maxdepth || sign[pos]) {
		return;
	}
	sign[pos] = true;
	cout << "Add" << pos << endl;
	for(auto item : G[pos]) {
		dfs(item, depth+1, maxdepth);
	}
	cout << "Delete" << pos << endl;
}

int main()
{
	//Installize
	freopen("data1.in" , "r",stdin);
	int n,k;
	cin >> n >> k;
	int ta,tb,tk;
	//Input
	for(int i=1; i<=n; i++) {
		cin >> tk;
		G[i].first = tk;
	}
	
	for(int i=1; i<=n-1; i++) {
		cin >> ta >> tb;
		G[i].
	}
	//Test Output
	for(auto it : G) {
		cout << it.first << ' ' << it.second.first << ':';
		for(auto item : it.second.second) {
			cout << item << ','; 
		}
		cout << endl; 
	}
	dfs(1,0,k);
	return 0;
}
