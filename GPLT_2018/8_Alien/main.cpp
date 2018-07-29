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

void shuchu(int n, int h, int m)
{
    if(n == 0)
    {
        printf("0 %02d:%02d\n", h, m);
        return;
    }

    int t, s, f;
    if(n%2)
    {
        t = n/2+1;
        s = h/2;
        f = (h%2)*30+m/2;
        printf("%d %02d:%02d\n", t, s, f);
    }
    else
    {
        t = n>>1;
        s = 12 + h/2;
        f = (h%2)*30+m/2;
        printf("%d %02d:%02d\n", t, s, f);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int t,h,m;
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d:%d", &t, &h, &m);
        shuchu(t, h, m);
    }
    return 0;
}










