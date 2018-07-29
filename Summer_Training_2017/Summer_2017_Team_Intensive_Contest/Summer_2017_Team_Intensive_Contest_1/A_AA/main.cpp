#include<iostream>
#include<cstring>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<algorithm>
#define set(x,y) memset(x,y,sizeof(x))
#define scan(x) scanf("%d",&x)

#define For(x,y,z)  for(int x=y;x<z;x++)
#define FOr(x,y,z) for(int x=y;x<=z;x++)
using namespace std;
const int MAXN=1e6+5;
double p[MAXN];
int main()
{
    int a,b,c,d,pr,n;
    while(scanf("%d%d%d%d%d%d",&pr,&a,&b,&c,&d,&n)==6)
    {
        double minn=MAXN,maxn=0,ans=0;
        int index1=1,index2=1;
        for(int i=1;i<=n;i++)
        {
            p[i]=pr*(sin(a*i+b)+cos(c*i+d));
            if(p[i]>maxn)
             {
                 maxn=p[i];
                 index1=i;
             }
              if(p[i]<minn)
            {
                minn=p[i];
                index2=i;
            }
            if(index1<index2 && ans<maxn-minn)
                    ans=maxn-minn;
    }

    if(fabs(ans-0)<=1e-6)
        cout<<"0.00"<<endl;
    else
     cout<<fixed<<setprecision(7)<<ans<<endl;

    }
    return 0;
}
