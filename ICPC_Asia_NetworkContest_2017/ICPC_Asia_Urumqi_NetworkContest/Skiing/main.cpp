#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#define maxn 200010
#define MAXN 200010
#define INF 0x3f3f3f3f
#define DataIn
typedef long long LL;
using namespace std;

int n,m,tot,unvisitdis;
int dp[maxn],head[maxn];
int in[maxn];
int T;
int d;


struct Node
{
    int v,w,next;
} edge[MAXN];

void addedge(int u,int v,int w)
{
    edge[tot].v=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot++;
}

queue<int> que;
vector<int> go;
bool vis[maxn];
//void dfs(int u)
//{
//    if(~dp[u]) //以u为起点的最长路径已知
//        return;
//    int i, v, best=unvisitdis, flag=0;
//    for(i=head[u]; ~i; i=edge[i].next)
//    {
//        flag=1;
//        v=edge[i].v;
//        dfs(v);
//        best=max(best, dp[v]+mp[P(u,v)]);
//    }
//    if(flag) //u不是终点
//        dp[u]=best;
//    else//u是终点
//        dp[u]= 0;
//}
void TuopuSort()
{
    que.push(0);
    //vis[0] = true;

    while( !que.empty() )
    {
        int u = que.front();
        que.pop();

        if(vis[u] == true)
            continue;
        go.push_back(u);
        for(int i=head[u]; ~i; i=edge[i].next)
        {
            int v = edge[i].v;
            vis[u] = true;
            que.push(v);
        }
    }
}

int solve()
{
    int ans = 0, flag = 0;
    que.push(0);
    for(int u = que.front(); ; u=que.front())
    {
        que.pop();
        flag = 0;
        for(int i=head[u]; ~i; i=edge[i].next)
        {
            flag = 1;
            int v = edge[i].v;
            que.push(v);
            dp[v] = max(dp[v], dp[u]+edge[i].w);
        }
        if(flag) //u不是终点
            continue;
        else//u是终点
            ans = max(ans, dp[u]);
        if(que.empty())
            break;
    }
    return ans;
}

int main()
{
    int i,u,v;
    unvisitdis=-1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        tot=0;
        memset(head, -1, sizeof(int)*(n+10));
        memset(in, 0, sizeof(int) * (n+10));
        memset(dp, 0, sizeof(int) * (n+10));
        memset(vis, false, sizeof(int) * (n+10));
        for(i=1; i<=m; i++)
        {
            scanf("%d%d%d",&u,&v,&d);
            addedge(u,v,d);
            in[v]++;
        }

        for(i=1; i<=n; i++)
        {
            if(in[i]==0)
                addedge(0,i,0);
        }

        //dfs(0);
        //printf("%d\n",dp[0]);
//        TuopuSort();
//        for(vector<int>::iterator it = go.begin(); it!=go.end(); it++)
//        {
//            printf("%d\n", *it);
//        }

        printf("%d\n",solve());
    }
    return 0;
}

