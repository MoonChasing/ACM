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
#define MAXN 2005
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int ans;
int h, m ,s;
int n;
int a[MAXN], b[MAXN];
int dp[MAXN];
int main()
{
    int T;

    scanf("%d", &T);
    while(T--)
    {
        memset(dp, 0, sizeof(dp));
        scanf("%d", &n);
        for(int i=1; i<=n; i++)
            scanf("%d", a+i);
        for(int i=2; i<=n; i++)
            scanf("%d", b+i);
        dp[1] = a[1];
        for(int i=2; i<=n; i++)
            dp[i] = min(dp[i-1]+a[i], dp[i-2]+b[i]);

        h = dp[n] / 3600 + 8;
        m = dp[n] / 60 % 60;
        s = dp[n] % 60;
        printf("%02d:%02d:%02d am\n", h, m, s);
    }
    return 0;
}











