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

struct edge
{
    int to, cost;
};

int V;
int d[MAXN];
typedef pair<int, int> P;

vector<edge> G[MAXN];

void addedge(int u, int v, int cost)
{
    G[u].push_back( (edge){v, cost} );
    G[v].push_back( (edge){u, cost} );
}

void Dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P> > que;

    fill(d, d+V, INF);
    d[s] = 0;
    que.push( P(0, s) );

    while( !que.empty() )
    {
        P p = que.top();
        que.pop();

        int v = p.second;

        if( d[v] < p.first )
            continue;

        for(int i=0; i<G[v].size(); i++)
        {
            edge e = G[v][i];

            if( d[e.to] > d[v]+e.cost )
            {
                d[e.to] = d[v]+e.cost;
                que.push( P(d[e.to], e.to) );
            }
        }
    }
}
int main()
{
    addedge(1, 2, 7);
    addedge(1, 3, 9);
    addedge(1, 6, 14);
    addedge(2, 3, 10);
    addedge(2, 4, 15);
    addedge(3, 6, 2);
    addedge(3, 4, 11);
    addedge(4, 5, 6);
    addedge(5, 6, 9);
    V = 7;
    Dijkstra(1);
    for(int i=1; i<=6; i++)
    	printf("%d\n", d[i]);
    return 0;
}



void Dijkstra()
{
    fill(d, d+V, INF);
    d[s] = 0;
    priority_queue<P, vector<P>, greater<P> > que;
    que.push(make_pair(0, s));

    while(!que.empty())
    {
        P p= que.top();
        que.pop();

        int v = p.second;
        if(d[v] < p.first)
            continue;

        for(int i=0; i<G[v].size(); i++)
        {
            edge e = G[v][i];
            if(d[e.to] > d[v]+e.cost)
            {
                d[e.to] = d[v]+e.cost;
                que.push( P(d[e.to], e.to));
            }
        }
    }
}

void Dijkstra()
{
    fill(d, d+V, INF);

    priority_queue<P, vector<P>, greater<P> > que;

    d[s] = 0;
    que.push( P(0, s) );

    while(!que.empty())
    {
        P p = que.top();
        que.pop();

        int v = p.second;
        if(d[v] < p.first)
            continue;

        for(int i=0; i<G[v].size(); i++)
        {
            edge e = G[v][i];

            if(d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v]+e.cost;
                que.push( P(d[e.to], e.to));
            }
        }
    }
}
