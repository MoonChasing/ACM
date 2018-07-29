#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#define MAXN 100010
#define INF 1e6
#define eps 1e-8
#define DEBUG
//#define DataIn
typedef long long LL;

using namespace std;

struct stele
{
    double a, b, r ,p;
    void getr()
    {
        double da = max(a, b);
        double xiao = min(a, b);
        r = sqrt( da*da/4 + xiao*xiao);
    }
    void getp(double R)
    {
        p = sqrt(R*R - r*r);
    }
};

bool cmp(stele a, stele b)
{
    return a.r < b.r;
}

stele ste[MAXN];
int n;

double maxr;

bool cc(double R)
{
    for(int i=1; i<=n; i++)
    {
        ste[i].getp(R);
    }

    double lpos = -R, rpos = R;
    for(int i=1; i<=n; i++)
    {
        double l1 = max(lpos, -ste[i].p);
        double r1 = min(rpos, ste[i].p);

        if(-l1 >= r1)
        {
            lpos = l1+1;
            if(fabs(lpos)>ste[i].p || lpos>rpos)
                return false;
        }
        else
        {
            rpos = r1-1;
            if(fabs(rpos)>ste[i].p || lpos>rpos)
                return false;
        }
    }
//    double lpos = 0, rpos = 0;
//    for(int i=1; i<=n; i++)
//    {
//        if(rpos+1 <= ste[i].p && rpos+1<R)
//            rpos++;
//        else if(lpos-1 >= -ste[i].p && lpos-1>R)
//            lpos--;
//        else
//            return false;
//    }
    return true;

}

int main()
{

    #ifdef DataIn
	freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
    #endif

    int T;
    scanf("%d", &T);
    int kiss = 1;
    while(T--)
    {
        maxr = 0;
        scanf("%d", &n);
        for(int i=1; i<=n; i++)
        {
            scanf("%lf%lf", &ste[i].a, &ste[i].b);
            ste[i].getr();
            maxr = max(maxr, ste[i].r);
        }
        sort(ste+1, ste+n+1, cmp);

        double l =maxr, r = INF;
        while(r-l > eps)
        {
            double mid = (l+r)/2;
            if(cc(mid))
                r = mid;
            else
                l = mid;
        }
        printf("Case #%d: %.10f\n", kiss++, l);
    }
    return 0;
}


/*
    知：
        该题使用二分+贪心，自己一直不过的原因是贪心时偏向于向一侧放，而正确答案应为对称放置。
        做了很长时间，最终靠 http://hzwer.com/8558.html 代码改正。

    时:
        2017年8月23日 19:17:34

    地:
        桂苑42-403-3
*/








