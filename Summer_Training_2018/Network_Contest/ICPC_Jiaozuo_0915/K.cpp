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
#define MAX 10000
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int dp[MAXN];
const int MOD = 1e9+7;
int main()
{
    int T;
    scanf("%d", &T);
    int v, c, bit;
    int n, q, query;
    while(T--)
    {
        scanf("%d%d", &n, &q);
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d", &v, &c);
            bit = 1;
            for(int j=0; j<c; j++)
            {
                for(int k=MAX; k-bit*v>=0; k--)
                {
                    dp[k] = (dp[k]+dp[k-bit*v])%MOD;
                }
                bit <<= 1;
            }
        }
        while(q--)
        {
            scanf("%d", &query);
            printf("%d\n", dp[query]);
        }
    }
    return 0;
}









