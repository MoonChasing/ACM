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
#define MAXN 100010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int n;
int dp[MAXN][15];
int t, pos;
int maxt;
int main()
{
    while( 1 == scanf("%d", &n) && n )
    {
        maxt = -INF;
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<n; i++)
        {
            scanf("%d%d", &pos, &t);
            dp[t][pos+1]++;
            if(t>maxt)
                maxt = t;
        }
        for(int i=maxt; i>=1; i--)
        {
            for(int j=1; j<=11; j++)
            {
                dp[i-1][j] = dp[i-1][j] + max(dp[i][j-1], max(dp[i][j], dp[i][j+1]));
            }
        }
        printf("%d\n", dp[0][6]);
    }
    return 0;
}












