#include<cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000010;
typedef long long LL;
LL width;
LL n;
LL a[MAXN];

int main()
{
    while(~scanf("%lld%lld", &width, &n))
    {
        width *= 10000000;
        for(int i=0; i<n; i++)
        {
            scanf("%lld", a+i);
        }
        sort(a, a+n);
        bool flag = false;
        LL need, pos, ans1, ans2;
        for(int i=0; i<n; i++)
        {
            need = width - a[i];
            pos = lower_bound(a+i+1, a+n, need) - a;
            if((pos != n )&& (a[pos] == need))
            {
                flag = true;
                ans1 = a[i];
                ans2 = need;
                break;
            }
        }
        if(flag)
        {
            printf("yes %lld %lld\n", ans1, ans2);
        }
        else
            puts("danger");
    }
    return 0;
}
