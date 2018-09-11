#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define LL long long
#define maxn 10000000
#define maxp 1000000
#define mod 1000000007
bool vis[maxn+5];
int cnt;
int prime[maxp];
LL p[maxn+5];
void sieve(int m)
{
    memset(vis,0,sizeof(bool)*(maxn/2+1));
    for (int i=2; i<=m; i++) if (!vis[i])
            for (int j=i*i; j<=maxn; j+=i) vis[j]=1;
}
void gen_primes()
{
    int m=sqrt(maxn+0.5);
    sieve(m);
    cnt=0;
    p[1]=1;
    for (int i=2; i<=maxn; i++)
    if (!vis[i]) prime[cnt++]=i;
    for(int i=2;i<=maxn;++i) p[i]=p[i-1]*i%mod;
}
int power(int a,int b)
{
    if (a==0) return 1;
    if (a==1) return b;
    LL tmp=power(a/2,b);
    tmp=tmp*tmp%mod;
    if (a%2==1) tmp=tmp*b%mod;
    return tmp%mod;
}
int main()
{
    gen_primes();
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if(!n) break;
        LL ans=1;
        for (int i=0; i<cnt; i++)
        {
            int z=n,res=0,k=prime[i];
            if(n/k<=0) break;
            while(z)
            {
                res+=z/k;
                z/=k;
            }
            if (res%2==1) ans=ans*k%mod;
        }
        printf("%I64d\n",p[n]*power(mod-2,ans)%mod);
    }
    return 0;
}
