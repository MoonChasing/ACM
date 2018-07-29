
#include <bits/stdc++.h>

using namespace std;
const int MAXN = 37;

struct g
{
    int p, a, c, m, g;
} good[MAXN];


int dp[MAXN][MAXN];
int P, A, C, M;
int n;

vector<int> na;

int _421(int p, int a, int c, int m)
{
    int ans = 0;
    c<<=6;
    a<<=12;
    p<<=18;
    ans = ans | p | a | c | m;
    return ans;
}

int main()
{
    cout << _421(1, 0, 2, 1) <<endl;
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
                            dp[i][_421(p, a, c, m)] = dp[i+1][_421(p, a, c, m)];
                        }
                        else
                        {
                            dp[i][_421(p, a, c, m)] = max(dp[i+1][_421(p, a, c, m)], dp[i+1][_421(p-good[i].p, a-good[i].a, c-good[i].c, m-good[i].m)] + good[i].g);
                        }

                    }
                }
            }
        }
    }

    for(int i=0, p=P, a=A, c=C, m=M; i<n; i++)
    {
        if(dp[i][_421(p, a, c, m) - good[i].g == dp[i+1][_421(p-good[i].p, a-good[i].a, c-good[i].c, m-good[i].m)])
        {
            na.push_back(i);
            p -= good[i].p;
            a -= good[i].a;
            c -= good[i].c;
            m -= good[i].m;
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


