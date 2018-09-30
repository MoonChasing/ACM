#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
/////////////
const int MAXN = 107;
int n, R, r;

struct Node
{
    int x, y, i;
    double d;
    void setd()
    {
        d = sqrt(x*x + y*y);
    }
    bool operator < (const Node & s) const
    {
        return d < s.d;
    }
}a[MAXN];
int ans[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &R, &r);
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d", &a[i].x, &a[i].y);
            a[i].setd();
            a[i].i = i;
        }
        sort(a+1, a+1+n);

        int same = 1;
        double minn = a[1].d;
        for(int i=2; i<=n; i++)
        {
            if( fabs(a[i].d - minn) > 1e-6 )
            {
                same = i-1;
                break;
            }
        }

        int cnt = 0;
        if(2*r > R)
        {
            int L = 2*r-R;
            for(int i=1; i<=n; i++)
            {
                if( a[i].d < L || fabs(a[i].d-L)<=1e-6)
                {
                    ans[cnt++] = a[i].i;
                }
                else
                    break;
            }
            if(cnt == 0)
            {
                for(int i=1; i<=same; i++)
                    ans[cnt++] = a[i].i;
            }
        }
        else
        {
            int L = R-r*2;
            for(int i=1; i<=n; i++)
            {
                if( a[i].d < L || fabs(a[i].d-L)<=1e-6)
                {
                    ans[cnt++] = a[i].i;
                }
                else
                    break;
            }
            if(cnt == 0)
                for(int i=1; i<=same; i++)
                    ans[cnt++] = a[i].i;
        }
        sort(ans,ans+cnt);
        printf("%d\n", cnt);
        for(int i=0; i<cnt; i++)
            printf("%d%c", ans[i], " \n"[i==cnt-1]);
    }
    return 0;
}
