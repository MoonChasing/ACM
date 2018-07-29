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

int n,m;
int Stack[MAXN], top;
bool inStack[MAXN];
int DFN[MAXN];
int Low[MAXN];
int ComponentNum = 0;
int Lindex = 0;
vector<int> Edge[MAXN];
vector<int> EdgeSave[MAXN];
vector<int> Component[MAXN];
vector<int>::iterator it;
int InComponent[MAXN];
int ComponetDegree[MAXN];
int edgenum[MAXN];
int a[MAXN];
int b[MAXN];
int ans;
void init(int n)
{
    memset(Stack, -1, sizeof(Stack));
    memset(inStack, false, sizeof(inStack));
    memset(DFN, -1, sizeof(DFN));
    memset(Low, -1, sizeof(Low));
    top = 0;
    Lindex = 0;
    ComponentNum = 0;

    for(int i=0; i<=n; i++)
    {
        Component[i].clear();
        Edge[i].clear();
    }
}

void Tarjan(int i)
{
    int tmp;
    DFN[i] = Low[i] = ++Lindex;
    inStack[i] = true;
    Stack[++top] = i;
    for(int e=0; e<Edge[i].size(); e++)
    {
        tmp = Edge[i][e];
        if(DFN[tmp] == -1)
        {
            Tarjan(tmp);
            Low[i] = min(Low[i], Low[tmp]);
        }
        else if(inStack[tmp])
            Low[i] = min(Low[i], DFN[tmp]);
    }

    if(DFN[i] == Low[i])
    {
        ComponentNum++;
        do
        {
            tmp = Stack[top--];
            inStack[tmp] = false;
            Component[ComponentNum].push_back(tmp);
            InComponent[tmp] = ComponentNum;
        }
        while(tmp != i);
    }
}

void SCC(int n)
{
    for(int i=1; i<=n; i++)
        if(DFN[i] == -1)
            Tarjan(i);
}

void addedge(int u, int v)
{
    EdgeSave[u].push_back(v);
    EdgeSave[v].push_back(u);
}

void deleteedge(int d)
{
    for(int i=1; i<=n; i++)
    {
        if(edgenum[i] <= d)
        {
            for(int j=0; j<Edge[i].size(); j++)
            {
                int v = Edge[i][j];
                Edge[v].erase(find(Edge[v].begin(), Edge[v].end(),i));
            }
            Edge[i].clear();
        }
    }
}

void huanyuanedge()
{
    for(int i=1; i<=n; i++)
        Edge[i].clear();
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<EdgeSave[i].size(); j++)
            Edge[i].push_back(EdgeSave[i][j]);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ans = 0;
        scanf("%d%d", &n, &m);
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            addedge(a[i], b[i]);
        }

        for(int i=1; i<=n; i++)
            edgenum[i] = EdgeSave[i].size();
        for(int i=0; i<n; i++)
        {
            if(ans == n-1)
                printf("%d",ans);
            else
            {
                init(n);
                huanyuanedge();
                deleteedge(i);
//            for(int j=1; j<=n; j++)
//                printf("%d ", Edge[j].size());
//            putchar(10);
                SCC(n);
                ans = ComponentNum-1;
                printf("%d",ans);
            }
            for(int j=1; j<=n; j++)
                if(i==n-1)
                    putchar(' ');

        }
        putchar(10);
    }
    return 0;
}
