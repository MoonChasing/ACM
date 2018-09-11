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

int main()
{
    int T;
    int n, m;
    int a, b;
    LL ans;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);

        if(n == 1 && m == 1)
            printf("1\n");
        else if(n == 1)
            printf("%d\n", max(m-2, 0));
        else if(m == 1)
            printf("%d\n", max(n-2, 0));
        else if(n == 2)
            puts("0");
        else if(m == 2)
            puts("0");
        else
        {
            a = max(0,n-2);
            b = max(0, m-2);
            ans = n*m-a*b;
            printf("%lld\n", ans);
        }
    }
    return 0;
}










