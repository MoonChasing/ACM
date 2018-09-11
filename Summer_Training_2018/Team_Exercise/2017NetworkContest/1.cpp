#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 500007;
double dp[MAXN+1];
int main()
{
    int T, n, pos;
    for(LL i=1;i<=MAXN;i++)
    {
        if(i%4==0) dp[i]=(i/4)*(i/4)*2;
        if(i%4==1) dp[i]=dp[i-1]+i/4-0.5;
        if(i%4==2) dp[i]=dp[i-2]+2*(i/4);
        if(i%4==3) dp[i]=dp[i-1]+i/4+0.5;

    }
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        pos = lower_bound(dp, dp+MAXN, n) - dp;
        printf("%d\n", pos);
    }
    return 0;
}
