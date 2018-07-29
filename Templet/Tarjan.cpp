#include<cstdio>
#include<iostream>
#include<cstring>
#define MAXN 20010//dian
#define MAXM 50010//bian
using namespace std;

int n;
int head[MAXN];
int current, tot, top, scc;//scc表示强连通分量个数
int DFN[MAXN], Low[MAXN], Stack[MAXN], belong[MAXN];
bool inStack[MAXN];
int num[MAXN];//num表示每个强连通分量中顶点个数
struct
{
    int to, next;
}edge[MAXM];

void addedge(int u, int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void Tarjan(int u)
{
    int v;
    Low[u] = DFN[u] = ++current;
    Stack[top++] = u;
    inStack[u] = true;

    for(int i=head[u]; i != -1; i = edge[i].next)
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
            belong[v] = scc;
            num[scc]++;
        }while(u != v);
    }
}

void solve()
{
    current = top = scc = 0;
    memset()
    for(int i=0; i<n; i++)
        if(!DFN[i])
            Tarjan(i);
}
int main()
{
    n = 3;
    int a, b;
    while(~scanf("%d%d",&a,&b))
    {
        addedge(a, b);
    }
    printf("%d",scc);
    getchar();
    return 0;
}
