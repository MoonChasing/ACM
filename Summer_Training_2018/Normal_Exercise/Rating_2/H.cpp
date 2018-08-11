#include<cstdio>
using namespace std;

const int MOD = 10000;

typedef struct
{
    long long m[2][2];
}matrix;
matrix I={1,1,1,0};
matrix P={1,1,1,0};

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

matrix qpow_MOD(int n)
{
    matrix a=P,b=I;
    while(n)
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
    int n;
    scanf("%d", &n);
    matrix ans = qpow_MOD(n);
    printf("%I64d\n", ans.m[1][0]);
}
