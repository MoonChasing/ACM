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
#define MAXN 17
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

const int dx[5] = {-1, 0, 0, 0, 1};
const int dy[5] = {0, -1, 0, 1, 0};

int M, N;
int tile[MAXN][MAXN];
int opt[MAXN][MAXN];
int flip[MAXN][MAXN];

int getcolor(int x, int y)
{
    int c = tile[x][y];
    for(int d=0; d<5; d++)
    {
        int x2 = x+dx[d], y2 = y+dy[d];
        if(x2>=0 && x2<M && y2>=0 && y2<N)
            c += flip[x2][y2];
    }
    return c&1;
}

int calc()
{
    for(int i=1; i<M; i++)
        for(int j=0; j<N; j++)
            if(getcolor(i-1, j))
                flip[i][j] = 1;

    for(int j=0; j<N; j++)
        if(getcolor(M-1, j))
            return -1;

    int ans = 0;
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++)
            ans += flip[i][j];
    return ans;
}

void solve()
{
    int res = -1;

    for(int i=0; i < 1<<N; i++)
    {
        memset(flip, 0, sizeof(flip));

        for(int j=0; j<N; j++)
            flip[0][N-j-1] = i>>j&1;

        int num = calc();
        if(num >= 0 && (res<0 || res > num))
        {
            res = num;
            memcpy(opt, flip, sizeof(flip));
        }
    }

    if(res < 0)
        printf("IMPOSSIBLE\n");
    else
    {
        for(int i=0; i<M; i++)
            for(int j=0; j<N; j++)
        printf("%d%c", opt[i][j], " \n"[j+1 == N]);
    }
}
int main()
{
    scanf("%d%d", &M, &N);
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &tile[i][j]);
    solve();
    return 0;
}












