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
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;
int n, k;
typedef struct point
{
    int pos, step;
} P;

int minn = INF;
int ans = INF;
bool vis[MAXN];
void bfs()
{
    queue<P> que;
    que.push(P {n, 0});
    vis[n] = true;
    P cur;
    while(!que.empty())
    {
        cur = que.front();
        que.pop();
        if(cur.pos < k)
        {
            if(cur.pos-1>=0 && !vis[cur.pos-1])
            {
                que.push(P {cur.pos-1, cur.step+1});
                vis[cur.pos-1] = true;
            }
            if(cur.pos+1<MAXN && !vis[cur.pos+1])
                que.push(P {cur.pos+1, cur.step+1}), vis[cur.pos+1] = true;
            if(cur.pos * 2 < MAXN && !vis[cur.pos << 1])
            {
                if(cur.pos * 2 <= k)
                    que.push(P {cur.pos<<1, cur.step+1});
                else
                {
                    if(cur.step + 1 + cur.pos * 2 - k <= ans)
                        ans = cur.step + 1 + cur.pos * 2 - k;
                }
                vis[cur.pos << 1] = true;
            }

        }
        else if(cur.pos == k)
        {
            ans = min(ans, cur.step);
        }
        else if(cur.pos > k)
        {
            ans = min(ans, cur.step+cur.pos-k);
        }
    }
}
int main()
{
    scanf("%d%d", &n, &k);

    if(k <= n)
        ans = n-k;
    else
        bfs();

    printf("%d\n",ans);
    return 0;
}












