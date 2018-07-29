#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <utility>

#define MOD 1e9+7
#define MAXN 10010
#define INF 0x3f3f3f3f
typedef long long LL;

using namespace std;

int dp[10000];

void init()
{
    dp[1]=0;
    dp[2]=1;
    for(int i=3; i<=MAXN; i++)
    {
        dp[i] = (i-1) * ( ( (dp[i-1]%MOD) + (dp[i-2]%MOD) ) % MOD);
    }
}



LL com(int n, int k)
{
    if( k > n-k)
        k = n-k;
    int a=1,b=1,c=1;
    for(int i=n; i>=n-k+1;i--)
    {
        a = (a*i)%MOD;
    }
    for(int i=2; i<=k; i++)
    {
        b = (b*i)%MOD;
    }
    return a/b;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        LL n,k, num, ans=0;
        scanf("%d%d",&n,&k);
        num = n-k;
        for(int i=num; i>0; i--)
        {
            ans += ((dp[i] % MOD) * com(n, num) )  %MOD;
        }
        printf("%lld\n",ans);
    }
}
