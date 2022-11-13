#include<stdio.h>
#pragma GCC optimize(2)

long long Trees[1000010];
long long n,m;
long long l,r,mid,sum;

int main()
{
    scanf("%lld%lld",&n,&m);
    for(long long i=1; i<=n; i++) {
        scanf("%lld",&Trees[i]);
        r=Trees[i]>r?Trees[i]:r;
    }
    while (sum != m)
    {
        //mid = (l + r) >> 1;
        mid = (l + r) / 2;
        sum=0;
        for(long long i=1; i<=n; i++) {
            if(Trees[i]>mid){
                sum+=Trees[i]-mid;
            }            
        }
        if (sum<m) r = mid - 1;
        else l = mid + 1;
    }
    printf("%lld\n",mid);
    return 0;
}
