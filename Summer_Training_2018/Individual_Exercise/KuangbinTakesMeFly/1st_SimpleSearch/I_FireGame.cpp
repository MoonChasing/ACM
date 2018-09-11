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
#define MAXN 13
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int T, n, m, sum;
char mz[MAXN][MAXN];
bool vis[MAXN][MAXN];

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

typedef struct point
{
    int x, y, t;
    point() {}
    point(int _x, int _y, int _t)
    {
        x = _x, y = _y, t = _t;
    }
} P;

int bfs(int x, int y)   //返回在x， y两点放火所需的时间
{
    int cnt = 0;
    int curx1 = x/m, cury1 = x-x/m*m;
    int curx2 = y/m, cury2 = y-y/m*m;

    queue<P> que;
    P p;

    que.push(P(curx1, cury1, 0));
    vis[curx1][cury1] = true;

    que.push(P(curx2, cury2, 0));
    vis[curx2][cury2] = true;
    if(x == y)
        cnt++;
    else
        cnt += 2;
    if(cnt == sum)
        return 0;
    while(!que.empty())
    {
        p = que.front();
        que.pop();

        curx1 = p.x;
        cury1 = p.y;

        for(int d=0; d<4; d++)
        {
            curx2 = curx1 + dx[d];
            cury2 = cury1 + dy[d];
            if(curx2 >= 0 && curx2 < n && cury2 >= 0 && cury2 < m && !vis[curx2][cury2] && mz[curx2][cury2] == '#')
            {
                vis[curx2][cury2] = true;
                que.push(P(curx2, cury2, p.t+1));
                cnt++;
                if(cnt == sum)
                    return p.t+1;
            }
        }
    }
    return INF;
}

int solve()
{
    int sz  = n*m;
    int ans = INF;
    for(int i=0; i<sz; i++)
    {
        if(mz[i/m][i-i/m*m] == '.')
            continue;
        for(int j=i; j<sz; j++)
        {
            if(mz[j/m][j-j/m*m] == '.')
                continue;
            memset(vis, false, sizeof(vis));
            ans = min(ans, bfs(i, j));
        }
    }
    return ans;
}

int main()
{
    scanf("%d", &T);
    for(int kiss = 1; kiss<=T; kiss++)
    {
        scanf("%d%d", &n, &m);
        getchar();
        sum = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                mz[i][j] = getchar();
                if(mz[i][j] == '#')
                    sum++;
            }
            getchar();
        }

        int ans = solve();
        printf("Case %d: %d\n", kiss, ans==INF ? -1 : ans);
    }
    return 0;
}











