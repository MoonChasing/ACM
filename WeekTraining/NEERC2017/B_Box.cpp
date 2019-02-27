#include <bits/stdc++.h>
#include     <algorithm>
#include      <iostream>
#include       <cstdlib>
#include       <cstring>
#include        <cstdio>
#include        <string>
#include        <vector>
#include         <stack>
#include         <cmath>
#include           <map>
using namespace std;
#define LL			    long long
#define ll 				long long
#define MOD 		    1000000007
#define CLR(a,x)        memset(a,x,sizeof(a))
#define INF 		    0x3fffffff
#define INFL            0x3f3f3f3f3f3f3f3f
#define pb 		        push_back
#define rep( i, l, r ) 	for( int i = (l); i <= (r); ++i )
#define fastio()        ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define CI              const int
#define PII             pair<int,int>

/*
* Tarjan 算法
* 复杂度O(N+M)
*/
const int MAXN = 50010;//点数
const int MAXM = 100010;//边数
struct Edge
{
    int u;
    int to,next;
    bool used;
} edge[MAXM];
int head[MAXN],tot;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];//Belong 数组的值是1 ∼ scc
int Index,top;
int scc;//强连通分量的个数
bool Instack[MAXN];
int num[MAXN];//各个强连通分量包含点的个数，数组编号1 ∼ scc
//num 数组不一定需要，结合实际情况
bool need[MAXN];
void addedge(int u,int v)
{
    edge[tot].u = u;
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void Tarjan(int u)
{
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    int flag = -1;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        v = edge[i].to;
        if( !DFN[v] )
        {
            Tarjan(v);
            need[i] = true;
            if( Low[u] > Low[v] )
                Low[u] = Low[v];
        }
        else if(Instack[v] )
        {
            if(Low[u] > Low[v])
                flag = i;
            if(Low[u] > DFN[v])
                Low[u] = DFN[v];
        }

    }
    if(~flag)
        need[flag] = true;
    if(Low[u] == DFN[u])
    {
        scc++;
        do
        {
            v = Stack[--top];
            Instack[v] = false;
            Belong[v] = scc;
            num[scc]++;
        }
        while( v != u);
    }
}

void solve(int N)
{
    memset(DFN,0,sizeof(DFN));
    memset(Instack,false,sizeof(Instack));
    memset(num,0,sizeof(num));
    Index = scc = top = 0;
    for(int i = 1; i <= N; i++)
        if(!DFN[i])
            Tarjan(i);
}
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
    memset(need, false, sizeof(need));
}

int n, m;
int main()
{
    int T;
    scanf("%d", &T);
    while( T-- )
    {
        init();
        scanf("%d%d", &n, &m);
        rep( i, 1, m )
        {
            int u, v;
            scanf("%d%d", &u, &v);
            addedge( u, v );

        }
        solve( n );
        int cnt = 0;
        for (int i=1; i<=m; i++)
        {
            if (!need[i])
            {
                printf("%d %d\n",edge[i].u, edge[i].to);
                cnt++;
            }
            if (cnt == m-(n<<1))
                break;
        }

    }
}
