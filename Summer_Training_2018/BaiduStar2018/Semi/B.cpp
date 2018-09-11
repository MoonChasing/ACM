#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
const LL mod = 1e9+7;
const double eps = 1e-9;
const int inf = 0x3f3f3f3f;

const int MAXN = 105;
int l[MAXN],r[MAXN];
long long powmod(long long a,long long b)
{
    long long ret=1;
    while(b)
    {
        if(b&1)
            ret=(ret*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ret;
}

signed main()
{
    int T,n,lajibbaidu,LaJiBaiDu;
    LL ans,todogo,k,tmp;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        lajibbaidu=0;
        LaJiBaiDu=0;
        for(int i=0; i<n; i++)
            scanf("%d %d",&l[i],&r[i]);
        for(int i=0; i<n; i++)
            lajibbaidu=max(lajibbaidu,l[i]);
        for(int i=0; i<n; i++)
            LaJiBaiDu=max(LaJiBaiDu,r[i]);
        k=1;
        for(int i=0; i<n; i++)
            k=k*(r[i]-l[i]+1)%mod;
        ans=0;
        tmp=0;
        for(int i=lajibbaidu; i<=LaJiBaiDu; i++)
        {
            todogo=1;
            tmp=1;
            for(int j=0; j<n; j++)
                if(r[j]>=i)
                    tmp=(tmp*((i-l[j]+1)*(i-l[j]+2)/2%mod))%mod;
                else tmp=(tmp*((i-l[j]+1+i-r[j]+1)*(r[j]-l[j]+1)/2%mod))%mod;
            for(int j=0; j<n; j++)
                if(r[j]>=i-1)
                    todogo=(todogo*((i-l[j]+3)*(i-l[j])/2%mod))%mod;
                else todogo=(todogo*((i-l[j]+1+i-r[j]+1)*(r[j]-l[j]+1)/2%mod))%mod;
            tmp=(tmp-todogo+mod)%mod;
            ans=(ans+tmp)%mod;
        }
        printf("%I64d\n",ans*powmod(k,mod-2)%mod);
    }
    return 0;
}
