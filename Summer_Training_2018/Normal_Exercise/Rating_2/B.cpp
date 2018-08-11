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
#define MAXN 110
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;


using namespace std;

int dp[MAXN], ans[MAXN], a[MAXN];

int main()
{
    int T;
    int n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d", a+i);
        }
        for(int i=1; i<=n; i++)
            ans[i] = 1;
        for(int i=n; i>=1; i--)
        {
            for(int j=i+1; j<=n; j++)
            {
                if(a[j] >= a[i])
                {
                        ans[i] += ans[j];
                }
            }
        }
        for(int i=1; i<=n; i++)
            printf("%d%c", ans[i], " \n"[i==n]);

    }


    return 0;
}





















