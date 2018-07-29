#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>

#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

//const double a = (1+sqrt(5))/2;
//const double b = (1-sqrt(5))/2;
//const double m = 1/sqrt(5);
const int MOD = 998244353;

typedef struct
{
    long long m[2][2];
}matrix;
matrix I={1,0,0,1};
matrix P={0,1,1,1};
matrix mul(matrix a,matrix b)
{
    int i,j,k;
    matrix c;
    for(i=0;i<2;i++)
      for(j=0;j<2;j++)
      {
          c.m[i][j]=0;
          for(k=0;k<2;k++)
            c.m[i][j]+=(a.m[i][k]*b.m[k][j])%MOD;
          c.m[i][j]%=MOD;
      }
    return c;
}
matrix quick_MOD(int n)
{
    matrix a=P,b=I;
    while(n>0)
    {
        if(n&1)
          b=mul(b,a);
        n=n>>1;
        a=mul(a,a);
    }
    return b;
}
int main()
{
    int n,k;
    while(~scanf("%d",&k))
    {
        n=2*k+2;
        matrix temp=quick_MOD(n-1);
        printf("%d\n",( ((temp.m[1][0]+temp.m[1][1])%MOD - 1) + MOD)%MOD );
    }
    return 0;
}







