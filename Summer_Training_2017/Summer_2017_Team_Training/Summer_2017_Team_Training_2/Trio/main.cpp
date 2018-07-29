//njupt2017team11

#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 1000010
//#define LOCAL
using namespace std;
int a[MAXN];
int n;

int solve()
{
    int cnt=0;
//    for(int i=0; i<n-2; i++)
//        for(int j=i+1; j<n-1; j++)
//            for(int k=j+1; k<n; k++)
//    {
//        if( (a[i]^a[j]) < (a[j]^a[k]) )
//            cnt++;
//    }
 for(int i=0; i<n-1; i++)
        for(int j=i+2; j<n; j++)
        {
            if((a[i]^a[j]) > (i&j))
                cnt++;
        }
    return cnt;
}
int main()
{
    #ifdef LOCAL
    freopen("新建文本文档.txt", "r", stdin);
    #endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",a+i);
        }
        int ans = solve();
        printf("%d\n",ans);

    }
    return 0;
}
