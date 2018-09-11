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

int a[MAXN], dp[MAXN];
int n, m;

int main()
{
    while(~scanf("%d%d", &n, &m) && (n || m))
    {
        map<int, int> last;
        for(int i=1; i<=n; i++)
        {
            scanf("%d", a+i);
            dp[i] = last[a[i]];
            last[a[i]] = i;
            dp[i] = max(dp[i], dp[i-1]);
        }

        int l, r;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d", &l, &r);
            if(dp[r] >= l)
                printf("%d\n", a[dp[r]]);
            else
                puts("OK");
        }
        putchar(10);
    }
    return 0;
}










