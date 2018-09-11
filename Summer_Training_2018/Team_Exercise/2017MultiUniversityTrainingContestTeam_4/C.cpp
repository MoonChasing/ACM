#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn=1000011,mod=998244353;
int mark[maxn],prime[maxn],res=0;
void get_prime(int n=1000000)
{
    for(int i=2;i<=n;i++)
    {
        if(!mark[i])mark[i]=prime[res++]=i;
        for(int j=0;j<res&&prime[j]*i<=n;j++)
        {
            mark[i*prime[j]]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
}
int T,k,n,ans[maxn];
ll l,r,a[maxn];
int Solve()
{
    for(int i=0;i<res&&prime[i]*prime[i]<=r;i++)
    {
        int p=prime[i];
        ll t=((l+p-1)/p)*p;
        for(int j=t-l+1;j<=n;j+=p)
        {
            int num=0;
            while(a[j]%p==0)a[j]/=p,num++;
            ans[j]=(ll)ans[j]*((ll)k*num%mod+1)%mod;
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>1)ans[i]=(ll)ans[i]*(k+1)%mod;
        sum=(sum+ans[i])%mod;
    }
    return sum;
}
int main()
{
    get_prime();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d%I64d%d",&l,&r,&k);
        n=r-l+1;
        for(int i=1;i<=n;i++)a[i]=l+i-1,ans[i]=1;
        printf("%d\n",Solve());
    }
    return 0;
}
