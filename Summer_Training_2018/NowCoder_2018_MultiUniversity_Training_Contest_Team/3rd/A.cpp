#include <bits/stdc++.h>

using namespace std;
const int MAXN = 37;

struct g
{
    int p, a, c, m, g;
} good[MAXN];


int dp[MAXN][MAXN][MAXN][MAXN];
int path[MAXN][MAXN][MAXN][MAXN];
int P, A, C, M;
int n;

vector<int> na[MAXN][][][];

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d%d%d%d", &good[i].p, &good[i].a, &good[i].c, &good[i].m, &good[i].g);
    }
    scanf("%d%d%d%d", &P, &A, &C, &M);

    memset(path, -1, sizeof(path));

    for(int i=n-1; i>=0; i--)
    {
        for(int p=P; p>=good[i].p; p--)
        {
            for(int a=A; a>=good[i].a; a--)
            {
                for(int c=C; c>=good[i].c; c--)
                {
                    for(int m=M; m>=good[i].m; m--)
                    {
                        dp[p][a][c][m] = max( dp[p][a][c][m], dp[p-good[i].p][a-good[i].a][c-good[i].c][m-good[i].m] );
                        if(dp[p][a][c][m] < dp[p-good[i].p][a-good[i].a][c-good[i].c][m-good[i].m])
                        {
                            dp[p][a][c][m] = dp[p-good[i].p][a-good[i].a][c-good[i].c][m-good[i].m];
                            path[p][a][c][m] = i;
                        }
                        else
                        {
                            path[p][a][c][m] = dp[p-good[i-1].p][a-good[i-1].a][c-good[i-1].c][m-good[i-1].m];
                        }
                    }
                }
            }
        }
    }
    int dx = path[P][A][C][M];
    for(int  p=P, a=A, c=C, m=M; ~dx; )
    {
        dx = path[p][a][c][m];
        if(dp[p][a][c][m] - good[dx].g == dp[p-good[dx].p][a-good[dx].a][c-good[dx].c][m-good[dx].m])
        {
            na.push_back(dx);
            p -= good[dx].p;
            a -= good[dx].a;
            c -= good[dx].c;
            m -= good[dx].m;
        }
    }

    int size = na.size();
    printf("%d\n", size);
    if(size == 0)
    {
        puts("");
    }
    else
    {
    for(int i=0; i<size-1; i++)
        printf("%d ", na[i]);
    printf("%d\n", na[size-1]);
    }
    return 0;
}



