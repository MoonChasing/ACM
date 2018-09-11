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
#define MAXN 21
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int n;
int a[MAXN], b[MAXN], numof1[1<<MAXN];
LL need[MAXN];
LL dp[1<<MAXN];

int main()
{
    fill(dp, dp + (1<<MAXN), -INF);
    memset(need, 0, sizeof(need));
    memset(numof1, 0, sizeof(numof1));

    scanf("%d", &n);
    int cika, foo;


    for(int i=0; i < 1<<n; i++)
    {
        for(int j=20; j>=0; j--)
            if((i >> j) & 1)
                numof1[i]++;
    }


    for(int i=0; i<n; i++)
    {
        scanf("%d%d%d", a+i, b+i, &cika);
        for(int j=0; j<cika; j++)
        {
            scanf("%d", &foo);
            need[i] |= (1 << (foo-1));
        }
    }

    LL ans = -INF;

    dp[0] = 0;

    for (int i = 0; i < 1<<n ; i++)
    {
        if (dp[i]  == -INF)
            continue;
        ans = max(ans, dp[i] );
        for (int j = 0; j < n; j++)
        {
            //if (i & (1<<j) )
            if( (i>>j) & 1 )
                continue;
            if ((i&need[j] ) != need[j] )
                continue;
            dp[ i|(1<<j) ] = max( dp[ i|(1<<j) ], dp[i]  + (long long)(numof1[i] +1)*a[j]  + b[j] );
        }
    }

    printf("%lld\n", ans);
    return 0;
}












