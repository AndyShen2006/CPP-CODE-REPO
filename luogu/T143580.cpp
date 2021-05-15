#include<bits/stdc++.h>

using namespace std;

vector<int> a;
int d[100001],n,len;

int main()
{
    int tempa;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin >> tempa;
        a.push_back(tempa);
    }
    d[1]=a[1];
    len=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]>d[len])
        d[++len]=a[i];
        else
        {
            int j=upper_bound(d+1,d+len+1,a[i])-d;
            d[j]=a[i];
        }
    }
    cout << n-len;
    return 0;
}
