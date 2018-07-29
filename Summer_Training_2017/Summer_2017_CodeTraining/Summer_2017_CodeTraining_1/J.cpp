#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define LL long long
LL  a[101];
LL b[10000010];
int main()
{
    int n,t;
    int cnt=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cnt = 0;
        for(int i=0; i<n; i++)
        {
             scanf("%I64d",&a[i]);

             for(int j=2; (LL)j*j <= a[i]; j++)
             {
                 while( a[i]%j == 0)
                 {
                    b[++cnt] = j;
                    a[i] /= j;
                 }
             }

             if(a[i] != 1)
                b[++cnt] = a[i];
        }
        if(cnt>1)
        {
            sort(b+1, b+cnt+1);
            printf("%I64d\n",b[1]*b[2]);
        }
        else
            printf("-1\n");
    }

    return 0;
}
