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
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int N, M, K;

struct qnode
{
    int v;
    int k;
    int c;
    qnode(int _v=0, int _k = 0, int _c=0):v(_v), k(_k),c(_c) {}
    bool operator <(const qnode &r)const
    {
        return c>r.c;
    }
};

struct Edge
{
    int v,cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost) {}
};

vector<Edge>E[MAXN];
bool vis[MAXN][11];
LL dist[MAXN][11];

//点的编号从 1 开始
void Dijkstra(int n,int start)
{
    memset(vis,false,sizeof(vis));
    for(int i=1; i<=n; i++)
        for(int k=0; k<=K; k++)
            dist[i][k]=INF;

    priority_queue<qnode> que;

    dist[start][0] = 0;

    que.push(qnode(start,0, 0));
    qnode tmp;

    while(!que.empty())
    {
        tmp = que.top();
        que.pop();

        int u = tmp.v;
        int k = tmp.k;
        if(vis[u][k])
            continue;

        vis[u][k]=true;

        for(int i=0; i<E[u].size(); i++)
        {
            int v = E[u][i].v;
            int cost=E[u][i].cost;

            if(k<K && !vis[v][k+1] && dist[v][k+1] > dist[u][k])
            {
                dist[v][k+1]=dist[u][k];
                que.push( qnode(v, k+1, dist[v][k+1]) );
            }
            if(!vis[v][k] && dist[v][k]>dist[u][k]+cost)
            {
                dist[v][k] = dist[u][k]+cost;
                que.push(qnode(v, k, dist[v][k]));
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        for(int i=0; i<MAXN; i++)
            E[i].clear();
        int u, v, w;
        scanf("%d%d%d", &N, &M, &K);
        for(int i=1; i<=M; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            E[u].push_back(Edge(v,w));
        }

        Dijkstra(N, 1);
        LL ans = INF;
        for(int i=0; i<=K; i++)
            ans = min(ans, dist[N][i]);
            //printf("%lld\n", dist[N][i]);

        printf("%lld\n", ans);
    }
    return 0;
}









