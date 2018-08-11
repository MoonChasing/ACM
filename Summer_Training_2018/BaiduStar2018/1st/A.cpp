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
#define MAXN 1007
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int a[MAXN];
int main()
{
    int n;
    int ans = 0;
    bool flag = false;
    while(~scanf("%d", &n))
    {
        flag = false;
        for(int i=0; i<n; i++)
            scanf("%d", a+i);
        sort(a, a+n, greater<int>() );
        for(int i=0; i<n-2; i++)
        {
            if(a[i] < a[i+1] + a[i+2])
            {
                ans = a[i]+a[i+1]+a[i+2];
                flag = true;
                break;
            }
        }
        if(flag)
            printf("%d\n", ans);
        else
            puts("-1");

    }

    return 0;
}










