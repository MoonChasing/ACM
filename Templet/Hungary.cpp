#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 5010;
const int MAXM = 50010;
int V, E;

struct Edge
{
    int to, next;
}edge[MAXM];

int head[MAXN], tot;

void init()
{
    tot = 0;
    memset(head, -1, sizeof(head));
}

void addedge(int u, int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

int match[MAXN];
bool used[MAXN];

//°×Êé
bool dfs(int u)
{
    used[u] = true;
    for(int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        int w = match[v];
        if(w<0 || !used[w] && dfs(w))
        {
            match[u] = v;
            match[v] = u;
            return true;
        }
    }
    return false;
}

//kuangbin
bool dfsk(int u)
{
    for(int i=head[u]; ~i; i=edge[i].next)
    {
        int v = edge[i].to;
        int w = match[v];

        if(!used[v])
        {
            used[v] = true;
            if(!~w || dfsk(w))
            {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungary()
{
    int res = 0;
    memset(match, -1, sizeof(match));
    for(int u=1; u<=V; u++)
    {
        memset(used, false, sizeof(used));
        if(dfsk(u))
            res++;
    }
    return res;
}

int main()
{
    init();
    scanf("%d%d", &V, &E);
    int u, v;
    for(int i=0; i<E; i++)
    {
        scanf("%d%d", &u, &v);
        addedge(u, v);
        addedge(v, u);
    }
    printf("%d\n", hungary());
    return 0;
}
