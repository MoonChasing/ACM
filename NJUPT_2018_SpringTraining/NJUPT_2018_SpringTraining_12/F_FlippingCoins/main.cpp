#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define MAXN 410
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

double dp[MAXN][MAXN];
int main()
{
    int n,k;
    scanf("%d%d", &n, &k);
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;

    for(int i=0; i<k; i++)
    {
        for(int j=0; j<n; j++)
        {
            dp[i+1][j] += dp[i][j]*0.5;
            dp[i+1][j+1] += dp[i][j]*0.5;
        }
        dp[i+1][n] += dp[i][n]*0.5;
        dp[i+1][n-1] += dp[i][n]*0.5;
    }

    double ans = 0;
    for(int i=1; i<=n; i++)
    {
        ans += dp[k][i] * i;
    }
    printf("%f\n",ans);
}











