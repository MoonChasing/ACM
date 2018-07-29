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
int cnt; //$�ĸ���
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int d[MAXN][MAXN]; //������λ�õ���̾���

int bfs(P s)
{
    queue<P> que;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            d[i][j] = INF;

    que.push(s);
    d[s.first][s.second] = 0;

    #ifdef DEBUG
    printf("�������꣺%d %d\n", s.first, s.second);
    #endif // DEBUG

    while( que.size() )
    {
        P p = que.front();
        que.pop();

        #ifdef DEBUG
        printf("que.front()���꣺%d %d, ����̾���:%d\n", p.first, p.second, d[p.first][p.second]);
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
                printf("�������꣺%d %d, ����̾���:%d,�Ѵ������\n", nx, ny, d[nx][ny]);
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
                    printf("�������꣺%d %d\n", i, j);
                    #endif // DEBUG
                }
                else if(ch == '%')
                {
                    e.first = i;
                    e.second = j;
                    #ifdef DEBUG
                    printf("�������꣺%d %d\n", i, j);
                    #endif // DEBUG
                }
                else if(ch == '$')
                {
                    cnt++;
                    sol[cnt].first = i;
                    sol[cnt].second = j;
                    #ifdef DEBUG
                    printf("ʿ�����꣺%d %d\n", i, j);
                    #endif // DEBUG
                }
            }

            getchar();
        }

        int step_princess = bfs(s);
        #ifdef DEBUG
        puts("�������\n");
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
    �ջ�
    1. pair�����е�
    2.���Թ�Ҫ�����������ߣ����ﲻ���ߣ���һ�������ϱ��˷��˺ܶ�ʱ�䣡
        ����.��%�������ߣ����Լ�ֻд��. ������%�� ���˺ܳ�ʱ�����
    3.DEBUGʱд�������Ҫ���鷳�������˸�

 */











