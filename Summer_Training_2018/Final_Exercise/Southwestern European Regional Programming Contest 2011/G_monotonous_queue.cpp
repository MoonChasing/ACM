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
#define MAXN 1000010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int n;

int a[MAXN], sum[MAXN<<1];
int que[MAXN<<1];

int main()
{
    while(scanf("%d", &n) && n)
    {
        scanf("%d", &a[0]);
        sum[0] = a[0];
        for(int i=1; i<n; i++)
        {
            scanf("%d", a+i);
            sum[i] = sum[i-1] + a[i];
        }

        for(int i=n; i<(n<<1); i++)
            sum[i] = sum[i-1] + a[i-n];

        int l = 0, r = 0;
        int ans = 0;

        for(int i=0; i<(n<<1); i++)
        {
            while(l<r && sum[i] < sum[que[r-1]])
                r--;
            que[r++] = i;

            if(i>=n && sum[que[l]] - sum[i-n] >= 0)
                ans++;
            while(l<r && que[l] <= i-n+1)
                l++;
        }

        printf("%d\n", ans);
    }
    return 0;
}











