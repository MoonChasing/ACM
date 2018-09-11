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
#define MAXN 10010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int ans[MAXN], que[MAXN], c[MAXN], res[MAXN];
int b, e, n, h;

int main()
{
    freopen("G.IN", "r", stdin);
    while(scanf("%d%d%d%d", &n, &h, &b, &e) == 4)
    {
        memset(res, 0, sizeof(res));
        for(int i=1; i<=n; i++)
            scanf("%d", c+i);
        int l=0, r=0;
        int stock=0;
        for(int i=1; i<=n; i++)
        {
            while(l<r && i - que[l] >= h)
                l++;
            while(l<r && c[i] <= c[que[r-1]])
                r--;
            que[r++] = i;



            if(stock == 0)
            {
                ans[i] = que[l];
                stock=1;
            }

            stock--;
        }

        for(int i=1; i<=n; i++)
            res[ans[i]]++;
        for(int i=b; i<=e; i++)
            printf("%d%c", res[i], " \n"[i==e]);
    }
    return 0;
}











