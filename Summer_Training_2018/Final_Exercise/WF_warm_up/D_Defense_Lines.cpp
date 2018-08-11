#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

//#define Debug
const int MAXN = 200010;
int n;

int a[MAXN], left[MAXN], right[MAXN];
int dp[MAXN];

void init()
{
    left[0] = 1;
    right[n-1] = 1;
    for(int i=1; i<n; i++)
    {
        left[i] = 1;
        if(a[i] > a[i-1])
            left[i] += left[i-1];
    }

    for(int i=n-2; i>=0; i--)
    {
        right[i] = 1;
        if(a[i] < a[i+1])
            right[i] += right[i+1];
    }
    memset(dp, 0x3f3f3f3f, sizeof(dp));
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d", a+i);
        }

        init();

        #ifdef Debug
        puts("------------------");
        puts("Left");
        for(int i=0; i<n; i++)
            printf("%d%c", left[i], " \n"[i==n-1]);
        puts("------------------");
        puts("Right");
        for(int i=0; i<n; i++)
            printf("%d%c", right[i], " \n"[i==n-1]);
        puts("------------------");
        #endif // Debug

        int len;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            len = lower_bound(dp+1, dp+n+1, a[i]) - dp;
            ans = max(ans, right[i]+len-1);
            dp[left[i]] = min(dp[left[i]], a[i]);
        }

        printf("%d\n", ans);
    }
    return 0;
}











