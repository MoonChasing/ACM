#include<bits/stdc++.h>

using namespace std;
const int MAXN = 100;
int n, m;
double p[MAXN];

double dp[MAXN][MAXN];
double ans[MAXN];
double pre[MAXN];

typedef long long ll;
ll pow_min(ll x,ll n)
{
    ll temp=x;
    ll ans=1;
    while(n)
    {
        if(n&1)
            ans*=temp;
        temp=(temp*temp);
        n>>=1;
    }

    return ans;
}

double getP(int st, int ed)
{
    double ret = 1;
    for(int i=st; i<=ed; i++)
    {
        ret *= p[i];
    }
    return ret;
}

double dodo()
{
    memset(dp, 0, sizeof(dp));
    memset(ans, 0, sizeof(ans));
    for(int i=1; i<=n+1; i++)
    {
        for(int j=0; j<=i-1; j++)
        {
            dp[i][j] = ans[i-j-1] + pow_min(j, m) * getP(i-j, i-1) * (1-p[i]);
            //dp[i][j] = ans[i-j-1] + pow_min(j, m) * (  (pre[i-1]  * invpre[i-j-1] % mod) * inv0 % mod * (100-p[i]) % mod )%mod;
            //dp[i][j] = ans[i-j-1] + pow_min(j, m) * (  (pre[i-1]  * invpre[i-j-1] % mod)  )%mod;
        }

        for(int j=0; j<=i-1; j++)
        {
            ans[i] += dp[i][j];
        }
    }
    return ans[n+1];
    //for(int i=0; i<=n; n)
}

int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> p[i];
    p[n+1] = 0;
    pre[0] = 1;
    printf("%f\n", dodo());
    return 0;
}
