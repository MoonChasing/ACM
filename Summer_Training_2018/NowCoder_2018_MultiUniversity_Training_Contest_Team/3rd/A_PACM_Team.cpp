#include <bits/stdc++.h>

using namespace std;
const int MAXN = 38;

struct g
{
    int p, a, c, m, g;
} good[MAXN];


unsigned short dp[MAXN][MAXN][MAXN][MAXN][MAXN];
bool path[MAXN][MAXN][MAXN][MAXN][MAXN];
int P, A, C, M;
int n;
vector<int> na;

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d%d%d%d", &good[i].p, &good[i].a, &good[i].c, &good[i].m, &good[i].g);
    }
    scanf("%d%d%d%d", &P, &A, &C, &M);

    for(int i=n-1; i>=0; i--)
    {
        for(int p=0; p<=P; p++)
        {
            for(int a=0; a<=A; a++)
            {
                for(int c=0; c<=C; c++)
                {
                    for(int m=0; m<=M; m++)
                    {
                        if(p<good[i].p || a<good[i].a || c<good[i].c || m<good[i].m)
                        {
                            dp[i][p][a][c][m] = dp[i+1][p][a][c][m];
                        }
                        else
                        {
                            //dp[i][p][a][c][m] = max(dp[i+1][p][a][c][m], (unsigned short)(dp[i+1][p-good[i].p][a-good[i].a][c-good[i].c][m-good[i].m] + (unsigned short)good[i].g));
                            if( dp[i+1][p][a][c][m] < dp[i+1][p-good[i].p][a-good[i].a][c-good[i].c][m-good[i].m] + good[i].g )
                            {
                                dp[i][p][a][c][m] = dp[i+1][p-good[i].p][a-good[i].a][c-good[i].c][m-good[i].m] + good[i].g;
                                path[i][p][a][c][m] = true;
                            }
                            else
                                dp[i][p][a][c][m] = dp[i+1][p][a][c][m];
                        }

                    }
                }
            }
        }
    }

    for(int i=0, p=P, a=A, c=C, m=M; i<n; i++)
    {
        //if(dp[i][p][a][c][m] - good[i].g == dp[i+1][p-good[i].p][a-good[i].a][c-good[i].c][m-good[i].m])
        if(path[i][p][a][c][m])
        {
            na.push_back(i);
            p -= good[i].p;
            a -= good[i].a;
            c -= good[i].c;
            m -= good[i].m;
        }
    }

    printf("%d\n", na.size());
    if(na.size() == 0)
    {
        puts("");
    }
    else
    {
    for(int i=0; i<na.size()-1; i++)
        printf("%d ", na[i]);
    printf("%d\n", na[na.size()-1]);
    }

    return 0;
}
