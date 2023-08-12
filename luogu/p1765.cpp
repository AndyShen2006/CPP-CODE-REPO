#include<bits/stdc++.h>

using namespace std;

int judge(const char a)
{
	if(a=='a' || a=='d' || a=='g' || a=='j' || a=='m' || a=='p' || a=='t' || a=='w' || a==' ')
		return 1;
	if(a=='b' || a=='e' || a=='h' || a=='k' || a=='n' || a=='q' || a=='u' || a=='x')
		return 2; 
	if(a=='c' || a=='f' || a=='i' || a=='l' || a=='o' || a=='r' || a=='v' || a=='y')
		return 3;
	if(a=='s' || a=='z')
		return 4;
	return 0;
}
int main()
{
	string a;
	getline(cin, a);
	int alen=a.size();
	int ans=0;
	for(int i=0; i<alen; i++) {
		ans+=judge(a[i]);
	}
	cout << ans << endl;
	return 0;
}

