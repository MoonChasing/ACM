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
#define MAXN 500005
#define INF 0x3f3f3f3f
#define DEBUG
//#define LOCAL
typedef long long LL;

using namespace std;


int a[MAXN];
int L,n,m;
int cross(int mid)
{
    int i,j, num, l;
    for(i=1, num=l=0; i<=n+1; i++)
    {
        l+=a[i]-a[i-1];
        if(l>mid)
        {
            l = a[i]-a[i-1];
            num++;
        }
    }
    return num+1;
}
int main( )
{
    #ifdef LOCAL
        freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
    #endif
    int i,j;
    while(~scanf("%d%d%d", &L, &n, &m))
    {
        for(i=1; i<=n; i++)
            scanf("%d", &a[i]);
        a[0] = 0;
        a[n+1] = L;

        sort(a+1, a+n+1);
        for(i=1, j=0; i<=n+1; i++)
            j = max(j, a[i]-a[i-1]);
        i=j;
        j=L;
        while(i<j)
        {
            int mid = i+j>>1;
            if(cross(mid) <= m)
                j = mid;
            else
                i = mid+1;
        }
        printf("%d\n",i);
    }

    return 0;
}












