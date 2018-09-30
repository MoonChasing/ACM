#include<cstdio>
#include<algorithm>
#include<iostream>
#define INF 0x3f3f3f3f;

using namespace std;

typedef long long LL;

const int MAXN = 1e5+10;

int n, m, p, x, t;
LL s[MAXN], cost[MAXN];

int main()
{
    //printf("%0llx\n", LONG_LONG_MAX);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &m, &p);
        for(int i=1; i<=n; i++)
        {
            scanf("%d", s+i);
        }
        LL sum = 0;
        for(int i=0; i<p; i++)
        {
            scanf("%d%d", &x, &t);
            cost[i] = (s[x]-1-t%m+m)%m;
            sum += cost[i];
        }
        LL  ans = 1e18;
        sort(cost, cost+p);
        for(int i=0; i<p; i++)
        {
            ans = min(ans, sum+1LL*i*m-1LL*cost[i]*p);
        }
        printf("%lld\n", ans);
    }

    return 0;
}
