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
#define MAXN 10005
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

double dp[MAXN];
int n,m;
int a[MAXN];
double b[MAXN];

int main()
{
    while(scanf("%d%d", &n, &m) && m+n)
    {
        for(int j=0; j<=n+1; j++)
            dp[j] = 1;

        for(int i=1; i<=m; i++)
            scanf("%d%lf", &a[i], &b[i]);

        for(int i=1; i<=m; i++)
            b[i] = 1-b[i];
        for(int i=1; i<=m; i++)
        {
            for(int j=n; j>=a[i]; j--)
                dp[j] = min(dp[j], dp[j-a[i]]*b[i]);
        }
        double ans = (1-dp[n]) * 100;
        printf("%.1f%%\n",  ans);
    }
    return 0;
}










