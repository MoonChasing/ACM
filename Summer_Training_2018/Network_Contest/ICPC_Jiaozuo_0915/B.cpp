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
#define MAXN 10010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int dp[10][MAXN], pd[10][MAXN];
int a[MAXN];
char op[MAXN];
int n, m, k;

void init()
{
    for(int i=0; i<=n; i++)
    {
        dp[0][i] = k;
        pd[0][i] = k;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &m, &k);
        for(int i=1; i<=n; i++)
            scanf("%d", a+i);
        scanf("%s", op+1);
        init();
        int maxx, minn;
        char ch;
        for(int i=1; i<=m; i++)
        {
            maxx = -INF;
            minn = INF;
            for(int j=i; j<=n; j++)
            {
                ch = op[i];
                if(ch=='+')
                {
                    maxx = max(maxx, dp[i-1][j-1]+a[j]);
                    minn = min(minn, pd[i-1][j-1]+a[j]);
                }
                else if(ch=='-')
                {
                    maxx = max(maxx, dp[i-1][j-1]-a[j]);
                    minn = min(minn, pd[i-1][j-1]-a[j]);
                }
                else if(ch=='*')
                {
                    if(a[j]>0)
                    {
                        maxx = max(maxx, dp[i-1][j-1]*a[j]);
                        minn = min(minn, pd[i-1][j-1]*a[j]);
                    }
                    else
                    {
                        maxx = max(maxx, pd[i-1][j-1]*a[j]);
                        minn = min(minn, dp[i-1][j-1]*a[j]);
                    }
                }
                else
                {
                    if(a[j]>0)
                    {
                        maxx = max(maxx, dp[i-1][j-1]/a[j]);
                        minn = min(minn, pd[i-1][j-1]/a[j]);
                    }
                    else
                    {
                        maxx = max(maxx, pd[i-1][j-1]/a[j]);
                        minn = min(minn, dp[i-1][j-1]/a[j]);
                    }
                }
            }
        }
    }
    return 0;
}










