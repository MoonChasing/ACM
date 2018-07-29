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
#define MAXN 755
#define MAXM 1005
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int n,m;
int cost[MAXN][MAXN];
int x[MAXN], y[MAXN];
bool vis[MAXN];
int dis[MAXN];
int path[MAXN];

void prim()
{
    memset(vis, false, sizeof(vis));

    for(int i=1; i<=n; i++)
    {
        dis[i] = cost[1][i];
        path[i] = 1;
    }

    dis[1] = 0;
    vis[1] = true;

    for(int i=1; i<=n; i++)
    {
        int v=0;
        int minn = INF;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j] && dis[j]<minn)
            {
                minn = dis[j];
                v = j;
            }
        }
        vis[v] = true;
        if(cost[path[v]][v])
            printf("%d %d\n", v, path[v]);
       for(int j=1; j<=n; j++)
       {
           if(!vis[j] && dis[j] > cost[v][j])
           {
               dis[j] = cost[v][j];
               path[j] = v;
           }
       }
    }
}
int main()
{
    scanf("%d", &n);
    memset(cost, 0, sizeof(cost));

    for(int i=1; i<=n; i++)
    {
        scanf("%d%d", &x[i], y+i);
        for(int j=1; j<=i; j++)
        {
            cost[i][j] = cost[j][i] = (x[i]-x[j]) * (x[i]- x[j]) + (y[i] - y[j])*(y[i] - y[j]);
        }
    }

    scanf("%d", &m);
    int v1,v2;
    for(int j=1; j<=m; j++)
    {
        scanf("%d%d", &v1, &v2);
        cost[v1][v2] = cost[v2][v1] = 0;
    }

    prim();
    return 0;
}







