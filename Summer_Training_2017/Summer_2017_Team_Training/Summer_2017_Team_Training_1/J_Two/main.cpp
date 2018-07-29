#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxn 1010
int a[maxn],b[maxn];
long long dp[maxn][maxn];
const int mod=1000000007;

int main()
{
    int N,M;
    while(~scanf("%d%d",&N,&M))
    {
        for(int i=1; i<=N; i++)
            scanf("%d", a+i);
        for(int i=1; i<=M; i++)
            scanf("%d", b+i);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=N;++i)
        {
            for(int j=1;j<=M;++j)
            {
                if(a[i]!=b[j])
                    dp[i][j]=(dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+mod)%mod;
                else
                    dp[i][j]=(dp[i-1][j]+dp[i][j-1]+1)%mod;
            }
        }
        printf("%I64d\n",dp[N][M]);
    }
    return 0;
}
