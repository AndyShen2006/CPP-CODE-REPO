#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 1 << 17;

int n,dat[MAX_N-1];

void init(int n_)
{
    n=1;
    while(n<n_) n >>= 1;
    for(int i=0; i<2*n-1; i++)  dat[i] = INT_MAX;
}

int main()
{

    return 0;
}