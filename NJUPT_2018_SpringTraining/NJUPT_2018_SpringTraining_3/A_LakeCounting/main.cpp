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
#define MAXN 105
#define MAXM 105
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int N, M;
char field[MAXN][MAXM+1];

void dfs(int x, int y)
{
    field[x][y] = '.';

    for(int dx = -1; dx <= 1; dx++)
    {
        for(int dy = -1; dy <= 1; dy++)
        {
            int nx = x + dx;
            int ny = y + dy;
            if(0<=nx && nx <N && 0<=ny && ny < M && field[nx][ny] == 'W')
                dfs(nx, ny);
        }

    }
    return ;
}

void solve()
{
    int ans = 0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(field[i][j] == 'W')
            {
                dfs(i,j);
                ans++;
            }
        }
    }
    printf("%d\n", ans);
}

int main()
{
    scanf("%d%d", &N, &M);
    getchar();
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
            field[i][j] = getchar();
        getchar();
    }
    solve();
    return 0;
}








