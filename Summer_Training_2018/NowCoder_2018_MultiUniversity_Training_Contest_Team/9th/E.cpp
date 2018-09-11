#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<map>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#define mem(x,y) memset(x,y,sizeof(x))
#define scan(x) scanf("%d",&x)
#define scan2(x,y) scanf("%d%d",&x,&y)
#define eps 1e-8
#define INF 100000000
#define MAXN 1005
#define rep(x,y,z) for(int x=y;x<=z;x++)
#ifdef LOCATION
    #define Printf(fmt, args...) printf( fmt, ## args)
#else
    #define Printf( fmt, args... ) ((void) 0)
#endif
using namespace std;
typedef  long long ll;
const long long mod=1e9+7;
ll pre[MAXN];
ll p[MAXN];
ll invpre[MAXN];
ll dp[MAXN][MAXN];
ll inv0;
long long inv(long long a,long long m)
{
    if(a == 1)return 1;
    if(a==0)
        return 0;
    return inv(m%a,m)*(m-m/a)%m;
}

ll pow_min(ll x,ll n)
{
    ll temp=x;
    ll ans=1;
    while(n)
    {
        if(n&1)
            ans*=temp;
        temp=(temp*temp)%mod;
        ans%=mod;
        n>>=1;
    }

    return ans;
}
ll n,m,ans[MAXN];

ll dodo()
{
    memset(dp, 0, sizeof(dp));
    memset(ans, 0, sizeof(ans));
    for(int i=1; i<=n+1; i++)
    {
        for(int j=0; j<=i-1; j++)
        {
            //dp[i][j] = ans[i-j-1] + pow_min(j, m) * (  (pre[i-1]  * invpre[i-j-1] % mod) * inv0 % mod * (100-p[i]) % mod )%mod;
            dp[i][j] = ans[i-j-1] + pow_min(j, m) * (  (pre[i-1]  * invpre[i-j-1] % mod)  )%mod;
            dp[i][j]%=mod;
        }

        for(int j=0; j<=i-1; j++)
        {
            ans[i] += dp[i][j];
            ans[i]%=mod;
        }
    }
    return ans[n+1];
    //for(int i=0; i<=n; n)
}

int main()
{
    inv0=inv(100,mod);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>p[i];
    p[n+1] = 0;
    pre[0]=invpre[0]=1;
    pre[1]=p[1]*inv0%mod;
    for(int i=2; i<=n; i++)
        pre[i]=(pre[i-1]*((p[i]*inv0)%mod))%mod;
    for(int i=1; i<=n; i++)
        invpre[i]=inv(pre[i],mod);

    cout<<dodo()<<endl;
    return 0;
}



















