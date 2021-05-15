#include<bits/stdc++.h>

#define MAX_V 500010

using namespace std;

typedef unsigned long long int ull;

vector<int> G[MAX_V];
int parent[MAX_V];
int depth[MAX_V];
int root;

void dfs(int v, int p, int d)
{
	parent[v] = p;
	depth[v] = d;
	for(int i=0; i < G[v].size(); i++) {
		if(G[v][i] != p)  dfs(G[v][i], v, d+1);
	}
}

void init()
{
	dfs(root, -1, 0);
}

int lca(int u, int v)
{
	while(depth[u] > depth[v])  u = parent[v];
	while(depth[v] > depth[u])  v = parent[v];
	
	while(u!=v) {
		u = parent[u];
		v = parent[v];
	}
	return u;
}

int main()
{
	int n,m,s;
	std::ios::sync_with_stdio(false); 
	cin >> n >> m >> s;
	int tx,ty,ta,tb;
	for(int i=0; i<m-1; i++) {
		cin >> tx >> ty;
		G[tx].push_back(ty);
		G[ty].push_back(tx);
	}
	root = s;
	init();
	/*
	for(int i=1; i<=m; i++) {
		cin >> ta >> tb;
		cout << lca(ta,tb) << endl;
	}
	*/
	return 0;
}

