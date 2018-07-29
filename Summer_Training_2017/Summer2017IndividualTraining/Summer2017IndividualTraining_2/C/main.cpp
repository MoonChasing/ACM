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
#define MAXN 3010
#define INF 0x3f3f3f3f
#define DEBUG
//#define DataIn
typedef long long LL;

using namespace std;

int childnum[MAXN];
int dp[MAXN][MAXN];
int n, f;

void solve()
{
    memset(dp, -1, sizeof(dp));
    if(childnum[1] != 0)
        dp[1][childnum[1]] = 1;
    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
       {
           dp[i][j] = dp[i-1][j];
           if(j-childnum[i] >= 0 && dp[i-1][j-childnum[i]] != -1 && childnum[i])
                if(dp[i][j] != -1)
                    dp[i][j] = min(dp[i-1][j-childnum[i]]+1, dp[i][j]);
                else
                    dp[i][j] = dp[i-1][j-childnum[i]]+1;
       }
        if(childnum[i] != 0)
            dp[i][childnum[i]] = 1;
    }
}
int main()
    {
    #ifdef DataIn
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
    #endif
    while(~scanf("%d",&n))
    {
        memset(childnum, 0, sizeof(childnum));
        for(int i=1; i<n; i++)
        {
            scanf("%d",&f);
            childnum[f]++;
        }
        solve();
        printf("0 ");
        for(int i=2; i<=n; i++)
        {
            printf("%d ", dp[n][i-1]);
        }
        putchar(10);
    }
    return 0;
}













