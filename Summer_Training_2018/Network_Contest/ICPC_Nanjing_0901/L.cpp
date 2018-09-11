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
#define MAXM 200010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

struct edge
{
    int to, cost;
};

int N, M, K;
int d[MAXN][11];
vector<edge> G[MAXN];
typedef pair<int, int> P;

void Dijkstra(int s)
{
    memset(d, INF, sizeof(d));

    priority_queue<P, vector<P>, greater<P> > que;

    d[s][0] = 0;
    que.push( P(0, s) );

    while(!que.empty())
    {
        P p = que.top();
        que.pop();

        int v = p.second;
        if(d[v][10] < p.first)
            continue;

        for(int k=0; k<=10; k++)
        {
            for(int i=0; i<G[v].size(); i++)
            {
                edge e = G[v][i];

                if(k == 0)
                {
                    if(d[e.to][0] > d[v][0] + e.cost)
                    {
                        d[e.to][0] = d[v][0] + e.cost;
                        que.push( P(d[e.to][0], e.to) )

                    }

                }
                if(d[e.to][k] > d[v][k-1] )
                {
                    d[e.to][k] = d[v][k-1];
                    que.push( P(d[e.to][k], e.to));
                }
            }
        }
//        for(int i=0; i<G[v].size(); i++)
//        {
//            edge e = G[v][i];
//
//            if(d[e.to] > d[v] + e.cost)
//            {
//                d[e.to] = d[v]+e.cost;
//                que.push( P(d[e.to], e.to));
//            }
//        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        for(int i=0; i<MAXN; i++)
            G[i].clear();
        int u, v, w;
        scanf("%d%d%d", &N, &M, &K);
        for(int i=1; i<=M; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back(edge {v, w});
        }
        Dijkstra(1);
        printf("%d\n", d[N][10]);
    }
    return 0;
}











