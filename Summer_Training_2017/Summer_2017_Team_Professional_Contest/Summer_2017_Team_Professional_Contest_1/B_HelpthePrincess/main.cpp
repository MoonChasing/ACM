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
#define MAXN 210
#define INF 0x3f3f3f3f
//#define DEBUG
//#define DataIn
typedef long long LL;

using namespace std;

char maze[MAXN][MAXN];
typedef pair<int, int> P;
P s, e, sol[40001];
int n,m;
int cnt; //$的个数
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int d[MAXN][MAXN]; //到各个位置的最短距离

int bfs(P s)
{
    queue<P> que;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            d[i][j] = INF;

    que.push(s);
    d[s.first][s.second] = 0;

    #ifdef DEBUG
    printf("出发坐标：%d %d\n", s.first, s.second);
    #endif // DEBUG

    while( que.size() )
    {
        P p = que.front();
        que.pop();

        #ifdef DEBUG
        printf("que.front()坐标：%d %d, 其最短距离:%d\n", p.first, p.second, d[p.first][p.second]);
        #endif // DEBUG

        if(p == e)
            break;

        for(int i=0; i<4; i++)
        {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];

            if(1<= nx && nx <=n && 1 <= ny && ny <= m && (maze[nx][ny] == '.' || maze[nx][ny] == '%')&& d[nx][ny] == INF)
            {
                que.push( P(nx, ny) );
                d[nx][ny] = d[p.first][p.second] + 1;

                #ifdef DEBUG
                printf("现在坐标：%d %d, 其最短距离:%d,已存入队列\n", nx, ny, d[nx][ny]);
                #endif // DEBUG
            }
        }
    }

    return d[e.first][e.second];
}
int main()
{
    #ifdef DataIn
	freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
    #endif
    char ch;
    while(~scanf("%d%d",&n, &m))
    {
        getchar();
        cnt = 0;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                ch = maze[i][j] = getchar();
                if( ch == '@')
                {
                    s.first = i;
                    s.second = j;
                    #ifdef DEBUG
                    printf("公主坐标：%d %d\n", i, j);
                    #endif // DEBUG
                }
                else if(ch == '%')
                {
                    e.first = i;
                    e.second = j;
                    #ifdef DEBUG
                    printf("出口坐标：%d %d\n", i, j);
                    #endif // DEBUG
                }
                else if(ch == '$')
                {
                    cnt++;
                    sol[cnt].first = i;
                    sol[cnt].second = j;
                    #ifdef DEBUG
                    printf("士兵坐标：%d %d\n", i, j);
                    #endif // DEBUG
                }
            }

            getchar();
        }

        int step_princess = bfs(s);
        #ifdef DEBUG
        puts("公主完成\n");
        #endif // DEBUG
        int ans = INF;
        for(int i=1; i<=cnt; i++)
            ans = min(ans, bfs(sol[i]));

        #ifdef DEBUG
        printf("%d  %d\n", step_princess, ans);
        #endif // DEBUG

        if(step_princess < ans)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}

/*
    收获：
    1. pair可以判等
    2.走迷宫要想清楚哪里可走，哪里不可走，这一题在这上边浪费了很多时间！
        比如.和%都可以走，而自己只写了. 忘记了%， 找了很长时间错误！
    3.DEBUG时写清楚，不要嫌麻烦复制忘了改

 */











