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
//#define DataIn
typedef long long LL;

using namespace std;

const int maxn = 20;
int dp[1<<maxn], n;

LL a[maxn];
int main()
{
    #ifdef DataIn
	freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
    #endif

    while(~scanf("%d", &n))
    {
        for(int i=0; i<n; i++)
        {
            scanf("%I64d", a+i);
        }
        sort(a, a+n);
        memset(dp, 0, sizeof(dp));
        int ret = 0;

        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                for(int k=j+1; k<n; k++)
                    if(a[i]+a[j] > a[k])
                    {
                        for(int t=0; t<(1<<n); t++)
                        {
                            if( ( (t>>i)&1 ) || ((t>>j)&1) || ( (t>>k)&1 ) )
                                continue;
                            int cika = (t|(1<<i)|(i<<j)|(i<<k));
                            dp[cika] = max(dp[cika], dp[t]+1);
                            ret = max(ret, dp[cika]);
                        }
                    }
        printf("%d\n", ret);
    }

    return 0;
}

//WA










