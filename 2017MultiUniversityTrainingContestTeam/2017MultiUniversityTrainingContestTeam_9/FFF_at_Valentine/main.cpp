//nupt2017team11
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
#define MAXN 1010
#define MAXM 6010
#define INF 0x3f3f3f3f
//#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int n,m;

int head[MAXN];
int current, tot, top, scc;//scc表示强连通分量个数
int DFN[MAXN], Low[MAXN], Stack[MAXN], belong[MAXN];
bool inStack[MAXN];
int num[MAXN];//num表示每个强连通分量中顶点个数
int out[MAXN];

vector<int> edge[MAXN];
void addedge(int u, int v)
{
    edge[u].push_back(v);
}

void Tarjan(int u)
{
    int v;
    Low[u] = DFN[u] = ++current;
    Stack[top++] = u;
    inStack[u] = true;

    for(int i=0; i<edge[u].size(); i++)
    {
        v = edge[u][i];
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
            belong[v] = scc;
            num[scc]++;
        }while(u != v);
    }
}

void solve()
{
    current = top = scc = 0;
    memset(Stack, 0, sizeof(Stack));
    memset(inStack, false, sizeof(inStack));
    memset(DFN, 0, sizeof(DFN));
    for(int i=1; i<=n; i++)
        if(!DFN[i])
            Tarjan(i);
}

int main()
{
    #ifdef DataIn
        freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
    #endif
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int u, v;
        scanf("%d%d", &n, &m);
        memset(head, -1, sizeof(head));
        memset(belong, 0, sizeof(belong));
        memset(out, 0, sizeof(out));
        for(int i=1; i<=n; i++)
            edge[i].clear();
        tot = 1;
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d", &u, &v);
            addedge(u, v);
        }

        solve();

        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<edge[i].size(); j++)
            {
                v = edge[i][j];
                #ifdef DEBUG
                printf("点%d可以通向点%d\n", i, v);
                #endif // DEBUG
                if(belong[v] != belong[i])
                    out[belong[i]]++;
            }
        }

        #ifdef DEBUG
        printf("共有%d个强连通分量\n",scc);
        for(int i=1; i<=n; i++)
        {
            printf("点%d位于强连通分量%d中\n", i, belong[i]);
        }
        for(int i=1; i<=scc; i++)
            printf("强连通分量%d的出度为%d\n", i, out[i]);
        #endif
        int sum=0;
        for(int i=1; i<=scc; i++)
        {
            if(out[i] > 1)
            sum ++;
        }

        if( sum == 0 )
            puts("I love you my love and our love save us!");
        else
            puts("Light my fire!");

    }
    return 0;
}











