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
#define MAXN 105
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int a[MAXN][MAXN], dp[MAXN][MAXN], vis[MAXN][MAXN];

int main()
{
    int T;
    cin >> T;
    for(int kiss=1; kiss <= T; kiss++)
    {
        int n,m;
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
                scanf("%d", &a[i][j]);
        }

        for(int j=1; j<=m; j++)
            dp[n][j] = a[n][j];

        for(int i=n-1; i>=1; i--)
        {
            for(int j=1; j<=m; j++)
            {
                dp[i][j] = dp[i+1][j];
                vis[i][j] = j;

                if(dp[i][j]>dp[i+1][j-1] && j-1>=1)
                {
                    dp[i][j]=dp[i+1][j-1];
                    vis[i][j]=j-1;
                }

                if(dp[i][j]>=dp[i+1][j+1]&&j+1<=m)
                {
                    dp[i][j]=dp[i+1][j+1];
                    vis[i][j]=j+1;
                }
                dp[i][j]+=a[i][j];
            }
        }
        int ans = INF;
        int k;
        for(int i=1; i<=m; i++)
        {
            if(dp[1][i]<=ans)
            {
                ans = dp[1][i];
                k= i;
            }
        }
        printf("Case %d\n%d", kiss, k);
        for(int i=1; i<n; i++)
        {
            k = vis[i][k];
            printf(" %d", k);
        }
        printf("\n");
    }
    return 0;
}







