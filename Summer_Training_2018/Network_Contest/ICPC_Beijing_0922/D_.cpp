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
#define MAXN 2000010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

LL city[MAXN];
LL sum, a;
int n, c;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        a = INF;
        scanf("%d%d", &n, &c);
        sum = c;

        for(int i=1; i<=n; i++)
            scanf("%lld", city+i);

        LL tmp;
        for(int i=1; i<=n; i++)
        {
            scanf("%lld", &tmp);
            city[i] -= tmp;
            sum += city[i];
            a = min(a, sum);
        }

        if(sum < 0)
        {
            puts("-1");
            continue;
        }
        if(a>=0)
        {
            puts("1");
            continue;
        }
        for(int i=1; i<n; i++)
        {
            a -= city[i];
            if(a>=0)
            {
                printf("%d\n",i+1);
                break;
            }
        }
    }
    return 0;
}








