#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,n) for(int i=a;i<n;i++)
namespace linear
{
    ll mo=1000000009;
    vector<ll> v;
    double a[105][105],del;
    int k;
    struct matrix
    {
        int n;
        ll a[50][50];
        matrix operator * (const matrix & b)const
        {
            matrix c;
            c.n=n;
            rep(i,0,n)rep(j,0,n)c.a[i][j]=0;
            rep(i,0,n)rep(j,0,n)rep(k,0,n)
            c.a[i][j]=(c.a[i][j]+a[i][k]*b.a[k][j]%mo)%mo;
            return c;
        }
    }A;
    bool solve(int n)
    {
        rep(i,1,n+1)
        {
            int t=i;
            rep(j,i+1,n+1)if(fabs(a[j][i])>fabs(a[t][i]))t=j;
            if(fabs(del=a[t][i])<1e-6)return false;
            rep(j,i,n+2)swap(a[i][j],a[t][j]);
            rep(j,i,n+2)a[i][j]/=del;
            rep(t,1,n+1)if(t!=i)
            {
                del=a[t][i];
                rep(j,i,n+2)a[t][j]-=a[i][j]*del;
            }
        }
        return true;
    }
    void build(vector<ll> V)
    {
        v=V;
        int n=(v.size()-1)/2;
        k=n;
        while(1)
        {
            rep(i,0,k+1)
            {
                rep(j,0,k)a[i+1][j+1]=v[n-1+i-j];
                a[i+1][k+1]=1;
                a[i+1][k+2]=v[n+i];
            }
            if(solve(n+1))break;
            n--;k--;
        }
        A.n=k+1;
        rep(i,0,A.n)rep(j,0,A.n)A.a[i][j]=0;
        rep(i,0,A.n)A.a[i][0]=(int)round(a[i+1][A.n+1]);
        rep(i,0,A.n-2)A.a[i][i+1]=1;
        A.a[A.n-1][A.n-1]=1;
    }
    void formula()
    {
        printf("f(n) =");
        rep(i,0,A.n-1)printf(" (%lld)*f(n-%d) +",A.a[i][0],i+1);
        printf(" (%lld)\n",A.a[A.n-1][0]);
    }
    ll cal(ll n)
    {
        if(n<v.size())return v[n];
        n=n-k+1;
        matrix B,T=A;
        B.n=A.n;
        rep(i,0,B.n)rep(j,0,B.n)B.a[i][j]=i==j?1:0;
        while(n)
        {
            if(n&1)B=B*T;
            n>>=1;
            T=T*T;
        }
        ll ans=0;
        rep(i,0,B.n-1)ans=(ans+v[B.n-2-i]*B.a[i][0]%mo)%mo;
        ans=(ans+B.a[B.n-1][0])%mo;
        while(ans<0)ans+=mo;
        return ans;
    }
}

int main()
{
    int abcdefg[] = {3,9,20,46,106,244,560,1286,2956,6794,15610,35866,82416,189384};
    vector<ll> V(abcdefg, abcdefg+14);//<-----
    linear::build(V);
    linear::formula();
    ll n;
    while(~scanf("%lld",&n))
    {
        printf("%lld\n",linear::cal(n-1));
    }
    return 0;
}
