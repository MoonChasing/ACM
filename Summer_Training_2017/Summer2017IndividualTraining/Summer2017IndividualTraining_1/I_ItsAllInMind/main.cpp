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
#define MAXN 110
#define INF 0x3f3f3f3f
//#define DEBUG
typedef long long LL;

using namespace std;
int T, n, m;
int a[MAXN];
int xiabiao[MAXN];
int val[MAXN];
int p,q;
int GCD(int a, int b)
{
    if(b==0) return a;
    return GCD(b, a%b);
}
void init()
{
    memset(a, 0, sizeof(a));
    memset(xiabiao, 0, sizeof(xiabiao));
    memset(val, 0, sizeof(val));
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d%d",&n, &m);
        for(int i=1; i<=m; i++)
            scanf("%d%d",&xiabiao[i],&val[i]);

        if(n==2)
        {
            printf("1/1\n");
            continue;
        }

        for(int i=1; i<=m; i++)
            a[xiabiao[i]] = val[i];

               if(a[1]==a[2] && a[2] == 0)
            a[1] = a[2] = 100;
        else if(a[1] != 0 && a[2] != 0)
        {}
        else if(a[1] ==0 && a[2]!=0)
            a[1] = 100;
        else
            a[2] = a[1];
        for(int i=n-1; i>=3; i--)
            if(a[i] == 0)
                a[i] = a[i+1];
        p=a[1] + a[2];
        q=0;

        for(int i=1; i<=n; i++)
            q+=a[i];
        int gcd = GCD(p,q);

        #ifdef DEBUG
        for(int i=1; i<=n; i++)
            printf("%-4d",a[i]);
        #endif DEBUG
        printf("%d/%d\n",p/gcd,q/gcd);
    }
    return 0;
}

/*
#include<cstdio>
#include<cstring>

using namespace std;
int T,n,m,a[105],sum,max,x,y,i,min;

int gcd(int x,int y)
{
    if(y==0) return x;
    return gcd(y,x%y);
}

int main()
{

    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(a,-1,sizeof(a));
        while(m--)
        {
            scanf("%d%d",&x,&y);
            a[x]=y;
        }

        max=100;
        if(a[1]==-1)
            a[1]=100;
        else
            max=a[1];
        if(a[2]==-1)
            a[2]=max;
        else
            max=a[2];

        min=0;
        sum=0;
        for(i=n;i>2;i--)
        {
            if(a[i]==-1)
            {
                a[i]=min;
            }
            else
            {
                min=a[i];
            }
            sum+=a[i];
        }
        max=a[1]+a[2];
        sum+=max;
        x=gcd(max,sum);
        if(x!=0)
        {
            max/=x;
            sum/=x;
        }
        printf("%d/%d\n",max,sum);
    }
}
*/
