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
#define MAXN 10007
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

bool notprime[MAXN];
bool vis[MAXN];
int n, m;
typedef struct node
{
    int num, step;
}P;

void init()
{
    memset(notprime, false, sizeof(notprime));
    notprime[0] = notprime[1] = true;
    for(int i=2; i<MAXN; i++)
    {
        if(!notprime[i])
        {
            if(i > MAXN/i)
                continue;
            for(int j=i*i; j<MAXN; j+=i)
                notprime[j] = true;
        }
    }
}

int bfs()
{
    int tmp, num, step;
    queue<P> que;

    que.push(P {n, 0});
    vis[n] = true;

    while(!que.empty())
    {
        num = que.front().num;
        step = que.front().step;
        if(num == m)
            return step;
        que.pop();

        for(int i=0; i<10; i++)
        {
            tmp = num / 10 * 10 + i;
            if(tmp == m)
                return step+1;
            if(!notprime[tmp] && !vis[tmp])
                que.push(P {tmp, step+1}), vis[tmp] = true;
        }
        for(int i=0; i<10; i++)
        {
            tmp = num/100*100 + num%10 + i*10;
            if(tmp == m)
                return step+1;
            if(!notprime[tmp] && !vis[tmp])
                que.push(P {tmp, step+1}), vis[tmp] = true;
        }
        for(int i=0; i<10; i++)
        {
            tmp = num/1000*1000 + num%100 + i*100;
            if(tmp == m)
                return step+1;
            if(!notprime[tmp] && !vis[tmp])
                que.push(P {tmp, step+1}), vis[tmp] = true;
        }
        for(int i=1; i<10; i++)
        {
            tmp = i*1000 + num%1000;
            if(tmp == m)
                return step+1;
            if(!notprime[tmp] && !vis[tmp])
                que.push(P {tmp, step+1}), vis[tmp] = true;
        }
    }
    return -1;
}
int main()
{
    int T;
    scanf("%d", &T);
    init();
    int ans;
    while(T--)
    {
        memset(vis, false, sizeof(vis));
        scanf("%d%d", &n, &m);

        ans = bfs();
        if(~ans)
            printf("%d\n", ans);
        else
            printf("Impossible\n");
    }
    return 0;
}











