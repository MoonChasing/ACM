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
#define MAXN 100010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;


int w[502], v[502];
int dp[50005];

int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int s, now;
        scanf("%d%d", &s, &now);
        now -= s;
        int num;
        scanf("%d", &num);
        for(int i=1; i<=num; i++)
            scanf("%d%d", &v[i], &w[i]);

        //fill(dp+1, dp+now+1, INF);
        for(int i=1; i<=now; i++)
            dp[i] = INF;
        dp[0] = 0;
        for(int i=1; i<=num; i++)
        {
            for(int j=w[i]; j<=now; j++)
            {
                    dp[j] = min(dp[j], dp[j - w[i]]+v[i]);
            }
        }
        if(dp[now] != INF)
            printf("The mininim amount of money in the piggy-bank is %d.\n",dp[now]);
        else
            puts("This is impossible.");
    }

    return 0;
}






