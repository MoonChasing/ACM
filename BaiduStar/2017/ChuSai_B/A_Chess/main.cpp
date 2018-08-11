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
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

const int MAXN = 1010;
const int MOD = 1e9+7;

int dp[MAXN][MAXN];

void init()
{
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int n=2; n<=1000; n++)
    {
        dp[n][0] = 1;
        for(int m=1; m<=n; m++)
        {
            if(m==n)
                dp[n][m] = 1;
            else
                dp[n][m] = (dp[n-1][m]+dp[n-1][m-1])%MOD;
        }
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    init();
    while(T--)
    {
        int n,m;
        scanf("%d%d", &n, &m);
        if(n>m)
            printf("%d\n", dp[n][m]);
        else
            printf("%d\n", dp[m][n]);

   }

    return 0;
}









