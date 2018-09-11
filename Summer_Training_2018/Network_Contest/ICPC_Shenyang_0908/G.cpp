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
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

const int MAXN = 100007;//点数的最大值
const int MAXM = 200007;//边数的最大值

struct Edge
{
    int to,next,cap,flow;
} edge[MAXM]; //注意是 MAXM
int tol;
int head[MAXN];
int gap[MAXN],dep[MAXN],pre[MAXN],cur[MAXN];
int S, T;
vector<int> graph;

void init()
{
    tol = 0;
    memset(head,-1,sizeof(head));
    graph.clear();
}
//加边，单向图三个参数，双向图四个参数
void addedge(int u,int v,int w,int rw=0)
{
    edge[tol].to = v;
    edge[tol].cap = w;
    edge[tol].next = head[u];
    edge[tol].flow = 0;
    head[u] = tol++;
    edge[tol].to = u;
    edge[tol].cap = rw;
    edge[tol].next = head[v];
    edge[tol].flow = 0;
    head[v]=tol++;
}
//输入参数：起点、终点、点的总数
//点的编号没有影响，只要输入点的总数
int sap(int start,int end,int N)
{
    memset(gap,0,sizeof(gap));
    memset(dep,0,sizeof(dep));
    memcpy(cur,head,sizeof(head));
    int u = start;
    pre[u] = -1;
    gap[0] = N;
    int ans = 0;
    while(dep[start] < N)
    {
        if(u == end)
        {
            int Min = INF;
            for(int i = pre[u]; i != -1; i = pre[edge[i^1].to])
                if(Min > edge[i].cap - edge[i].flow)
                    Min = edge[i].cap - edge[i].flow;
            for(int i = pre[u]; i != -1; i = pre[edge[i^1].to])
            {
                edge[i].flow += Min;
                edge[i^1].flow -= Min;
            }
            u = start;
            ans += Min;
            continue;
        }
        bool flag = false;
        int v;
        for(int i = cur[u]; i != -1; i = edge[i].next)
        {
            v = edge[i].to;
            if(edge[i].cap - edge[i].flow && dep[v]+1 == dep[u])
            {
                flag = true;
                cur[u] = pre[v] = i;
                break;
            }
        }
        if(flag)
        {
            u = v;
            continue;
        }
        int Min = N;
        for(int i = head[u]; i != -1; i = edge[i].next)
            if(edge[i].cap - edge[i].flow && dep[edge[i].to] < Min)
            {
                Min = dep[edge[i].to];
                cur[u] = i;
            }
        gap[dep[u]]--;
        if(!gap[dep[u]])return ans;
        dep[u] = Min+1;
        gap[dep[u]]++;
        if(u != start) u = edge[pre[u]^1].to;
    }
    return ans;
}



void graphaddedge(int u, int v, int l, int r)
{
    int cnt = r - l;
    addedge(u, v, cnt);
    if(l > 0)
    {
        addedge(S, v, l);
        graph.push_back(tol-2);
        addedge(u, T, l);
        graph.push_back(tol-2);
    }
}

bool judge()
{
    int sz = graph.size();
    int temp;
    for(int i=0; i<sz; i++)
    {
        temp = graph[i];
        if(edge[temp].flow != edge[temp].cap)
            return false;
    }
    return true;
}

int N, M, K;
int main()
{
    int kiss = 1;
    int low, high;

    while( 3 == scanf("%d%d%d", &N, &M, &K) )
    {
        scanf("%d%d", &low, &high);
        init();
        S = N+M+2;
        T = (M<<1)+3;
        for(int i=1; i<=N; i++)
            graphaddedge(0, i, low, high);
        for(int i=N+1; i<=N+M; i++)
            graphaddedge(i, N+M+1, low, high);

        int u, v;
        for(int i=0; i<K; i++)
        {
            scanf("%d%d", &u, &v);
            addedge(u, v+N, 1);
        }
        addedge(N+M+1, 0, INF);
        sap(S, T, T+1);
        printf("Case %d: %s\n", kiss++, judge() ? "Yes" : "No");
    }


    return 0;
}










