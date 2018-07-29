#include<cstdio>
#include<algorithm>
using namespace std;

#define MAXN 500000
int a[MAXN], b[MAXN], c[MAXN];

int main()
{
    int x, y, z, n;
    while ( scanf("%d",&n) && n )
    {
        for ( int i = 0; i < n; i++ )
        {
            scanf("%d%d%d",&x,&y,&z);
            a[i] = x-y;
            b[i] = y-z;
            c[i] = z-x;
        }
        sort(a,a+n);
        sort(b,b+n);
        sort(c,c+n);
        long long ans = 0;
        for ( long long i = 0; i < n; i++ )
        {
            ans += (i+i-n+1) * a[i];
            ans += (i+i-n+1) * b[i];
            ans += (i+i-n+1) * c[i];
        }
        printf("%I64d\n",ans/2);
    }
    return 0;
}
