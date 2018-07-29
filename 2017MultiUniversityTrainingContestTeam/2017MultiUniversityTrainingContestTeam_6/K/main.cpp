#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int T;
int a,b,c, d, e, f, g;

bool judge()
{
    if(a>=0 && b>=0 && c>=0 && d>=0 && e>=0 && f>= 0 && g>=0 && d-g>=0 && e-g>=0 && f-g>=0 && a-d-f+g>=0 && b-d-e+g>=0 && c-e-f+g>=0)
        return true;
    else
        return false;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int ans = 0;
        while(n--)
        {
            scanf("%d%d%d%d%d%d%d",&a, &b, &c, &d, &e, &f, &g);
            if( judge() )
                ans = max(ans, a+b+c-d-e-f+g);
        }
        printf("%d\n",ans);
    }
    return 0;
}
