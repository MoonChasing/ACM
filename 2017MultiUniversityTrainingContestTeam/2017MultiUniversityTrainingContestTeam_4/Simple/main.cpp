//njupt2017team11
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
typedef long long LL;

using namespace std;

int T, n, a[MAXN], cnt;
int main()
{
    scanf("%d",&T);
     while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(a[i]%2==0)
                cnt++;
        if(cnt>=n/2)
            printf("2 0\n");
        else
            printf("2 1\n");
    }

    return 0;
}
