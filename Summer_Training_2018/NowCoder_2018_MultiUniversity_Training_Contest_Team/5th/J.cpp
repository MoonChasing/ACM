#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<map>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#define mem(x,y) memset(x,y,sizeof(x))
#define scan(x) scanf("%d",&x)
#define scan2(x,y) scanf("%d%d",&x,&y)
#define eps 1e-8;
#define INF 100000000
#define MAXN 500
#define rep(x,y,z) for(int x=y;x<=z;x++)
using namespace std;
typedef long long ll;

int main()
{

    ll n,p1,p2;
    ll ans=0;
    cin>>n>>p1>>p2;

    if(p2<=p1)
    {

            ans=(n/3)*p2;
        if(n%3)
            ans+=p2;

    }
    else
    {
        if(n<=2)
            ans=p1;
        else
        {
            int temp=0;
             if(p1*(1.5)<=p2) //2ÈË¼ä·ÖÌ¯±ãÒË
             {
                 if(n%2==0)
                    ans=n/2*p1;
                 else
                 {
                      if(p2>2*p1)
                      {
                          ans=(n+1)/2*p1;
                      }
                      else
                      {
                          ans=(n/2-1)*p1+p2;
                      }
                 }
             }
            else
            {
                if(n%3==0)
                    ans=n/3*p2;
                else
                {
                    if(n%3==2)
                    {
                        ans=n/3*p2+p1;
                    }
                    else
                    {
                        ans=(n/3-2)*p2+2*p1;
                    }
                }
            }
        }
    }
    int main()
    cout<<ans<<endl;

    return 0;
}
