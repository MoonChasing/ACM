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

int Stack[MAXN], top;
bool inStack[MAXN];
int DFN[MAXN];
int Low[MAXN];
int ComponentNum = 0;
int index = 0;
vector<int> Edge[MAXN];
vector<int> Component[MAXN];
int InComponent[MAXN];
int ComponetDegree[MAXN];

void init(int n)
{
    memset(Stack, -1, sizeof(Stack));
    memset(inStack, false, sizeof(inStack));
    memset(DFN, -1, sizeof(DFN));
    memset(Low, -1, sizeof(Low));
    top = 0;
    index = 0;
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
    DFN[i] = Low[i] = ++index;
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
        }while(tmp != i);
    }
}

void SCC(int n)
{
    for(int i=1; i<=n; i++)
        if(DFN[i] == -1)
            Tarjan(i);
}


int main()
{
    int n,m;
    while(scanf("%d%d", &n, &m) && (n||m))
    {
        int a,b;
        init(n);
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&a,&b);
            Edge[a].push_back(b);
        }
        SCC(n);
        if(ComponentNum == 1)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
