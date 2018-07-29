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
typedef long long LL;

using namespace std;

struct node
{
    int to, next;
} edge[MAXN*5];

int head[MAXN], tot;
int Low[MAXN], DFN[MAXN], Stack[MAXN], Belong[MAXN];
int index, top;
int scc;
bool inStack[MAXN];
int num[MAXN];
int vis[MAXN];

void addedge(int u, int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void Tarjan(int u)
{
    int v;
    Low[u] = DFN[u] = ++index;
    Stack[top++] = u;
    inStack[u] = true;

    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        v = edge[i].to;
        if(!DFN[v])
        {
            Tarjan(v);
            if(Low[u] > Low[v])
                Low[u] = Low[v];
        }
        else if(inStack[v] && Low[u] > DFN[v])
            Low[u] = DFN[v];
    }

    if(Low[u] == DFN[u])
    {
        scc++;
        do
        {
            v = Stack[--top];
            inStack[v] = false;
            Belong[v] = scc;
            num[scc]++;
        }
        while(u!=v);
    }
}

void init()
{
    index = tot = scc = top = 0;
    memset(DFN, 0, sizeof(DFN));
    memset(Low, 0, sizeof(Low));
    memset(head, -1, sizeof(head));
    memset(inStack, false, sizeof(inStack));
    memset(num, 0, sizeof(num));
    memset(Belong, 0, sizeof(Belong));
    memset(vis, 0, sizeof(vis));
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n, &m))
    {
        init();
        while(m--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
        }

        for(int i=1; i<=n; i++)
            if(!DFN[i])
                Tarjan(i);
        int sum=0, x;
        for(int i=1; i<=n; i++)
            for(int j=head[i]; j!=-1; j=edge[j].next)
                if(Belong[i] != Belong[edge[j].to])
                    vis[Belong[i]]++;
        for(int i=1; i<=scc; i++)
        {
            if(!vis[i])
            {
                sum++;
                x = i;
            }
        }

        if(sum == 1)
            printf("%d\n",num[x]);
        else
            printf("0\n");

    }
    return 0;
}
