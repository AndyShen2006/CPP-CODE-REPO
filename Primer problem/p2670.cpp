#include<bits/stdc++.h>
#define X 101
#define Y 101

using namespace std;

void judge(char a[X][Y], int x, int y,char jc)
{
	if(a[x][y] != jc){				//x,y-1;x,y+1;x-1,y;x+1,y;x-1,y-1;x-1,y+1;x+1,y-1;x+1,y+1
		if(a[x-1][y-1] == jc) {
			a[x][y] += 1;
		}if(a[x][y-1] == jc){
			a[x][y] += 1;
		}if(a[x+1][y-1] == jc){
			a[x][y] += 1;
		}if(a[x-1][y] == jc){
			a[x][y] += 1;
		}if(a[x+1][y] == jc){
			a[x][y] += 1;
		}if(a[x-1][y+1] == jc){
			a[x][y] += 1;
		}if(a[x][y+1] == jc){
			a[x][y] += 1;
		}if(a[x+1][y+1] == jc){
			a[x][y] += 1;
		}
	}
}
int main()
{
	int n,m;
	cin >> n >> m;
	char t;
	char b[X][Y]={0};
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++){
			cin >> t;
			if(t=='*')  b[i][j]='*';
			else b[i][j]='0';
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++){
			judge(b, i, j, '*');
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++){
			cout << b[i][j];
		}
		cout << endl;
	}
	return 0;
}

