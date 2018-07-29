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
#define MAXN 10005
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

struct oasis
{
    int l, t, w, h;
}s[MAXN];
int n, m;

LL cc(int x)
{
    LL ans = 0;
    for(int i=0; i<m; i++)
    {
        if(s[i].l < x)
            ans += (LL)(min(s[i].w, x) - s[i].l) * s[i].h;

    }
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        LL ans = 0;
        scanf("%d%d", &n, &m);
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d%d", &s[i].l, &s[i].t, &s[i].w, &s[i].h);
            ans += (LL)s[i].w * s[i].h;
            s[i].w += s[i].l;
        }

        int l=0, r=n;

        while(l<r)
        {
            int mid = l+r>>1;
            LL area = cc(mid);
            if(area*2 < ans)
                l = mid + 1;
            else
                r = mid;
        }
        LL res = cc(r);
        while(cc(r) == res && r<=n)
            r++;
        cout<<r-1<<endl;
    }
    return 0;
}








