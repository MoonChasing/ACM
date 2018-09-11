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
#define MAXN 1000010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

const int MOD = 1e9+7;
LL dp[MAXN];
LL pow2[MAXN];

void init()
{
    pow2[0] = 1;
    pow2[1] = 2;
    for(int i=2; i<MAXN; i++)
        pow2[i] = (pow2[i-1] << 1) % MOD;
}

int main()
{
    init();
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        LL cika1 = (pow2[k]-1+MOD)%MOD;
        LL cika2 = (pow2[k]-2+MOD)%MOD;
        dp[1] = pow2[k];
        dp[2] = pow2[k] * cika1 % MOD;
        for(int i=3; i<=n; i++)
        {
            dp[i] = ((( dp[i-2] * cika1 %MOD + (dp[i-1]-dp[1]) * cika2 % MOD)%MOD)+MOD)%MOD;
        }
        printf("%lld\n", dp[n]);
    }
    return 0;
}











