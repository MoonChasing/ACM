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
#define MAXN 2005
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int par[MAXN], rak[MAXN];
int n;
char tr[MAXN][8];
int cnt = 0;
struct edge
{
    int u,v,cost;
};

bool cmp(edge a, edge b)
{
    return a.cost <b.cost;
}

edge es[MAXN * MAXN + 1];

int calc(int x, int y)
{
    int ans  = 0;
    for(int i=0; i<7; i++ )
    {
        if(tr[x][i] != tr[y][i])
            ans++;
    }
    return ans;
}
void init()
{
    for(int i=0; i<n; i++)
    {
        par[i] = i;
        rak[i] = 0;
    }
}

int findpar(int x)
{
    if(par[x] == x)
        return x;
    return par[x] = findpar(par[x]);
}

bool same(int x, int y)
{
    return findpar(x) == findpar(y);
}
void uniteufs(int x, int y)
{
    x = findpar(x);
    y = findpar(y);

    if(x == y)
        return;
    if(rak[x] < rak[y])
    {
        par[x] = y;
    }
    else
    {
        par[y] = x;
        if(rak[x] == rak[y])
            rak[x]++;
    }
}

int kruskal()
{
    sort(es, es+cnt, cmp);
    init();
    int ans = 0;
    for(int i=0; i<cnt; i++)
    {
        edge e = es[i];
        if(!same(e.u, e.v))
        {
            uniteufs(e.u, e.v);
            ans += e.cost;
        }

    }
    return ans;
}

int main()
{
    int juli;
    while(scanf("%d", &n) && n)
    {
        cnt = 0;
        for(int i=0; i<n; i++)
        {
            scanf("%s", tr[i]);
            for(int j=0; j<i; j++)
            {
                juli = calc(i,j);
                es[cnt].u = i;
                es[cnt].v = j;
                es[cnt++].cost = juli;
//                es[cnt].u = j;
//                es[cnt].v = i;
//                es[cnt++].cost = juli;
            }
        }
        printf("The highest possible quality is 1/%d.\n", kruskal());
    }
    return 0;
}











