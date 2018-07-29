//njupt2017team11
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 200010
#define LL long long
using namespace std;

const LL MOD = 1e9+7;
LL qPower(LL a, LL b)
{
    LL ans = 1;
    a = a % MOD;
    while(b>0)
    {
        if(b&1)
            ans = (ans * a) % MOD;
        b = b>>1;
        a = (a * a) % MOD;
    }
    return ans;
}

int main()
{
    int kase = 1;
    LL n,k;
    while(scanf("%I64d%I64d",&n,&k)!=EOF)
    {
        LL ans;
        n=n% MOD;
        ans=0;
        ans=qPower(n,k);
        ans=ans %MOD;
        printf("Case #%d: %I64d\n",kase++,ans);
    }
    return 0;
}
