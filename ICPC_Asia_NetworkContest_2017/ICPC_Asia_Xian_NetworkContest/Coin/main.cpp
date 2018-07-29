#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<cmath>
#include<vector>
#include<algorithm>
#define eps 1e-6
#define set(x,y) memset(x,y,sizeof(x))
#define scan(x) scanf("%d",&x)
using namespace std;
const int mod=1e9+7;
double p=0;
double getmin(int n,double p)
{
    double res=1;
    while(n>0)
    {
        if(n&1)
            res = fmod(res*p, mod);
        n>>=1;
        p=fmod(p*p, mod);
    }
    return res;
}
int main()
{
    int t;
    cin>>t;
    int n;
    double k1,k2;
    double a;
    double b;
    while(t--)
    {
        double p,q;
        cin>>p>>q>>n;
        a = 1-2*q/p;

        if(fabs(a-0)<eps)
        {printf("500000004\n"); continue;}
        b = 1/a;
        double res=getmin(n,b);
        res = 1/res;
//        res=res/2+0.5;
        b = fmod(fmod((1+res),(2*mod))/b,mod);
        printf("%.lf\n",b*mod+0.5);

    }
    return 0;
}

