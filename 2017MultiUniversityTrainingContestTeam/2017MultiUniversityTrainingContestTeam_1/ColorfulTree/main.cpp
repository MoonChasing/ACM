//team595
//B16041432 ������
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
#define MAXN 200010
#define INF 0x3f3f3f3f
typedef long long LL;

using namespace std;

struct node
{
    int id;
    int color;
} Head[MAXN];

vector<int> edge[MAXN];

int top;
int Stack[MAXN];
bool inStack[MAXN];
int colorStack[MAXN];
bool vis[MAXN];
int sum;
int time = 0;
void init()
{
    top=0;
    sum = 0;
    memset(Head, 0, sizeof(Head));
    memset(Stack, 0, sizeof(Stack));
    memset(inStack, false, sizeof(inStack));
    memset(vis, false, sizeof(vis));
    memset(colorStack, 0, sizeof(colorStack));
    for(int i=0; i<MAXN; i++)
        edge[i].clear();
}

void addedge(int u, int v)
{
    edge[u].push_back(v);
    edge[v].push_back(u);
}

int colorNum()
{
    map<int,int> mp;
    int sum=0;
    int i=0;
    do
    {
        mp[colorStack[i]] = 1;
        i++;
    }
    while(colorStack[i]);
    map<int,int>::iterator it;
    for(it=mp.begin(); it!=mp.end(); it++)
        sum++;
    return sum;
}
int dfs(int u)
{
    Stack[top] = u;
    inStack[u] = true;
    colorStack[top++] = Head[u].color;
    vis[u] = true;
    int sum = colorNum();
    int v;
    for(int i=0; i<edge[u].size(); i++)
    {
        if(inStack[edge[u][i]] == false )
            sum += dfs(edge[u][i]);
    }

    v = Stack[--top];
    Stack[top] = 0;
    inStack[v] = false;
    colorStack[top] = 0;
    return sum;
}
int main()
{
    freopen("1003.in", "r", stdin);
    int n;
    while(~scanf("%d",&n))
    {
        init();
        for(int i=1; i<=n; i++)
            scanf("%d",&Head[i].color);
        for(int i=1; i<=n-1; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
        }
        LL ans=0;
        for(int i=1; i<=n; i++)
        {
            ans += (dfs(i)-1);
        }
           printf("Case #%d: %I64d\n", ++time,ans/2);
    }


    return 0;
}
